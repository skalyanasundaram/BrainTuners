#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main()
{
    int h = 0, m = 0;
    while(true)
    {
        scanf("%d:%d", &h, &m);
        if (h == 0 && m == 0)
        {
            break;
        }
    
        double hourangle = (double)((60 * h) + m) / 2;
        double minuteangle = 6 * m;
        double angle = hourangle - minuteangle;

        if (angle < 0)
        {
            angle = angle * -1;
        }
        // cout << hourangle << " " << minuteangle << " " << angle << " ";
        angle = (angle > 180) ? 360 - angle : angle;
        angle = (angle * 1000) / 1000;

        cout << std::fixed << std::setprecision(3) << angle << endl;
        
    }
    return 0;
}
