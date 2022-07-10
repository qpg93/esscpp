/* modify fibonacci main() to allow the user
 * to keep entering positions until she indicates she wishes to stop
 */

#include <iostream>
using namespace std;

extern bool fibon_elem(int, int &);

int main() {
    int pos, elem;
    char letter;
    bool more = true;

    while (more) {
        cout << "Please enter a position: ";
        if (cin >> pos) {
            if (fibon_elem(pos, elem)) {
                cout << "element # " << pos
                     << " is " << elem << endl;
            } else {
                cout << "Sorry. Could not calculate element # "
                     << pos << endl;
            }
            cout << "Would you like to try again? (y/n) ";
            cin >> letter;
            if (letter != 'y' && letter != 'Y') {
                more = false;
            }
        } else {
            cout << "Sorry. Invalid element. Program aborted." << endl;
            break;
        }
    }

    return 0;
}

bool fibon_elem(int pos, int &elem) {
    if (pos < 0 || pos > 1024) {
        cerr << "Invalid position: " << pos
             << " -- cannot handle request!" << endl;
        return false;
    }

    int n1 = 1, n2 = 1;
    elem = 1;
    for (int ix = 3; ix <= pos; ++ix) {
        elem = n1 + n2;
        n2 = n1;
        n1 = elem;
    }
    return true;
}
