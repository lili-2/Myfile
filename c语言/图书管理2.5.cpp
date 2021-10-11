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
/* ָ���鼮����������ָ������ */
inf	*ptype[100] = { NULL };
inf	*pprice[100] = { NULL };
inf	*paut[100] = { NULL };
inf	*pname[100] = { NULL };
inf	*pnum[100] = { NULL };
int	g_len; /* lenΪ¼���������� */


/* ��������
   ������������
   ����ֵ����*/
void Secret()
{
	char	secret[20] = "123456", name[20];
	int	i;
	printf( "���������룺\n" );
	for ( i = 0; i < 5; i++ )
	{
		gets( name );
		/* ����strcmp()�Ա�Ԥ���������������� */
		if ( strcmp( secret, name ) != 0 )
			{
			    mciSendString("open ������Ч.mp3",NULL,0,NULL);
                mciSendString("play ������Ч.mp3",NULL,0,NULL);
			    printf( "������������������Գ���%d�Σ�\n", 4 - i );
			}
		else
        {
			mciSendString("open ��ȷ��Ч.mp3",NULL,0,NULL);
		    mciSendString("play ��ȷ��Ч.mp3",NULL,0,NULL);
			printf( "������ȷ��\n" );
			return;
		}
	}
	printf( "�Բ������ĳ��Դ����Ѻľ���" );
	exit( 0 );
}


/* �������ܣ����ֲ�������
   ���������name[],len
   ������������
   ����ֵ���� */
void BinSearch_by_name( char name[], int len )
{
	int low = 0, high = len - 1, mid, flag = 0;
	printf( "����     ����                ����                ���       �۸�    ����\n" );
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
		printf( "û���ҵ���\n" );
}


/*�������ܣ������Ͳ��Ҳ����
  ���������type[],len
  ������������
  ����ֵ���� */
void Search_by_type( char type[], int len )
{
	int i, flag = 0;
	printf( "����     ����                ����                ���       �۸�    ����\n" );
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
		printf( "û���ҵ���\n" );
}


/*�������ܣ���������ģ�����Ҳ����
  �����������
  ������������
  ����ֵ���� */
void search_by_author( )
{
    char author[20],aut1[3],aut2[3];
    char *p1=NULL,*p2=NULL;
    int i=0,flag=0;
    printf("��������������\n");
    gets(author);
    strncpy(aut1,author,2);
    aut1[2]=0;
    if(strlen(author)>2)
    {
        strncpy(aut2,&author[2],2);
        aut2[2]=0;
    }
    printf( "����     ����                ����                ���       �۸�    ����\n" );
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
		printf( "û���ҵ���\n" );
    printf( "���س�������" );
	getchar();
}


/* �������ܣ����������㷨(���ͣ�
   ���������begin,end
   ������������
   ����ֵ���� */
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
				/* ������ַ */
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
		/* �ݹ���� */
		quicksort1( begin, i );
		quicksort1( j, end );
	}
}


/* �������ܣ����������㷨(���ۣ�
   ���������begin,end
   ������������
   ����ֵ���� */
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
		/* �ݹ���� */
		quicksort2( begin, i );
		quicksort2( j, end );
	}
}


/* �������ܣ����������㷨(��������
   ���������begin,end
   ������������
   ����ֵ���� */
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
		/* �ݹ���� */
		quicksort3( begin, i );
		quicksort3( j, end );
	}
}


/* �������ܣ����������㷨(���ƣ�
   ���������begin,end
   ������������
   ����ֵ���� */
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
		/* �ݹ���� */
		quicksort4( begin, i );
		quicksort4( j, end );
	}
}


/* �������ܣ����������㷨(������
   ���������begin,end
   ������������
   ����ֵ���� */
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
		/* �ݹ���� */
		quicksort5( begin, i );
		quicksort5( j, end );
	}
}


/* �������ܣ�����һ���½��
   ���������*head
   ����������g_len
   ����ֵ��head */
