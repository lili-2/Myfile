#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"WinMM.lib")
typedef struct inf
{
	float	price;
	int	num;
	char	type[50];
	char	loc[50];
	char	name[50];
	char	aut[50];
	struct inf	*next;
} inf;
struct data
{
	float	price;
	int	num;
	char	type[50];
	char	loc[50];
	char	name[50];
	char	aut[50];
};
/* 指向书籍各种特征的指针数组 */
inf	*ptype[100] = { NULL };
inf	*pprice[100] = { NULL };
inf	*paut[100] = { NULL };
inf	*pname[100] = { NULL };
inf	*pnum[100] = { NULL };
int	g_len; /* len为录入数据总数 */


/* 输入密码
   函数参数：无
   返回值：无*/
void Secret()
{
	char	secret[20] = "123456", name[20];
	int	i;
	printf( "请输入密码：\n" );
	for ( i = 0; i < 5; i++ )
	{
		gets( name );
		/* 利用strcmp()对比预设密码与输入密码 */
		if ( strcmp( secret, name ) != 0 )
			{
			    mciSendString("open 错误音效.mp3",NULL,0,NULL);
                mciSendString("play 错误音效.mp3",NULL,0,NULL);
			    printf( "密码输入错误，您还可以尝试%d次！\n", 4 - i );
			}
		else
        {
			mciSendString("open 正确音效.mp3",NULL,0,NULL);
		    mciSendString("play 正确音效.mp3",NULL,0,NULL);
			printf( "密码正确！\n" );
			return;
		}
	}
	printf( "对不起，您的尝试次数已耗尽！" );
	exit( 0 );
}


/* 函数功能：二分查找书名
   传入参数：name[],len
   传出参数：无
   返回值：无 */
void BinSearch_by_name( char name[], int len )
{
	int low = 0, high = len - 1, mid, flag = 0;
	printf( "类型     书名                作者                书架       价格    数量\n" );
	while ( low <= high )
	{
		mid = (high + low) / 2;
		if ( strcmp( name, pname[mid]->name ) > 0 )
		{
			low = mid + 1;
		}else if ( strcmp( name, pname[high]->name ) < 0 )
		{
			high = mid - 1;
		}else  {
			printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", pname[mid]->type, pname[mid]->name, pname[mid]->aut, pname[mid]->loc, pname[mid]->price, pname[mid]->num );
			flag = 1;
			break;
		}
	}
	if ( flag == 0 )
		printf( "没有找到！\n" );
}


/*函数功能：按类型查找并输出
  传入参数：type[],len
  传出参数：无
  返回值：无 */
void Search_by_type( char type[], int len )
{
	int i, flag = 0;
	printf( "类型     书名                作者                书架       价格    数量\n" );
	for ( i = 0; i < len; i++ )
	{
		if ( strcmp( type, ptype[i]->type ) == 0 )
		{
			printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", ptype[i]->type, ptype[i]->name, ptype[i]->aut, ptype[i]->loc, ptype[i]->price, ptype[i]->num );
			flag = 1;
		}else if ( strcmp( type, ptype[i]->type ) < 0 )
			break;
	}
	if ( flag == 0 )
		printf( "没有找到！\n" );
}


/*函数功能：按作者名模糊查找并输出
  传入参数：无
  传出参数：无
  返回值：无 */
void search_by_author( )
{
    char author[20],aut1[3],aut2[3];
    char *p1=NULL,*p2=NULL;
    int i=0,flag=0;
    printf("请输入作者名：\n");
    gets(author);
    strncpy(aut1,author,2);
    aut1[2]=0;
    if(strlen(author)>2)
    {
        strncpy(aut2,&author[2],2);
        aut2[2]=0;
    }
    printf( "类型     书名                作者                书架       价格    数量\n" );
    for(i=0;i<g_len;i++)
    {
        p1=strstr(paut[i]->aut,aut1);
        if(strlen(author)>2)
            p2=strstr(paut[i]->aut,aut2);
        if ( p1 != NULL || p2 !=NULL )
            {
                flag=1;
                printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", paut[i]->type, paut[i]->name, paut[i]->aut, paut[i]->loc, paut[i]->price, paut[i]->num );
            }
    }
	if ( flag == 0 )
		printf( "没有找到！\n" );
    printf( "按回车键继续" );
	getchar();
}


