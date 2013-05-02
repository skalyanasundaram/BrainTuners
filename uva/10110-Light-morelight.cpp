#include <iostream>
#include <math.h>

using namespace std;

int main() {
    unsigned long x = 0;

    while(true) {
        cin >> x;

        if (!x)
            break;

        double s = sqrt(x);
        if (s - (unsigned long)s > 0)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
    return 0;
}
