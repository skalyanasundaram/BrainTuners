#include <iostream>

using namespace std;

int main()
{
    int inputs, X, Y, inputX, inputY;
    char out[3] = {'\0'};

    while(true)
    {
        cin >> inputs;

        // no more input. quit
        if (!inputs)
        {
            break;
        }

        cin >> X >> Y;

        while (inputs)
        {
            cin >> inputX >> inputY;

            if (inputX == X || inputY == Y)
            {
                cout << "divisa" << endl;
            }
            else
            {
                out[0] = (inputY < Y)? 'S' : 'N';
                out[1] = (inputX < X)? 'O' : 'E';

                cout << out << endl;
            }

            inputs--;
        }
    }
    return 0;
}
