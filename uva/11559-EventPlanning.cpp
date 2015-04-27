#include <iostream>

using namespace std;

int main()
{
    int participants, hotels, weeks, priceForOnePerson, avilableBed;
    long budget, minCost = 0;

    
    while(cin >> participants >> budget >> hotels >> weeks)
    {
        minCost = 0;

        while (hotels > 0)
        {
            cin >> priceForOnePerson;

            for(int i = 0; i < weeks; i++)
            {
                cin >> avilableBed;

                if (avilableBed > 0 && avilableBed >= participants)
                {
                    long cost = participants * priceForOnePerson;
                    if (cost > 0 && cost < budget)
                    {
                        if (minCost == 0 || cost < minCost)
                        {
                            minCost = cost;
                        }
                    }
                }
            }
        
            hotels--;
        }

        if (!minCost)
            cout << "stay home" << endl;
        else
            cout << minCost << endl;
    }            

    return 0;
}
