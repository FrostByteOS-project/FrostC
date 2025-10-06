#ifndef _SYS_IPC_H
#define _SYS_IPC_H

#include <sys/types.h>

/* Mode bits for IPC */
#define IPC_CREAT  01000   /* Create key if key does not exist */
#define IPC_EXCL   02000   /* Fail if key exists */
#define IPC_NOWAIT 04000   /* Return error on wait */

/* Control commands */
#define IPC_RMID   0       /* Remove identifier */
#define IPC_SET    1       /* Set options */
#define IPC_STAT   2       /* Get options */

/* Special key values */
#define IPC_PRIVATE ((key_t)0)

typedef int key_t;

struct ipc_perm {
    key_t  key;
    uid_t  uid;
    gid_t  gid;
    uid_t  cuid;
    gid_t  cgid;
    mode_t mode;
    int    seq;
};

key_t ftok(const char *pathname, int proj_id);

#endif /* _SYS_IPC_H */
