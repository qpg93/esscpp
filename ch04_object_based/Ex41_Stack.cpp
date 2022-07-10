/* create a Stack.h and a Stack.cpp
 * write a main() function to exercise the full public interface
 *      and compile and execute it
 * both the program text file and main() must include Stack.h
 */

#include <iostream>
#include "Ex41_Stack.h"
using namespace std;

bool Ex41_Stack::pop(string &elem) {
    if (empty()) return false;
    elem = _stack.back();
    _stack.pop_back();
    return true;
}

bool Ex41_Stack::peek(string &elem) {
    if (empty()) return false;
    elem = _stack.back();
    return true;
}

bool Ex41_Stack::push(const string &elem) {
    if (full()) return false;
    _stack.push_back(elem);
    return true;
}

int main() {
    Ex41_Stack st;
    string str;

    while (cin >> str && !st.full()) {
        if (str == "quit")
            break;
        else
            st.push(str);
    }

    if (st.empty()) {
        cout << endl << "Oops: no strings were read -- bailing out" << endl;
        return 0;
    }

    st.peek(str);
    if (st.size() == 1 && st.empty()) {
        cout << endl << "Oops: no strings were read -- bailing out" << endl;
        return 0;
    }

    cout << endl << "Read in " << st.size() << " strings!" << endl
         << "The strings, in reverse order: " << endl;

    while (st.size())
        if (st.pop(str))
            cout << str << ' ';

    cout << endl << "There are now " << st.size()
         << " elements in the stack!" << endl;
}
