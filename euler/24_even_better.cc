#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;

unsigned long long factorial (int x)
{
 unsigned long long factorial = 1;
 if (x==1) return 1;
 for (int i = 1; i <= x; ++i) factorial = factorial * i;
 return factorial;
}

int main(int argc, char **argv) {
    
    vector<int> list;
    unsigned long long nthperm = 0, rejectquantity = 0;
    int num = 0;
    
    if (argc < 3) {
        cerr << "No number and limit, enter a number 1-10, and limit 1000000" << endl;
        return 1;
    }

    num = atoi(argv[1]);
    nthperm = atol(argv[2]);

    for (int i=0; i<num; i++)
        list.push_back(i);

    while(list.size() > 1) {
        rejectquantity = (unsigned long long) factorial(num) / num;
        int nthelement = 0;
        if ( ceil((float)nthperm / rejectquantity) > floor((float)nthperm / rejectquantity) ) {
            nthelement = ceil(nthperm / rejectquantity); //takes the next element +1 
            nthperm -=  (floor(nthperm / rejectquantity) * rejectquantity); //removes the possible not required prior element
        }
        else {
            nthelement = (nthperm / rejectquantity) - 1; //take the current element, index starts at 0
            nthperm -= (nthperm / rejectquantity); //this is wrong, but works, mab be num!
        }
            
        cout << list[nthelement];
        list.erase(list.begin() + nthelement);
        num --;

    }
    cout << list[0] << endl;
}
/* continued the 24_better till no element left
 * the if else happens because 10, 1000000, 362880 will be 2.8 times which means remove the 2*362880 (1000000 - (2*362880))
 * and the element start with will be 3 (2.8 --> 3)
 * sometimes total element 3, 4th element, 2 will be 2 we need to only remove 2
 * and the element start with will be 1 (2 - 1)
 */
