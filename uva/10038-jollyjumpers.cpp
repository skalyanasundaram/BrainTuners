#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
    vector<bool> answer;
    bool set[3001] = {false};
    int n;

    while(!cin.eof()) {
        cin >> n;

        if(n > 3000 || n < 1)
            continue;

        int prev = 0, cur = 0;

        for(int i=0; i < n; i++)
            set[i] = false;

        for(int i=0; i < n; i++) {
            cin >> cur;

            if(i > 0)
                set[abs(prev-cur)] = true;

            prev = cur;
        }

        int i = 1;
        for(; i < n; i++) {
            if(set[i] == false) {
                answer.push_back(false);
                break;
            }
        }
        if (i == n)
            answer.push_back(true);

    }

    for(int i=0; i < answer.size()-1; i++)
        cout << (answer.at(i) ? "Jolly":"Not jolly") << endl;
    return 0;
}
