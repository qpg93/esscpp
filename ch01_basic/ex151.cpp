// write a program to ask the user his or her name
// read the response
// confirm that the input is at least two characters in length
// if the name seems valid, respond to the users
// provide two implementations:
//      one using a c-style character string,
//      and the other using a string class object

#include <iostream>
#include <string>
using namespace std;

int main() {
    string user_name;
    cout << "Please enter your name: ";
    cin >> user_name;

    switch (user_name.size()) {
        case 0:
            cout << "Ah, the user with no name. "
                 << "Well, ok, hi, user with no name." << endl;
            break;

        case 1:
            cout << "A 1-character name? Hmm, have you read Kafka?: "
                 << "Hello, " << user_name << endl;
            break;

        default:
            cout << "Hello, " << user_name
                 << " -- happy to make your acquaintance!" << endl;
            break;
    }

    return 0;
}
