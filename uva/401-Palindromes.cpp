#include <iostream>
using namespace std;

int main()
{
    char alpha_mirror_map[26] = { 'A', ' ', ' ', ' ', '3', ' ', ' ',
        'H', 'I', 'L', ' ', 'J', 'M', ' ', 'O', ' ', ' ', ' ',
        '2', 'T', 'U', 'V', 'W', 'X', 'Y', '5' };
    char numeric_mirror_map[10] = { ' ' ,'1', 'S', 'E', ' ', 'Z', ' ', ' ', '8', ' ' };

    string s;
    int start, end;

    while (cin >> s)
    {
        start = 0;
        end = s.length() - 1;

        bool polyndrome = true, mirror = true;

        while (start <= end && (polyndrome || mirror))
        {
            if (s[start] != s[end])
            {
                polyndrome = false;
            }

            char mirrorchar = (s[start] >= 'A' && s[start] <= 'Z') ? alpha_mirror_map[s[start] - 'A'] : numeric_mirror_map[s[start] - '0'];
            if (mirrorchar == ' ' || mirrorchar != s[end])
            {
                mirror = false;
            }
            start++;
            end--;
        }

        cout << s << " -- ";
        if (mirror && polyndrome)
        {
            cout << "is a mirrored palindrome.";
        }
        else
        {
            if (mirror)
            {
                cout << "is a mirrored string.";
            }
            else
            {
                if (polyndrome)
                {
                    cout << "is a regular palindrome.";
                }
                else
                {
                    cout << "is not a palindrome.";
                }
            }
        }
        cout << endl << endl;
    }
    return 0;
}