#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int x[2][101], t = 0, n = 1, i = 0, rc = 0, cc = 0, r = 0, c = 0;

    while (true)
    {
        cin >> n;
        if (!n)
        {
            break;
        }

        memset (x, 0, sizeof(x[0][0]) * 2 * 101);
        rc = cc = r = c =0;

        for (i = 0; i < n*n; i++)
        {
            cin >> t;
            x[0][i / n] += t;
            x[1][i % n] += t;
        }

        for (i = 0; i < n; i++)
        {
            rc += x[0][i] % 2;
            cc += x[1][i] % 2;

            r = r ? r : ((x[0][i] % 2) ? i+1 : 0);
            c = c ? c : ((x[1][i] % 2) ? i+1 : 0);
        }

        if (rc == 0 && cc == 0)
        {
            cout << "OK" << endl;
        }
        else if (rc == 1 && cc == 1)
        {
            cout << "Change bit (" << r << "," << c << ")" << endl;
        }
        else
        {
            cout << "Corrupt" << endl;
        }
    }

    return 0;
}
