#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

enum Color { Uncolored, Black, White };
typedef map<int, Color> Nodes;
typedef map<int, vector<int> > Neighbors;

bool Colorable(Nodes &nodes, Neighbors &neighbors)
{
    queue<int> q;

    nodes[0] = Black;
    q.push(0);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        Color expectedColor = nodes[node] == Black? White: Black;

        for (vector<int>::iterator it = neighbors[node].begin(); it != neighbors[node].end(); it++)
        {
            if (nodes[*it] == nodes[node])
            {
                return false;
            }
            else if (nodes[*it] == Uncolored)
            {
                nodes[*it] = expectedColor;
                q.push(*it);
            }
        }
    }

    return true;
}

int main()
{
    Nodes nodes;
    Neighbors neighbors;

    int n = 0, edges = 0, index = 0, nodeX = 0, nodeY = 0;

    while (true)
    {
        cin >> n;

        if (!n)
        {
            break;
        }

        nodes.clear();
        neighbors.clear();

        for (index = 0; index < n; index++)
        {
            nodes[index] = Uncolored;
        }
        
        cin >> edges;

        while (edges)
        {
            cin >> nodeX >> nodeY;

            neighbors[nodeX].push_back(nodeY);
            neighbors[nodeY].push_back(nodeX);

            edges--;
        }

        cout << (Colorable(nodes, neighbors)? "BICOLORABLE." : "NOT BICOLORABLE.") << endl;
    }
    return 0;
}
