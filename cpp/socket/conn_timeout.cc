// https://blog.csdn.net/daiyudong2020/article/details/50675219
// 带超时的connect

#include <sys/types.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netinet/in.h>  
#include <arpa/inet.h> 
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
 
int connect_nonb(int sockfd, const struct sockaddr *addr, socklen_t addrlen, int nsec)
{
    int flags, n, error;
    socklen_t len;
    fd_set rset, wset;
    struct timeval tval;
 
    /* 调用fcntl把套接字设置为非阻塞 */
    flags = fcntl(sockfd, F_GETFL, 0);
    fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);
 
    /* 发起非阻塞connect。期望的错误是EINPROGRESS，表示连接建立已经启动但是尚未完成  */
    error = 0;
    if ( (n = connect(sockfd, addr, addrlen)) < 0)
        if (errno != EINPROGRESS)
            return(-1);
    
    /* 如果非阻塞connect返回0，那么连接已经建立。当服务器处于客户端所在主机时这种情况可能发生 */
    if (n == 0)
        goto done; /* connect completed immediately */
 
    /* 调用select等待套接字变为可读或可写，如果select返回0，那么表示超时 */
    FD_ZERO(&rset);
    FD_SET(sockfd, &rset);
    wset = rset;
    tval.tv_sec = nsec;
    tval.tv_usec = 0;
 
    if ( (n = select(sockfd+1, &rset, &wset, NULL, nsec ? &tval : NULL)) == 0) {
        close(sockfd); /* timeout */
        errno = ETIMEDOUT;
        return(-1);
    }
 
    /* 检查可读或可写条件，调用getsockopt取得套接字的待处理错误，如果建立成功，该值将为0 */
    if (FD_ISSET(sockfd, &rset) || FD_ISSET(sockfd, &wset)) {
        len = sizeof(error);
        if (getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &error, &len) < 0)
            return(-1); /* Solaris pending error */
    } else {
        perror("select error: sockfd not set");
        exit(1);
    }
 
    /* 恢复套接字的文件状态标志并返回 */
done:
    fcntl(sockfd, F_SETFL, flags); /* restore file status flags */
    if (error) {
        close(sockfd); /* just in case */
        errno = error;
        return(-1);
    }
    return(0);
}
 
int main()
{
    // socket  
    struct sockaddr_in servaddr;    
    short port = 9999;    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);    
    servaddr.sin_family = AF_INET;    
    servaddr.sin_addr.s_addr = inet_addr("113.107.231.211");    
    servaddr.sin_port = htons(port);
    int timeout = 3;
    
    if (connect_nonb(sockfd, (sockaddr *) &servaddr, sizeof(sockaddr_in), 2) < 0) {  
        perror("connect fail: ");
        return(-1);
    }
    printf("connect success!\n");
 
    return 0;
}
