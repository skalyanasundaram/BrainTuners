#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int> &numbers, int start, int mid, int end)
{
    int s1 = mid - start + 1,
        s2 = end - mid,
        i = 0, j = 0, k = 0, exchange = 0;

    vector<int> left, right;

    for (i = 0; i < s1; i++)
    {
        left.push_back(numbers[i + start]);
    }
    for (i = 0; i < s2; i++)
    {
        right.push_back(numbers[i + mid + 1]);
    }

    i = j = 0;
    k = start;

    while (i < s1 && j < s2)
    {
        if (left[i] > right[j])
        {
            exchange += s1 - i;
            numbers[k++] = right[j++];
        }
        else
        {
            numbers[k++] = left[i++];
        }
    }

    while (i < s1)
    {
        numbers[k++] = left[i++];
    }
    while (j < s2)
    {
        numbers[k++] = right[j++];
    }

    return exchange;
}

int get_exchange_count(vector<int> &numbers, int start, int end)
{
    int exchange = 0;

    if (start < end)
    {
        int mid = (start + end) / 2;
        exchange = get_exchange_count(numbers, start, mid);
        exchange += get_exchange_count(numbers, mid + 1, end);
        exchange += merge(numbers, start, mid, end);
    }
    return exchange;
}

int main()
{
    int n = 0, x =0;
    vector<int> numbers;

    while (cin >> n)
    {
        numbers.clear();
        while (n)
        {
            cin >> x;
            numbers.push_back(x);
            n--;
        }
        cout << "Minimum exchange operations : " << get_exchange_count(numbers, 0, numbers.size() - 1) << endl;
    }
    return 0;
}
