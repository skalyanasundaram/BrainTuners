#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

string  tolower_trim(string s)
{
    string out;
    for (int j = 0; j < s.length(); j++)
    {
        out.push_back(tolower(s[j]));
    }

    return out;
}

void binary_search_insert(vector<string> &list, string s)
{
    int i = 0, j = list.size() - 1, mid = 0;

    while (i <= j)
    {
        mid = (i + j) / 2;
        if (list[mid] > s)
        {
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }

    list.insert(list.begin() + i, s);
}

int main()
{
    string s, temp;
    map<string, bool> dict;
    vector<string> list;

    while (getline(cin, s))
    {
        int i = 0, j = 0;
        while (true)
        {
            while (j < s.length())
            {
                if (isalpha(s[j]))
                {
                    break;
                }
                j++;
            }
            if (j == s.length())
            {
                break;
            }
            i = j;

            while (j < s.length())
            {
                if (!isalpha(s[j]))
                {
                    break;
                }
                j++;
            }

            temp = tolower_trim(s.substr(i, ((j < s.length()) ? j - i: s.length() - i)));

            if (dict.find(temp) == dict.end())
            {
                dict[temp] = true;
                binary_search_insert(list, temp);
            }

            if (j == s.length())
            {
                break;
            }
        }
    }

    for (vector<string>::iterator it = list.begin();
        it != list.end();
        it++)
    {
        cout << *it << endl;
    }

    return 0;
}