#include <iostream>
#include <math.h>

using namespace std;

int main() {
    
    string s;

    while(cin >> s) {
        
        if (!s.compare("0"))
            break;

        unsigned long value = 0;

        for(int i=s.length()-1, j = 1; i>=0; i--, j++) {
            value += (s[i]-48) * (pow(2,j) - 1);
        }
        cout << value << endl;
    }
    return 0;
}
