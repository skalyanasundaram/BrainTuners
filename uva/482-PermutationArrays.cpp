#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

int main()
{
    vector<int> index;
    vector<string> value, outvalues;
    int n = 0, x = 0;
    string s, ss;

    cin >> n;
    getline(cin, s); getline(cin, s);

    while (n)
    {
        istringstream stream;
        index.clear(); value.clear(); outvalues.clear();

        s.clear(); stream.clear();
        getline(cin, s); stream.str(s);
        while (stream >> x)
        {
            index.push_back(x);
        }

        s.clear();stream.clear();
        getline(cin, s);stream.str(s);
        while (stream >> ss)
        {
            value.push_back(ss);
        }
        
        outvalues.resize(value.size());
        for (int i = 0; i < index.size(); i++)
        {
            outvalues[index[i] - 1] = value[i];
        }

        for (vector<string>::iterator it = outvalues.begin(); it != outvalues.end(); it++)
        {
            cout << *it << endl;
        }

        n--;

        if (n)
        {
            getline(cin, s);
            cout << endl;
        }
    }
    return 0;
}