inf *AppendNode( inf *head )
{
	inf	*p = NULL, *pr = head, *p1 = NULL;
	char	c;
	do
	{
		pr	= head;
		p	= NULL;
		p	= (inf *) malloc( sizeof(inf) );
		/* �ж��ڴ�����Ƿ�ɹ� */
		if ( p == NULL )
		{
			printf( "�ڴ治�㣡" );
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
		printf( "����������" );
		gets( p->name );
		printf( "����������ͣ�" );
		gets( p->type );
		printf( "�������ߣ�" );
		gets( p->aut );
		printf( "�����������(����׼�ṹ��һ������+һ����д��ĸ������)��" );
		gets( p->loc );
		if ( strlen( p->loc ) != 2 )
		{
			printf( "����Ƿ���\n" );
			Sleep(500);
			exit( 0 );
		}
		if(p->loc[0]<'0'||p->loc[0]>'9'||p->loc[1]>'Z'||p->loc[1]<'A')
        {
            printf( "����Ƿ���\n" );
			exit( 0 );
        }
		printf( "����۸�" );
		scanf( " %f", &p->price );
		printf( "����������" );
		scanf( " %d", &p->num );
		p->next = NULL;
		/* Ϊÿ��ָ�������ʼ�� */
		pnum[g_len]		= p;
		ptype[g_len]	= p;
		pprice[g_len]	= p;
		paut[g_len]		= p;
		pname[g_len]	= p;
		/* �������� */
		g_len++;
		printf( "���Ƿ������������ݣ������롰y����1����������룬����ֹͣ����)" );
		scanf( " %c", &c );
		getchar();
	}
	while ( c == 'y' || c == '1' );
	return(head);
}


/* �������ܣ����ļ��ж�ȡͼ������
   ���������*head
   ����������g_len
   ����ֵ��head*/
inf *AppendNodefromFile( inf *head )
{
	inf	*p = NULL, *pr = head;
	FILE		*fp;
	int		i;
	/* �ж��ļ��Ƿ�򿪳ɹ� */
	if ( (fp = fopen( "data1.txt", "r" ) ) == NULL )
	{
		printf( "�ļ���ʧ�ܣ���ȷ��data1.txt�Ƿ��ڵ�ǰ�ļ���!\n" );
		exit( 0 );
	}
	fscanf( fp, "%d\n", &g_len );
	for ( i = 0; i < g_len; i++ )
	{
		pr	= head;
		p	= NULL;
		p	= (inf *) malloc( sizeof(inf) );
		/* �ж��ڴ�����Ƿ�ɹ� */
		if ( p == NULL )
		{
			printf( "�ڴ治�㣡" );
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
		/* Ϊÿ��ָ�������ʼ�� */
		pnum[i]		= p;
		ptype[i]	= p;
		pprice[i]	= p;
		paut[i]		= p;
		pname[i]	= p;
		fscanf( fp, "%s%s%s%s%f%d\n", p->type, p->name, p->aut, p->loc, &p->price, &p->num );
	}
	/* �ر��ļ� */
	fclose( fp );
	printf("����ɹ�\n");
	printf( "���س����������˵�\n" );
	getchar();
    return head;
}

/* �������ܣ���ʾ�����е���������
   ���������*head
   ������������
   ����ֵ���� */
void DisplyNode( inf *head )
{
	inf *p = head;
	printf( "���������������Ϊ��\n" );
	printf( "����      ����                ����               ���       �۸�   ����\n" );
	while ( p != NULL )
	{
		printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", p->type, p->name, p->aut, p->loc, p->price, p->num );
		p = p->next;
	}
	printf( "���س����������˵�\n" );
	getchar();
}


/* �������ܣ��ͷ����������ڴ�
   ���������head
   ������������
   ����ֵ��NULL */
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


/*�������ܣ�����������������
  ���������head
  ������������
  ����ֵ���� */
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
	printf( "������������Ϊ��\n" );
	printf( "����      ����                ����               ���       �۸�   ����\n" );
	for ( i = 0; i < g_len; i++ )
	{
		printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", ptype[i]->type, ptype[i]->name, ptype[i]->aut, ptype[i]->loc, ptype[i]->price, ptype[i]->num );
	}
	printf( "���س����������˵�" );
	getchar();
}


/*�������ܣ�����Ķ����������
   ���������head
   ������������
   ����ֵ����*/
void output_by_price( inf *head )
{
	inf	*p2 = head;
	int	i;
	for ( i = 0; i < g_len; i++ ) /* ��ָ�����鸳����ĵ�ַ */
	{
		pprice[i]	= p2;
		p2		= p2->next;
	}
	quicksort2( 0, g_len - 1 );
	printf( "����������Ľ��Ϊ��\n" );
	printf( "����      ����                ����               ���       �۸�   ����\n" );
	for ( i = 0; i < g_len; i++ )
	{
		printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", pprice[i]->type, pprice[i]->name, pprice[i]->aut, pprice[i]->loc, pprice[i]->price, pprice[i]->num );
	}
	printf( "���س����������˵�" );
	getchar();
}


/*�������ܣ�������������������
  ���������head
   ������������
   ����ֵ���� */
void output_by_author( inf *head )
{
	inf	*p2 = head;
	int	i;
	for ( i = 0; i < g_len; i++ ) /* ��ָ�����鸳����ĵ�ַ */
	{
		paut[i] = p2;
		p2	= p2->next;
	}
	quicksort3( 0, g_len - 1 );
	printf( "����������Ľ��Ϊ��\n" );
	printf( "����      ����                ����               ���       �۸�   ����\n" );
	for ( i = 0; i < g_len; i++ )
	{
		printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", paut[i]->type, paut[i]->name, paut[i]->aut, paut[i]->loc, paut[i]->price, paut[i]->num );
	}
	printf( "���س����������˵�" );
	getchar();
}


/*�������ܣ�����������������
  ���������head
   ������������
   ����ֵ����*/
void output_by_name( inf *head )
{
	inf	*p2 = head;
	int	i;
	for ( i = 0; i < g_len; i++ ) /* ��ָ�����鸳����ĵ�ַ */
	{
		pname[i]	= p2;
		p2		= p2->next;
	}
	quicksort4( 0, g_len - 1 );
	printf( "����������Ľ��Ϊ��\n" );
	printf( "����      ����                ����               ���       �۸�   ����\n" );
	for ( i = 0; i < g_len; i++ )
	{
		printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", pname[i]->type, pname[i]->name, pname[i]->aut, pname[i]->loc, pname[i]->price, pname[i]->num );
	}
	printf( "���س����������˵�" );
	getchar();
}


/*�������ܣ�����������������
  ���������head
   ������������
   ����ֵ����*/
void output_by_number( inf *head )
{
	int i;
	quicksort5( 0, g_len - 1 );
	printf( "�������������Ľ��Ϊ��\n" );
	printf( "����      ����                ����               ���       �۸�   ����\n" );
	for ( i = 0; i < g_len; i++ )
	{
		printf( "%-10s%-20s%-20s%-10s%-5.2f%5d\n", pnum[i]->type, pnum[i]->name, pnum[i]->aut, pnum[i]->loc, pnum[i]->price, pnum[i]->num );
	}
	printf( "���س����������˵�" );
	getchar();
}


/* �������ܣ������Ͳ���
   ���������head
   ������������
   ����ֵ����*/
void search_by_type( inf *head )
{
	char booktype[50];
	printf( "������Ҫ���ҵ����ͣ�" );
	gets( booktype );
	/* �������ò��Һ��� */
	Search_by_type( booktype, g_len );
	printf( "���س����������˵�" );
	getchar();
}


/*�������ܣ�����������
   ���������head
   ������������
   ����ֵ���� */
void search_by_name( inf *head )
{
	char bookname[50];
	printf( "������Ҫ���ҵ�������" );
	gets( bookname );
	/* ���ò��Һ��� */
	quicksort4(0,g_len-1);
	BinSearch_by_name( bookname, g_len );
	printf( "���س����������˵�" );
	getchar();
}




/* �������ܣ�����������ߵı���
�����������
   ������������
   ����ֵ���� */
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
	printf( "ÿ�����ߵ�������ռ������\n" );
	for ( i = 0; i <= k; i++ )
	{
		printf( "%s������ռ�� %.2f%%\n", authorname[i], rate[i] );
	}
	printf( "���س����������˵�" );
	getchar();
}


