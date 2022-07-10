// write a program to open the file
// reading each word into a vector<string> object
// iterate over the vector, displaying it to cout
// that done, sort the words using the sort() generic algorithm
//      #include <algorithm>
//      sort(container.begin(), container.end());
// then print the sorted words to an output file

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
// sort(container.begin(), container.end());
using namespace std;

int main() {
    // init
    string word;
    vector<string> words;

    // files
    ifstream infile("ex171.txt");
    if (!infile) {
        cerr << "Oops! Unable to open input file" << endl;
        return -1;
    }
    ofstream outfile("ex172.txt");
    if (!outfile) {
        cerr << "Oops! Unable to open output file" << endl;
        return -2;
    }

    // read
    while (infile >> word) {
        words.push_back(word);
    }

    // print
    for (int ix = 0; ix < words.size(); ++ix) {
        cout << words[ix] << " ";
    }
    cout << endl;

    // sort and write
    sort(words.begin(), words.end());
    for (int ix = 0; ix < words.size(); ++ix) {
        cout << words[ix] << " ";
        outfile << words[ix] << endl;
    }
    cout << endl;

    return 0;
}
