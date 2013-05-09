#include <iostream>
#include <stack>

using namespace std;

int main() {
    
    int n = 0;
    stack<char> st;
    string s;

    cin >> n;
    cin.ignore(256, '\n');

    while(n) {

        getline(cin, s);
        //cin.ignore();
        
        int len = s.length(), i = 0;

        for(i = 0; i < len; i++) {

            if (s[i] == '(' || s[i] == '[')
                st.push(s[i]);
            else if (s[i] == ')')
                if (!st.empty() && st.top() == '(') 
                    st.pop();
                else
                    break;
            else if (s[i] == ']')
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else
                    break;
        }

        if (st.empty() && i == len) 
            cout << "Yes\n";
        else
            cout << "No\n";

        while(!st.empty())
            st.pop();

        n--;
    }

    return 0;
}


//still performing worse than the previous one
// int main() {
    
//     int n = 0;
//     string s, st;

//     cin >> n;
//     cin.ignore(256, '\n');

//     while(n) {

//         getline(cin, s);
        
//         int len = s.length(), i = 0, index = 0;

//         for(i = 0; i < len; i++) {

//             if (s[i] == '(' || s[i] == '[')
//                 st[index++] = s[i];

//             else if (s[i] == ')')
//                 if (index >= 1 && st[index - 1] == '(') 
//                     index--;
//                 else
//                     break;

//             else if (s[i] == ']')
//                 if (index >= 1 && st[index - 1] == '[')
//                     index--;
//                 else
//                     break;
//         }

//         if (!index && i == len) 
//             cout << "Yes\n";
//         else
//             cout << "No\n";

//         n--;
//     }

//     return 0;
// }
