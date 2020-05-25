#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include "struct.h"

#define MAX_LINE 1024
#define SERV_PORT 9880


int udp_cli(const char* serv_ip);

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s serv_ip\n", argv[0]);
    return 1;
  }
  int ret = udp_cli(argv[1]);
  printf("ret=%d", ret);
  return ret;
}

int udp_cli(const char* serv_ip) {
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(SERV_PORT);
  if (inet_pton(AF_INET, serv_ip, &serv_addr.sin_addr) <= 0) {
    perror("inet_pton");
    return -1;
  }
  while (1) {
    UDP_MSG msg;
    memset(&msg, 0, sizeof(msg));
    msg.add1 = 1;
    msg.add2 = 2;
    scanf("%s%s", msg.str1, msg.str2);
    if (sendto(sockfd, &msg, sizeof(msg), 0, (struct sockaddr*)&serv_addr,
               sizeof(serv_addr)) == -1) {
      perror("write");
      return -1;
    } else {
      printf("send success\n");
    }
    if (sendto(sockfd, &msg, sizeof(msg), 0, (struct sockaddr*)&serv_addr,
               sizeof(serv_addr)) == -1) {
      perror("write2");
      return -1;
    } else {
      printf("send2 success\n");
    }
    socklen_t serv_addr_len = sizeof(serv_addr);
    if (recvfrom(sockfd, &msg, sizeof(msg), 0, (struct sockaddr*)&serv_addr,
                 &serv_addr_len) == -1) {
      perror("read");
      return -1;
    }
    printf("msg.add1 is: %d\n", msg.add1);
    printf("msg.add2 is: %d\n", msg.add2);
    printf("msg.sum is: %d\n", msg.sum);
    printf("msg.str1 is: %s\n", msg.str1);
    printf("msg.str2 is: %s\n", msg.str2);
    printf("msg.cat is: %s\n", msg.cat);
    break;
  }
  return 0;
}
