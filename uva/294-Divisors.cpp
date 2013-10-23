#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <stdlib.h>
using namespace std;

vector<unsigned long long> primes;

int apowerbmodc(unsigned long long a, unsigned long long b, unsigned long long c)
{
    unsigned long long x = 1, y = a;

    while (b > 0)
    {
        if (b % 2 == 1)
            x = (x * y) % c;
        y = (y * y) %c;
        b /= 2;
    }
    return x%c;
}

// fermet's thearom
bool is_prime(unsigned long long num)
{
    unsigned long long a = 0;
    int i = 0;

    // avoiding fermet liars
    for (i = 0; i < 20; i++)
    {
        a= rand() % (num - 1) + 1;
        if (apowerbmodc(a, num - 1, num) != 1)
        {
            return false;
        }
    }
    return true;
}

unsigned long long getnext_prim(unsigned long long n)
{
    while (!is_prime(++n));
    return n;
}

unsigned long get_factor_count(unsigned long long n)
{
    long primeindex = 0, count = 1;
    map<int, int> factors;
    unsigned long long limit = sqrt(n) + 1;
    
    // just check till squre root, no need to go beyond
    while (primes[primeindex] <= limit && n > 1)
    {
        if (n % primes[primeindex] == 0)
        {
            factors[primeindex] = (factors.find(primeindex) == factors.end()? 1 : factors[primeindex] + 1);
            n /= primes[primeindex];
        }
        else
        {
            primeindex++;
            // we are running out next prime numbers get next one and fill the cache as well
            if (primeindex >= primes.size())
            {
                primes.push_back(getnext_prim(primes[primeindex - 1]));
            }
        }
    }
    if (n > 1)
    {
        factors[n] = (factors.find(n) == factors.end()? 1 : factors[n] + 1);
    }

    for (map<int, int>::iterator it = factors.begin();
         it != factors.end();
         it++)
    {
        count *= (it->second + 1);
    }
    return count;
}

int main()
{
    unsigned long long L,U, factor_count = 0, max_num = 0, temp = 0, index = 0;
    int testcase;

    primes.push_back(2);
    primes.push_back(3);

    cin >> testcase;
    while (testcase)
    {
        cin >> L >> U;

        max_num = 1; factor_count = 1;
        for (index = L; index <= U; index++)
        {
            temp = get_factor_count(index);
            if (temp >= factor_count)
            {
                max_num = (temp == factor_count && max_num < index)? max_num : index;
                factor_count = temp;
            }                
        }
        cout << "Between " << L << " and " << U << ", " << max_num << " has a maximum of " << factor_count << " divisors." << endl;
        testcase--;
    }
    return 0;
}
