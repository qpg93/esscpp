/* introduce a static local vector to hold the elements of pentagonal series
 * this function returns a const pointer to the vector
 * it accepts a position by which to grow the vector
 *      if the vector is not that size as yet
 * implement a second function that, given a position, returns the element
 *      at that position
 * write a main() function to exercise these functions
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const vector<int>* core_calc(int pos);

inline bool check_pos(int pos) {
    const int max_pos = 64;
    return ((pos <= 0 || pos > max_pos) ? false : true);
}

bool calculate(int pos, int &elem, ostream &os = cerr) {
    if (!check_pos(pos)) {
        os << "Sorry. Invalid position: " << pos << endl;
        elem = 0;
        return false;
    }

    const vector<int> *penta = core_calc(pos);
    elem = (*penta)[pos - 1];
    return true;
}

const vector<int>* core_calc(int pos) {
    static vector<int> pentagonal;
    for (int ix = pentagonal.size() + 1; ix <= pos; ++ix) {
        pentagonal.push_back(ix*(3*ix-1)/2);
    }
    return &pentagonal;
}

void display(int pos, int &elem, ostream &os = cout) {
    os << "element " << pos << " is " << elem << endl;
}

int main() {
    int elem;
    if (calculate(0, elem)) {
        display(0, elem);
    }
    if (calculate(8, elem)) {
        display(8, elem);
    }
    if (calculate(14, elem)) {
        display(14, elem);
    }
    if (calculate(138, elem)) {
        display(138, elem);
    }

    return 0;
}
