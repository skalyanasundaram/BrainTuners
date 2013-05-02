#include <iostream>

using namespace std;

int main() {
    unsigned int a, b, T, i;
    unsigned long sum;

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

        sum = 0;


        while(a <= b) {
            sum += a;
            a += 2;
        }

        cout << "Case " << i + 1 << ": " << sum << endl;
    }
    return 0;
}
