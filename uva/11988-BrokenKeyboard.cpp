#include <iostream>
#include <list>
using namespace std;

int main()
{
    string s1, s2;
    list<char> lst;
    string::iterator i;
    list<char>::iterator j;

    while (cin >> s1)
    {
        j = lst.begin();

        for (i = s1.begin(); i != s1.end(); i++)
        {
            if (*i == '[')
            {
                j = lst.begin();
            }
            else if (*i == ']')
            {
                j = lst.end();
            }
            else
            {
                lst.insert(j, *i);
            }
        }

        for (j = lst.begin(); j != lst.end(); j++)
        {
            s2.push_back(*j);
        }
        cout << s2 << endl;
        s1.clear();
        s2.clear();
        lst.clear();
    }

    return 0;
}
