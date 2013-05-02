#include <iostream>

using namespace std;

int main() {
    long long a, b;
    int n;

    cin >> n;

    if (n >= 15)
        return -1;

    while(true) {
        cin >> a >> b;

        if (a == b)
            cout << "=";
        else if (a < b)
            cout << "<";
        else
            cout << ">";
        cout << endl;

        n--;

        if (n == 0)
            break;
    }
    return 0;
}
