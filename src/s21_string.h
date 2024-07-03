#ifndef SRC_s_STRING_H_  //  SRC_s_STRING_H_
#define SRC_s_STRING_H_  //  SRC_s_STRING_H_
#define s_size_t unsigned long long int
#define s_NULL (void *)0
#define s_ptrdiff_t long
#include <float.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "s_string.h"

#define NTOA_BUFFER_SIZE 32U
#define FTOA_BUFFER_SIZE 32U
#define DEFAULT_FLOAT_PRECISION 6U
#define MAX_FLOAT 1e9

#define F_ZERO (1U << 0U)
#define F_MINUS (1U << 1U)
#define F_PLUS (1U << 2U)
#define F_SPACE (1U << 3U)
#define F_HASH (1U << 4U)
#define F_UP_CASE (1U << 5U)
#define F_CHAR (1U << 6U)
#define F_SHORT (1U << 7U)
#define F_LONG (1U << 8U)
#define F_LONG_LONG (1U << 9U)
#define F_PRECISION (1U << 10U)
#define F_ADAPT_EXP (1U << 11U)

#ifdef __APPLE__
#define ERRMAX 107
#define ERRMIN 0
#define ERRSTR                                                                 \
    "Undefined error: 0", "Operation not permitted",                           \
        "No such file or directory", "No such process",                        \
        "Interrupted system call", "Input/output error",                       \
        "Device not configured", "Argument list too long",                     \
        "Exec format error", "Bad file descriptor", "No child processes",      \
        "Resource deadlock avoided", "Cannot allocate memory",                 \
        "Permission denied", "Bad address", "Block device required",           \
        "Resource busy", "File exists", "Cross-device link",                   \
        "Operation not supported by device", "Not a directory",                \
        "Is a directory", "Invalid argument", "Too many open files in system", \
        "Too many open files", "Inappropriate ioctl for device",               \
        "Text file busy", "File too large", "No space left on device",         \
        "Illegal seek", "Read-only file system", "Too many links",             \
        "Broken pipe", "Numerical argument out of domain", "Result too large", \
        "Resource temporarily unavailable", "Operation now in progress",       \
        "Operation already in progress", "Socket operation on non-socket",     \
        "Destination address required", "Message too long",                    \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Operation not supported", "Protocol family not supported",            \
        "Address family not supported by protocol family",                     \
        "Address already in use", "Can't assign requested address",            \
        "Network is down", "Network is unreachable",                           \
        "Network dropped connection on reset",                                 \
        "Software caused connection abort", "Connection reset by peer",        \
        "No buffer space available", "Socket is already connected",            \
        "Socket is not connected", "Can't send after socket shutdown",         \
        "Too many references: can't splice", "Operation timed out",            \
        "Connection refused", "Too many levels of symbolic links",             \
        "File name too long", "Host is down", "No route to host",              \
        "Directory not empty", "Too many processes", "Too many users",         \
        "Disc quota exceeded", "Stale NFS file handle",                        \
        "Too many levels of remote in path", "RPC struct is bad",              \
        "RPC version wrong", "RPC prog. not avail", "Program version wrong",   \
        "Bad procedure for program", "No locks available",                     \
        "Function not implemented", "Inappropriate file type or format",       \
        "Authentication error", "Need authenticator", "Device power is off",   \
        "Device error", "Value too large to be stored in data type",           \
        "Bad executable (or shared library)", "Bad CPU type in executable",    \
        "Shared library version mismatch", "Malformed Mach-o file",            \
        "Operation canceled", "Identifier removed",                            \
        "No message of desired type", "Illegal byte sequence",                 \
        "Attribute not found", "Bad message", "EMULTIHOP (Reserved)",          \
        "No message available on STREAM", "ENOLINK (Reserved)",                \
        "No STREAM resources", "Not a STREAM", "Protocol error",               \
        "STREAM ioctl timeout", "Operation not supported on socket",           \
        "Policy not found", "State not recoverable", "Previous owner died",    \
        "Interface output queue is full"
#endif