/* 函数功能：快速排序算法(类型）
   传入参数：begin,end
   传出参数：无
   返回值：无 */
void quicksort1( int begin, int end )
{
	int	i, j;
	inf	*temp = NULL;
	if ( begin < end )
	{
		i	= begin + 1;
		j	= end;
		while ( i < j )
		{
			if ( strcmp( ptype[i]->type, ptype[begin]->type ) > 0 )
			{
				/* 交换地址 */
				temp		= ptype[i];
				ptype[i]	= ptype[j];
				ptype[j]	= temp;
				j--;
			}else  {
				i++;
			}
		}
		if ( strcmp( ptype[i]->type, ptype[begin]->type ) >= 0 )
		{
			i--;
		}
		temp		= ptype[i];
		ptype[i]	= ptype[begin];
		ptype[begin]	= temp;
		/* 递归调用 */
		quicksort1( begin, i );
		quicksort1( j, end );
	}
}


/* 函数功能：快速排序算法(定价）
   传入参数：begin,end
   传出参数：无
   返回值：无 */
void quicksort2( int begin, int end )
{
	int	i, j;
	inf	*temp = NULL;
	if ( begin < end )
	{
		i	= begin + 1;
		j	= end;
		while ( i < j )
		{
			if ( pprice[i]->price < pprice[begin]->price )
			{
				temp		= pprice[i];
				pprice[i]	= pprice[j];
				pprice[j]	= temp;
				j--;
			}else  {
				i++;
			}
		}
		if ( pprice[i]->price <= pprice[begin]->price )
		{
			i--;
		}
		temp		= pprice[i];
		pprice[i]	= pprice[begin];
		pprice[begin]	= temp;
		/* 递归调用 */
		quicksort2( begin, i );
		quicksort2( j, end );
	}
}


/* 函数功能：快速排序算法(作者名）
   传入参数：begin,end
   传出参数：无
   返回值：无 */
void quicksort3( int begin, int end )
{
	int	i, j;
	inf	*temp = NULL;
	if ( begin < end )
	{
		i	= begin + 1;
		j	= end;
		while ( i < j )
		{
			if ( strcmp( paut[i]->aut, paut[begin]->aut ) > 0 )
			{
				temp	= paut[i];
				paut[i] = paut[j];
				paut[j] = temp;
				j--;
			}else  {
				i++;
			}
		}
		if ( strcmp( paut[i]->aut, paut[begin]->aut ) >= 0 )
		{
			i--;
		}
		temp		= paut[i];
		paut[i]		= paut[begin];
		paut[begin]	= temp;
		/* 递归调用 */
		quicksort3( begin, i );
		quicksort3( j, end );
	}
}


/* 函数功能：快速排序算法(名称）
   传入参数：begin,end
   传出参数：无
   返回值：无 */
void quicksort4( int begin, int end )
{
	int	i, j;
	inf	*temp = NULL;
	if ( begin < end )
	{
		i	= begin + 1;
		j	= end;
		while ( i < j )
		{
			if ( strcmp( pname[i]->name, pname[begin]->name ) > 0 )
			{
				temp		= pname[i];
				pname[i]	= pname[j];
				pname[j]	= temp;
				j--;
			}else  {
				i++;
			}
		}
		if ( strcmp( pname[i]->name, pname[begin]->name ) >= 0 )
		{
			i--;
		}
		temp		= pname[i];
		pname[i]	= pname[begin];
		pname[begin]	= temp;
		/* 递归调用 */
		quicksort4( begin, i );
		quicksort4( j, end );
	}
}


/* 函数功能：快速排序算法(数量）
   传入参数：begin,end
   传出参数：无
   返回值：无 */
