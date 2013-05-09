#include <iostream>

using namespace std;

int main() {
    unsigned long long a = 0, b = 0;

    while(cin >> a >> b) {
        long long c = a - b;
        cout << ((c < 0) ? (c * -1) : c) << endl;
    }
    return 0;
}
