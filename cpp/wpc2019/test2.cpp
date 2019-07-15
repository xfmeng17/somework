#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T = 0;
    cin >> T;
    while (T-- > 0) {
        int n = 0, m = 0;
        cin >> n >> m;
        vector<long> bookVec;
        int zeroCnt = 0;
        long book = 0;
        for (int i = 0; i < n; i++) {
            cin >> book;
            if (book > 0) {
            	bookVec.push_back(book);
            } else {
            	zeroCnt++;
            }
        }
 		
 		if (m == n) {
        	cout << "Richman" << endl;
        	continue;
        }
        if (m < zeroCnt) {
        	cout << "Impossible" << endl;
			continue;
        }
        
        m -= zeroCnt;
        long ret = 0;
        int i = 0;
        while (i < m) {
        	ret += bookVec[i];
        	i++;
        }
        long minVal = 2147483647;
        while (i < bookVec.size()) {
        	minVal = min(minVal, bookVec[i]);
        	i++;
        }
        cout << ret + minVal - 1 << endl;
    }

    return 0;
}