#ifdef __linux__
#define ERRMAX 133
#define ERRMIN 1
#define ERRSTR                                                                 \
    "Operation not permitted", "No such file or directory", "No such process", \
        "Interrupted system call", "I/O error", "No such device or address",   \
        "Argument list too long", "Exec format error", "Bad file number",      \
        "No child processes", "Try again", "Out of memory",                    \
        "Permission denied", "Bad address", "Block device required",           \
        "Device or resource busy", "File exists", "Cross-device link",         \
        "No such device", "Not a directory", "Is a directory",                 \
        "Invalid argument", "File table overflow", "Too many open files",      \
        "Not a typewriter", "Text file busy", "File too large",                \
        "No space left on device", "Illegal seek", "Read-only file system",    \
        "Too many links", "Broken pipe",                                       \
        "Math argument out of domain of func",                                 \
        "Math result not representable", "Resource deadlock would occur",      \
        "File name too long", "No record locks available",                     \
        "Function not implemented", "Directory not empty",                     \
        "Too many symbolic links encountered", "Operation would block",        \
        "No message of desired type", "Identifier removed",                    \
        "Channel number out of range", "Level 2 not synchronized",             \
        "Level 3 halted", "Level 3 reset", "Link number out of range",         \
        "Protocol driver not attached", "No CSI structure available",          \
        "Level 2 halted", "Invalid exchange", "Invalid request descriptor",    \
        "Exchange full", "No anode", "Invalid request code", "Invalid slot",   \
        "Bad font file format", "Device not a stream", "No data available",    \
        "Timer expired", "Out of streams resources",                           \
        "Machine is not on the network", "Package not installed",              \
        "Object is remote", "Link has been severed", "Advertise error",        \
        "Srmount error", "Communication error on send", "Protocol error",      \
        "Multihop attempted", "RFS specific error", "Not a data message",      \
        "Value too large for defined data type", "Name not unique on network", \
        "File descriptor in bad state", "Remote address changed",              \
        "Can not access a needed shared library",                              \
        "Accessing a corrupted shared library",                                \
        ".lib section in a.out corrupted",                                     \
        "Attempting to link in too many shared libraries",                     \
        "Cannot exec a shared library directly", "Illegal byte sequence",      \
        "Interrupted system call should be restarted", "Streams pipe error",   \
        "Too many users", "Socket operation on non-socket",                    \
        "Destination address required", "Message too long",                    \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Operation not supported on transport endpoint",                       \
        "Protocol family not supported",                                       \
        "Address family not supported by protocol", "Address already in use",  \
        "Cannot assign requested address", "Network is down",                  \
        "Network is unreachable",                                              \
        "Network dropped connection because of reset",                         \
        "Software caused connection abort", "Connection reset by peer",        \
        "No buffer space available",                                           \
        "Transport endpoint is already connected",                             \
        "Transport endpoint is not connected",                                 \
        "Cannot send after transport endpoint shutdown",                       \
        "Too many references: cannot splice", "Connection timed out",          \
        "Connection refused", "Host is down", "No route to host",              \
        "Operation already in progress", "Operation now in progress",          \
        "Stale NFS file handle", "Structure needs cleaning",                   \
        "Not a XENIX named type file", "No XENIX semaphores available",        \
        "Is a named type file", "Remote I/O error", "Quota exceeded",          \
        "No medium found", "Wrong medium type", "Operation Canceled",          \
        "Required key not available", "Key has expired",                       \
        "Key has been revoked", "Key was rejected by service", "Owner died",   \
        "State not recoverable", "Operation not possible due to RF-kill"
#endif

s_size_t s_strlen(const char *s);
s_size_t s_strcspn(const char *str1, const char *str2);
s_size_t s_strspn(const char *str1, const char *str2);
char *s_strcpy(char *destination, const char *source);
char *s_strncpy(char *destination, const char *source, s_size_t n);
char *s_strcat(char *destination, const char *source);
char *s_strncat(char *destination, const char *source, s_size_t n);
char *s_strstr(const char *haystack, const char *needle);
char *s_strchr(const char *str, int c);
char *s_strrchr(const char *str, int c);
int s_strcmp(const char *str1, const char *str2);
int s_strncmp(const char *str1, const char *str2, s_size_t n);
char *s_strpbrk(const char *str1, const char *str2);
char *s_strtok(char *str, const char *delim);
int s_memcmp(const void *str1, const void *str2, s_size_t n);
void *s_memmove(void *dest, const void *src, s_size_t n);
void *s_memcpy(void *dest, const void *src, s_size_t n);
void *s_memset(void *str, int c, s_size_t n);
void *s_memchr(const void *str, int c, s_size_t n);
char *s_strerror(int errnum);

void *s_to_upper(const char *str);
void *s_to_lower(const char *str);
void *s_insert(const char *src, const char *str, s_size_t start_index);
void *s_trim(const char *src, const char *trim_chars);

int s_sprintf(char *buffer, const char *format, ...);

#endif  // SRC_s_STRING_H_
