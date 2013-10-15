#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    unsigned long n = 0, i = 0;
    unsigned short x = 0, v = 0;
    vector<unsigned short> arr;
    bool first = false;

    string s;
    while (true)
    {
        cin >> n;
        getline(cin, s);
        if (!n)
        {
            break;
        }
        getline(cin, s);

        arr.clear();
        arr.assign(101, 0);
        first = true;

        for (i = 0, v = 0;; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                arr[v]++;
                v = 0;
            }
            else
            {
                v = v * 10 + (s[i] - '0');
            }
        }
        arr[v]++;

        for (i = 1; i <= 100; i++)
        {
            if (arr[i])
            {
                while (arr[i])
                {
                    if (!first)
                    {
                        cout << " ";
                    }
                    cout << i;
                    first = false;
                    arr[i]--;
                }
            }
        }
        cout << endl;
    }

    return 0;
}