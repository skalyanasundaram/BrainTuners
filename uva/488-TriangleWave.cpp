#include <iostream>
#include <string>

using namespace std;

void PrintWave(int height)
{
    for(int i = 0; i < height; i++)
    {
        cout << height;
    }
    cout << endl;
}

int main()
{
    int tests = 0, amp = 0, freq = 0, index = 0;
    string s;

    cin >> tests;

    while (tests)
    {
        getline(cin, s);
        cin >> amp >> freq;

        while (freq)
        {
            for (index = 1; index <= amp; index++)
            {
                PrintWave(index);
            }
            for (index = amp - 1; index > 0; index--)
            {
                PrintWave(index);
            }
            freq--;

            if (tests != 1 || freq)
            {
                cout << endl;
            }
        }
        
        tests--;
    }
    return 0;
}
