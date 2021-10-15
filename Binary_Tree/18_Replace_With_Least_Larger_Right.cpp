#include <stdio.h>
 
int main(void) {
	int i,j,max = -1;
	int arr[] = {-7, -2, 8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 28, 80, 28};
	int size = sizeof(arr)/sizeof(arr[0]);
 
	for(i=0;i<size;i++)
	printf("%d ",arr[i]);
	printf("\n");
 
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(arr[i]<arr[j])
			{
				if(max==-1)
					max = arr[j];
 
				else if(max>arr[j])
					max = arr[j];
			}
		}
		arr[i] = max;
		max = -1;
	}
 
	for(i=0;i<size;i++)
	printf("%d ",arr[i]);
 
	return 0;
}