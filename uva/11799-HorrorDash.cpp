#include <iostream>

using namespace std;

int main()
{
    int testcase = 0, N = 0, min = 0, speed = 0;

    cin >> testcase;

    for(int index = 1; index <= testcase; index++)
    {
        cin >> N;
        min = 0;

        while (N) 
        {
            cin >> speed;
            if (speed > min)
                min = speed;
            N--;
        }

        cout << "Case " << index << ": " << min << endl;
    }

    return 0;
}
