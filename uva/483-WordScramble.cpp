#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int i, j;
    while (getline(cin, s))
    {
        i = j =0;
        while (i < s.length())
        {
            j = s.find(" ", i);
            if (j == string::npos)
            {
                j = s.length();
            }

            for (int start = i, end = j - 1; start < end; start++, end--)
            {
                char t = s[start];
                s[start] = s[end];
                s[end] = t;
            }
            i = j + 1;
        }
        cout << s << endl;
        s.clear();
    }
}