void quicksort5( int begin, int end )
{
	int	i, j;
	inf	*temp = NULL;
	if ( begin < end )
	{
		i	= begin + 1;
		j	= end;
		while ( i < j )
		{
			if ( pnum[i]->num < pnum[begin]->num )
			{
				temp	= pnum[i];
				pnum[i] = pnum[j];
				pnum[j] = temp;
				j--;
			}else  {
				i++;
			}
		}
		if ( pnum[i]->num <= pnum[begin]->num )
		{
			i--;
		}
		temp		= pnum[i];
		pnum[i]		= pnum[begin];
		pnum[begin]	= temp;
		/* 递归调用 */
		quicksort5( begin, i );
		quicksort5( j, end );
	}
}


/* 函数功能：创建一个新结点
   传入参数：*head
   传出参数：g_len
   返回值：head */
inf *AppendNode( inf *head )
{
	inf	*p = NULL, *pr = head, *p1 = NULL;
	char	c;
	do
	{
		pr	= head;
		p	= NULL;
		p	= (inf *) malloc( sizeof(inf) );
		/* 判断内存分配是否成功 */
		if ( p == NULL )
		{
			printf( "内存不足！" );
			exit( 0 );
		}
		if ( head == NULL )
		{
			head = p;
		}else  {
			while ( pr->next != NULL )
			{
				pr = pr->next;
			}
			pr->next = p;
		}
		printf( "输入书名：" );
		gets( p->name );
		printf( "输入书的类型：" );
		gets( p->type );
		printf( "输入作者：" );
		gets( p->aut );
		printf( "输入所在书架(按标准结构“一个数字+一个大写字母”输入)：" );
		gets( p->loc );
		if ( strlen( p->loc ) != 2 )
		{
			printf( "输入非法！\n" );
			Sleep(500);
			exit( 0 );
		}
		if(p->loc[0]<'0'||p->loc[0]>'9'||p->loc[1]>'Z'||p->loc[1]<'A')
        {
            printf( "输入非法！\n" );
			exit( 0 );
        }
		printf( "输入价格：" );
		scanf( " %f", &p->price );
		printf( "输入数量：" );
		scanf( " %d", &p->num );
		p->next = NULL;
		/* 为每个指针数组初始化 */
		pnum[g_len]		= p;
		ptype[g_len]	= p;
		pprice[g_len]	= p;
		paut[g_len]		= p;
		pname[g_len]	= p;
		/* 给结点计数 */
		g_len++;
		printf( "你是否想继续添加数据？（输入“y”或“1”则继续输入，否则停止输入)" );
		scanf( " %c", &c );
		getchar();
	}
	while ( c == 'y' || c == '1' );
	return(head);
}


/* 函数功能：从文件中读取图书数据
   传入参数：*head
   传出参数：g_len
   返回值：head*/
inf *AppendNodefromFile( inf *head )
{
	inf	*p = NULL, *pr = head;
	FILE		*fp;
	int		i;
	/* 判断文件是否打开成功 */
	if ( (fp = fopen( "data1.txt", "r" ) ) == NULL )
	{
		printf( "文件打开失败，请确认data1.txt是否在当前文件夹!\n" );
		exit( 0 );
	}
	fscanf( fp, "%d\n", &g_len );
	for ( i = 0; i < g_len; i++ )
	{
		pr	= head;
		p	= NULL;
		p	= (inf *) malloc( sizeof(inf) );
		/* 判断内存分配是否成功 */
		if ( p == NULL )
		{
			printf( "内存不足！" );
			exit( 0 );
		}
		if ( head == NULL )
		{
			head = p;
		}
		else
        {
			while ( pr->next != NULL )
			{
				pr = pr->next;
			}
			pr->next = p;
		}
		p->next = NULL;
		/* 为每个指针数组初始化 */
		pnum[i]		= p;
		ptype[i]	= p;
		pprice[i]	= p;
		paut[i]		= p;
		pname[i]	= p;
		fscanf( fp, "%s%s%s%s%f%d\n", p->type, p->name, p->aut, p->loc, &p->price, &p->num );
	}
	/* 关闭文件 */
	fclose( fp );
	printf("读入成功\n");
	printf( "按回车键返回主菜单\n" );
	getchar();
    return head;
}

/* 函数功能：显示链表中的所有内容
   传入参数：*head
   传出参数：无
   返回值：无 */
