#include <iostream>
#include <map>

using namespace std;

int main() {
    map<char, char*> keymap;

    char keys[4][20] = {{'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
                        {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'},
                        {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\''},
                        {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'}};

    for(int i=0; i<4; i++) {
        for(int j = 0; keys[i][j] != 0; j++) {
            keymap[keys[i][j]] = keys[i] + j;
        }
    }


    string s;
    while(getline(cin, s)) {

        for(string::iterator it = s.begin();
            it != s.end();
            it++) {
            
            std::map<char, char*>::iterator m = keymap.find(*it);
            if (m != keymap.end()) {
                char *p =  m->second;
                char c = *(p-(sizeof(char)));
                cout << c;
            }
            else
                cout << *it;
        }
        cout << endl;
    }


    return 0;
}
