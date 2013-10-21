#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n = 0, val = 0, index = 0, div = 0, sub = 0, x = 0;
    map <int, map<int, int> > counts;
    
    cin >> n;
    
    while(n)
    {
        cout << n << ": ";
        
        for (index = n; index >= 1; index--)
        {
            if ( counts.find(index) == counts.end())
            {
                map <int, int> count;

                count[1] = 0;
                count[5] = 0;
                count[10] = 0;
                count[50] = 0;
                count[100] = 0;
        
                for (div = 100, sub = 10, x  = 5, val = index; val >= 1; x = (x == 5? 2: 5), div /= x, sub = div <= 10 ? 1:10)
                {
                    count[div] += val / div;
                    val %= div;
                    
                    if (val && val >= div - sub)
                    {
                        count[div]++;
                        count[sub]++;
                        val -= div-sub;
                    }
                }
                counts[index] = count;
            }
            else
            {
                break;
            }
        }
        
        for (++index; index <= n; index++)
        {
            if (index > 1)
            {
                counts[index][1] += counts[index - 1][1];
                counts[index][5] += counts[index - 1][5];
                counts[index][10] += counts[index - 1][10];
                counts[index][50] += counts[index - 1][50];
                counts[index][100] += counts[index - 1][100];
            }
        }
        
        cout << counts[n][1] << " i, " << counts[n][5] << " v, " << counts[n][10] << " x, " << counts[n][50] << " l, " << counts[n][100] << " c" << endl;
        cin >> n;
    }
    return 0;
}