void DisplyNode( inf *head )
{
	inf *p = head;
	printf( "已输入的所有数据为：\n" );
	printf( "类型      书名                作者               书架       价格   数量\n" );
	while ( p != NULL )
	{
		printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", p->type, p->name, p->aut, p->loc, p->price, p->num );
		p = p->next;
	}
	printf( "按回车键返回主菜单\n" );
	getchar();
}


/* 函数功能：释放所有链表内存
   传入参数：head
   传出参数：无
   返回值：NULL */
inf *DeleteMemory( inf *head )
{
	inf *p = head, *pr = NULL;
	while ( p != NULL )
	{
		pr	= p;
		p	= p->next;
		free( pr );
	}
	g_len = 0;
	return(NULL);
}


/*函数功能：按书的类型排序并输出
  传入参数：head
  传出参数：无
  返回值：无 */
void output_by_type( inf *head )
{
	inf	*p2 = head;
	int	i;
	for ( i = 0; i < g_len; i++ )
	{
		ptype[i]	= p2;
		p2		= p2->next;
	}
	quicksort1( 0, g_len - 1 );
	printf( "按类型排序结果为：\n" );
	printf( "类型      书名                作者               书架       价格   数量\n" );
	for ( i = 0; i < g_len; i++ )
	{
		printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", ptype[i]->type, ptype[i]->name, ptype[i]->aut, ptype[i]->loc, ptype[i]->price, ptype[i]->num );
	}
	printf( "按回车键返回主菜单" );
	getchar();
}


/*函数功能：按书的定价排序并输出
   传入参数：head
   传出参数：无
   返回值：无*/
void output_by_price( inf *head )
{
	inf	*p2 = head;
	int	i;
	for ( i = 0; i < g_len; i++ ) /* 给指针数组赋链表的地址 */
	{
		pprice[i]	= p2;
		p2		= p2->next;
	}
	quicksort2( 0, g_len - 1 );
	printf( "按定价排序的结果为：\n" );
	printf( "类型      书名                作者               书架       价格   数量\n" );
	for ( i = 0; i < g_len; i++ )
	{
		printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", pprice[i]->type, pprice[i]->name, pprice[i]->aut, pprice[i]->loc, pprice[i]->price, pprice[i]->num );
	}
	printf( "按回车键返回主菜单" );
	getchar();
}


/*函数功能：按书的作者名排序并输出
  传入参数：head
   传出参数：无
   返回值：无 */
void output_by_author( inf *head )
{
	inf	*p2 = head;
	int	i;
	for ( i = 0; i < g_len; i++ ) /* 给指针数组赋链表的地址 */
	{
		paut[i] = p2;
		p2	= p2->next;
	}
	quicksort3( 0, g_len - 1 );
	printf( "按作者排序的结果为：\n" );
	printf( "类型      书名                作者               书架       价格   数量\n" );
	for ( i = 0; i < g_len; i++ )
	{
		printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", paut[i]->type, paut[i]->name, paut[i]->aut, paut[i]->loc, paut[i]->price, paut[i]->num );
	}
	printf( "按回车键返回主菜单" );
	getchar();
}


/*函数功能：按书的名称排序并输出
  传入参数：head
   传出参数：无
   返回值：无*/
void output_by_name( inf *head )
{
	inf	*p2 = head;
	int	i;
	for ( i = 0; i < g_len; i++ ) /* 给指针数组赋链表的地址 */
	{
		pname[i]	= p2;
		p2		= p2->next;
	}
	quicksort4( 0, g_len - 1 );
	printf( "按书名排序的结果为：\n" );
	printf( "类型      书名                作者               书架       价格   数量\n" );
	for ( i = 0; i < g_len; i++ )
	{
		printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", pname[i]->type, pname[i]->name, pname[i]->aut, pname[i]->loc, pname[i]->price, pname[i]->num );
	}
	printf( "按回车键返回主菜单" );
	getchar();
}


/*函数功能：按书的数量排序并输出
  传入参数：head
   传出参数：无
   返回值：无*/
