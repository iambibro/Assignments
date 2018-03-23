#include<stdio.h>
#include<stdlib.h>
int main()
{
	int *a,i,j,min,t,n,k;
	printf("Enter the number of elements of the array: ");
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++){
		printf("Enter the element no. %d: ",i+1);
		scanf("%d",a+i);
	}
	for(i=1;i<n;i++){//Controlling the unsorted part
		for(j=0;j<i;j++){//Controlling the sorted part
			if(a[i]<a[j]){
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	for(i=0;i<n;i++){
		printf("%d\n",*(a+i));
	}
	return 0;
}
