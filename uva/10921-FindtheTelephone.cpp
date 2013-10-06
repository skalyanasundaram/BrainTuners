#include <iostream>

using namespace std;

int main()
{
    int map[26] = { 2, 2, 2,
                    3, 3, 3,
                    4, 4, 4,
                    5, 5, 5,
                    6, 6, 6,
                    7, 7, 7, 7,
                    8, 8, 8,
                    9, 9, 9, 9};

    string s;

    while (cin >> s)
    {
        for (string::iterator it = s.begin(); it != s.end(); it++)
        {
            if (*it >= 'A' && *it <= 'Z')
                cout << map[*it - 'A'];
            else
                cout << *it;
        }
        cout << endl;
    }
}