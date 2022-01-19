#include <bits/stdc++.h>
using namespace std;

long  double intersectionArea(long double X1, long double Y1, long double R1, long double X2, long double Y2, long double R2)
{
    long double Pi = 3.14;
    long double d, alpha, beta, a1, a2;
    long double ans;
    d = sqrt((X2 - X1) * (X2 - X1) + (Y2 - Y1) * (Y2 - Y1));

    if (d > R1 + R2)
        ans = 0;
    else if (d <= abs(R2 - R1) && R1 >= R2)
        ans = floor(Pi * R2 * R2);

    else if (d <= abs(R2 - R1) && R2 >= R1)
        ans = floor(Pi * R1 * R1);

    else
    {
        alpha = acos((R1 * R1 + d * d - R2 * R2) / (2 * R1 * d)) * 2;
        beta = acos((R2 * R2 + d * d - R1 * R1) / (2 * R2 * d)) * 2;
        a1 = 0.5 * beta * R2 * R2 - 0.5 * R2 * R2 * sin(beta);
        a2 = 0.5 * alpha * R1 * R1 - 0.5 * R1 * R1 * sin(alpha);
        ans = floor(a1 + a2);
    }
    return ans;
}

int main()
{
    long double x1, y1, r1, x2, y2, r2;
    cin >> x1>>y1>>r1;
    cin >> x2>>y2>>r2;

    long double ans=intersectionArea(x1,y1,r1,x2,y2,r2);
    cout<< fixed<<setprecision(4)<<ans<<endl;
    return 0;
}