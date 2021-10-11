#include <stdio.h>
int fun(int x)
{
    int a, b, c;
    a = x / 100;
    b = x % 100 / 10;
    c = x % 10;
    if (x == a * a * a + b * b * b + c * c * c)
        return 1;
    else
        return 0;
}
int main()
{
    int m;
    for (m = 100; m <= 500; m++)
    {
        if(fun(m)==1)
        printf("%5d\n", m);
    }
	return 0; 
}

