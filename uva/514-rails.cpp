#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N = 0 , t = 0, i = 0, j = 0;
    int required[1001];
    vector<int> st;

    do {
        cin >> N;
        if (!N)
        {
            break;
        }

        while (true)
        {

            for (i = 0; i < N; i++)
            {
                cin >> required[i];

                if (required[0] == 0)
                {
                    break;
                }
            }

            if (required[0] == 0)
            {
                break;
            }

            st.clear();
            j = 0;

            for (i = 1; i <= N; i++)
            {
                while (!st.empty() && required[j] == st.back())
                {
                    st.pop_back();
                    j++;
                }

                st.push_back(i);

            }

            while (!st.empty())
            {
                if (required[j] == st.back())
                {
                    st.pop_back();
                    j++;
                }
                else
                {
                    break;
                }
            }
            cout << (st.empty() ? "Yes" : "No") << endl;
        }
        cout << endl;

    }while(true);
    
    return 0;
}
