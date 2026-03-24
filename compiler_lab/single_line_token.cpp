#include<bits/stdc++.h>
using namespace std;
int main() {
    ifstream file;
    int i = 0, token = 0;
    char code;
    file.open("token.txt");
   

    // while ( getline(file, code)) { it is wrong as it reads entire lines
    while ( file.get(code)) {

        if (code == '+' || code == ';') {
            token++;
        }
        else if (code == ' '||code=='\n') {
            continue;
        }
        else {
            token++;
        }
    }
    cout << "tokens = " << token << endl;
    file.close();
    return 0;
}