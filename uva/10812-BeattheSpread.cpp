#include <iostream>

using namespace std;

int main()
{
    int N, m, n;

    cin >> N;
    while (N)
    {
        cin >> m >> n;

        if ((m + n) % 2 == 0 && m-n >= 0 && (m - n) % 2 == 0)
        {
            cout << (m + n) / 2 << " " << (m - n) / 2 << endl;
        }
        else
        {
            cout << "impossible" << endl;
        }
        N--;
    }

    return 0;
}