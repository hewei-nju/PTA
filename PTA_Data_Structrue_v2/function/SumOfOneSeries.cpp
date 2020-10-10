#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

double fn( double x, int n );

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x,n));

    return 0;
}

/* 你的代码将被嵌在这里 */
double fn( double x, int n )
{
    if (x == (double)0) {
        return x;
    } else if (n == 1) {
        return x;
    } else {
        return x * (1 - fn(x, n - 1));
    }
}


/**
double fn( double x, int n )
{
    double sum = 0;
    double y = x;
    if (x == 0) {
        sum = x;
    } else if (n > 0) {
        for (int i = 1; i <= n; ++i) {
            sum += x;
            x *= (-1 * y);
        }
    }
    return sum;
}
*/