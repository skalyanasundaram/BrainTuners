#include <iostream>
#include <map>
using namespace std;

int main()
{
    map <char, bool> vowels;
    string s1, s2;
    int n;

    vowels['a'] = true;
    vowels['e'] = true;
    vowels['i'] = true;
    vowels['o'] = true;
    vowels['u'] = true;

    cin >> n;

    while (n)
    {
        s1.clear();
        s2.clear();

        cin >> s1 >> s2;
        n--;

        if (s1.length() == s2.length())
        {
            string::iterator it1, it2;

            for (it1 = s1.begin(), it2 = s2.begin();
                it1 != s1.end(); it1++, it2++)
            {
                if (*it1 != *it2)
                {
                    if (vowels.find(*it1) == vowels.end() || vowels.find(*it2) == vowels.end())
                    {
                        break;
                    }
                }
            }

            if (it1 == s1.end() && it2 == s2.end())
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }        
        else
        {
            cout << "No\n";
        }
        
    }
}