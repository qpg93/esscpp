/* separate the function to calculate the pentagonal numeric sequence in ex22
 *      into two functions
 * one function should be inline, it checks the validity of the position
 * a valid position not as yet calculated causes the function to invoke a second function
 *      that does the actual calculation
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

inline bool calculate(vector<int> &vec, int pos, ostream &os = cerr);
void core_calc(vector<int> &vec, int pos);
void display(vector<int> &vec, const string &title, ostream &os = cout);

bool calculate(vector<int> &vec, int pos, ostream &os) {
    const int max_pos = 64;
    if (pos <= 0 || pos > max_pos) {
        os << "Sorry. Invalid position: " << pos << endl;
        return false;
    } else {
        if (pos > vec.size())
            core_calc(vec, pos);
        return true;
    }
}

void core_calc(vector<int> &vec, int pos) {
    for (int ix = vec.size() + 1; ix <= pos; ++ix)
        vec.push_back(ix * (3 * ix - 1) / 2);
}

void display(vector<int> &vec, const string &title, ostream &os) {
    os << "\n" << title << "\n\t";
    for (int ix = 0; ix < vec.size(); ++ix) {
        os << vec[ix] << " ";
    }
    os << endl;
}

int main() {
    vector<int> pentagonal;
    const string title("Pentagonal Numeric Series");

    if (calculate(pentagonal, 0)) {
        display(pentagonal, title);
    }
    if (calculate(pentagonal, 8)) {
        display(pentagonal, title);
    }
    if (calculate(pentagonal, 14)) {
        display(pentagonal, title);
    }
    if (calculate(pentagonal, 138)) {
        display(pentagonal, title);
    }

    return 0;
}
