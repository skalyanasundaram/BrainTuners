#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int N;
    string s;
    map<string, int> girl_count_per_country;
    vector<string> sorted_country;
    vector<string>::iterator it;

    cin >> N;
    while (N)
    {
        getline(cin, s);
        if (s.size() == 0)
            continue;
        stringstream stream(s);

        stream >> s;
        girl_count_per_country[s] = (girl_count_per_country.find(s) == girl_count_per_country.end()) ? 0 : girl_count_per_country[s] + 1;

        it = sorted_country.begin();
        for (; it != sorted_country.end(); it++)
        {
            if (*it >= s)
            {
                break;
            }
        }

        if (it == sorted_country.end() || *it > s)
        {
            sorted_country.insert(it, s);
        }

        N--;
    }

    for (it = sorted_country.begin(); it != sorted_country.end(); it++)
    {
        cout << *it << " " << girl_count_per_country[*it] << endl;
    }
    return 0;
}