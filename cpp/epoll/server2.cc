#include "epoll2.h"

int main(int argc, char** argv) {
	ServerHandler serverhandler(10077);
	IOLoop::Instance()->start();
	return 0;
}