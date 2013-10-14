#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <stdlib.h>
#include <strings.h>
#include <stdio.h>
using namespace std;

struct Team
{
    string name;
    long total_points, games_played, win, tie, loss, goals, against;

    inline bool operator>(Team &t)
    {
        return (this->total_points > t.total_points) ? true : ((this->total_points < t.total_points) ? false : 
            ((this->win > t.win) ? true : ((this->win < t.win) ? false : 
            ((this->goals - this->against > t.goals - t.against) ? true : ((this->goals - this->against < t.goals - t.against ? false : 
            ((this->goals > t.goals ? true : (this->goals < t.goals ? false : 
            ((this->games_played < t.games_played ? true: (this->games_played > t.games_played ? false : 
            (((strcasecmp(this->name.c_str(), t.name.c_str())) < 0 ? true : false))))))))))))));
    }
};

void sort_teams(vector<int> &order, Team *teams)
{
    int size = order.size(),
        i = 0;

    bool swapped = false;

    do 
    {
        swapped = false;
        for (i = 0; i < size - 1; i++)
        {
            if (teams[order[i + 1]] > teams[order[i]])
            {
                int t = order[i];
                order[i] = order[i + 1];
                order[i + 1] = t;
                swapped = true;
            }
        }
    } while (swapped);
}

int main()
{
    int N = 0, n = 0, teamcount = 0, i = 0;
    string s, tourname;
    map<string, int> teammap;
    vector<int> sortedorder;
    Team teams[30];

    cin >> N;
    getline(cin, s);
    while (N)
    {
        // process each tournament
        teammap.clear();
        
        // get the tournament name
        getline(cin, tourname);

        // get list of team names
        cin >> teamcount;
        getline(cin, s);
        n = teamcount;
        while (n)
        {
            getline(cin, s);
            teams[n-1].name = s;
            teams[n - 1].against = teams[n - 1].games_played = teams[n - 1].goals = 
                teams[n - 1].loss = teams[n - 1].tie = teams[n - 1].total_points = teams[n - 1].win = 0;

            teammap[s] = n - 1;
            n--;
        }

        // get list of the matches and it details
        cin >> n;
        getline(cin, s);
        while (n)
        {
            Team *A, *B;
            int goals1, goals2, start = 0, end = 0;
            string teamA, teamB, temp;
            getline(cin, s);

            end = s.find("#", start);
            teamA = s.substr(start, end - start);
            
            start = end + 1;
            end = s.find("@", start);
            temp = s.substr(start, end - start);
            goals1 = atoi(temp.c_str());

            start = end + 1;
            end = s.find("#", start);
            temp = s.substr(start, end - start);
            goals2 = atoi(temp.c_str());

            teamB = s.substr(end + 1);

            //sscanf(s.c_str(), "%[^#]#%d@%d#%s", teamA, &goals1, &goals2, teamB);
            A = &teams[teammap[teamA]];
            B = &teams[teammap[teamB]];
            
            // count total goals
            A->goals += goals1;
            B->goals += goals2;
            
            // count goals against
            A->against += goals2;
            B->against += goals1;

            // update games played
            A->games_played += 1;
            B->games_played += 1;

            // count total points
            if (goals1 > goals2)
            {
                A->total_points += 3;
                A->win++;
                B->loss++;
            }
            else if (goals1 < goals2)
            {
                B->total_points += 3;
                A->loss++;
                B->win++;
            }
            else
            {
                A->total_points += 1;
                B->total_points += 1;
                A->tie++;
                B->tie++;
            }

            n--;
        }

        N--;

        sortedorder.clear();
        for (i = 0; i < teamcount; i++)
        {
            sortedorder.push_back(i);
        }
        sort_teams(sortedorder, teams);

        cout << tourname << endl;
        for (int i = 0; i < teamcount; i++)
        {
            Team *t = &teams[sortedorder[i]];
            cout << i+1 << ") " << t->name << " " << t->total_points << "p, " << t->games_played << "g (" << t->win
                << "-" << t->tie << "-" << t->loss << "), " << t->goals - t->against << "gd (" << t->goals << "-" << t->against << ")" << endl;
        }

        if (N)
        {
            cout << endl;
        }
    }
    return 0;
}