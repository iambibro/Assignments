#include<stdio.h>
#include<conio.h>

int main()
{
    
	int x,i,j,k,temp,flag,check=0; char ch;
	do
    	{
	   	printf("Enter the number:"); 
    		scanf("%d",&x); //Taking the number from user
    		if(x>=2) //To omit 1 or 0 or negative numbers from the input
    		{	
check=0;
			for(k=x/2;k>=2;k--)
			{
				if(x%k==0)
				{
					check=1;
				}
			}
			if(check==1)
			{	
				printf("The prime factors for the number %d are: ",x);
				for(i=x/2;i>=2;i--) 
				{
					if(x%i==0) //checking whether it has factors or not
					{	
						flag=0;//setting the flag variable to 0
						temp=i;/*taking a temporary variable to	
avoid calculation errors*/
						for(j=temp/2;j>=2;j--)/*inner for loop to
check whether the factor is prime or not*/
						{
							if(temp%j==0)/*prime
number checking*/
							{
					 			flag=1;/*when the factor is not 
prime*/
								break;
			 				}
		 				}	
		 				if(flag==0)//when the factor is prime
		 				printf("%d ",i);
	 				}
			
				}
			}
			else//when the input is prime
			{
				printf("%d is a prime number. No factors found.",x);
				goto loop;//shifting the control to the continuity check
			}
		}
		else //when the input is less than
		printf("Wrong input given");		
	loop:	printf("\nDo you want to continue?(Y/N)");//continuity checking
			scanf(" %c",&ch);
			if(ch=='n'||ch=='N')
			return 0;
		}while(ch=='y'||ch=='Y');
	if(ch!='y'||ch!='Y')//when any input other than 1 or 0  is given
	{
		printf("Wrong choice");/*shifting the control to the continuity check*/
		goto loop;
	}
	getch();
	return 0;
}	

