#include <vector>
#include <string>
using namespace std;

class Ex41_Stack {
 public:
     bool   push(const string &elem);
     bool   pop(string &elem);
     bool   peek(string &elem);
     bool   empty() const { return _stack.empty(); }
     bool   full()  const { return _stack.size() == _stack.max_size(); }
     int    size()  const { return _stack.size(); }

 private:
     vector<string> _stack;
};
