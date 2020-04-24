#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int socket(const char * host, int clientport) {
  
  struct socketaddr_in ad;    //建立连接时的参数
  /* IPv4 AF_INET sockets:    IPv6是 sockaddr_in6
    struct sockaddr_in {
      short            sin_family;   // AF_INET--->IPv4
      unsigned short   sin_port;     // port
      struct in_addr   sin_addr;     //
      char             sin_zero[8];  // Not used, must be zero
    };

    struct in_addr {
     unsigned long s_addr;          // load with inet_pton()
    };
  */
  
  memset(&ad, 0, sizeof(ad));
  ad.sin_family = AF_INET;
  ad.sin_port = htons(clientport);  // htons是Host to Network Short integer，将本机字节序(endian)转换成网络字节序，网络是大端存储，本机看处理器。
  // inet_addr()的功能是将一个点分十进制的IP转换成一个长整数型数，如果传入的字符串不是一个合法的IP地址，将返回INADDR_NONE
  inaddr = inet_addr(host);
  if (inaddr != INADDR_NONE) {
    memset(&ad.sin_addr, &)
  }
  
  /* 新建socket： int socket(int domain, int type, int protocol);
   * 返回为0表示失败
   * domain AF_UNIX/AF_LOCAL(内网)    AF_INET/AF_INET6（外网）
   * type   SOCK_STREAM(tcp)     SOCK_DGRAM(udp)
   * protocol socket协议，一般设置为0，让kernel选择type对应的协议
   */
   sock = socket(AF_INET, SOCK_STREAM, 0);
   if (sock < 0) {
     return sock;
   }
   /*建好socket之后需要连接到server： int connect(int sd, struct sockaddr *server, int addr_len);
    * sd: 建立socket的返回值，是socket描述符
    * server 连接到server的这个socket的信息，包括地址端口，ipv4的套接字等
    * addr_len: server的大小
}
