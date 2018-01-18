#include<stdio.h>
#include<conio.h>
int main()
{
	int x,y,p,q,s,a[50],i,count;
	char ch;
	do{
		i=0;
		s=0;
		count=0;
		printf("Enter the numbers:");
		scanf("%d %d",&x,&y);
		printf("\nThe multiplication method of %d & %d\nusing Russian Peasant Method is as follows:\n\n",x,y);
		p=x;
		q=y;
		printf("%d\t\t%d",p,q);
		if(p%2!=0)
		{
			s=q;
			a[0]=q;
			i++;
		}
		else
			printf("X(STRUCK OFF)");
		while(p>1)
		{
			p=p/2;
			q=q*2;
			printf("\n%d\t\t%d",p,q);
			if(p%2!=0)
			{
				s=s+q;
				a[i]=q;
		  		i++;
				count++;	
			}
			else
				printf("X(STRUCK OFF)");
		}
		count--;		
		printf("\n\nThe answer is:\n");
		for(i=0;i<=count;i++)
		{
			printf("%d+",a[i]);
		}		
		printf("\b=%d",s);
		printf("\n\nWhich satisfies the statement %d*%d=%d",x,y,x*y);
		while(1)
		{
			printf("\nDo you want to continue?(Y/N)");
			scanf(" %c",&ch);
			if(ch=='n'||ch=='N')
				return 0;
			if(ch=='y'||ch=='Y')
				break;
			if(ch!='y'||ch!='Y')
				printf("Wrong choice given");
		}
	}while(ch=='y'||ch=='Y');
	getch();
	return 0;
}
