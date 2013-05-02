#include <iostream>

using namespace std;

int main() {
    unsigned long long a, b;

    while (cin >> a >> b) {
        
        if (a == 0 && b == 0)
            break;

        int carry_count = 0, carry = 0;

        while(a > 0 || b > 0) {
            int sum = (a % 10) + (b % 10) + carry;
            if (sum >= 10) {
                carry_count++;
                carry = sum / 10;
            }
            else
                carry = 0;

            a /= 10;
            b /= 10;

        }

        if (carry_count == 0)
            cout << "No";
        else
            cout << carry_count;

        cout << " carry operation" << (carry_count > 1 ? "s." :".") << endl;
    }

    return 0;
}
