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
//int n , arr[200200]; //arr�洢������ 
//const int minn = -19260817; // ������Сֵ 
//inline int Max( int a , int b) { return a > b ? a : b ;} //�Զ��� Max �����������stl�Ŀ�һ�㣩 
//int rec( int l , int r ) { //���κ��� 
//    if ( l == r ) {    //    l=rʱ��ֱ�ӷ��ظ�λ�õ�ֵ 
//        return arr[l];
//    }
//    int mid = ( l + r ) >> 1;  
//    int sum = 0 , ret1 = minn , ret2 = minn; //ret1Ϊ[l..mid]�����ڰ���mid������Ӷκͣ�ret2Ϊ[mid+1..r]�����ڰ���(mid+1)������Ӷκ�  
//    for( int i = mid ; i >= l ; i-- ) {
//        sum += arr[i];
//        ret1 = Max( ret1 , sum );
//    }  //���[i..mid]�������ֵ
//    sum = 0;
//    for( int i = mid+1 ; i <= r ; i++ ) {
//        sum += arr[i];
//        ret2 = Max( ret2 , sum );
//    }  //���[mid+1..r]�������ֵ
//    return Max( Max( rec( l , mid ) , rec( mid + 1 , r ) ) , ret1 + ret2 );   //���ؿ���һ ���ܶ� ������ �е����ֵ
//}
//int main() { // ����������  
//    scanf("%d", &n );
//    
//    for( int i = 1 ; i <= n ; i++ ) {
//        scanf("%d" , &arr[i] );
//    }
//    
//    printf("%d" , rec(1 , n) ); 
//    return 0;
//}`

