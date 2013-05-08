#include <iostream>

using namespace std;

unsigned long long result[1000000] = {0};

unsigned long long f91(unsigned long long num) {
    if (!num)
        return num;

    if (result[num] == 0)
        result[num] = (num <= 100) ? f91(f91(num + 11)) : result[num] = num - 10;

    return result[num];
}

int main() {

    unsigned long long num = 0;

    while(cin >> num) {
        if (!num)
            break;

        cout << "f91(" << num << ") = " << f91(num) << endl;
    }

    return 0;
}
