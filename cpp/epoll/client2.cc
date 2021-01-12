#include <arpa/inet.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <iostream>
#include <exception>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/epoll.h>

int GetConnect(std::string ip, int port) {
  try {
    int fdSocket;
    struct sockaddr_in inAddr;
    memset(&inAddr, 0, sizeof(inAddr));
    inAddr.sin_family = AF_INET;
    inAddr.sin_port = htons(port);
    inAddr.sin_addr.s_addr = inet_addr(ip.c_str());
    fdSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (fdSocket < 0) {
      std::cout << "socket init error" << std::endl;
      return -1;
    }

    if (connect(fdSocket, (struct sockaddr *)&inAddr, sizeof(inAddr)) != 0) {
      std::cout << "socket connect error, errno=" << std::endl;
      return -1;
    }

    return fdSocket;
  }
  catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return -1;
  }
  catch (...) {
    return -1;
  }
}

int Send(int fd, const char* buf, int len) {
    int send_len = 0;
    if ((send_len = send(fd,buf, len, 0)) < 0) {
        std::cout << "send() error,send_len=" << send_len << std::endl;
        close(fd);
        return -1;
    }
    return send_len;
}


int main() {
    epoll_event e;
    std::cout << "e.data.fd=" << e.data.fd << ",e.events=" << e.events << std::endl;

    int fd = GetConnect("127.0.0.1", 10077);
    std::cout << "client fd=" << fd <<std::endl;
    
    char* recv_msg = new char[256];

    while (true) {
        std::cout << "INPUT:\n";
        std::string input = "";
        std::cin >> input;
        if (input == "STOP") {
            std::cout << "client loop stop!" << std::endl;
            break;
        }
        
        int send_len = Send(fd, input.c_str(), input.length());
        std::cout << "client send_len=" << send_len << std::endl;

        memset(recv_msg, 0, sizeof(recv_msg));
        int recv_len = recv(fd, recv_msg, 256, 0);
        recv_msg[recv_len] = 0;
        std::cout << "recv_len=" << recv_len << ", recv_msg=" << recv_msg << std::endl;
    }

    return 0;
}