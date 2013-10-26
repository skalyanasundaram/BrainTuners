#include <iostream>
#include <string>
#include <list>
#include <ctype.h>
using namespace std;

int main()
{
    string s;
    char t;

    while (getline(cin , s))
    {
        list<char> lst(s.begin(), s.end());
        list<char>::iterator it1, it2;

        it1 = it2 = lst.begin();

        while (it2 != lst.end())
        {
            // reach to the start of the word
            while (it1 != lst.end() && !((*it1 >= 'A' && *it1 <= 'Z') || (*it1 >= 'a' && *it1 <= 'z')))
            {
                it1++;
            }

            if (it1 == lst.end())
                break;

            it2 = it1;
            // reach to the end of word
            while (it2 != lst.end() && (*it2 >= 'A' && *it2 <= 'Z') || (*it2 >= 'a' && *it2 <= 'z'))
            {
                it2++;
            }

            t = tolower(*it1);
            if (! (t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u'))
            {
                lst.insert(it2, *it1);
                it1 = lst.erase(it1);
            }
            lst.insert(it2, 'a');
            lst.insert(it2, 'y');
            it1 = it2;
        }

        s.clear();
        for (it1 = lst.begin(); it1 != lst.end(); it1++)
        {
            s.push_back(*it1);
        }
        cout << s << endl;

    }

    return 0;
}
