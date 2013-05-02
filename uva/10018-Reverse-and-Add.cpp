#include <iostream>

using namespace std;

int main() {
    int N, i = 0;
    cin >> N;

    while(i < N) {
        long num, rev, t;
        int steps = 0;

        cin >> num;

        while(true) {
            t = num;
            rev = 0;

            while(t) {
                rev = rev * 10 + t % 10;
                t /= 10;
            }
            
            if ( num == rev) {
                cout << steps << " " << rev << endl;
                break;
            }
            else {
                num += rev;
                steps++;
            }
        }
        i++;
    }
}
