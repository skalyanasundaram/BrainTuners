#include <iostream>
#include <ctype.h>

using namespace std;

int main() {
    
    string s;

    while(getline(cin, s)) {
        bool word = false;
        int start = 0, words = 0;
        for(int i = 0; i < s.size(); i++) {
            if (isalpha(s[i]) && !isalpha(s[i+1]))
                words++;
            //if(isalpha(s[i))
            //     word = true;
            // else {
            //     if (word)
            //         words++;

            //     start = i+1;
            //     word = false;
            // }
        }
        // if (word)
        //     words++;
        cout << words << endl;
    }
}
