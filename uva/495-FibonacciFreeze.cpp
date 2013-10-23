#include <iostream>
using namespace std;

string fibs[5001];

string add(string s1, string s2)
{
    int carry = 0, i = s1.size() - 1, j = s2.size() - 1;
    string out;

    while (i >= 0 || j >= 0 || carry)
    {
        if (i >= 0)
        {
            carry += (s1[i] - '0');
            i--;
        }
        if (j >= 0)
        {
            carry += (s2[j] - '0');
            j--;
        }
        out.insert(out.begin(), '0' + (carry % 10));
        carry /= 10;
    }
    return out;
}

string fibOf(int n)
{
    if (fibs[n].size() == 0)
    {
        fibs[n] = add(fibOf(n-1), fibOf(n-2));
    }

    return fibs[n];
}
        
int main()
{
    int n = 0;
    fibs[0] = "0";
    fibs[1] = "1";
    fibs[2] = "1";

    while (cin >> n)
    {
        cout << "The Fibonacci number for " << n << " is " << fibOf(n) << endl;
    }
    
    return 0;
}

    
    
