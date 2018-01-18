/*Print the following series:-
sin x=x-x^3/3!+x^5/5!-...for all x
The loop should continue until the num/de is less than 0.00001 i.e.  at no. of terms is 3 numer = 5 and denom =5!  */
#include<stdio.h>
#include<math.h>
int main()
{ 
	char ch;
 	do
  	{
   		int i, j, denom, index, sign;
   		float term, sum, x, sine, numer, error, c,t;
   		printf("Enter the value of x:");
   		scanf("%f",&x);
   		t= (3.141593*x)/180;
   		sine=t;
   		sign=-1;
   		index=3;
   		while(1)
	 	{
		 	numer=pow(t,index);
			denom=1;
			for(j=1;j<=index;j++)
			denom=denom*j;
			term=(sign*numer)/denom;
			if(numer /denom<0.00001)
				break;
			sine=sine+term;
			index=index+2;
			sign=sign*-1;
		}
		c=sin(t);
		error=fabs(sine-c);
		printf("\nValue of sine %f",x);
		printf("\nAs per series=%f",sine);
		printf("\nAs per library function %f", c);
		printf("\nError =%f",error);
		printf("\nDo you want to continue:(Y/N)?");
		fflush(stdin);
		scanf(" %c",& ch);
		if(ch=='n'|| ch=='N')
			return 0;
 	} while (ch=='y'|| ch=='Y');
 	if(ch!='y'|| ch!='Y')
 		printf("Wrong choice");
 	return 0;
}
