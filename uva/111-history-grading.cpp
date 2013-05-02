#include <iostream>
#include <vector>

using namespace std;

// int lcs(vector<int> s1, vector<int> s2) {

//     if (s1.size() == 0 || s2.size() == 0)
//         return 0;

//     vector<int> ss1, ss2;
//     ss1.assign(s1.begin(), s1.end()-1);
//     ss2.assign(s2.begin(), s2.end()-1);

//     if (s1.back() == s2.back())
//         return 1 + lcs(ss1, ss2);
//     else {
//         int left_lcs = lcs(ss1, s2);
//         int right_lcs = lcs(s1, ss2);
//         return (left_lcs > right_lcs) ? left_lcs : right_lcs;
//     } 
        
// }

int main() {

    int n, x;
    int *seq, *inp;
    int **lcs;
    vector<int> res;
    
    cin >> n;

    if (n < 2 || n > 20)
        return -1;

    seq = new int[n + 1];
    inp = new int[n + 1];

    lcs = new int*[n+1];
    for(int i=0; i<=n; i++)
        lcs[i] = new int[n+1];

    for(int i=1; i<=n; i++) {
        cin >> x;
        seq[x] = i;
    }

    while(!cin.eof()) {
        for(int i=1; i<=n; i++) {
            cin >> x;
            inp[x] = i;
        }

        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++)
                lcs[i][j] = 0;

        for(int i=0; i<=n; i++)
            for(int j=0; j<=n; j++) {
                if (i == 0 || j == 0)
                    lcs[i][j] = 0;
                else if (seq[i] == inp[j]) {
                    lcs[i][j] = lcs[i-1][j-1] + 1;
                }
                else {
                    lcs[i][j] = (lcs[i-1][j] > lcs[i][j-1]) ? lcs[i-1][j] : lcs[i][j-1];
                }
            }

        res.push_back(lcs[n][n]);
    }

    for(vector<int>::iterator it = res.begin();
        it != res.end()-1;
        it++) {
        cout << *it << endl;
    }
    return 0;
}
