#include <iostream>
#include <vector>

using namespace std;

class BigInteger {
private:
    vector<int> numbers;
    void set(int n) {
        while(n) {
            numbers.insert(numbers.begin(), n%10);
            n /= 10;
        }
    }
public:
    BigInteger(void) { }
    BigInteger(int n) { set(n); }

    BigInteger(BigInteger& b) {
        numbers.assign(b.numbers.begin(), b.numbers.end());
    }

    void print() {
        bool t = false;
        for(vector<int>::iterator it = numbers.begin();
            it != numbers.end();
            it++) {

            if (*it) t = true;
            if (t) cout << *it;
        }
    }

    void operator=(int n) {
        numbers.clear();
        set(n);
    }

    BigInteger operator+(BigInteger &b) {
        BigInteger c;
        int carry = 0;
        int size = numbers.size() > b.numbers.size()? numbers.size() : b.numbers.size();

        for(vector<int>::reverse_iterator ait = numbers.rbegin(),
                bit = b.numbers.rbegin();

            ait != numbers.rend() || bit != b.numbers.rend();) {

            
            int aa = 0, bb = 0;
            if (ait != numbers.rend()) {
                aa = *ait;
                ait++;
            }
            if(bit != b.numbers.rend()) {
                bb = *bit;
                bit++;
            }
                
            c.numbers.insert(c.numbers.begin(), (carry + aa + bb) % 10);
            carry = (carry + aa + bb ) / 10;
        }
        
        c.numbers.insert(c.numbers.begin(), carry);
        return c;
    }

    BigInteger operator+(int n) {
        BigInteger b(n);
        BigInteger c;
        c = (*this) + b;
        return c;
    }

    bool operator==(int n) {
        vector<int>::reverse_iterator it = numbers.rbegin();
        int rem;

        while(n) {
            if (*it != n % 10)
                break;
            n /= 10;
            it++;
        }

        return (it == numbers.rend())?true:false;
    }
};

BigInteger fibs[10000];

BigInteger fib(int n) {
    if (n == 0) {
        BigInteger c(0);
        return c;
    }

    if (fibs[n] == 0) {
        BigInteger a,b,c;
        a = fib(n-1);
        b = fib(n-2);
        c = a + b;
        fibs[n] = c;
    }


    return fibs[n];
}

int main() {

    int n;
    fibs[1] = 1;
    fibs[2] = 1;

    while(cin >> n){
        BigInteger c;
        c = fib(n);
        c.print();
        cout << endl;
    }
   
    return 0;
}
