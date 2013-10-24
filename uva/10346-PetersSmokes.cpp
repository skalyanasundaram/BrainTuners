#include <iostream>
using namespace std;

int main()
{
    int n = 0, k = 0, butts = 0, tot = 0;

    while (cin >> n >> k)
    {
        tot = 0;
        butts = 0;

        while (n)
        {
            butts += n;
            tot += n;
            n = (butts / k);
            butts -= (n * k);
        }
        cout << tot << endl;
    }

    return 0;
}

    
