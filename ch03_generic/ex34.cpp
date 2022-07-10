/* write a program to read a sequence of integer numbers
 *      from standard input using an istream_iterator
 * write the odd numbers into one file using an ostream_iterator
 *      each value should be separated by a space
 * write the even numbers into a second file
 *      also using an ostream_iterator
 *      each of these values should be placed on a separate line
 */

#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

// define function object
class EvenElem {
 public:
        bool operator() (int elem)
            {return (elem % 2) ? false : true;}
};


int main() {
    istream_iterator<int> is(cin);
    istream_iterator<int> eos;

    vector<int> num_vec;
    copy(is, eos, back_inserter(num_vec));

    vector<int>::iterator division = partition(num_vec.begin(),
                                               num_vec.end(),
                                               EvenElem());
    ofstream ofile_odd("ex34.odd");
    ofstream ofile_even("ex34.even");
    if (!ofile_odd || !ofile_even) {
        cerr << "Unable to open the output files!" << endl;
        return -1;
    }

    ostream_iterator<int> iter_odd(ofile_odd, " ");
    ostream_iterator<int> iter_even(ofile_even, "\n");
    copy(num_vec.begin(), division, iter_even);
    copy(division, num_vec.end(), iter_odd);

    return 0;
}
