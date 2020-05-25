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

int udp_serv();

int main() { return udp_serv(); }

int udp_serv() {
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return -1;
  }

  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_addr.sin_port = htons(SERV_PORT);

  if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
    perror("bind");
    return -1;
  }

  while (1) {
    printf("sleeping\n");
    sleep(10);
    printf("akwaked\n");
    char buf[BUFSIZ];
    struct sockaddr_in cli_addr;
    memset(&cli_addr, 0, sizeof(cli_addr));
    socklen_t cli_addr_len = sizeof(cli_addr);
    int recvn = recvfrom(sockfd, buf, sizeof(buf), 0,
                         (struct sockaddr*)&cli_addr, &cli_addr_len);
    printf("recv %d bytes\n", recvn);
    UDP_MSG msg;
    memset(&msg, 0, sizeof(msg));
    printf("UDP_MSG size is %d\n", sizeof(msg));
    memcpy(&msg, buf, sizeof(msg));
    msg.sum = msg.add1 + msg.add2;
    strcpy(msg.cat, msg.str1);
    strcat(msg.cat, msg.str2);
    printf("msg.add1 is: %d\n", msg.add1);
    printf("msg.add2 is: %d\n", msg.add2);
    printf("msg.sum is: %d\n", msg.sum);
    printf("msg.str1 is: %s\n", msg.str1);
    printf("msg.str2 is: %s\n", msg.str2);
    printf("msg.cat is: %s\n", msg.cat);
    sendto(sockfd, &msg, sizeof(msg), 0, (struct sockaddr*)&cli_addr,
           cli_addr_len);
  }

  return 0;
}
