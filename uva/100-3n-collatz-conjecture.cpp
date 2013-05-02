//Author kalyan - s.kalyanasundaram@gmail.com

#include <iostream>

using namespace std;

#define SIZE 1000000

static unsigned table[SIZE + 1] = {0,1};

unsigned int find_cycle_length(unsigned n) {

    if (n < SIZE && table[n])
        return table[n];

    //any even number will become odd after 3n+1
    //the even number will be processed anyway and count++ will be called
    //instead we reduce that step by increasing the counter by 2 and call n/=2 outself here
    if (n & 1) {
        if (n > SIZE)
            return 2 + find_cycle_length(((3 * n) + 1) >> 1);
        else {
            table[n] = 2 + find_cycle_length(((3 * n) + 1) >> 1);
            return table[n];
        }
    }
    else {
        if (n > SIZE)
            return 1 + find_cycle_length(n >> 1);
        else {
            table[n] = 1 + find_cycle_length(n >> 1);
            return table[n];
        }
    }
}

// unsigned int find_cycle_length(unsigned n) {

//     unsigned count = 1, N = n;

//     if (n < 1 || n > SIZE)
//         return 0;

//     if (table[n])
//         return table[n];

//     while(n != 1) {
//         if (n & 1) {
//             //any even number will become odd after 3n+1
//             //the even number will be processed anyway and count++ will be called
//             //instead we reduce that step by increasing the counter by 2 and call n/=2 ourself
//             count += 2;
//             n = ((3 * n) + 1) >> 1;
//         }
//         else {
//             n >>= 1;
//             count ++;
//         }
//     }

//     table[N] = count;
//     return table[N];
// }

int main() {
    
    unsigned int i = 0, j = 0, k = 0, l = 0;

    while(cin >> i >> j) {
        
        if (i == 0 || j == 0)
            break;

        unsigned int max = 0, len = 0;

        if (j < i) { k=j; l=i;}
        else { k=i; l=j;}

        //iterate through k->L and find the max cycle length
        for (unsigned int x = k; x <= l; x++) {
            if ((len = find_cycle_length(x)) > max)
                max = len;
        }

        //print the result
        cout << i << " " << j << " " << max << endl;

    }

    return 0;
}
