
/* http://en.wikipedia.org/wiki/Repeating_decimals
 *
 *In order to convert a rational number represented as a fraction into decimal form, one may use long division. For example, consider the rational number 5/74:
        0.0675
   74 ) 5.00000
        4.44
          560
          518
           420
           370
            500
etc. Observe that at each step we have a remainder; the successive remainders displayed above are 56, 42, 50. When we arrive at 50 as the remainder, and bring down the "0", we find ourselves dividing 500 by 74, which is the same problem we began with. Therefore the decimal repeats: 0.0675 675 675 ….
 */

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>

using namespace std;

// 1/5, we ceil 1 to 10 and divide, 1/50 ceil(1) 100/50, 1/500 = 1000/500
//#define CEIL(n) ((n<=10)?10:((n<=100)?100:1000))
inline int CEIL(int n, int m) {while(n<m) n *= 10; return n;}
#define  CCEIL(n, m, c) while(n<m) {n *= 10; c++; cout<<"0";}

inline bool contain(vector<int> v, int ele) {

    for(vector<int>::iterator it = v.begin(); it < v.end(); it++)
        if (*it == ele) return true;
    return false;
}

int main(int argc, char **argv) {
    int max = 0, finalnum = 0, finalnumlen = 0, len = 0, numerator = 0;
    vector<int> remainders;

    if (argc < 2) {
        cerr << "enter n, to find maximum length of recurring cycle of 1/2..1/n-1" << endl;
        return -1;
    }

    max = atoi(argv[1]);

    clock_t start, end;
    start = clock();

    for (int i=2; i<max; i++) {
        len = 0;
        remainders.clear();
        numerator = 10;  //like regular division, add 0 bydefault add additional 0 in quotient if it can't be devided

        cout << "1/" << i << " = ";

        CCEIL(numerator, i, len);

        do {
            remainders.push_back(numerator);
            
            cout << numerator / i;
            numerator = (numerator % i ) * 10;

            /* no recurring cycle, terminator */
            if (numerator == 0) {len = 0; break;}

            len ++;
            CCEIL(numerator, i, len);


        } while(contain(remainders, numerator) == false);
        
        if (len > finalnumlen) {
            finalnum = i;
            finalnumlen = len - 1;
        }
        cout << endl;
        
    }
    end = clock();

    cout << "len = " << finalnumlen << " num = " << finalnum << endl;
    cout << "difference:" << ((double) (end - start)) / CLOCKS_PER_SEC<< endl;

    return 0;

}
