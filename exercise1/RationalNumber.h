#ifndef __RATIONALNUMBER_H__
#define __RATIONALNUMBER_H__
#define M 1000000//M为计算精确度 

typedef struct RationalNumber//有理数结构体 
{
	int numerator;
	int denominator;
}Rational;

int GCD(int a,int b);
void simplify(Rational *p);

void getRationalNumber(Rational *p)//创建有理数函数 
{
	int i=0,j=0,count=0;
	float num=0,a=0,b=0;
	char str[30],str1[30],str2[30];
	printf("请输入一个有理数(若以分数形式输入请用“/ ”隔开分子分母)：\n");
	label_1:
	gets(str);
	
	for(i=0;i<30;i++)//判断该有理数的输入形式 
	{
		if(str[i]=='/')break;
		count++;
	}
	
	if(count==30)//如果是小数形式则直接将字符串转化为浮点数 
	{
		num=atof(str);
		p->numerator=(int)(num*M); 
		p->denominator=M;
		simplify(p);
		//printf("该分数为：%d/%d\n",p->numerator,p->denominator);
	}
	else//如果是分数形式则分别提取分子分母 
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
			printf("非法数字，请重新输入：\n");//检查分母为0的情况 
			count=0;
			i=0;
			j=0;
			goto label_1;
		}
		p->numerator=(int)(a*M);
		p->denominator=(int)(b*M);
		simplify(p);
		//printf("该分数为：%d/%d\n",p->numerator,p->denominator);
	}
}

Rational plus(Rational *p,Rational *q)//有理数加法 
{
	Rational c,*r=&c;
	c.numerator=p->numerator*q->denominator+q->numerator*p->denominator;
	c.denominator=p->denominator*q->denominator;
	simplify(r);
	return c;
}

Rational sub(Rational *p,Rational *q)//有理数减法 
{
	Rational c,*r=&c;
	c.numerator=p->numerator*q->denominator-q->numerator*p->denominator;
	c.denominator=p->denominator*q->denominator;
	simplify(r);
	return c;
}

Rational multiply(Rational *p,Rational *q)//有理数乘法 
{
	Rational c,*r=&c;
	c.numerator=p->numerator*q->numerator;
	c.denominator=p->denominator*q->denominator;
	simplify(r);
	return c;
}

Rational divide(Rational *p,Rational *q)//有理数除法 
{
	Rational c,*r=&c;
	c.numerator=p->numerator*q->denominator;
	c.denominator=p->denominator*q->numerator;
	simplify(r);
	return c;
}

void putRationalNumber(Rational a)//输出有理数 
{
	if(a.denominator==1)
	{
		printf("运算结果为：%d\n",a.numerator); 
	}
	else if(a.numerator==0)
	{
		printf("运算结果为：0\n");
	}
	else
	{
		printf("运算结果为：%d/%d\n",a.numerator,a.denominator);
	}
}

int GCD(int a,int b)//求最大公约数函数 
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
	return a;//a中存放的即为两数的最大公约数 
}

void simplify(Rational *p)//分子分母化简函数 
{
	int gcd=GCD(p->numerator,p->denominator);
	p->numerator/=gcd;
	p->denominator/=gcd;
}

void menu(Rational *p,Rational *q)//菜单选择函数 
{
	int i=0,j=0;
	for(i=0;i<=40;i++)
	{
		printf("*");
	}
	printf("\n");
	printf("*\t\t\t\t\t*\n");
	printf("*     要进行有理数加法运算，请输入1     *\n");
	printf("*     要进行有理数减法运算，请输入2     *\n");
	printf("*     要进行有理数乘法运算，请输入3     *\n");
	printf("*     要进行有理数除法运算，请输入4     *\n");
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
