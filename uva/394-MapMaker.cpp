#include <iostream>
#include <map>

using namespace std;

struct Array
{
    string name;
    int base_address;
    int element_size;
    int dimension;
    int upper_lower_bounds[20];
    int element_count_per_dimension[10];
};

int main()
{
    map<string, Array> array_details;
    int N, R, i, n, inp_ref[10];
    string s;

    cin >> N >> R;
    
    while (N)
    {
        Array array;
        cin >> array.name >> array.base_address >> array.element_size >> array.dimension;
        for (i = 0; i < array.dimension; i++)
        {
            cin >> array.upper_lower_bounds[i * 2] >> array.upper_lower_bounds[(i * 2) + 1];
            array.element_count_per_dimension[i] = array.upper_lower_bounds[(i * 2) + 1] - array.upper_lower_bounds[i * 2] + 1;
        }

        array_details[array.name] = array;
        N--;
    }

    while (R)
    {
        cin >> s;
        Array a = array_details[s];
        int previous_elements = 0, temp;

        cout << s << "[";

        for (i = 0; i < a.dimension; i++)
        {
            cin >> n;

            // find the difference by subtracting with the lower bound to calculate the previous elements
            temp = n - a.upper_lower_bounds[i * 2];

            for (int j = i + 1; j < a.dimension; j++)
            {
                // multiply with subsequent elements for NxMxL it is N-i * M * L and M-j * L and L-k
                temp *= a.element_count_per_dimension[j];
            }

            previous_elements += temp;

            cout << n;
            
            if (i + 1 < a.dimension)
                cout << ", ";
        }

        cout << "] = " << a.base_address + (previous_elements * a.element_size) << endl;

        R--;
    }
    return 0;
}