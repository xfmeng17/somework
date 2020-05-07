#include <iostream>
#include <map>
#include <vector>

using namespace std;

class base {
public:
	base(string s, int32_t i) : s_(s), i_(i) {}
	virtual ~base() {}

	string s_;
	int32_t i_;
};

int main() {
	map<string, vector<base>> tmap;
	
	vector<base> vect;
	vect.emplace_back(base("1", 1));
	vect.emplace_back(base("2", 2));
	tmap["1"] = vect;

	vector<base>& temp = tmap["2"];
	for (auto it = tmap.begin(); it != tmap.end(); it++) {
		cout << it->first << ": ";
		for (auto i = 0; i < it->second.size(); i++) {
		 cout << ", i=" << i << ", v=" << it->second[i].s_;
		}
		cout << endl;
	}
	return 0;
}
