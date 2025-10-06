#ifndef _SYS_SOCKET_H
#define _SYS_SOCKET_H

#include <sys/types.h>

/* Socket types */
#define SOCK_STREAM    1  /* Stream socket */
#define SOCK_DGRAM     2  /* Datagram socket */
#define SOCK_RAW       3  /* Raw protocol interface */

/* Address families */
#define AF_UNSPEC      0  /* Unspecified */
#define AF_UNIX        1  /* Local to host (pipes, portals) */
#define AF_LOCAL       AF_UNIX  /* POSIX name for AF_UNIX */
#define AF_INET        2  /* Internet IP protocol */

/* Protocol families (same as address families for now) */
#define PF_UNSPEC      AF_UNSPEC
#define PF_UNIX        AF_UNIX
#define PF_LOCAL       AF_LOCAL
#define PF_INET        AF_INET

/* Socket options */
#define SO_DEBUG       1
#define SO_REUSEADDR   2
#define SO_TYPE        3
#define SO_ERROR       4
#define SO_DONTROUTE   5
#define SO_BROADCAST   6
#define SO_SNDBUF      7
#define SO_RCVBUF      8
#define SO_KEEPALIVE   9
#define SO_OOBINLINE   10

/* Socket level */
#define SOL_SOCKET     1

/* Message flags */
#define MSG_OOB        0x1   /* Out-of-band data */
#define MSG_PEEK       0x2   /* Peek at incoming message */
#define MSG_DONTROUTE  0x4   /* Send without using routing tables */
#define MSG_WAITALL    0x100 /* Wait for full request or error */
#define MSG_DONTWAIT   0x40  /* Non-blocking IO */

typedef unsigned int socklen_t;
typedef unsigned short sa_family_t;

struct sockaddr {
    sa_family_t sa_family;
    char        sa_data[14];
};

struct msghdr {
    void         *msg_name;
    socklen_t     msg_namelen;
    struct iovec *msg_iov;
    int           msg_iovlen;
    void         *msg_control;
    socklen_t     msg_controllen;
    int           msg_flags;
};

/* System calls */
int socket(int domain, int type, int protocol);
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int listen(int sockfd, int backlog);
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
ssize_t send(int sockfd, const void *buf, size_t len, int flags);
ssize_t recv(int sockfd, void *buf, size_t len, int flags);
ssize_t sendto(int sockfd, const void *buf, size_t len, int flags,
               const struct sockaddr *dest_addr, socklen_t addrlen);
ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,
                 struct sockaddr *src_addr, socklen_t *addrlen);
int shutdown(int sockfd, int how);
int getsockopt(int sockfd, int level, int optname, void *optval, socklen_t *optlen);
int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
int getpeername(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int getsockname(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

#endif /* _SYS_SOCKET_H */
