#include<stdio.h>
#include<math.h>
unsigned long long y(int n,int prev) {
    return n > 2 ? y(n - 1, 2 * prev + 1) : 2 * prev + 1;
}
    
unsigned long long Y(int n){
    return n > 1 ? y(n-1,1) : 1;
}    
int main()
{
	printf("%d",Y(2));
	return 0;
}
