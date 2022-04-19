#ifndef __SSTRING_H__
#define __SSTRING_H__
#include <stdio.h>
#define MAXLEN 30
#define TRUE 1;
#define FALSE 0;
typedef struct{//定长顺序串 
	char ch[MAXLEN];
	int len;//串长！=下标 
}SString;

void StrClean(SString *s){//将顺序串s置为空串 
	s->len=0;
}

void GetSString(SString *s){//顺序串的赋值
	int count=0;
	char c;
	//printf("请输入一个串：\n");
	while(1){
		c=getchar();
		if(c=='\n') break;
		s->ch[count]=c;
		count++;
	}
	s->len=count;
}

void PutSString(SString *s){//顺序串的输出
	int i=0;
	for(i=0;i<s->len;i++){
		printf("%c",s->ch[i]);
	}
	printf("\n");
}

int StrLength(SString s){//顺序串求串长函数 
	return(s.len);
}

int StrEmpty(SString s){//判空函数
	if(s.len==0) return 1;
	else return 0; 
} 

void StrCopy(SString *s,SString *t){//将t内容复制到s中(顺序串拷贝函数) 
	int i=0;
	for(i=0;i<t->len;i++){
		s->ch[i]=t->ch[i];
	}
	s->len=t->len;
}


int StrInsert(SString *s,SString *t,int pos){//顺序串插入函数 (分三种情况)
	int i=0,j=0;
	if(pos<1||pos>s->len+1) return FALSE;//插入位置错误排除 
	if(s->len+t->len<=MAXLEN){//情况1:插入后长度小于两串长度之和，t串可完全插入，s串部分长度后移 
		for(i=s->len-1;i>=pos-1;i--){
			s->ch[i+t->len]=s->ch[i];//s串后移
		}
		for(i=0;i<=t->len-1;i++){ 
			s->ch[i+pos-1]=t->ch[i];//将t串插入指定位置 
		}
		s->len=s->len+t->len;
	}
	else if(pos+t->len<=MAXLEN){//情况2:t串可完全插入，但两串插入后总长度大于MAXLEN,此时舍弃串s的部分元素 
		for(i=s->len-1;i>=pos-1;i--){
			s->ch[i+t->len]=s->ch[i];
		}
		for(i=0;i<=t->len-1;i++){
			s->ch[i+pos-1]=t->ch[i];
		}
		s->len=MAXLEN;
	}
	else{
		for(i=pos-1;i<=MAXLEN;i++){//情况3:t串不可完全插入,此时完全舍弃s串后半部分 
			s->ch[i]=t->ch[i-pos-1];
		}
		s->len=MAXLEN;
	}
}


int StrCompare(SString s,SString t){//字符串匹配函数，s>t返回正整数，s<t返回负整数，相等返回0 
	int i=0;
	for(i=0;i<s.len&&i<t.len;i++){
		if(s.ch[i]!=t.ch[i])
		return (s.ch[i]-t.ch[i]);
	}
	if(i==s.len&&s.len==t.len) return 0;
	if(s.len>t.len) return s.ch[i];
	else return 0-t.ch[i];
}

int StrDelete(SString *s,int pos,int len){//字符串删除函数，在s串中删除pos起len个字符 
	if(pos<1||pos>s->len-len+1) return FALSE;
	int i=0;
	for(i=pos+len-1;i<=s->len-1;i++){
		s->ch[i-len]=s->ch[i];
	}
	s->len=s->len-len;
	return 1;
}

int Index(SString *s,SString *t,int pos){//简单模式匹配算法,其中pos表示从主串开始寻找模式串的位置 
	int i=pos-1,j=0;//i和j是下标，所以要从0开始 
	while(i<s->len&&j<t->len){
		if(s->ch[i]==t->ch[j]){
			i++;
			j++;
		}
		else{
			i=i-j+1;//匹配失败，i回溯至k的位置 
			j=0;
		}
	}
	if(j==t->len) return i-j+1;//完全匹配则返回下标值 
	else return 0;//返回0表示匹配失败 
}

void get_next(SString *t,int next[]){//kmp算法中用于计算next[j]数组 
	next[0]=-1;
	next[1]=0;
	int i=1,j=0;
	while(i<t->len){//求next[j]的算法相当于一次与自身的模式匹配,即寻找失配前两个相等最长子串(分别是从下标0开始和下标j-1处结束的两个串) 
		if(t->ch[i]==t->ch[j]||j==-1){ 
			i++;
			j++;
			next[i]=j; 
		}
		else j=next[j];
	}
}

int Index_KMP(SString *s,SString *t,int pos){//KMP模式匹配算法 
	 int i=pos-1;
	 int j=0;
	 int next[t->len];
	 get_next(t,next);
	 while(i<s->len&&j<t->len){
	 	if(j==-1){//j==-1时i向下移动 
	 		i++;
	 		j=0;
		 }
		 if(s->ch[i]==t->ch[j]){//相等时i和j都继续向下移动 
		 	i++;
		 	j++; 
		 }
		 else j=next[j];//不等时i不用回溯,j=next[j] 
	 }
	 if(j==t->len) return i-t->len+1;//匹配到结尾处返回位置 
	 else return 0;
}

#endif
