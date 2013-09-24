#include <iostream>

using namespace std;

// have got submission error
// http://uva.onlinejudge.org/index.php?option=com_content&task=view&id=21&Itemid=1

int main()
{
    int n_devices, m_operation, 
        c_capacity, i, current_capacity, max_capacity, 
        device, seq = 1;
    bool device_status[21] = { false };
    int device_capacity[21] = { 0 };

    while (true)
    {
        cin >> n_devices >> m_operation >> c_capacity;

        if (!n_devices && !m_operation && !c_capacity)
        {
            break;
        }

        for (i = 0; i < n_devices; i++)
        {
            cin >> device_capacity[i + 1];
            device_status[i + 1] = false;
        }

        current_capacity = max_capacity = 0;
        for (i = 0; i < m_operation; i++)
        {
            cin >> device;
            if (device_status[device])
            {
                device_status[device] = false;
                current_capacity -= device_capacity[device];
            }
            else
            {
                device_status[device] = true;
                current_capacity += device_capacity[device];

                max_capacity = (current_capacity > max_capacity) ? current_capacity : max_capacity;

                if (current_capacity > c_capacity)
                {
                    break;
                }
            }
        }

        cout << "Sequence " << seq << endl;
        seq++;

        if (current_capacity > c_capacity)
        {
            cout << "Fuse was blown." << endl;
        }
        else
        {
            cout << "Fuse was not blown." << endl << "Maximal power consumption was " << max_capacity << " amperes." << endl;
        }
    }
    return 0;
}