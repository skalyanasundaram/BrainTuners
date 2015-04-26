#include <iostream>

using namespace std;

int main() {
    int T, input[4], res, other;
    cin >> T;

    for(int i = 1; i <= T; i++)
    {
        cin >> input[0];
        other = 0;
        res = input[0];

        cin >> input[1];
        if (input[1] > res)
        {
            res = input[1];
        }
        else
        {
            other = 1;
        }

        cin >> input[2];
        if (input[2] < res)
        {
            if (input[2] > input[other])
            {
                res = input[2];
            }
            else
            {
                res = input[other];
            }
        }
        
        cout << "Case " << i << ": " << res << endl;

    }

    return 0;
}

