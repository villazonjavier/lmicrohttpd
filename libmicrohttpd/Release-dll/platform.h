#ifndef MHD_PLATFORM_H
#define MHD_PLATFORM_H

#include "MHD_config.h"

#define _XOPEN_SOURCE_EXTENDED  1
#if OS390
#define _OPEN_THREADS
#define _OPEN_SYS_SOCK_IPV6
#define _OPEN_MSGQ_EXT
#define _LP64
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#if !defined(MINGW) && !defined(__SYMBIAN32__)
#include <search.h>
#endif
#include <stddef.h>
#undef HAVE_CONFIG_H
#include <pthread.h>
#define HAVE_CONFIG_H 1

/* different OSes have fd_set in
   a broad range of header files;
   we just include most of them (if they
   are available) */


#ifdef OS_VXWORKS
#include <sockLib.h>
#include <netinet/in.h>
#include <stdarg.h>
#include <sys/mman.h>
#define RESTRICT __restrict__
#endif

#if HAVE_SYS_SELECT_H
#include <sys/select.h>
#endif
#if HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#if HAVE_SYS_TIME_H
#include <sys/time.h>
#endif
#if HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#if HAVE_SYS_MSG_H
#include <sys/msg.h>
#endif
#if HAVE_SYS_MMAN_H
#include <sys/mman.h>
#endif
#if HAVE_NETDB_H
#include <netdb.h>
#endif
#if HAVE_NETINET_IN_H
#include <netinet/in.h>
#endif
#if HAVE_TIME_H
#include <time.h>
#endif
#if HAVE_SYS_SOCKET_H
#include <sys/socket.h>
#endif
#if HAVE_ARPA_INET_H
#include <arpa/inet.h>
#endif

#include <plibc.h>


#endif