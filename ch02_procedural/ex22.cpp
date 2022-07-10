/* the formula for the pentagonal numeric sequence is Pn=n*(3n-1)/2
 *      this yields the sequence 1, 5, 12, 22, 5
 * define a function to fill a vector of elements passed in to
 *      the function calculated to some user-specific position
 * be sure to verify that the position specified is valid
 * write a second function that, given a vector, displays its elements
 *      it should take a second parameter identifying the type
 *      of numeric series the vector represents
 * write a main() function to exercise these functions
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool calculate(vector<int> &vec, int pos);
void display(vector<int> &vec, const string &title, ostream &os = cout);

bool calculate(vector<int> &vec, int pos) {
    if (pos <= 0 || pos > 64) {
        cerr << "Sorry. Invalid position: " << pos << endl;
        return false;
    }

    for (int ix = vec.size() + 1; ix <= pos; ++ix) {
        vec.push_back(ix * (3 * ix - 1) / 2);
    }

    return true;
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
