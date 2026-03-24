

// Simple NFA to DFA conversion (student-friendly)
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// Max states and symbols for simplicity
#define MAX_NFA 10
#define MAX_DFA 32
#define MAX_SYM 5

int nfa[MAX_NFA][MAX_SYM][MAX_NFA]; // nfa[state][symbol][next_state]=1 if exists
int nfa_states, nfa_symbols;
char symbols[MAX_SYM];

// Store DFA states as bitmasks
int dfa[MAX_DFA][MAX_SYM];
int dfa_states[MAX_DFA]; // bitmask of NFA states
int dfa_final[MAX_DFA];
int dfa_state_count = 0;

// Check if a DFA state (bitmask) is already present
int get_dfa_state(int mask)
{
    for (int i = 0; i < dfa_state_count; i++)
        if (dfa_states[i] == mask)
            return i;
    return -1;
}

int main()
{
    memset(nfa, 0, sizeof(nfa));
    cout << "Enter number of NFA states: ";
    cin >> nfa_states;
    cout << "Enter number of input symbols: ";
    cin >> nfa_symbols;
    cout << "Enter symbols (space separated): ";
    for (int i = 0; i < nfa_symbols; i++)
        cin >> symbols[i];

    cout << "Enter number of transitions: ";
    int ntrans;
    cin >> ntrans;
    cout << "Enter transitions (from symbol to):\n";
    for (int i = 0; i < ntrans; i++)
    {
        int from, to;
        char sym;
        cin >> from >> sym >> to;
        int sym_idx = -1;
        for (int j = 0; j < nfa_symbols; j++)
            if (symbols[j] == sym)
                sym_idx = j;
        nfa[from][sym_idx][to] = 1;
    }

    int start, nfa_final_count, nfa_final[MAX_NFA];
    cout << "Enter start state: ";
    cin >> start;
    cout << "Enter number of final states: ";
    cin >> nfa_final_count;
    cout << "Enter final states: ";
    for (int i = 0; i < nfa_final_count; i++)
        cin >> nfa_final[i];

    // Subset construction
    dfa_state_count = 0;
    dfa_states[0] = (1 << start);
    dfa_final[0] = 0;
    if (find(nfa_final, nfa_final + nfa_final_count, start) != nfa_final + nfa_final_count)
        dfa_final[0] = 1;
    dfa_state_count++;

    for (int i = 0; i < dfa_state_count; i++)
    {
        for (int s = 0; s < nfa_symbols; s++)
        {
            int next_mask = 0;
            for (int st = 0; st < nfa_states; st++)
            {
                if (dfa_states[i] & (1 << st))
                {
                    for (int to = 0; to < nfa_states; to++)
                    {
                        if (nfa[st][s][to])
                            next_mask |= (1 << to);
                    }
                }
            }
            if (next_mask == 0)
            {
                dfa[i][s] = -1;
                continue;
            }
            int idx = get_dfa_state(next_mask);
            if (idx == -1)
            {
                idx = dfa_state_count;
                dfa_states[dfa_state_count] = next_mask;
                dfa_final[dfa_state_count] = 0;
                for (int f = 0; f < nfa_final_count; f++)
                    if (next_mask & (1 << nfa_final[f]))
                        dfa_final[dfa_state_count] = 1;
                dfa_state_count++;
            }
            dfa[i][s] = idx;
        }
    }

    // Print DFA
    cout << "\nDFA States (as sets of NFA states):\n";
    for (int i = 0; i < dfa_state_count; i++)
    {
        cout << "State " << i << ": { ";
        for (int st = 0; st < nfa_states; st++)
            if (dfa_states[i] & (1 << st))
                cout << st << ' ';
        cout << "}";
        if (dfa_final[i])
            cout << " (final)";
        cout << endl;
    }
    cout << "\nDFA Transition Table:\n";
    for (int i = 0; i < dfa_state_count; i++)
    {
        for (int s = 0; s < nfa_symbols; s++)
        {
            cout << "From state " << i << " on '" << symbols[s] << "' -> ";
            if (dfa[i][s] == -1)
                cout << "-";
            else
                cout << dfa[i][s];
            cout << endl;
        }
    }
    return 0;
}