#include <iostream>

using namespace std;

//sieving http://blogs.msdn.com/b/devdev/archive/2006/06/19/637332.aspx
//http://pastie.org/1236070

int main() {
    int ugly_number[1500];
    int p2, p3, p5, wall;

    p2 = p3 = p5 = wall = 0;
    ugly_number[0] = 1;

    while(wall < 1500) {
        while(ugly_number[p2] * 2 <= ugly_number[wall]) p2++;
        while(ugly_number[p3] * 3 <= ugly_number[wall]) p3++;
        while(ugly_number[p5] * 5 <= ugly_number[wall]) p5++;

        if(ugly_number[p2] * 2 < ugly_number[p3] * 3 && 
           ugly_number[p2] * 2 < ugly_number[p5] * 5)

            ugly_number[++wall] = ugly_number[p2] * 2;

        else if (ugly_number[p3] * 3 < ugly_number[p5] * 5)

            ugly_number[++wall] = ugly_number[p3] * 3;

        else
            ugly_number[++wall] = ugly_number[p5] * 5;
    }
    
    cout << "The 1500'th ugly number is " << ugly_number[1499] << "." << endl;

    return 0;
}
