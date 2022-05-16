#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int WordCount(FILE* fp,int flag) {
		int word_Nums = 0;
		int char_Nums = 0;
		char ch;
			while(((ch=getc(fp))!=EOF)){
				char_Nums++;
			
				if(ch==' '||ch==','||ch=='\n')
					word_Nums++;
			}
		return (flag==1)?char_Nums:++word_Nums;
	}
int main(int argc, char* argv[]){
	int i;
	int flag = -1;

	for(i = 0; i < argc-1; i++){
	
		if (strcmp(argv[i], "-c") == 0)
			flag = 1;
	
		else if (strcmp(argv[i], "-w") == 0)
			flag = 0;
	}
	
	FILE* fp;	
	fp = fopen(argv[argc-1], "r");
	if (fp == NULL){
		printf("请检查文件是否存在！");
		return 0;
	}
	if(flag==1)
		printf("字符数：%d", WordCount(fp,flag));
	else if(flag==0)
		printf("单词数：%d", WordCount(fp,flag));
	fclose(fp);
	return 0;
} 
	

 

