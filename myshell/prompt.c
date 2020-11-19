#include "prompt.h"

const int max_name_len = 256;
const int max_path_len = 1024;
void type_prompt()
{
    char prompt[1024];
    struct passwd *pwd;
    char hostname[max_name_len];
    char pathname[max_path_len];
    int length;
    
    //获取用户名
    pwd = getpwuid(getuid());
    //printf("name=%s\n",pwd->pw_name);
    //获取路径
    getcwd(pathname,max_path_len);
//    printf("%s\n",pathname);
    //获取主机名
    if(gethostname(hostname,max_name_len)==0)
        sprintf(prompt,"[minishell]%s@%s:",pwd->pw_name,hostname);
    else
        sprintf(prompt,"[minishell]%s@unknown:",pwd->pw_name);
//    printf("%s\n",prompt);
    length = strlen(prompt);
     if(strlen(pathname) < strlen(pwd->pw_dir) || 
            strncmp(pathname,pwd->pw_dir,strlen(pwd->pw_dir))!=0)
        sprintf(prompt+length,"%s",pathname);
    else
        sprintf(prompt+length,"~%s",pathname+strlen(pwd->pw_dir));
//    length = strlen(prompt);
      printf("%s",prompt);
    if(geteuid()==0)
        printf("#");
    else
        printf("$");
}
