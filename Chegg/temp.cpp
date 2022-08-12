// #include <bits/stdc++.h>
// using namespace std;

// // int solve(int n, int t, vector<vector<int>> task)
// // {
// //     sort(task.begin(), task.end());
// //     long long sumNum = 0;
// //     int ansNum = 0;
// //     multiset<int> st;
// //     for (int i = 0; i < n; i++)
// //     {
// //         sumNum += 1LL * task[i][1];
// //         st.insert(-task[i][1]);
// //         long long timeNum = 2LL * task[i][0];
// //         while (!st.empty() and sumNum + timeNum > 1LL * t)
// //         {
// //             sumNum += 1LL * (*st.begin());
// //             st.erase(st.begin());
// //         }
// //         ansNum = max(ansNum, (int)st.size());
// //     }
// //     return ansNum;
// // }

// long long solve(int N,vector<int>&A)
// {
//     long long sumNum=0;
//     long long curNum=0;
//     int i=0;
//     if(A[0]<0)
//     {
//         sumNum+=A[i];
//         i++;
//     }
//     for(;i<N;i++) {
//         sumNum+=abs(A[i]);
//     }
//     return sumNum;
// }

// int main()
// {
//     int n;
//     cin>>n;
//     vector<int>nums(n);
//     for(int i=0;i<n;i++)
//     {
//         cin>>nums[i];
//     }
//     int ans=solve(n,nums);
//     cout<<ans<<endl;
// }

// #include <iostream>

// using namespace std;

// int hack(int arr[], int n)
// {
//     int res=0;
//     int i;
//     for (i = 0; i < n; i++) res ^= arr[i];
//     return res;
// }

// int main(void)
// {
// int arr[] = { 22, 22, 24, 90, 24, 24, 24};

// int n = sizeof(arr) / sizeof(arr[0]);
// cout << hack(arr, n);

// return 0;
// }

// #include <iostream>

// using namespace std;

// template <typename T>
// struct func
// {
//     void x()
//     {
//         cout << "hi" << endl;
//     }
//     void y()
//     {
//         cout << "hello" << endl;
//     }
// };

// template<>
// void func<int>::x()
// {
//     cout<<"hello world"<<endl;
// }

// int main()
// {
//     func<int>t;
//     t.x();
//     t.y();
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int a[]{3, 5, 1, 2, 7, 9, 8, 4};

//     int n = sizeof(a) / sizeof(a[0]);
//     sort(a, a + n, greater<int>());

//     for (int i = 0; i < n; ++i)
//         cout << a[i] << " ";

//     return 0;
// }

// #include <iostream>

// using namespace std;

// int operate(int a, int b)
// {
//     return (a * b);
// }
// float operate(float a, float b)
// {
//     return (a / b);
// }
// int main()
// {
//     int x = 5, y = 2;

//     float n = 5.0, m = 2.0;
//     cout << operate(x, y) << "\n";

//     cout << operate(n, m);
// }

// #include <iostream>
// using namespace std;

// template <typename T>
// T myMax(T x, T y)
// {
//     return (x > y) ? x : y;
// }

// int main()
// {
//     cout << myMax<int>(3, 7) << endl;

//     cout << myMax<double>(3.0, 7.0) << endl;

//     cout << myMax<char>('g', 'e') << endl;

//     return 0;
// }

// #include <iostream>

// using namespace std;

// class Shape
// {
// public:
//     virtual int getCalc() = 0;

//     void setWidth(int w)
//     {

//         width = w;
//     }

//     void setHeight(int h)
//     {

//         height = h;
//     }

// protected:
//     int width;

//     int height;
// };

// class Shape1 : public Shape
// {
// public:
//     int getCalc()
//     {
//         return (width * height);
//     }
// };

// class Shape2 : public Shape
// {

// public:
//     int getCalc()
//     {

//         return (width * height)/2;
//     }
// };

// int main()
// {
//     Shape1 obj1;

//     Shape2 obj2;

//     obj1.setWidth(5);

//     obj1.setHeight(4);

//     cout << obj1.getCalc() << " ";
//     obj2.setHeight(8);
//     obj2.setHeight(4);
//     cout << obj2.getCalc() << endl;
// }

#include <bits/stdc++.h>

using namespace std;

void hack_code(int arr[], int n, int *x, int *y)
{

    int X = arr[0];

    int no;

    int i;

    *x = 0;

    *y = 0;

    for (int i = 1; i < n; i++)
    {
        X ^= arr[i];
    }

    no = X & ~(X - 1);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & no)
        {
            *x = *x ^ arr[i];
        }
        else
        {
            *y = *y ^ arr[i];
        }
    }
}

int main()
{

    int arr[] = {2, 5, 7, 9, 11, 2, 4, 11};

    int n = sizeof(arr) / sizeof(*arr);

    int *x = new int[(sizeof(int))];

    int *y = new int[(sizeof(int))];
    hack_code(arr, n, x, y);

    cout << *x << " and " << *y;
}