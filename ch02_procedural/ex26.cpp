/* reimplemet the functions of ex25 using templates
 * modify the main() function accordingly
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template <typename Type>
inline Type max(Type m1, Type m2) {
    return m1 > m2 ? m1 : m2;
}

template <typename vecType>
inline vecType max(const vector<vecType> &vec) {
    return *max_element(vec.begin(), vec.end());
}

string min(const vector<string> &vec) {
    return *min_element(vec.begin(), vec.end());
}

template <typename arrType>
inline arrType max(const arrType *parray, int size) {
    return *max_element(parray, parray+size);
}

int main() {
    string sarray[] = {"we", "were", "her", "pride", "of", "ten"};
    vector<string> svec(sarray, sarray+6);
    int iarray[] = {12, 70, 2, 169, 1, 5, 29};
    vector<int> ivec(iarray, iarray+7);
    float farray[] = {2.5, 24.8, 18.7, 4.1, 23.9};
    vector<float> fvec(farray, farray+5);

    int imax = ::max(::max(ivec), ::max(iarray, 7));
    float fmax = ::max(::max(fvec), ::max(farray, 5));
    string smax = ::max(::max(svec), ::max(sarray, 6));

    cout << "imax should be 169 -- found: " << imax << endl;
    cout << "fmax should be 24.8 -- found: " << fmax << endl;
    cout << "smax should be were -- found: " << smax << endl;

    cout << "=====================================" << endl;

    cout << "iarraymax should be 169 -- found: " << ::max(iarray, 7) << endl;
    cout << "farraymax should be 24.8 -- found: " << ::max(farray, 5) << endl;
    cout << "sarraymax should be were -- found: " << ::max(sarray, 6) << endl;

    cout << "ivecmax should be 169 -- found: " << ::max(ivec) << endl;
    cout << "fvecmax should be 24.8 -- found: " << ::max(fvec) << endl;
    cout << "svecmax should be were -- found: " << ::max(svec) << endl;
    cout << "svecmin should be her -- found: " << ::min(svec) << endl;

    return 0;
}
