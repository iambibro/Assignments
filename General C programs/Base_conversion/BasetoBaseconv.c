
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
long int convert10(long int,long int);
void base16(long int input[25],long int);
long int convert16to10(char hex[20],long int);
int l;	
char ch;
	
int main()
{
do //continuity checking loop
{
long int num,input[25],ib,ob,c,p,i=1;
char hex[17]; //for hexadecimal inputs
printf("Enter the input base: ");
scanf("%ld",&ib); //input base scanning
if(ib!=16) //when input is not hexadecimal
{
printf("Enter the number : ");
scanf("%ld",&num);
}
else //when input is hexadecimal
{
printf("Enter the number : ");
fflush(stdin);
gets(hex); //storing the hexadecimal input to the array
}
printf("Enter the output base : ");
scanf("%ld",&ob); //scanning the output base
if(ib!=10) //when input is not decimal
{
if(ib!=16) /*when input base is not 16 but output base is 
10*/
c=convert10(num,ib); 
else //when input base is 16 and ouput base is 10
c=convert16to10(hex,ib);
}
else //when input is not decimal
c=num; //setting the input in c
if(ob==10) //when ouput base is 10
{
printf("The output is : %ld",c); /*when input and output 
base are same*/
}
while(c>=1) 
{
input[i]=c%ob; /*storing the mod value of input and output 
    base*/
c=c/ob; //storing the remainder in c
p=i; //storing the value value of i
i++;
}
if(ob!=10) //when output base not equals to 10
{
printf("The output is : ");
for(i=p;i>=1;i--) //printing output
{
if(input[i]>=10)
base16(input,i); 
else
printf("%ld",input[i]);
}
}
printf("\nDo you want to continue(Y/N)? : "); /*continuity 
   check*/
fflush(stdin);
scanf("%c",&ch);
if(ch=='n' || ch=='N')
return 0;
}while(ch=='y' || ch=='Y');
return 0;
}
long int convert10(long int num,long int ibase)
{
long int y[25],i=0,s=0,p,decimal,value;
while(num>=1)
{
y[i]=num%10;
num=num/10;
p=i;
i++;
}
for(i=0;i<=p;i++)
s=s+y[i]*pow(ibase,i);
return s;
}
long int convert16to10(char hex[20],long int ibase)
{
long int length,value,decimal=0;
int i=0;
length=strlen(hex);
length--;
for(i=0;hex[i]!='\0';i++)
{
switch(hex[i])
{
case '0': value=0;
break;
case '1': value=1;
break;
case '2': value=2;
break;
case '3': value=3;
break;
case '4': value=4;
break;
case '5': value=5;
break;
case '6': value=6;
break;
case '7': value=7;
break;
case '8': value=8;
break;
case '9': value=9;
break;
case 'A':
case 'a': value=10;
break;
case 'B':
case 'b': value=11;
break;
case 'C':
case 'c': value=12;
break;
case 'D':
case 'd': value=13;
break;
case 'E':
case 'e': value=14;
break;

case 'F':
case 'f': value=15;
break;
}
decimal=decimal+value*pow(ibase,length);
length--;
}
return decimal;
}
void base16(long int input[25], long int i)
{
char c;
c=input[i]+55;
printf("%c",c);
}

