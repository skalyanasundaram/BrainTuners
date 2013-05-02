#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

enum CMP_FIELD{KEYWORD, WEIGHT};

class index{
public:
    string title;
    string keyword;
    int key_pos;
    int weight;

    bool less(index &b, CMP_FIELD flag) {
        if (flag == KEYWORD)
            return this->keyword < b.keyword;
        else
            return (this->weight == b.weight) ? this->key_pos < b.key_pos : this->weight < b.weight;
        //for the same keys, we need to sort the title in which order they entered
        //for the same keys occuring in the title multiple times, decide based on the position
    }
};

int partition(vector<index> &indexes, int lo, int hi, CMP_FIELD flag) {
    int i = lo, j = hi + 1;
    index temp;

    while(true) {
        
        while(indexes[++i].less(indexes[lo], flag))
            if(i == hi) break;

        while(indexes[lo].less(indexes[--j], flag))
            if(j == lo) break;

        if (i >= j) break;

        temp = indexes[i];
        indexes[i] = indexes[j];
        indexes[j] = temp;
    }

    temp = indexes[j];
    indexes[j] = indexes[lo];
    indexes[lo] = temp;

    return j;
}

void qsort(vector<index> &indexes, int lo, int hi, CMP_FIELD flag) {
    if (hi <= lo)
        return;

    int p = partition(indexes, lo, hi, flag);

    qsort(indexes, lo, p-1, flag);
    qsort(indexes, p+1, hi, flag);
}


void sort(vector<index> &indexes) {
    qsort(indexes, 0, indexes.size() - 1, KEYWORD);

    for(int i = 0; i < indexes.size() - 1; i++) {

        int j = i;

        while(j < indexes.size() && indexes[i].keyword == indexes[j].keyword)
            j++;

        qsort(indexes, i, j-1, WEIGHT);
    }
}

void fill_title_for_each_keyword(vector<index> &indexes, 
                                 const map<string, bool> &stopwords, 
                                 string title,
                                 int weight) {

    size_t start = 0, end = 0;
    bool title_done = false;

    do {
        start = title.find_first_not_of(' ', end);
        if (start == string::npos)
            return;

        end = title.find(' ', start);

        if (end == string::npos) {
            end = title.size();
            title_done = true;
        }

        if (stopwords.find(title.substr(start, end-start)) == stopwords.end()) {
            index nindex;
            nindex.title = title;

            std::transform(nindex.title.begin() + start, nindex.title.begin() + end, nindex.title.begin() + start, ::toupper);
            nindex.keyword = nindex.title.substr(start, end-start);
            nindex.key_pos = start;
            nindex.weight = weight;

            indexes.push_back(nindex);
        }

    } while(!title_done);


}

int main() {
    int stop_word_count = 0, title_count = -1;
    string temp;
    map<string, bool> stop_words;
    vector<index> indexes;

    while(getline(cin, temp)) {

        if (temp == "::") {
            title_count++;
            continue;
        } 

        if (title_count == -1) {
            if(temp.size() > 10 || stop_word_count > 50) 
                continue;
            stop_words[temp] = true;
            stop_word_count++;
        }
        else {

            if (temp.size() > 10000 || temp.size() < 1 || title_count > 200)
                continue;

            std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            fill_title_for_each_keyword(indexes, stop_words, temp, title_count++);

        }
    }

    sort(indexes);

    for(vector<index>::iterator it = indexes.begin();
        it != indexes.end(); it++) {
        cout << (*it).title << endl;
    }
    return 0;
}


//qucik sort, qsort, index, KWIC, Key Word In Context, string, upper, transform
