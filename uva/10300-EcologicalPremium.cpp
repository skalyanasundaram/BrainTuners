#include <iostream>

using namespace std;

int main()
{
    int tests = 0, farmers = 0, index = 0;
    double land = 0, animals = 0, envfrndliness = 0, sum = 0;

    while (cin >> tests)
    {
        while (tests)
        {
            cin >> farmers;

            sum = 0;
            for (index = 0; index < farmers; index++)
            {
                cin >> land >> animals >> envfrndliness;

                sum += ((land / animals) * envfrndliness) * animals;
            }

            cout << sum << endl;
            tests--;
        }
    }

    
    return 0;
}
