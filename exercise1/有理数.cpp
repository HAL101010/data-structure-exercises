#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "RationalNumber.h"

void main() 
{
	Rational rational1,*p=&rational1;
	Rational rational2,*q=&rational2;
	getRationalNumber(p);
	getRationalNumber(q);
	menu(p,q);
}
