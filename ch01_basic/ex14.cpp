// ask the user to enter both a first and last name
// modify the output to write out both names

#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstname, lastname;

    cout << "Please enter your first name: ";
    cin >> firstname;

    cout << "Hi, " << firstname
         << ". Please enter your last name: ";
    cin >> lastname;

    cout << "Hello, "
         << firstname << " " << lastname
         << "... and goodbye!"
         << endl;

    return 0;
}
