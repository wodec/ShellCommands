#ifndef _PROMPT_H_
#define _PROMPT_H_
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h> 
#include <errno.h>
#include <pwd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h> 

//struct passwd {
//	char   *pw_name;       /* username */
//	char   *pw_passwd;     /* user password */
//	uid_t   pw_uid;        /* user ID */
//	gid_t   pw_gid;        /* group ID */
//	char   *pw_gecos;      /* real name */
//	char   *pw_dir;        /* home directory */
//	char   *pw_shell;      /* shell program */
//};


void type_prompt(void);
#endif
