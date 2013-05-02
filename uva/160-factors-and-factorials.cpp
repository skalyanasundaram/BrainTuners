#include <iostream>
#include <vector>
#include <stdlib.h>
#include <iomanip>

using namespace std;


int apowerbmodc(long a, long b, long c) {
    long x = 1, y = a;
    while(b > 0) {
        if (b % 2 != 0)
            x = (x * y) % c;
        y = (y * y) % c;
        b >>= 1;
    }
    return x%c;
}

bool is_prime(long num) {
    
    for(int i=0; i<10; i++) {
        long random = (rand() % (num - 1)) + 1;

        if (apowerbmodc(random, num-1, num) != 1)
            return false;
    }
    return true;
}

int main() {
    bool prime[101] = {false};
    int factors[101];
    vector<int> res;
    int N;

    for(int i=2; i<=100; i++)
        prime[i] = is_prime(i);

    while(true) {
        cin >> N;

        if (N == 0)
            break;

        if (N < 2 || N > 100)
            continue;

        res.push_back(N);

        for(int i=2; i<=100; i++)
            factors[i] = 0;

        for (int num = 2; num<=N; num++) {
            int tempnum = num;
            for(int p = 2; p < 100 && tempnum > 1; p++) {
                if (prime[p]) {
                    while(tempnum % p == 0) {
                        tempnum /= p;
                        factors[p]++;
                    }
                }
            }
        }

        for(int i = 2; i<=100; i++) {
            if (factors[i])
                res.push_back(factors[i]);
        }
        res.push_back(0);
    }
    
    bool block_start = true;
    int col_count = 0;
    for(int i = 0; i < res.size(); i++ ){

        int val = res.at(i);

        if (val == 0) {
            block_start = true;
            col_count = 0;
            cout << endl;
            continue;
        }
        if (block_start) {
            cout << setw(3) << val << setw(0) << "! =";
            block_start = false;
        }
        else {
            if (col_count < 15) {
                cout << setw(3) << val;
                col_count++;
            }
            else {
                col_count = 0;
                cout << endl << "      " << setw(3) << val;
            }
        }

    }

}
