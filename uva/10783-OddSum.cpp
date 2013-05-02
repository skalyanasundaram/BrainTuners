#include <iostream>

using namespace std;

int main() {
    unsigned int a, b, T, i;

    cin >> T;

    if (T < 1 || T > 100)
        return -1;

    for (int i = 0; i < T; i++) {
        cin >> a >> b;

        if (a > 100 || b > 100)
            continue;

        if (a % 2 == 0)
            a++;

        if (b % 2 == 0)
            b--;

        unsigned long sum = 0;

        /**
         *To find how many elements in between a and b
         *a + (ith element - 1) * 2
         *start value + 2 * index of that element
         *1 3 5 7 9
         *to get 7 (1 + 2*(4-1))
         *
         *To get nth element b = a + 2(n-1)
         *b - a = 2n - 2
         *(b - a + 2) / 2 = n
         */

        int n = (b - a + 2) / 2;

        /**
         *Arithmetic sum
         *http://en.wikipedia.org/wiki/Arithmetic_sequence#Sum
         *
         *a, a+x, a+x+x, a+x+x+x...
         *sum is n*(a + a+x..xn) / 2
         */


        cout << "Case " << i + 1 << ": " << n * (a+b) / 2 << endl;
    }
    return 0;
}
