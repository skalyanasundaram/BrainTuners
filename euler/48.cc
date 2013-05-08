#include<iostream>

using namespace std;

unsigned long long apowerbmodc(long long a,long long b,unsigned long long c) {
    
    unsigned long long x = 1, y = a;

    while (b > 0) {
        if (b%2 == 1)
            x = (x*y) % c;

        y = (y*y) % c;

        b /= 2;
    }

    return x%c;
}

int main(int argc, char **argv) {
    
    unsigned long long num = 12345678901234;

    cout << apowerbmodc(51,51,10000000000) << endl;
    return 0;
}
