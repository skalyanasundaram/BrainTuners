#include <iostream>
using namespace std;

int main() 
{
    int H, D, F, days;
    double climbed, U, fatigue;
    bool first;

    while (true)
    {
        cin >> H;
        if (!H)
        {
            break;
        }

        cin >> U >> D >> F;
        days = climbed = 0;
        fatigue = F * U / 100;

        while (true)
        {
            if (!days)
            {
                climbed += U;
            }
            else
            {
                if (U - fatigue > 0)
                {
                    U -= fatigue;
                    climbed += U;
                }
            }
            
            if (climbed > H)
            {
                break;
            }
         
            climbed -= D;
            if (climbed < 0)
            {
                break;
            }

            days++;
        }

        if (climbed <= 0)
        {
            cout << "failure on day " << days+1 << endl;
        }
        else
        {
            cout << "success on day " << days+1 << endl;
        }
    }

    return 0;
}