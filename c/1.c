 #include <stdio.h>
 int main()
 {
 	int n,l = 0,r = 0,flag = 1;
 	int arr[10002][2];
 	scanf("%d",&n);
 	for(int i = 0;i < n;i++)
 	{
 		scanf("%d %d",&arr[i][0],&arr[i][1]);
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < i;j++)
		{
			if(arr[j][0] > arr[j+1][0])
			{
    
				int temp = arr[j][0];
				arr[j][0] = arr[j+1][0];
				arr[j+1][0] = temp;
				
				temp = arr[j][1];
				arr[j][1] = arr[j+1][1];
				arr[j+1][1]= temp;
			}
            else if(arr[j][0] == arr[j+1][0] && arr[j][1] > arr[j+1][1]){
                int temp = arr[j][0];
				arr[j][0] = arr[j+1][0];
				arr[j+1][0] = temp;
				
				temp = arr[j][1];
				arr[j][1] = arr[j+1][1];
				arr[j+1][1]= temp;
            }
		}
	}
	l = arr[0][0],r = arr[0][1];
	for(int i = 1;i < n;i++)
	{
		if(arr[i][0] <= r)
		{
			r = arr[i][1];
		}else{
			flag = 0;
			break;
		}
	}
	if(flag == 1)
	{
		printf("%d %d",l,r);
	}
	else
	{
		printf("no");
	}
	return 0;
 }
