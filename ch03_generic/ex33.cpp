/* define a map for which the index is the family surname
 * and the value is a vector of the children's name
 * populate the map with at least six entries
 * test it by supporting user queries based on a surname
 *      and printing all the map entries
 */

#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

typedef vector<string> vstring;
void populate_families(map<string, vstring> &, ifstream &);
void user_query(const map<string, vstring> &, const string &);
void display_map(const map<string, vstring> &, ostream &os = cout);

int main() {
    ifstream in_file("ex33.txt");
    if (!in_file) {
        cerr << "Unable to open the text file!" << endl;
        return -1;
    }

    map<string, vstring> families;
    populate_families(families, in_file);

    string family_name;
    while (1) {
        cout << "Please enter a family name or q to quit ";
        cin >> family_name;
        if (family_name == "q")
            break;
        user_query(families, family_name);
    }
    display_map(families);
    return 0;
}

void populate_families(map<string, vstring> &families, ifstream &ifile) {
    string textline;
    while (getline(ifile, textline)) {
        // add trailing space
        if (textline.back() != ' ')
            textline.insert(textline.end(), ' ');

        string family_name;
        vstring child;
        string::size_type pos = 0, prev_pos = 0,
                          text_size = textline.size();

        // find each word separated by a space
        while ((pos = textline.find_first_of(" ", pos)) != string::npos) {
            string::size_type end_pos = pos - prev_pos;
            if (!prev_pos)
                family_name = textline.substr(prev_pos, end_pos);
            else
                child.push_back(textline.substr(prev_pos, end_pos));
            prev_pos = ++pos;
        }

        // handle last child
        if (prev_pos < text_size)
            child.push_back(textline.substr(prev_pos, pos - prev_pos));

        if (!families.count(family_name))
            families[family_name] = child;
        else
            cerr << "Oops! We already have a " << family_name
                 << " family in our map!" << endl;
    }
}

void display_map(const map<string, vstring> &families, ostream &os) {
    map<string, vstring>::const_iterator iter = families.begin(),
                                         end_it = families.end();
    while (iter != end_it) {
        os << " The " << iter->first << " family ";
        if (iter->second.empty())
            os << "has no children" << endl;
        else {
            os << "has " << iter->second.size() << " children: ";
            vstring::const_iterator iter_child = iter->second.begin(),
                                    end_it_child = iter->second.end();
            while (iter_child != end_it_child) {
                os << *iter_child++ << " ";
            }
            os << endl;
        }
        ++iter;
    }
}

void user_query(const map<string, vstring> &families, const string &family_name) {
    map<string, vstring>::const_iterator iter = families.begin(),
                                         end_it = families.end();
    if (iter == end_it) {
        cout << "Sorry. The " << family_name
             << " is not currently entered." << endl;
        return;
    }

    cout << "The " << family_name;
    if (iter->second.empty())
        cout << " has no children." << endl;
    else {
        cout << " has " << iter->second.size() << " children: ";
        vstring::const_iterator iter_child = iter->second.begin(),
                                end_it_child = iter->second.end();
        while (iter_child != end_it_child) {
            cout << *iter_child++ << " ";
        }
        cout << endl;
    }
}
