#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>

struct message{
        int lines;
        int words;
        int max_line_length;
        int size;
        int chars;
}info;

void error_print(char str[]){
	printf("Error:%s",str);
}

void init(char filename[]){

	struct stat get_message = {};
	//char path[128] = "/home/test/myshell/test7/mycode/";
	//strncat(path,filename,50);

	FILE *fp;
	//stat函数读取filename信息，并将结果返回到get_message中 
	int ret_stat = stat(filename,&get_message);
	if(ret_stat == -1){
		error_print(filename);
		return;
	}
	//接收文件信息，用于判断是不是目录 
	//mode_t st_mode 文件的类型和存取权限 
	mode_t mode = get_message.st_mode;
	int length = 0;
	//判断是否是目录
	if(S_ISDIR(mode)) 
		printf("Error %s is dir\n0\t0\t0\t%s",filename,filename);
	else
	{
		//文件字节数大小 
		info.size = get_message.st_size;
		fp = fopen(filename,"r"); //以只读方式打开文件
		char ch;
		int flag = 0;
		while((ch=fgetc(fp))!=EOF) {//一直读到文件尾
			info.chars++; 
			
			if(ch !='\n'){
				//记录当前行的长度
				length++; 
			}
			if(ch=='\n'){
				info.lines++;
				if(length>info.max_line_length)
				info.max_line_length = length;
				length = 0;
			}
			if(ch == '\t'||ch==' '||ch=='\n'){
				flag = 0;
				continue;
			}
			else{
				if(flag==0)
				{
					info.words++;
					flag=1;
				}
			}
		}
		fclose(fp);
	}
}

int main(int argc,char* argv[])
{

	if(argc==2){
		if(argv[1][0]!='-'){
			init(argv[1]);
			printf("%d %d %d %s\n",info.lines,info.words,info.size,argv[1]);
			return 0;
		}
	}
	else if(argc==3){
		init(argv[2]);
	}
	int num;
	while((num=getopt(argc,argv,"lwmcL"))!=-1){
		switch(num){
			case 'l':
				printf("%d\t",info.lines);
				break;
			case 'w':
				printf("%d\t",info.words);
				break;
			case 'm':
				printf("%d\t",info.chars);
				break;
			case 'c':
				printf("%d\t",info.size);
				break;
			case 'L':
				printf("%d\t",info.max_line_length);
				break;
		}
	}
	if(argc==3&&argv[1][0]=='-')
	printf("%s\n",argv[2]);
}
