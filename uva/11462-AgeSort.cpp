#include <iostream>
#include <string>
//#include <sstream>
#include <vector>

using namespace std;

void shift_down(vector<unsigned short> &arr, long cur, unsigned long size)
{
    long left = cur * 2 + 1,
        right = cur * 2 + 2,
        max = cur;

    if (left < size && arr[left] > arr[max])
    {
        max = left;
    }
    if (right < size && arr[right] > arr[max])
    {
        max = right;
    }

    if (max != cur)
    {
        unsigned short t = arr[max];
        arr[max] = arr[cur];
        arr[cur] = t;
        shift_down(arr, max, size);
    }
}

void max_heapify(vector<unsigned short> &arr, unsigned long size)
{
    for (long p = (size / 2) - 1; p >= 0; p--)
    {
        shift_down(arr, p, size);
    }
}

void heap_sort(vector<unsigned short> &arr, unsigned long size)
{
    max_heapify(arr, size);
    while (size > 1)
    {
        unsigned long t = arr[0];
        arr[0] = arr[size - 1];
        arr[size - 1] = t;
        max_heapify(arr, --size);
    }
}

int main()
{
    unsigned long n = 0, i = 0;
    unsigned short x = 0, v = 0;
    vector<unsigned short> arr;
    bool first = false;

    string s;
    while (true)
    {
        cin >> n;
        getline(cin, s);
        if (!n)
        {
            break;
        }
        getline(cin, s);

        arr.clear();
        arr.assign(101, 0);
        first = true;

        for (i = 0, v = 0;; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                arr[v]++;
                v = 0;
            }
            else
            {
                v = v * 10 + (s[i] - '0');
            }
        }
        arr[v]++;

        for (i = 1; i <= 100; i++)
        {
            if (arr[i])
            {
                while (arr[i])
                {
                    if (!first)
                    {
                        cout << " ";
                    }
                    cout << i;
                    first = false;
                    arr[i]--;
                }
            }
        }
        cout << endl;
    }

    return 0;
}