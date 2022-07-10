/* write a program to read a text file
 * store each word in a map
 * the key value of the map is the count of the number of times
 *      the word appears in the text
 * define a word exclusion set containing words such as a, an, or, the, and and but
 * before entering a word in the map, make sure it is not present in the word exclusion set
 * display the list of words and their associated count
 *      when the reading of the text is complete
 * as an extension, before displaying the text,
 *      allow the user to query the text for the presence of a word
 */

#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
using namespace std;

void initialize_exclusion_set(set<string>&);
void process_file(map<string, int>&, const set<string>&, ifstream &);
void user_query(const map<string, int>&);
void display_word_count(const map<string, int>&, ofstream&);

int main() {
    ifstream in_file("ex31.txt");
    ofstream out_file("ex31.map");
    if (!in_file || !out_file) {
        cerr << "Unable to open the text file!" << endl;
        return -1;
    }

    set<string> exclude_set;
    initialize_exclusion_set(exclude_set);

    map<string, int> word_count;
    process_file(word_count, exclude_set, in_file);
    user_query(word_count);
    display_word_count(word_count, out_file);

    return 0;
}

void initialize_exclusion_set(set<string> &exs) {
    static string _excluded_words[29] = {
        "the", "and", "but", "that", "then", "are", "been",
        "can", "a", "an", "could", "did", "for", "of", "be",
        "had", "have", "him", "his", "her", "its", "is", "to",
        "were", "which", "when", "with", "would", "what",
    };
    exs.insert(_excluded_words, _excluded_words+25);
}

void process_file(map<string, int> &word_count,
                  const set<string> &exclude_set,
                  ifstream &ifile) {
    string word;
    while (ifile >> word) {
        if (exclude_set.count(word))
            continue;
        word_count[word]++;
    }
}

void user_query(const map<string, int> &word_count) {
    string search_word;
    cout << "Please enter a word to search: q to quit" << endl;
    cin >> search_word;
    while (search_word.size() && search_word != "q") {
        map<string, int>::const_iterator iter;
        if ((iter = word_count.find(search_word)) != word_count.end()) {
            cout << "Found! " << iter->first
                 << " occurs " << iter->second
                 << " times!" << endl;
        } else {
            cout << search_word << " was not found in text." << endl;
        }
        cout << "Another search? q to quit" << endl;
        cin >> search_word;
    }
}

void display_word_count(const map<string, int> &word_count,
                        ofstream &ofile) {
    map<string, int>::const_iterator iter = word_count.begin(),
                                     end_it = word_count.end();
    while (iter != end_it) {
        ofile << iter->first << " ("
              << iter->second << ")" << endl;
        ++iter;
    }
}
