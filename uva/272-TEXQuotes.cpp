#include <iostream>
#include <string>

using namespace std;
 
int main()
{
    string s;
    bool odd = true;

    while (getline(cin, s))
    {
        size_t pos = 0;
        while (true)
        {
            pos = s.find("\"", pos);
            if (pos != string::npos)
            {
                if (odd)
                {
                    s.replace(pos, 1, "``");
                    odd = false;
                }
                else
                {
                    s.replace(pos, 1, "''");
                    odd = true;
                }
                pos++;
            }
            else
            {
                break;
            }
        }
        cout << s << endl;
        s.clear();
    }
}