/*�������ܣ� ����������͵ı���
  ���������head
   ������������
   ����ֵ���� */
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
	printf( "ÿ�������鼮��ռ������\n" );
	for ( i = 0; i <= k; i++ )
	{
		printf( "%s ռ�� %.2f%%\n", typena[i], rate[i] );
	}
	printf( "���س����������˵�" );
	getchar();
}


/*˵���� 0~20Ϊ�ͼ�λ��20~50Ϊ�м�λ��50����Ϊ�߼�λ
  �������ܣ��������λ����
  �����������
   ������������
   ����ֵ���� */
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
	printf( "�͡��С��߼�λ��ռ�����ֱ�Ϊ��\n" );
	printf( "%.2f%%  %.2f%%  %.2f%%\n", 100*rate[0], 100*rate[1], 100*rate[2] );
	printf( "���س����������˵�" );
	getchar();
}


/* �������ܣ�����������д�뵽�ļ�
   ���������head
   ������������
   ����ֵ����*/
void WritealreadytoFile( inf *head )
{
	FILE	*fp;
	inf	*p = head;
	int	i;
	/* �ж��ļ��Ƿ�򿪳ɹ� */
	if ( (fp = fopen( "data1.txt", "w" ) ) == NULL )
	{
		printf( "�ļ���ʧ�ܣ���ȷ��data1.txt�Ƿ��ڵ�ǰ�ļ���!\n" );
		exit( 0 );
	}
	fprintf( fp, "%d\n", g_len );
	for ( i = 0; i < g_len; i++ )
	{
		fprintf( fp, "%-10s%-20s%-20s%-10s%-5.2f%5d\n", ptype[i]->type, ptype[i]->name, ptype[i]->aut, ptype[i]->loc, ptype[i]->price, ptype[i]->num );
	}
	fclose( fp );
	printf("д��ɹ���");
	printf( "���س����������˵�" );
	getchar();
}


