 #include <stdio.h>
 int a[2000000];
 int fn(int l,int r);
 int Max(int a,int b);
 int main()
 {
 	int n,i;
 	scanf("%d",&n);
 	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("%d",fn(1,n));
	return 0;
 } 
 int fn(int l,int r)
 {
 	int max=-100009;
 	int mid=(r+l)/2,ret1=max,ret2=max,sum=0,i;
 	if(l==r)
 	return a[l];
 	for(i=mid;i>=l;i--)
 	{
 		sum+=a[i];
 		ret1=Max(sum,ret1);
	}
	sum=0;
	for(i=mid+1;i<=r;i++)
	{
		sum+=a[i];
		ret2=Max(sum,ret2);
	}
	return Max(Max(fn(l,mid),fn(mid+1,r)),ret1+ret2);
 }
 int Max(int a,int b)
 {
 	return a>b ? a : b; 
 }


//#include<cstdio>
//int n , arr[200200]; //arr存储该序列 
//const int minn = -19260817; // 定义最小值 
//inline int Max( int a , int b) { return a > b ? a : b ;} //自定义 Max 函数（好像比stl的快一点） 
//int rec( int l , int r ) { //分治函数 
//    if ( l == r ) {    //    l=r时，直接返回该位置的值 
//        return arr[l];
//    }
//    int mid = ( l + r ) >> 1;  
//    int sum = 0 , ret1 = minn , ret2 = minn; //ret1为[l..mid]区间内包含mid的最大子段和，ret2为[mid+1..r]区间内包含(mid+1)的最大子段和  
//    for( int i = mid ; i >= l ; i-- ) {
//        sum += arr[i];
//        ret1 = Max( ret1 , sum );
//    }  //求出[i..mid]区间最大值
//    sum = 0;
//    for( int i = mid+1 ; i <= r ; i++ ) {
//        sum += arr[i];
//        ret2 = Max( ret2 , sum );
//    }  //求出[mid+1..r]区间最大值
//    return Max( Max( rec( l , mid ) , rec( mid + 1 , r ) ) , ret1 + ret2 );   //返回可能一 可能二 可能三 中的最大值
//}
//int main() { // 以下主函数  
//    scanf("%d", &n );
//    
//    for( int i = 1 ; i <= n ; i++ ) {
//        scanf("%d" , &arr[i] );
//    }
//    
//    printf("%d" , rec(1 , n) ); 
//    return 0;
//}`

