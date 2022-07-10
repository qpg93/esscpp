// write a program to read a sequence of integers from standard input
// place the values, in turn, in a built-in array and a vector
// iterate over the containers to sum the values
// display the sum and average of the entered values to standard output

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> ivec;
    int ival;
    while (cin >> ival) {
        ivec.push_back(ival);
    }

    int sum = 0;
    for (int ix = 0; ix < ivec.size(); ++ix) {
        sum += ivec[ix];
    }

    int average = sum / ivec.size();

    cout << "Sum of " << ivec.size()
         << " elements: " << sum
         << ". Average: " << average << endl;

    return 0;
}
