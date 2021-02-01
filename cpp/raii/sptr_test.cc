#include <iostream>
#include <memory>

using namespace std;

int print(const shared_ptr<int>& a) {
    cout << "use_count=" << a.use_count() << endl;
}

int main() {
    shared_ptr<int> a = make_shared<int>();
    
    print(a);
    
    shared_ptr<int> b = a;
    {
        print(a);
        print(a);
    }

    return 0;
}