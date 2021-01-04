#include <iostream>
#include <sys/time.h>
#include <unistd.h>

using namespace std;

static uint64_t get_system_milliseconds() {    
	struct timeval tv;    
	gettimeofday(&tv, nullptr);    
	return tv.tv_sec * 1000 + tv.tv_usec / 1000;    
}    


int main() {
	
	struct timeval tv;
	gettimeofday(&tv, nullptr);
	std::cout << "tv_sec=" << tv.tv_sec << ", tv_usec=" << tv.tv_usec << endl;
	int i = 10 * tv.tv_sec;
	cout << "i=" << i << endl;	
	uint64_t j = 1000 * tv.tv_sec;

	cout << "j=" << j << endl;	
	cout << "10=" << 10 * tv.tv_sec << endl;
	cout << "100=" << 100 * tv.tv_sec << endl;
	cout << "1000=" << 1000 * tv.tv_sec << endl;
	cout << "x=" << get_system_milliseconds() << endl;

	return 0;
}
