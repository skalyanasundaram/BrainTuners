#include <iostream>
#include <vector>
#include <string>

using namespace std;

string reverse(string s) {
    string s2;
    for(string::reverse_iterator rit = s.rbegin();
        rit < s.rend();
        rit ++)
        s2.push_back(*rit);

    return s2;
}
int main() {
    
    string s;
    vector<string> res;

    while(true) {
        s.clear();
        cin >> s;

        if (s == "#")
            break;

        if (s.size() > 50)
            continue;

        int i = 0, j = 0;
        for(i = s.size() - 2; i >= 0 && s[i] >= s[i+1]; i--) {
            //do nothing wait till we find i
        }


        if (i < 0)
            res.push_back("No Successor");
        else {
            for(j = s.size() -1 ; j>i && s[j] <= s[i]; j--) { }
            
            char t = s[i];
            s[i] = s[j];
            s[j] = t;

            string s2 = s.substr(0, i+1);
            s2 += reverse(s.substr(i+1));
            res.push_back(s2);
        }
    }

    for(vector<string>::iterator it = res.begin();
        res.size() > 0 && it != res.end();
        it++) 
        cout << *it << endl;

    return 0;
}
