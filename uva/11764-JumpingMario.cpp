#include <iostream>
using namespace std;

int main()
{
    int T = 0, index = 0, N = 0, high = 0, low = 0;

    cin >> T;

    while (index < T)
    {
        int prev = 0, cur = 0;
        cin >> N;

        for (int i = 0; i < N; i++)
        {
            cin >> cur;
            if (i)
            {
                if (prev < cur)
                    high++;
                else if (prev > cur)
                    low++;
            }

            prev = cur;
        }

        cout << "Case " << index + 1 << ": " << high << " " << low << endl;
        high = low = 0;
        index++;
    }
}
