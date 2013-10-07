#include <iostream>
#include <vector>
#include <map>

using namespace std;

unsigned long long get_next_number(unsigned long long num)
{
    vector<int> numbers;
    unsigned long long n1 = 0, n2 = 0, n3 = 0;

    while (num)
    {
        int t = num % 10, i = 0;

        for (; i < numbers.size(); i++)
        {
            if (numbers[i] >= t)
            {
                break;
            }
        }
        numbers.insert(numbers.begin() + i, t);
        num /= 10;
    }

    vector<int>::iterator forward_it;
    vector<int>::reverse_iterator reverse_it;

    for (forward_it = numbers.begin(), reverse_it = numbers.rbegin();
        forward_it != numbers.end();
        forward_it++, reverse_it++)
    {
        n1 = (n1 * 10) + *reverse_it;
        n2 = (n2 * 10) + *forward_it;
    }

    n3 = n1 - n2;
    cout << n1 << " - " << n2 << " = " << n3 << endl;

    return n3;
}
int main()
{
    map<unsigned long long, bool> mymap;
    unsigned long long n;
    int chain_size = 0;

    while (true)
    {
        cin >> n;

        if (!n)
        {
            break;
        }

        mymap.clear();
        chain_size = 0;

        cout << "Original number was " << n << endl;
        

        while(mymap.find(n) == mymap.end())
        {
            mymap[n] = true;
            n = get_next_number(n);
            chain_size++;
        }

        cout << "Chain length " << chain_size << endl << endl;
    }
    return 0;
}