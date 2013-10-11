#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct node
{
    int count, weight;
};

struct DNA
{
    string seq;
    int pos, unsortedness;
};

int get_unsortedness(string s)
{
    map <char, node> counts;
    node A = { 0, 0 }, C = { 0, 0 }, G = { 0, 0 }, T = { 0, 0 };
    counts['A'] = A;
    counts['C'] = C;
    counts['G'] = G;
    counts['T'] = T;

    for (string::iterator it = s.begin(); it != s.end(); it++)
    {
        counts[*it].count++;
        switch (*it)
        {
        case 'A':
            counts['C'].weight += counts['C'].count;
            counts['G'].weight += counts['G'].count;
            counts['T'].weight += counts['T'].count;
            break;
        case 'C':
            counts['G'].weight += counts['G'].count;
            counts['T'].weight += counts['T'].count;
            break;
        case 'G':
            counts['T'].weight += counts['T'].count;
            break;
        }
    }

    return counts['A'].weight + counts['C'].weight + counts['G'].weight + counts['T'].weight;
}

void insert(vector<DNA> &dnas, DNA &dna)
{
    if (dnas.size() == 0)
    {
        dnas.push_back(dna);
    }
    else
    {
        for (vector<DNA>::iterator it = dnas.begin(); it != dnas.end(); it++)
        {
            if (it->unsortedness > dna.unsortedness || (it->unsortedness == dna.unsortedness && it->pos > dna.pos))
            {
                dnas.insert(it, dna);
                return;
            }
        }
        dnas.push_back(dna);
    }
}
int main()
{
    int M, m, len, index, unsortedness;
    vector<DNA> dnas;
    string s;
    cin >> M;

    getline(cin, s); getline(cin, s);
    while (M)
    {
        index = 0;
        dnas.clear();

        cin >> len >> m;
        while (m)
        {
            cin >> s;
            unsortedness = get_unsortedness(s);
            DNA temp = { s, index++, unsortedness };
            insert(dnas, temp);
            m--;
        }
        getline(cin, s);

        for (vector<DNA>::iterator it = dnas.begin(); it != dnas.end(); it++)
        {
            cout << it->seq << endl;
        }
        M--;

        if (M)
        {
            getline(cin, s);
            cout << endl;
        }
    }

   
    return 0;
}