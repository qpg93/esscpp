/* read in a text file, storing it in a vector
 * sort the vector by the length of the string
 * define a function object to pass to sort()
 * it should accept two strings and return true
 *      if the first string is shorter than the second
 * print the sorted vector
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// define function object
class LessThan {
    public:
        bool operator()(const string &str1, const string &str2) {
            return str1.size() < str2.size();
        }
};

template <typename elemType>
void display_vector(const vector<elemType> &word_vec,
                    ostream &ofile = cout,
                    int col_width = 8) {
    vector<string>::const_iterator iter = word_vec.begin(),
                                   end_it = word_vec.end();
    int elem_cnt = 1;
    while (iter != end_it) {
        ofile << *iter++ << ((elem_cnt++ % col_width) ? " " : "\n");
    }
    ofile << endl;
}

int main() {
    ifstream in_file("ex31.txt");
    ofstream out_file("ex32.sort");
    if (!in_file || !out_file) {
        cerr << "Unable to open the text file!" << endl;
        return -1;
    }

    vector<string> word_vec;
    string word;

    while (in_file >> word) {
        word_vec.push_back(word);
    }

    sort(word_vec.begin(), word_vec.end(), LessThan());
    display_vector(word_vec, out_file);

    return 0;
}

