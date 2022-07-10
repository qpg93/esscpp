/* modify fibonacci main() to allow the user
 * to keep entering positions until she indicates she wishes to stop
 */

#include <iostream>
using namespace std;

bool enter_position(int &);
bool print_sequence(int);

int main() {

    int pos;
    while (enter_position(pos)) {
        if (print_sequence(pos)) {
        }
    }
    return 0;
}

bool enter_position(int &pos) {
    cout << "Please enter a position: ";
    if (cin >> pos) {
        return true;
    } else {
        return false;
    }
}

bool print_sequence(int pos) {
    if (pos <= 0 || pos > 1024) {
        cerr << "Invalid position: " << pos
             << " -- cannot handle request!" << endl;
        return false;
    }

    cout << "The Fibonacci Sequence for " << pos
         << " positions: " << "\n\t";

    switch (pos) {
        default:
        case 2:
            cout << "1\t";
        case 1:
            cout << "1\t";
            break;
    }

    int n1 = 1, n2 = 1, elem;
    for (int ix = 3; ix <= pos; ++ix) {
        elem = n1 + n2;
        n1 = n2;
        n2 = elem;
        cout << elem << ((ix % 10 == 0)?"\n\t":"\t");
    }
    cout << endl;

    return true;
}
