#include<Stdio.h>
int main()
{
	printf("%d",a+=a-=a*a)
}



//#include<stdio.h>
//int main()
//{
//    int n,m,i,j,t;
//    scanf("%d %d",&n,&m);
//    int arr[m];
//   
//    for(i=0;i<m;++i)
//        scanf("%d",&arr[i]);
//    for(i=0;i<m-1;++i)//因为每次需要和a[i]后面的数进行比较,所以到a[n-2](倒数第2个元素)就行
//    {
//        for(j=i+1;j<m;++j)//j从i后一个开始,a[i]与a[j]进行比较
//        {
//            if(arr[i]>arr[j])//a[i]为当前值,若是比后面的a[j]大,进行交换
//            {
//                t=arr[i];
//                arr[i]=arr[j];
//                arr[j]=t;
//            }
//        }//每排序一次,就会将a[i](包括a[i])之后的最小值放在a[i]的位置
//    }
//     for(i=0;i<m;++i)
//        printf("%d",arr[i]);
//
//
//}