void output_by_number( inf *head )
{
	int i;
	quicksort5( 0, g_len - 1 );
	printf( "按书的数量排序的结果为：\n" );
	printf( "类型      书名                作者               书架       价格   数量\n" );
	for ( i = 0; i < g_len; i++ )
	{
		printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", pnum[i]->type, pnum[i]->name, pnum[i]->aut, pnum[i]->loc, pnum[i]->price, pnum[i]->num );
	}
	printf( "按回车键返回主菜单" );
	getchar();
}


/* 函数功能：按类型查找
   传入参数：head
   传出参数：无
   返回值：无*/
void search_by_type( inf *head )
{
	char booktype[50];
	printf( "请输入要查找的类型：" );
	gets( booktype );
	/* 排序后调用查找函数 */
	Search_by_type( booktype, g_len );
	printf( "按回车键返回主菜单" );
	getchar();
}


/*函数功能：按书名查找
   传入参数：head
   传出参数：无
   返回值：无 */
void search_by_name( inf *head )
{
	char bookname[50];
	printf( "请输入要查找的书名：" );
	gets( bookname );
	/* 调用查找函数 */
	quicksort4(0,g_len-1);
	BinSearch_by_name( bookname, g_len );
	printf( "按回车键返回主菜单" );
	getchar();
}




/* 函数功能：输出各个作者的比例
传入参数：无
   传出参数：无
   返回值：无 */
void output_author_rate()
{
	char	authorname[50][50];
	int	i		= 0, j = 0, k = -1, sum = 0, count[50] = { 0 };
	float	rate[50]	= { 0 };
	while ( paut[i] != NULL )
	{
		k++;
		strcpy( authorname[k], paut[i]->aut );
		while ( paut[j] != NULL && strcmp( authorname[k], paut[j]->aut ) == 0 )
		{
			j++; i++; count[k]++;
		}
		sum += count[k];
	}
	for ( i = 0; i <= k; i++ )
	{
		rate[i] = (float) count[i] / sum * 100;
	}
	printf( "每个作者的著作所占比例：\n" );
	for ( i = 0; i <= k; i++ )
	{
		printf( "%s的著作占了 %.2f%%\n", authorname[i], rate[i] );
	}
	printf( "按回车键返回主菜单" );
	getchar();
}


/*函数功能： 输出各个类型的比例
  传入参数：head
   传出参数：无
   返回值：无 */
void output_type_rate()
{
	char	typena[50][50];
	int	i		= 0, j = 0, k = -1, sum = 0, count[50] = { 0 };
	float	rate[50]	= { 0 };
	while ( ptype[i] != NULL )
	{
		k++;
		strcpy( typena[k], ptype[i]->type );
		while ( ptype[j] != NULL && strcmp( typena[k], ptype[j]->type ) == 0 )
		{
			j++; i++; count[k]++;
		}
		sum += count[k];
	}
	for ( i = 0; i <= k; i++ )
	{
		rate[i] = (float) count[i] / sum * 100;
	}
	printf( "每种类型书籍所占比例：\n" );
	for ( i = 0; i <= k; i++ )
	{
		printf( "%s 占了 %.2f%%\n", typena[i], rate[i] );
	}
	printf( "按回车键返回主菜单" );
	getchar();
}


/*说明： 0~20为低价位，20~50为中价位，50以上为高价位
  函数功能：输出各价位比例
  传入参数：无
   传出参数：无
   返回值：无 */
void output_price_rate()
{
	int	count[3] = { 0 }, i, sum;
	float	rate[3];
	for ( i = 0; pprice[i] != NULL; i++ )
	{
		if ( pprice[i]->price < 20 )
			count[0]++;
		else if ( pprice[i]->price >= 20 && pprice[i]->price < 50 )
			count[1]++;
		else if ( pprice[i]->price >= 50 )
			count[2]++;
	}
	sum	= count[0] + count[1] + count[2];
	rate[0] = (float) count[0] / sum;
	rate[1] = (float) count[1] / sum;
	rate[2] = (float) count[2] / sum;
	printf( "低、中、高价位所占比例分别为：\n" );
	printf( "%.2f%%  %.2f%%  %.2f%%\n", 100*rate[0], 100*rate[1], 100*rate[2] );
	printf( "按回车键返回主菜单" );
	getchar();
}