int main()
{
	int	n,ret;
	char a;
	inf	*head = NULL;
	system( "color F4" );
	printf( "                         ***************��ӭʹ��iBookstore������ϵͳ***************\n" );
	printf( "                         ------------------------------------------------------------\n\n" );
	Secret();
	printf("���Ƿ���Ҫ�����֣�(����1��ʼ�����֣����������򲻷�����)\n");
	scanf(" %c",&a);
	/*��������*/
	while(getchar()!='\n');
	if(a=='1')
	{
		mciSendString("open ��������.mp3",NULL,0,NULL);
		mciSendString("play ��������.mp3",NULL,0,NULL);
	}
	system( "cls" );

	while ( 1 )
	{
		printf( "**********************************************���˵�*************************************************\n\n");
		printf( "-----------------------------------------------------------------------------------------------------\n\n");
		printf( "[1]¼�������鼮�����͡����������ߡ���ܡ��۸�����     [2]�ֶ�¼��̫�鷳��ֱ�Ӵ��ļ��ж�ȡ�鼮����\n\n" );
		printf( "[3]����������������                                   [4]���������������\n\n" );
		printf( "[7]����Ķ����������                                   [8]��������ͼ����鼮\n\n" );
		printf( "[9]�����������鼮                                         [10]������ģ�������鼮\n\n" );
		printf( "[11]�����ͬ�����鼮��ռ�İٷֱ�                          [12]����������ߵ�����ռ�İٷֱ�\n\n" );
		printf( "[13]�����ͬ��λ������ռ�İٷֱ�                          [14]����������д���ļ�\n\n" );
		printf( "[15]������˳����ʾ����                                    [16]�����������\n\n" );
		printf( "[0]�˳�ϵͳ\n\n" );
		printf( "-----------------------------------------------------------------------------------------------------\n\n");
		printf( "\n����������ʹ�õĹ��ܶ�Ӧ����ţ�" );
		ret=scanf( " %d", &n );
		if(ret!=1)
		{


			while(getchar()!='\n')
		    continue;
		}
		/*��������*/
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
		case 16: head = DeleteMemory( head );printf("����ɹ���");Sleep(500); break;
		case 0: printf("��лʹ��iBookStore,�ټ�!");exit( 0 );
		default: printf( "�������" );
		}
		system( "cls" );
	}
}

