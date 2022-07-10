/* extend the Stack class to support both a find() and a count() operation
 * find() returns true or false depending on whether the value is found
 * count() returns the number of occurences of the string
 * reimplement the main() to invoke both functions
 */

#include <iostream>
#include <algorithm>
#include "Ex42_Stack.h"
using namespace std;

bool Ex42_Stack::pop(string &elem) {
    if (empty()) return false;
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool Ex42_Stack::peek(string &elem) {
    if (empty()) return false;
    elem = _stack.back();
    return true;
}

bool Ex42_Stack::push(const string &elem) {
    if (full()) return false;
    _stack.push_back(elem);
    return true;
}

bool Ex42_Stack::find(const string &elem) const {
    vector<string>::const_iterator iter = _stack.begin();
    vector<string>::const_iterator end_iter = _stack.end();
    return ::find(iter, end_iter, elem) != end_iter;
}

int Ex42_Stack::count(const string &elem) const {
    return ::count(_stack.begin(), _stack.end(), elem);
}

int main() {
    Ex42_Stack st;
    string str;

    while (cin >> str && !st.full()) {
        if (str == "quit")
            break;
        else
            st.push(str);
    }

    cout << endl << "Read in " << st.size() << " strings!" << endl;
    cin.clear();

    cout << "What word to search for? ";
    cin >> str;

    bool found = st.find(str);
    int count = st.count(str);

    cout << str << (found ? " is " : " isn\'t ") << "in the stack" << endl;
    if (found)
        cout << "It occurs " << count << " times" << endl;
}
