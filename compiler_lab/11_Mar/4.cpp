#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct State {
    int id;
};

struct Transition {
    int from;
    int to;
    char symbol;
};

struct NFA {
    int start;
    int accept;
    vector<Transition> trans;
};

int stateCount = 0;

int newState() {
    return stateCount++;
}

NFA symbolNFA(char c) {
    NFA nfa;
    int s = newState();
    int e = newState();

    nfa.start = s;
    nfa.accept = e;

    nfa.trans.push_back({s, e, c});
    return nfa;
}

NFA concatNFA(NFA a, NFA b) {
    NFA nfa;

    nfa.start = a.start;
    nfa.accept = b.accept;

    nfa.trans = a.trans;
    nfa.trans.insert(nfa.trans.end(), b.trans.begin(), b.trans.end());

    nfa.trans.push_back({a.accept, b.start, 'e'}); // epsilon

    return nfa;
}

NFA unionNFA(NFA a, NFA b) {
    NFA nfa;

    int s = newState();
    int e = newState();

    nfa.start = s;
    nfa.accept = e;

    nfa.trans = a.trans;
    nfa.trans.insert(nfa.trans.end(), b.trans.begin(), b.trans.end());

    nfa.trans.push_back({s, a.start, 'e'});
    nfa.trans.push_back({s, b.start, 'e'});
    nfa.trans.push_back({a.accept, e, 'e'});
    nfa.trans.push_back({b.accept, e, 'e'});

    return nfa;
}

NFA starNFA(NFA a) {
    NFA nfa;

    int s = newState();
    int e = newState();

    nfa.start = s;
    nfa.accept = e;

    nfa.trans = a.trans;

    nfa.trans.push_back({s, a.start, 'e'});
    nfa.trans.push_back({s, e, 'e'});
    nfa.trans.push_back({a.accept, a.start, 'e'});
    nfa.trans.push_back({a.accept, e, 'e'});

    return nfa;
}

int main() {

    string regex;
    cout << "Enter postfix regular expression: ";
    cin >> regex;

    stack<NFA> st;

    for(char c : regex) {

        if(isalnum(c)) {
            st.push(symbolNFA(c));
        }

        else if(c == '.') {
            NFA b = st.top(); st.pop();
            NFA a = st.top(); st.pop();
            st.push(concatNFA(a,b));
        }

        else if(c == '|') {
            NFA b = st.top(); st.pop();
            NFA a = st.top(); st.pop();
            st.push(unionNFA(a,b));
        }

        else if(c == '*') {
            NFA a = st.top(); st.pop();
            st.push(starNFA(a));
        }
    }

    NFA result = st.top();

    cout << "\nStart State: " << result.start << endl;
    cout << "Accept State: " << result.accept << endl;

    cout << "\nTransitions:\n";
    for(auto t : result.trans) {
        cout << t.from << " -- " << t.symbol << " --> " << t.to << endl;
    }

    return 0;
}