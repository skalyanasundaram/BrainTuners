#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    vector<double> lst;
    lst.resize(1000);

    int C;
    double N,s,t, Nt;

    cin >> C;

    while(C) {
        cin >> N;
        if (N < 1 || N > 1000 )
            continue;

        Nt = N;
        s = 0;
        lst.clear();

        while(Nt) {
            cin >> t;
            s += t;
            lst.push_back(t);
            
            Nt--;
        }

        s /= N;

        int count = 0;
        for(vector<double>::iterator it = lst.begin();
            it != lst.end();
            it++) {
            if (*it > s)
                count++;
        }

        std::cout.setf(std::ios::fixed);
        std::cout.precision(3);
        cout << (double)count / N * 100 << "%" << endl;
        C--;
    }
    return 0;
}
