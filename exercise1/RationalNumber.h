#ifndef __RATIONALNUMBER_H__
#define __RATIONALNUMBER_H__
#define M 1000000//MΪ���㾫ȷ�� 

typedef struct RationalNumber//�������ṹ�� 
{
	int numerator;
	int denominator;
}Rational;

int GCD(int a,int b);
void simplify(Rational *p);

void getRationalNumber(Rational *p)//�������������� 
{
	int i=0,j=0,count=0;
	float num=0,a=0,b=0;
	char str[30],str1[30],str2[30];
	printf("������һ��������(���Է�����ʽ�������á�/ ���������ӷ�ĸ)��\n");
	label_1:
	gets(str);
	
	for(i=0;i<30;i++)//�жϸ���������������ʽ 
	{
		if(str[i]=='/')break;
		count++;
	}
	
	if(count==30)//�����С����ʽ��ֱ�ӽ��ַ���ת��Ϊ������ 
	{
		num=atof(str);
		p->numerator=(int)(num*M); 
		p->denominator=M;
		simplify(p);
		//printf("�÷���Ϊ��%d/%d\n",p->numerator,p->denominator);
	}
	else//����Ƿ�����ʽ��ֱ���ȡ���ӷ�ĸ 
	{
		strncpy(str1,str,count);
		str1[count]='\0';//?
		a=atof(str1);
		for(i=count+1;i<30;i++)
		{
			str2[j++]=str[i];
		}
		b=atof(str2);
		if(b==0)
		{
			printf("�Ƿ����֣����������룺\n");//����ĸΪ0����� 
			count=0;
			i=0;
			j=0;
			goto label_1;
		}
		p->numerator=(int)(a*M);
		p->denominator=(int)(b*M);
		simplify(p);
		//printf("�÷���Ϊ��%d/%d\n",p->numerator,p->denominator);
	}
}

Rational plus(Rational *p,Rational *q)//�������ӷ� 
{
	Rational c,*r=&c;
	c.numerator=p->numerator*q->denominator+q->numerator*p->denominator;
	c.denominator=p->denominator*q->denominator;
	simplify(r);
	return c;
}

Rational sub(Rational *p,Rational *q)//���������� 
{
	Rational c,*r=&c;
	c.numerator=p->numerator*q->denominator-q->numerator*p->denominator;
	c.denominator=p->denominator*q->denominator;
	simplify(r);
	return c;
}

Rational multiply(Rational *p,Rational *q)//�������˷� 
{
	Rational c,*r=&c;
	c.numerator=p->numerator*q->numerator;
	c.denominator=p->denominator*q->denominator;
	simplify(r);
	return c;
}

Rational divide(Rational *p,Rational *q)//���������� 
{
	Rational c,*r=&c;
	c.numerator=p->numerator*q->denominator;
	c.denominator=p->denominator*q->numerator;
	simplify(r);
	return c;
}

void putRationalNumber(Rational a)//��������� 
{
	if(a.denominator==1)
	{
		printf("������Ϊ��%d\n",a.numerator); 
	}
	else if(a.numerator==0)
	{
		printf("������Ϊ��0\n");
	}
	else
	{
		printf("������Ϊ��%d/%d\n",a.numerator,a.denominator);
	}
}

int GCD(int a,int b)//�����Լ������ 
{
	int t=0;
	if(a<b)
	{
		t=a;
		a=b;
		b=t;
	}
	while(b!=0)
	{
		t=b;
		b=a%b;
		a=t;
	}
	return a;//a�д�ŵļ�Ϊ���������Լ�� 
}

void simplify(Rational *p)//���ӷ�ĸ������ 
{
	int gcd=GCD(p->numerator,p->denominator);
	p->numerator/=gcd;
	p->denominator/=gcd;
}

void menu(Rational *p,Rational *q)//�˵�ѡ���� 
{
	int i=0,j=0;
	for(i=0;i<=40;i++)
	{
		printf("*");
	}
	printf("\n");
	printf("*\t\t\t\t\t*\n");
	printf("*     Ҫ�����������ӷ����㣬������1     *\n");
	printf("*     Ҫ�����������������㣬������2     *\n");
	printf("*     Ҫ�����������˷����㣬������3     *\n");
	printf("*     Ҫ�����������������㣬������4     *\n");
	printf("*\t\t\t\t\t*\n");
	for(i=0;i<=40;i++)
	{
		printf("*");
	}
	printf("\n");
	scanf("%d",&j);
	switch(j)
	{
		case 1:putRationalNumber(plus(p,q));break;
		case 2:putRationalNumber(sub(p,q));break;
		case 3:putRationalNumber(multiply(p,q));break;
		case 4:putRationalNumber(divide(p,q));break;
	}
}

#endif
