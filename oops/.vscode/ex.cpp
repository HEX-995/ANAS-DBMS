#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inf1("classA.txt");
    ifstream inf2("classB.txt");

    ofstream outf("merge.txt");
    string word;
    vector<string> buf;
    while(inf1 >> word){
        buf.push_back(word);
    }
    while(inf2 >> word){
        buf.push_back(word);
    }
    sort(buf.begin(), buf.end());
    for(int i = 0; i<buf.size(); i++){
        cout << buf[i] << endl;
        outf << buf[i] << endl;
    }
    return 0;
}

