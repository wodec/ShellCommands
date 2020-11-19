//我的第一个shell
//哈哈哈

#include"prompt.h"
#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define IN 1
#define OUT 0
#define MAX_CMD 10
#define BUFFSIZE 512

int flag_run=1;
void myexit(){
	flag_run=0;
}

//获取用户从命令行的输入
int get_input(char buf[]){
  int ret,ch;
  //
  memset(buf,0x00,BUFFSIZE);
  //%*c用来回收正常输入命令后面的回车键
  //如果只输入回车键，因为scanf的第一个参数就不匹配，scanf直接返回，回车键不会被处理
  ret = scanf("%[^\n]%*c",buf);
  
  //处理只输入回车的情况
  //只输入回车ret=0
  if(ret==0){
      ch = getchar();
  }

  return ret;
}


//解析命令
void do_cmd(int argc,char* argv[])
{
  if(argc==2&&(!strcmp(argv[0],"exit")))
  {
	myexit();
	return;
  }
  char path[128]="/home/test/myshell/shell-command/test7/mycode/";
  strncat(path,argv[0],50);
  pid_t pid;
  while((pid=fork())==-1);
  if(pid==0)
  execv(path,argv);
  else
  wait(NULL);
  return;
}

//将用户输入的字符串转化为字符串数组，即去掉空格
void parse(char *buf){

  int i,flg = OUT;
  int argc = 0;
  char* argv[MAX_CMD];
  
  for(i = 0;buf[i] != '\0';i++){

     if(flg == OUT && !isspace(buf[i])){
	flg = IN;
	argv[argc++]=buf+i;
     }
     else if(flg == IN && isspace(buf[i])){
	flg = OUT;
	buf[i] = '\0';
     }
  }

  argv[argc++] = NULL;
  do_cmd(argc,argv);//执行命令
}


int main(void){
  
  char buf[BUFFSIZE];
  //shell重复执行各种指令
  flag_run = 1;
  while(flag_run){
	//printf("[lqy's Linux]$ ");
	type_prompt();
	if((get_input(buf) == 0))
	   continue;
	parse(buf);//解析字符串  
   }

  return 0;
}

































