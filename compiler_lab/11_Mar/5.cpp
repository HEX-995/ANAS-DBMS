#include <iostream>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main() {

    int n, m;

    cout << "Enter number of NFA states: ";
    cin >> n;

    cout << "Enter number of input symbols: ";
    cin >> m;

    char symbols[m];
    cout << "Enter input symbols:\n";
    for(int i=0;i<m;i++)
        cin >> symbols[i];

    map<pair<int,char>, set<int>> nfa;

    int t;
    cout << "Enter number of transitions: ";
    cin >> t;

    cout << "Enter transitions (from symbol to):\n";

    for(int i=0;i<t;i++){
        int from,to;
        char sym;
        cin >> from >> sym >> to;
        nfa[{from,sym}].insert(to);
    }

    int start;
    cout << "Enter start state: ";
    cin >> start;

    int f;
    cout << "Enter number of final states: ";
    cin >> f;

    set<int> finalStates;
    cout << "Enter final states:\n";
    for(int i=0;i<f;i++){
        int x;
        cin >> x;
        finalStates.insert(x);
    }

    set<int> startSet = {start};

    queue<set<int>> q;
    map<set<int>, int> dfaState;
    vector<map<char,set<int>>> dfaTrans;

    q.push(startSet);
    dfaState[startSet] = 0;

    int stateCount = 1;

    while(!q.empty()){

        set<int> curr = q.front();
        q.pop();

        map<char,set<int>> trans;

        for(char sym : symbols){

            set<int> next;

            for(int s : curr){
                if(nfa.count({s,sym}))
                    next.insert(nfa[{s,sym}].begin(),
                                nfa[{s,sym}].end());
            }

            if(!next.empty()){

                if(!dfaState.count(next)){
                    dfaState[next] = stateCount++;
                    q.push(next);
                }

                trans[sym] = next;
            }
        }

        dfaTrans.push_back(trans);
    }

    cout << "\nDFA States:\n";

    for(auto p : dfaState){
        cout << "State " << p.second << " = { ";
        for(int x : p.first)
            cout << x << " ";
        cout << "}\n";
    }

    cout << "\nDFA Transitions:\n";

    for(auto p : dfaState){

        int id = p.second;

        for(char sym : symbols){

            if(dfaTrans[id].count(sym)){

                set<int> next = dfaTrans[id][sym];
                cout << id << " --" << sym << "--> "
                     << dfaState[next] << endl;
            }
        }
    }

    cout << "\nFinal DFA States:\n";

    for(auto p : dfaState){

        for(int x : p.first){
            if(finalStates.count(x)){
                cout << "State " << p.second << endl;
                break;
            }
        }
    }

    return 0;
}