/* consider the following global data:
 *      string program_name;
 *      string version_stamp;
 *      int version_number;
 *      int tests_run;
 *      int tests_passed;
 * write a class to wrap around this data
 */

#include <string>
using namespace std;

class GlobalWrapper {
public:
    /* because we wish only a single instance of each global object,
     * we declare each one to be a static class member as well as
     *      the member functions that access them */
    static string   program_name()      { return _program_name; }
    static string   version_stamp()     { return _version_stamp; }
    static int      version_number()    { return _version_number; }
    static int      tests_run()         { return _tests_run; }
    static int      tests_passed()      { return _tests_passed; }

    static void     program_name(const string& npn)
                    { _program_name = npn; }
    static void     version_stamp(const string& nstamp)
                    { _version_stamp = nstamp; }
    static void     version_number(int nval)
                    { _version_number = nval; }
    static void     tests_run(int nval)
                    { _tests_run = nval; }
    static void     tests_passed(int nval)
                    { _tests_passed = nval; }

private:
    static string   _program_name;
    static string   _version_stamp;
    static int      _version_number;
    static int      _tests_run;
    static int      _tests_passed;
};

string GlobalWrapper::_program_name;
string GlobalWrapper::_version_stamp;
int GlobalWrapper::_version_number;
int GlobalWrapper::_tests_run;
int GlobalWrapper::_tests_passed;

int main() {}
