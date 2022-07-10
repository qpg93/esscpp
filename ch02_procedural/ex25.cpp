/* implement an overload set of max() functions to accept
 *      a. two integers
 *      b. two floats
 *      c. two strings
 *      d. a vector of intergers
 *      e. a vector of floats
 *      f. a vector of strings
 *      g. an array of integers and an interger indicating the array size
 *      h. an array of floats and an integer indicating the array size
 *      i. an array of strings and an integer indicating the array size
 * write a main() function to exercise these functions
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int max(int m1, int m2) {
    return m1 > m2 ? m1 : m2;
}

float max(float m1, float m2) {
    return m1 > m2 ? m1 : m2;
}

string max(string &m1, string &m2) {
    return m1 > m2 ? m1 : m2;
}

int max(vector<int> &vec) {
    return *max_element(vec.begin(), vec.end());
}

float max(vector<float> &vec) {
    return *max_element(vec.begin(), vec.end());
}

string max(vector<string> &vec) {
    return *max_element(vec.begin(), vec.end());
}

string min(vector<string> &vec) {
    return *min_element(vec.begin(), vec.end());
}

int max(int *parray, int size) {
    return *max_element(parray, parray+size);
}

float max(float *parray, int size) {
    return *max_element(parray, parray+size);
}

string max(string *parray, int size) {
    return *max_element(parray, parray+size);
}

int main() {
    string sarray[] = {"we", "were", "her", "pride", "of", "ten"};
    vector<string> svec(sarray, sarray+6);
    int iarray[] = {12, 70, 2, 169, 1, 5, 29};
    vector<int> ivec(iarray, iarray+7);
    float farray[] = {2.5, 24.8, 18.7, 4.1, 23.9};
    vector<float> fvec(farray, farray+5);

    int imax = max(max(ivec), max(iarray, 7));
    float fmax = max(max(fvec), max(farray, 5));
    string smax = max(max(svec), max(sarray, 6));

    cout << "imax should be 169 -- found: " << imax << endl;
    cout << "fmax should be 24.8 -- found: " << fmax << endl;
    cout << "smax should be were -- found: " << smax << endl;

    cout << "=====================================" << endl;

    cout << "iarraymax should be 169 -- found: " << max(iarray, 7) << endl;
    cout << "farraymax should be 24.8 -- found: " << max(farray, 5) << endl;
    cout << "sarraymax should be were -- found: " << max(sarray, 6) << endl;

    cout << "ivecmax should be 169 -- found: " << max(ivec) << endl;
    cout << "fvecmax should be 24.8 -- found: " << max(fvec) << endl;
    cout << "svecmax should be were -- found: " << max(svec) << endl;
    cout << "svecmin should be her -- found: " << min(svec) << endl;

    return 0;
}
