#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  map<string, map<string, string>> mm;

  string a = "a";
  map<string, string> ma;
  ma["a1"] = "a2";

  string b = "b";
  map<string, string> mb;
  mb["b1"] = "b2";

  mm[a] = ma;
  mm[b] = mb;

  ma["a1"] = "ax";
  ma["a2"] = "axx";

  for (map<string, map<string, string>>::iterator it = mm.begin();
       it != mm.end(); it++) {
    cout << "key = " << it->first << endl;
    for (map<string, string>::iterator itt = it->second.begin();
         itt != it->second.end(); itt++) {
      cout << "value1 = " << itt->first << ", value2=" << itt->second << endl;
    }
  }
  return 0;
}
