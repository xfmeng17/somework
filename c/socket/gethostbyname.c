// https://blog.csdn.net/daiyudong2020/article/details/51946080
//和 nslookup www.baidu.com 差不多
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>

extern int h_errno;

int main(int argc, char **argv) {
  if (argc != 2) {
    printf("Use example: %s www.google.com\n", *argv);
    return -1;
  }

  char *name = argv[1];
  struct hostent *hptr;

  hptr = gethostbyname(name);
  if (hptr == NULL) {
    printf("gethostbyname error for host: %s: %s\n", name, hstrerror(h_errno));
    return -1;
  }
  //输出主机的规范名
  printf("\tofficial: %s\n", hptr->h_name);

  //输出主机的别名
  char **pptr;
  for (pptr = hptr->h_aliases; *pptr != NULL; pptr++) {
    printf("\ttalias: %s\n", *pptr);
  }

  //输出ip地址
  char str[INET_ADDRSTRLEN];
  switch (hptr->h_addrtype) {
    case AF_INET:
      pptr = hptr->h_addr_list;
      for (; *pptr != NULL; pptr++) {
        printf("\taddress: %s\n",
               inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
      }
      break;
    default:
      printf("unknown address type\n");
      break;
  }

  return 0;
}
