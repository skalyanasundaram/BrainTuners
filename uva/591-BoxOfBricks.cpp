#include <iostream>

using namespace std;

int main()
{
    int n = 0, i = 0,  moves = 0, set = 1, blocks[51];

    while (true)
    {
        cin >> n;
        
        if (!n)
        {
            break;
        }

        int sum = 0, avg = 0;
        moves = 0;
        for (i = 0; i < n; i++)
        {
            cin >> blocks[i];
            sum += blocks[i];
        }
        avg = sum / n;
        for (i = 0; i < n; i++)
        {
            if (blocks[i] > avg)
            {
                moves += blocks[i] - avg;
            }
        }

        cout << "Set #" << set << endl;
        cout << "The minimum number of moves is " << moves << "." << endl << endl;

        set++;
    }
    return 0;
}
