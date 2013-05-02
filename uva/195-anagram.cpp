#include <iostream>
#include <vector>

using namespace std;

//http://compprog.wordpress.com/2007/10/08/generating-permutations-2/ wordings are little wrong pi will be swapped smallest of after pi but larger than pi
//sort in AaBbCc order
void insertion_sort(string &s) {
    
    for(int i = 1; i < s.size(); i++) {
        for(int j = i; j > 0; j--) {
            if (tolower(s[j-1]) > tolower(s[j]) ||
                (tolower(s[j-1]) == tolower(s[j]) && s[j] < s[j-1])) {
                char t = s[j];
                s[j] = s[j-1];
                s[j-1] = t;
            }
            else break;
                
        }
    }
}

bool strless(string &s1, string &s2) {
    for(int i=0; i<s1.size(); i++) {
        if (tolower(s1[i]) < tolower(s2[i]))
            return true;
        else if(tolower(s1[i]) > tolower(s2[i]))
            return false;
        else if (s1[i] < s2[i])
            return true;
    }

    return false;
}

/* slow in permutating aaaaaaaaaaaaaaaaaaaa */
void _permutate(vector<string> &out, string s1, string s2) {
    if (s2.size() == 0) {
        if (out[out.size()-1] == "" || strless(out[out.size()-1], s1))
            out.push_back(s1);
        return;
    }
    else {
        for(string::iterator it = s2.begin();
            it != s2.end();
            it++) {
            
            char t = *it;
            
            s2.erase(it);
            _permutate(out, s1 + t, s2);
            s2.insert(it, t);
        }
    }

}

string str_reverse(string s) {
    string s2;
    for(string::reverse_iterator it = s.rbegin();
        it != s.rend(); it++)
        s2.push_back(*it);
    return s2;
}

string next_perm(string s) {
    int pos = -1;

    for(int i = s.size() - 1; i > 0; i--) {
        if (tolower(s[i-1]) < tolower(s[i]) ||
            (tolower(s[i-1]) == tolower(s[i]) && s[i-1] < s[i])) {
                pos = i-1;
                break;
            }
    }

    if (pos != -1) {
        for (int i = s.size() - 1; i > pos; i--) {
            if (tolower(s[i]) > tolower(s[pos]) || 
                (tolower(s[i]) == tolower(s[pos]) && s[i] > s[pos])) {
                
                char t = s[i];
                s[i] = s[pos];
                s[pos] = t;
                
                string s2 = s.substr(0,pos+1) + str_reverse(s.substr(pos+1));
                return s2;
        
            }
        }
    }
    else 
        return "";
}

void _permutate_fast(vector<string> &out, string s) {
    string s1 = s;

    while((s1 = next_perm(s1)) != "") {
        if (strless(out[out.size()-1], s1))
            out.push_back(s1);
    }
}

void permutate(vector<string> &out, string s) {

    insertion_sort(s);
    out.push_back(s);

    // _permutate(out, "", s);
    _permutate_fast(out, s);

}

int main() {
    int n;
    string s;
    vector<string> out;

    cin >> n;
    while(n--) {
        s.clear();
        cin >> s;

        permutate(out, s);
    }

    for(vector<string>::iterator it = out.begin();
        it != out.end(); it++) 
        cout << *it << endl;

    return 0;
}
