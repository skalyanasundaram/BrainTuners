#include<iostream>

using namespace std;

int main()
{
    int n, out;

    while (cin >> n)
    {
        out = ((n << 24 & 0xff000000)
            | ((n << 8) & 0xff0000)
            | ((n >> 8) & 0xff00)
            | ((n >> 24) & 0xff));
        cout << n << " converts to " << out << endl;
    }

    return 0;
}
