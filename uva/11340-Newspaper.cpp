#include <iostream>
#include <map>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    int test = 0, k = 0;
    unsigned long long sum = 0, c = 0;
    map<char, int> value;
    char a;
    string s;

    cin >> test;
    while (test)
    {
        value.clear();
        sum = 0;

        // get the charater value
        cin >> k;
        while (k)
        {
            cin >> a >> c;
            value[a] = c;
            k--;
        }

        // get the newspaper content
        cin >> k;
        getline(cin, s);
        while (k)
        {
            s.clear();
            getline(cin, s);

            for (string::iterator it = s.begin(); it != s.end(); it++)
            {
                sum += (value.find(*it) == value.end() ? 0 : value[*it]);
            }
            k--;
        }

        cout << setw(0) << sum / 100 << "." << setfill('0') << setw(2) << sum % 100 << "$" << endl;
        test--;
    }
    return 0;
}