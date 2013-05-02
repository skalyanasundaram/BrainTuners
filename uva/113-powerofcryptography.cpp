#include <iostream>
#include <math.h>

using namespace std;

int main() {
    double p,n;

    while(cin >> n >> p) {
        if (n < 1 || n > 200 || p < 1)
            break;
        cout << (long) floor(pow(10, log10(p) / n) + 0.5) << endl;
    }
    return 0;
}
