#include <iostream>

using namespace std;

int lcs(string s1, string s2) {
    int matrix[s1.length() + 1][s2.length() + 1];

    for(int i = 0 ; i <= s1.length(); i++) {
        for(int j = 0; j <= s2.length(); j++) {
            if(i == 0 || j == 0)
                matrix[i][j] = 0;
            else if (s1[i-1] == s2[j-1])
                matrix[i][j] = matrix[i-1][j-1] + 1;
            else
                matrix[i][j] = matrix[i-1][j] > matrix[i][j-1] ? matrix[i-1][j] : matrix[i][j-1];
        }
    }

    return matrix[s1.length()][s2.length()];
}

int main() {
    string s1, s2;

    while(cin >> s1 >> s2) {
        if (lcs(s1,s2) == s1.length())
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
