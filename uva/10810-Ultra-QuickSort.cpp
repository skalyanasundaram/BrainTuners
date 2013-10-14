#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<long long> &numbers, long long start, long long mid, long long end)
{
    vector<long long> left, right;
    long long s1 = mid - start + 1,
        s2 = end - mid,
        i = 0, j = 0, k = 0, swaps = 0;

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
            swaps += s1 - i;
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

    return swaps;
}

long long get_merge_sort_swap_count(vector<long long> &numbers, long long start, long long end)
{
    long long swaps = 0, mid = 0;

    if (start < end)
    {
        mid = (start + end) / 2;
        swaps += get_merge_sort_swap_count(numbers, start, mid);
        swaps += get_merge_sort_swap_count(numbers, mid + 1, end);
        swaps += merge(numbers, start, mid, end);
    }
    return swaps;
}

int main()
{
    long long n, x;
    vector<long long> numbers;

    while (true)
    {
        cin >> n;
        if (!n)
        {
            break;
        }

        numbers.clear();
        while (n)
        {
            cin >> x;
            numbers.push_back(x);
            n--;
        }

        cout << get_merge_sort_swap_count(numbers, 0, numbers.size() - 1) << endl;
    }
    return 0;
}