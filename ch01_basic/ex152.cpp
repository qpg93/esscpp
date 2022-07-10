// write a program to ask the user his or her name
// read the response
// confirm that the input is at least two characters in length
// if the name seems valid, respond to the users
// provide two implementations:
//      one using a c-style character string,
//      and the other using a string class object

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main() {
    const int nm_size = 128;
    char user_name[nm_size];
    cout << "Please enter your name: ";
    cin >> setw(nm_size) >> user_name;

    switch (strlen(user_name)) {
        case 0:
            cout << "Ah, the user with no name. "
                 << "Well, ok, hi, user with no name." << endl;
            break;

        case 1:
            cout << "A 1-character name? Hmm, have you read Kafka?: "
                 << "Hello, " << user_name << endl;
            break;

        case 127:
            // maybe string was truncated by setw()
            cout << "That is a very big name, indeed -- "
                 << "we may have needed to shorted it!"
                 << endl << "In any case," << endl;
            // no break

        default:
            cout << "Hello, " << user_name
                 << " -- happy to make your acquaintance!" << endl;
            break;
    }

    return 0;
}
