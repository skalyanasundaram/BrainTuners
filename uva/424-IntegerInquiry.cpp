#include <iostream>
#include <vector>

using namespace std;

class Integer {
private:
    vector<int> res;

public:
    Integer() { res.assign(1000, 0); }
    void print() {
        bool begin = false;
        for(vector<int>::reverse_iterator it = res.rbegin();
            it != res.rend();
            it++) {

            if (*it)
                begin = true;

            if(begin)
                cout << *it;
        }

        cout << endl;
    }

    void add(string s) {
        int carry = 0, index = s.length() - 1;
        for(vector<int>::iterator it = res.begin();
            it != res.end();
            it++)
            {
                int sum = carry + *it;
                if (index >= 0)
                    sum += s[index--] - 48;
                
                *it = sum % 10;
                carry = sum / 10;

            }

        while(carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }
};

int main() {
    
    string s;
    Integer Linteger;

    while(true) {
        cin >> s;
        if (s.compare("0") == 0)
            break;
        else
            Linteger.add(s);
    }
    Linteger.print();
    return 0;
}
