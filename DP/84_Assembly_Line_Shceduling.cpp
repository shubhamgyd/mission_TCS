/*
A car factory has two assembly lines, each with n stations. A station is denoted by Si,j 
where i is either 1 or 2 and indicates the assembly line the station is on, and j indicates 
the number of the station. The time taken per station is denoted by ai,j. Each station is 
dedicated to some sort of work like engine fitting, body fitting, painting, and so on. So, 
a car chassis must pass through each of the n stations in order before exiting the factory. 
The parallel stations of the two assembly lines perform the same task. After it passes through 
station Si,j, it will continue to station Si,j+1 unless it decides to transfer to the other line. 
Continuing on the same line incurs no extra cost, but transferring from line i at station j – 1 to
 station j on the other line takes time ti,j. Each assembly line takes an entry time ei and exit 
 time xi which may be different for the two lines. Give an algorithm for computing the minimum time 
 it will take to build a car chassis
*/

 
// DP Method Not space optimised

#include<bits/stdc++.h>
using namespace std;

int carAssembly(int a[][4],int t[][4],int *e,int *x)
{
    int T1[4],T2[4];

    // Entering time plus time to leave first station for assembly line
    T1[0]=a[0][0]+e[0];


    // Enteering time of line 2 and time to leave of first station of assembly line 2
    T2[0]=a[0][1]+e[1];

    for(int i=1;i<4;i++)
    {
        // Minimum time to reach station i either going
        // from station i-1 to i of line 1 or
        // going from station i-1 to to i of line 2
        T1[i]=min(T1[i-1]+a[0][i],T2[i-1]+t[1][i]+a[0][i]);


        // Same for line ith station of 2 line
        T2[i]=min(T2[i-1]+a[1][i],T1[i-1]+a[1][i]+t[0][i]);
    }

    return min(T1[4-1]+x[0],T2[4-1]+x[1]);

}

int main()
{
    int a[][4] = { { 4, 5, 3, 2 },
                   { 2, 10, 1, 4 } };
    int t[][4] = { { 0, 7, 4, 5 },
                   { 0, 9, 2, 8 } };
    int e[] = { 10, 12 }, x[] = { 18, 7 };
    cout << carAssembly(a, t, e, x);
    return 0;
}
/*
Time Complexity: O(n)
Space Complexity :O(n)
*/



// Space optimised

#include<bits/stdc++.h>
using namespace std;

int carAssembly1(int a[][4],int t[][4],int *e,int *x)
{
    int first,second;

    // Entering time plus time to leave first station for assembly line
    first=a[0][0]+e[0];


    // Enteering time of line 2 and time to leave of first station of assembly line 2
    second=a[0][1]+e[1];

    for(int i=1;i<4;i++)
    {
        // Minimum time to reach station i either going
        // from station i-1 to i of line 1 or
        // going from station i-1 to to i of line 2
        int first1=min(first+a[0][i],second+t[1][i]+a[0][i]);


        // Same for line ith station of 2 line
        int second1=min(second+a[1][i],first+a[1][i]+t[0][i]);

        first=first1;
        second=second1;
    }

    return min(first+x[0],second+x[1]);
}

int main()
{
    int a[][4] = { { 4, 5, 3, 2 },
                   { 2, 10, 1, 4 } };
    int t[][4] = { { 0, 7, 4, 5 },
                   { 0, 9, 2, 8 } };
    int e[] = { 10, 12 }, x[] = { 18, 7 };
    cout << carAssembly1(a, t, e, x);
    return 0;
}

/*
Time Complexity: O(n)
Space Complexity :O(1)
*/