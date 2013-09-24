#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    string s, out;
    int code[26] = { 0, 1, 2, 3, 0, 1, 2, 0, 0, 2, 2, 4, 5, 5, 0, 1, 2, 6, 2, 3, 0, 1, 0, 2, 0, 2 };
    vector <string> inp;

    while (cin >> s)
    {
        inp.push_back(s);
    }

    cout << setw(9) << "" << setw(25) << left << "NAME" << "SOUNDEX CODE" << endl;

    for (vector<string>::iterator it = inp.begin(); it != inp.end(); it++)
    {
        s = *it;
        for (int i = 0; i < s.length(); i++)
        {
            if (!out.length())
            {
                out.push_back(s[i]);
            }
            else
            {
                if (!code[s[i] - 'A'])
                {
                    continue;
                }
                else
                {
                    if (out.length() < 4)
                    {
                        if (code[s[i - 1]- 'A'] != code[s[i] - 'A'])
                        {
                            out.push_back(code[s[i] - 'A'] + '0');
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }

        cout << setfill(' ') << setw(9) << "" << setw(25) << left << s << setfill('0') << setw(4) << left << out << endl;
        s.clear();
        out.clear();
    }

    cout << setfill(' ') << setw(19) << "" << "END OF OUTPUT" << endl;
    return 0;
}