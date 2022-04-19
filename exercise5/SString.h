#ifndef __SSTRING_H__
#define __SSTRING_H__
#include <stdio.h>
#define MAXLEN 30
#define TRUE 1;
#define FALSE 0;
typedef struct{//����˳�� 
	char ch[MAXLEN];
	int len;//������=�±� 
}SString;

void StrClean(SString *s){//��˳��s��Ϊ�մ� 
	s->len=0;
}

void GetSString(SString *s){//˳�򴮵ĸ�ֵ
	int count=0;
	char c;
	//printf("������һ������\n");
	while(1){
		c=getchar();
		if(c=='\n') break;
		s->ch[count]=c;
		count++;
	}
	s->len=count;
}

void PutSString(SString *s){//˳�򴮵����
	int i=0;
	for(i=0;i<s->len;i++){
		printf("%c",s->ch[i]);
	}
	printf("\n");
}

int StrLength(SString s){//˳���󴮳����� 
	return(s.len);
}

int StrEmpty(SString s){//�пպ���
	if(s.len==0) return 1;
	else return 0; 
} 

void StrCopy(SString *s,SString *t){//��t���ݸ��Ƶ�s��(˳�򴮿�������) 
	int i=0;
	for(i=0;i<t->len;i++){
		s->ch[i]=t->ch[i];
	}
	s->len=t->len;
}


int StrInsert(SString *s,SString *t,int pos){//˳�򴮲��뺯�� (���������)
	int i=0,j=0;
	if(pos<1||pos>s->len+1) return FALSE;//����λ�ô����ų� 
	if(s->len+t->len<=MAXLEN){//���1:����󳤶�С����������֮�ͣ�t������ȫ���룬s�����ֳ��Ⱥ��� 
		for(i=s->len-1;i>=pos-1;i--){
			s->ch[i+t->len]=s->ch[i];//s������
		}
		for(i=0;i<=t->len-1;i++){ 
			s->ch[i+pos-1]=t->ch[i];//��t������ָ��λ�� 
		}
		s->len=s->len+t->len;
	}
	else if(pos+t->len<=MAXLEN){//���2:t������ȫ���룬������������ܳ��ȴ���MAXLEN,��ʱ������s�Ĳ���Ԫ�� 
		for(i=s->len-1;i>=pos-1;i--){
			s->ch[i+t->len]=s->ch[i];
		}
		for(i=0;i<=t->len-1;i++){
			s->ch[i+pos-1]=t->ch[i];
		}
		s->len=MAXLEN;
	}
	else{
		for(i=pos-1;i<=MAXLEN;i++){//���3:t��������ȫ����,��ʱ��ȫ����s����벿�� 
			s->ch[i]=t->ch[i-pos-1];
		}
		s->len=MAXLEN;
	}
}


int StrCompare(SString s,SString t){//�ַ���ƥ�亯����s>t������������s<t���ظ���������ȷ���0 
	int i=0;
	for(i=0;i<s.len&&i<t.len;i++){
		if(s.ch[i]!=t.ch[i])
		return (s.ch[i]-t.ch[i]);
	}
	if(i==s.len&&s.len==t.len) return 0;
	if(s.len>t.len) return s.ch[i];
	else return 0-t.ch[i];
}

int StrDelete(SString *s,int pos,int len){//�ַ���ɾ����������s����ɾ��pos��len���ַ� 
	if(pos<1||pos>s->len-len+1) return FALSE;
	int i=0;
	for(i=pos+len-1;i<=s->len-1;i++){
		s->ch[i-len]=s->ch[i];
	}
	s->len=s->len-len;
	return 1;
}

int Index(SString *s,SString *t,int pos){//��ģʽƥ���㷨,����pos��ʾ��������ʼѰ��ģʽ����λ�� 
	int i=pos-1,j=0;//i��j���±꣬����Ҫ��0��ʼ 
	while(i<s->len&&j<t->len){
		if(s->ch[i]==t->ch[j]){
			i++;
			j++;
		}
		else{
			i=i-j+1;//ƥ��ʧ�ܣ�i������k��λ�� 
			j=0;
		}
	}
	if(j==t->len) return i-j+1;//��ȫƥ���򷵻��±�ֵ 
	else return 0;//����0��ʾƥ��ʧ�� 
}

void get_next(SString *t,int next[]){//kmp�㷨�����ڼ���next[j]���� 
	next[0]=-1;
	next[1]=0;
	int i=1,j=0;
	while(i<t->len){//��next[j]���㷨�൱��һ���������ģʽƥ��,��Ѱ��ʧ��ǰ���������Ӵ�(�ֱ��Ǵ��±�0��ʼ���±�j-1��������������) 
		if(t->ch[i]==t->ch[j]||j==-1){ 
			i++;
			j++;
			next[i]=j; 
		}
		else j=next[j];
	}
}

int Index_KMP(SString *s,SString *t,int pos){//KMPģʽƥ���㷨 
	 int i=pos-1;
	 int j=0;
	 int next[t->len];
	 get_next(t,next);
	 while(i<s->len&&j<t->len){
	 	if(j==-1){//j==-1ʱi�����ƶ� 
	 		i++;
	 		j=0;
		 }
		 if(s->ch[i]==t->ch[j]){//���ʱi��j�����������ƶ� 
		 	i++;
		 	j++; 
		 }
		 else j=next[j];//����ʱi���û���,j=next[j] 
	 }
	 if(j==t->len) return i-t->len+1;//ƥ�䵽��β������λ�� 
	 else return 0;
}

#endif