/* 函数功能：将已有数据写入到文件
   传入参数：head
   传出参数：无
   返回值：无*/
void WritealreadytoFile( inf *head )
{
	FILE	*fp;
	inf	*p = head;
	int	i;
	/* 判断文件是否打开成功 */
	if ( (fp = fopen( "data1.txt", "w" ) ) == NULL )
	{
		printf( "文件打开失败，请确认data1.txt是否在当前文件夹!\n" );
		exit( 0 );
	}
	fprintf( fp, "%d\n", g_len );
	for ( i = 0; i < g_len; i++ )
	{
		fprintf( fp, "%-10s%-20s%-20s%-10s%-5.2f%5d\n", ptype[i]->type, ptype[i]->name, ptype[i]->aut, ptype[i]->loc, ptype[i]->price, ptype[i]->num );
	}
	fclose( fp );
	printf("写入成功！");
	printf( "按回车键返回主菜单" );
	getchar();
}


int main()
{
	int	n,ret;
	char a;
	inf	*head = NULL;
	system( "color F4" );
	printf( "                         ***************欢迎使用iBookstore书店管理系统***************\n" );
	printf( "                         ------------------------------------------------------------\n\n" );
	Secret();
	printf("您是否想要听音乐？(输入1则开始放音乐，输入其他则不放音乐)\n");
	scanf(" %c",&a);
	/*清理缓冲区*/
	while(getchar()!='\n');
	if(a=='1')
	{
		mciSendString("open 背景音乐.mp3",NULL,0,NULL);
		mciSendString("play 背景音乐.mp3",NULL,0,NULL);
	}
	system( "cls" );

	while ( 1 )
	{
		printf( "**********************************************主菜单*************************************************\n\n");
		printf( "-----------------------------------------------------------------------------------------------------\n\n");
		printf( "[1]录入或添加书籍的类型、书名、作者、书架、价格、数量     [2]手动录入太麻烦，直接从文件中读取书籍数据\n\n" );
		printf( "[3]按书的类型排序并输出                                   [4]按作者名排序并输出\n\n" );
		printf( "[7]按书的定价排序并输出                                   [8]按书的类型检索书籍\n\n" );
		printf( "[9]按书名检索书籍                                         [10]按作者模糊检索书籍\n\n" );
		printf( "[11]输出不同类型书籍所占的百分比                          [12]输出各个作者的书所占的百分比\n\n" );
		printf( "[13]输出不同价位的书所占的百分比                          [14]将已有数据写入文件\n\n" );
		printf( "[15]按输入顺序显示数据                                    [16]清空输入数据\n\n" );
		printf( "[0]退出系统\n\n" );
		printf( "-----------------------------------------------------------------------------------------------------\n\n");
		printf( "\n请输入您想使用的功能对应的序号：" );
		ret=scanf( " %d", &n );
		if(ret!=1)
		{


			while(getchar()!='\n')
		    continue;
		}
		/*清理缓冲区*/
		while(getchar()!='\n');
		system( "cls" );
		switch ( n )
		{
		case 1: head = AppendNode( head ); break;
		case 2: head = AppendNodefromFile( head );break;
		case 3: output_by_type( head ); break;
		case 4: output_by_author( head ); break;
		case 5: output_by_name( head ); break;
		case 6: output_by_number( head ); break;
		case 7: output_by_price( head ); break;
		case 8: search_by_type( head ); break;
		case 9: search_by_name( head ); break;
		case 10: search_by_author(); break;
		case 11: output_type_rate(); break;
		case 12: output_author_rate(); break;
		case 13: output_price_rate(); break;
		case 14: WritealreadytoFile( head ); break;
		case 15: DisplyNode( head ); break;
		case 16: head = DeleteMemory( head );printf("清理成功！");Sleep(500); break;
		case 0: printf("感谢使用iBookStore,再见!");exit( 0 );
		default: printf( "输入错误！" );
		}
		system( "cls" );
	}
}

