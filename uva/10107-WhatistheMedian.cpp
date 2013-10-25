#include <iostream>
#include <vector>
using namespace std;

void insert_binary_search(vector<unsigned long long> &arr, unsigned long long x)
{
    int start = 0, end = arr.size(), mid = 0;

    while (start < end)
    {
        mid = (start + end) / 2;
        if (arr[mid] < x)
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }

    arr.insert(arr.begin() + start, x);
}

int main()
{
    vector<unsigned long long> arr;
    unsigned long long x = 0, size = 0;

    while (cin >> x)
    {
        insert_binary_search(arr, x);
        size++;
        cout << ((size % 2 == 0) ? (arr[size / 2] + arr[size / 2 - 1]) / 2 : arr[size / 2]) << endl;
    }

    return 0;
}
