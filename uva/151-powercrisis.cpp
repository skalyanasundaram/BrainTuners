#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;
    bool regions[101] = {false};
    vector<int> res;

    while(true) {
        cin >> N;
        if (N == 0)
            break;

        if (N < 13 || N >= 100)
            continue;

        for (int m=1; m<=N; m++) {

            int not_blacked_out = N;
            for(int j=0; j <= N; j++)
                regions[j] = true;

            int region = 0;
            while (true) {

                regions[region] = false;
                not_blacked_out--;

                if (region == 12)
                    break;

                for(int t=1; t<=m; t++) {
                    do { 
                        region = (region + 1) % N;
                    }while(!regions[region]);
                }
            }

            if(not_blacked_out == 0) {
                res.push_back(m);
                break;
            }
        }
    }

    for(vector<int>::iterator it = res.begin();
        res.size() > 0 && it != res.end();
        it++)
        cout << *it << endl;

    return 0;

}
