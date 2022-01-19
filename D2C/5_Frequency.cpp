// // // #include<bits/stdc++.h>
// // // using namespace std;

// // // int main()
// // // {
// // //     string str;
// // //     cin>>str;
// // //     int n=str.length();
// // //     map<char,int>mp;
// // //     int i;
// // //     for(i=0;i<n/2;i++)
// // //     {
// // //         mp[str[i]]++;
// // //     }
// // //     int ct=0;
// // //     set<char>st;
// // //     for(i;i<n;i++)
// // //     {
// // //         if(mp.find(str[i])!=mp.end())
// // //         {
// // //             st.insert(str[i]);
// // //         }
// // //     }
// // //     cout<<st.size()<<endl;
// // //     return 0;
// // // }

// // // CPP code for Dynamic Programming based
// // // solution for 0-1 Knapsack problem
// // #include <bits/stdc++.h>

// // // A utility function that returns maximum of two integers
// // int max(int a, int b) { return (a > b) ? a : b; }

// // // Prints the items which are put in a knapsack of capacity W
// // void printknapSack(int W, int wt[], int val[], int n)
// // {
// //     int i, w;
// //     int K[n + 1][W + 1];

// //     // Build table K[][] in bottom up manner
// //     for (i = 0; i <= n; i++) {
// //         for (w = 0; w <= W; w++) {
// //             if (i == 0 || w == 0)
// //                 K[i][w] = 0;
// //             else if (wt[i - 1] <= w)
// //                 K[i][w] = max(val[i - 1] +
// //                     K[i - 1][w - wt[i - 1]], K[i - 1][w]);
// //             else
// //                 K[i][w] = K[i - 1][w];
// //         }
// //     }

// //     // stores the result of Knapsack
// //     int res = K[n][W];
// //     printf("%d", res);

// //     w = W;
// //     for (i = n; i > 0 && res > 0; i--) {

// //         // either the result comes from the top
// //         // (K[i-1][w]) or from (val[i-1] + K[i-1]
// //         // [w-wt[i-1]]) as in Knapsack table. If
// //         // it comes from the latter one/ it means
// //         // the item is included.
// //         if (res == K[i - 1][w])
// //             continue;
// //         else {

// //             // This item is included.
// //             printf("%d ", wt[i - 1]);

// //             // Since this weight is included its
// //             // value is deducted
// //             res = res - val[i - 1];
// //             w = w - wt[i - 1];
// //         }
// //     }
// // }

// // // Driver code
// // int main()
// // {
// //     int val[] = {1,1,1,1,1,1};
// //     int wt[] = { 1,2,3,4,5,6 };
// //     int W = 9;
// //     int n = sizeof(val) / sizeof(val[0]);

// //     printknapSack(W, wt, val, n);

// //     return 0;
// // }

// // #include<bits/stdc++.h>
// // using namespace std;

// // int main()
// // {
// //     char ch='a';
// //     int y=ch;
// //     cout<<y<<endl;
// // }













// // #include <bits/stdc++.h>
// // using namespace std;

// // class Student
// // {
// //     int roll_no;
// //     char name[20];
// //     int mark[5];
// //     float average;
// //     priority_queue<pair<float, int>> pq;

// // public:
// //     void getData();
// //     void showData();
// //     int getRoll_No() { return roll_no; }
// // } s;

// // void Student::getData()
// // {
// //     cout << "\n\nEnter Student Details......\n";
// //     cout << "Enter Roll No.     : ";
// //     cin >> roll_no;
// //     cout << "Enter Full Name         : ";
// //     cin.ignore();
// //     cin.getline(name, 20);
// //     cout << "\nEnter maths mark:";
// //     cin >> mark[0];
// //     cout << "\nEnter science mark:";
// //     cin >> mark[1];
// //     cout << "\nEnter english mark:";
// //     cin >> mark[2];
// //     cout << "\nEnter social science mark:";
// //     cin >> mark[3];
// //     cout << "\nEnter hindi mark:";
// //     cin >> mark[4];
// //     int sum = 0;
// //     for (int i = 0; i < 5; i++)
// //     {
// //         sum += mark[i];
// //     }
// //     average = (float)sum / (float)5;
// //     pq.push({average, roll_no});
// //     cout << endl;
// // }

// // void addData()
// // {
// //     ofstream fout;
// //     fout.open("Students.dat", ios::binary | ios::out | ios::app);
// //     s.getData();
// //     fout.write((char *)&s, sizeof(s));
// //     fout.close();
// //     cout << "\n\nData Successfully Saved to File....\n";
// // }
// // void Student::showData()
// // {
// //     cout << "\n\n.......Student Details......\n";
// //     cout << "Roll.     : " << roll_no << endl;
// //     cout << "Name      : " << name << endl;
// //     cout << "Marks: " << endl;
// //     for (int i = 0; i < 5; i++)
// //     {
// //         cout << mark[i] << " ";
// //     }
// //     cout << endl;
// // }

// // void searchData()
// // {
// //     int n, flag = 0;
// //     ifstream fin;
// //     fin.open("Students.dat", ios::in | ios::binary);
// //     cout << "Enter Roll Number you want to search : ";
// //     cin >> n;

// //     while (fin.read((char *)&s, sizeof(s)))
// //     {
// //         if (n == s.getRoll_No())
// //         {
// //             cout << "The Details of Roll No. " << n << " shown here with:\n";
// //             s.showData();
// //             flag++;
// //         }
// //     }
// //     fin.close();
// //     if (flag == 0)
// //         cout << "The Roll No. " << n << " not found....\n\n";
// //     cout << "\n\nData Reading from File Successfully Done....\n";
// // }

// // void project()
// // {
// //     int ch;
// //     do
// //     {
// //         system("cls");
// //         cout << "...............STUDENT MANAGEMENT SYSTEM..............\n";
// //         cout << "======================================================\n";
// //         cout << "0. Exit from Program\n";
// //         cout << "1. Write Student Data to File\n";
// //         cout << "2. Read Student Data From File By using Roll no\n";
// //         cout << "Enter your choice  : ";
// //         cin >> ch;
// //         system("cls");
// //         switch (ch)
// //         {
// //         case 0:
// //             exit(0);
// //             break;
// //         case 1:
// //             addData();
// //             break;
// //         case 2:
// //             searchData();
// //             break;
// //         default:
// //             break;
// //         }
// //         system("pause");
// //     } while (ch);
// // }

// // int main()
// // {
// //     project();
// // }




// #include <bits/stdc++.h>
// using namespace std;

// map<float,int>mp;
// class Student
// {
//     int roll_no;
//     char name[20];
//     int mark[5];
//     float average;

// public:
//     void getData();
//     void showData();
//     int getRoll_No() { return roll_no; }
// } s;

// void Student::getData()
// {
//     cout << "\n\nEnter Student Details......\n";
//     cout << "Enter Roll No.     : ";
//     cin >> roll_no;
//     cout << "Enter Full Name    : ";
//     cin.ignore();
//     cin.getline(name, 20);
//     cout << "\nEnter maths mark:";
//     cin >> mark[0];
//     cout << "\nEnter science mark:";
//     cin >> mark[1];
//     cout << "\nEnter english mark:";
//     cin >> mark[2];
//     cout << "\nEnter social science mark:";
//     cin >> mark[3];
//     cout << "\nEnter hindi mark:";
//     cin >> mark[4];
//     int sum = 0;
//     for (int i = 0; i < 5; i++)
//     {
//         sum += mark[i];
//     }
//     average = (float)sum / (float)5;
//     mp[average]=roll_no;
//     cout << endl;
// }

// void addData()
// {
//     ofstream fout;
//     fout.open("Students.dat", ios::binary | ios::out | ios::app);
//     s.getData();
//     fout.write((char *)&s, sizeof(s));
//     fout.close();
// }
// void Student::showData()
// {
//     cout << ".......Student Details......\n";
//     cout << "Roll.     : " << roll_no << endl;
//     cout << "Name      : " << name << endl;
//     cout << "Marks: " << endl;
//     for (int i = 0; i < 5; i++)
//     {
//         cout << mark[i] << " ";
//     }
//     cout << endl;
// }

// void top3()
// {
//     if(mp.size()<3)
//     {
//         cout<<"Toppers are not available yet...!!"<<endl;
//         return;
//     }
//     else
//     {
//         int top=1;
//         for(auto it=mp.rbegin();it!=mp.rend() && top<=3;++it)
//         {
//             int n=it->second;
//             int flag=0;
//             ifstream fin;
//             fin.open("Students.dat", ios::in | ios::binary);
//             while (fin.read((char *)&s, sizeof(s)))
//             {
//                 if (n == s.getRoll_No())
//                 {
//                     cout<<"Topper: "<<top<<endl;
//                     s.showData();
//                     flag++;
//                 }
//             }
//             top++;
//             fin.close();
//         }
//     }
// }


// void searchData()
// {
//     int n, flag = 0;
//     ifstream fin;
//     fin.open("Students.dat", ios::in | ios::binary);
//     cout << "Enter Roll Number you want to search : ";
//     cin >> n;

//     while (fin.read((char *)&s, sizeof(s)))
//     {
//         if (n == s.getRoll_No())
//         {
//             cout << "The Details of Roll No. " << n << " shown here with:\n";
//             s.showData();
//             flag++;
//         }
//     }
//     fin.close();
//     if (flag == 0)
//         cout << "The Roll No. " << n << " not found....\n\n";
//     // cout << "\n\nData Reading from File Successfully Done....\n";
// }

// void project()
// {
//     int ch;
//     do
//     {
//         // system("cls");
//         cout << "...............STUDENT MANAGEMENT SYSTEM..............\n";
//         cout << "======================================================\n";
//         cout << "0. Exit from Program\n";
//         cout << "1. Write Student Data to File\n";
//         cout << "2. Read Student Data From File By using Roll no\n";
//         cout << "3. Get Top 3 Students.\n";
//         cout << "Enter your choice  : ";
//         cin >> ch;
//         system("cls");
//         switch (ch)
//         {
//         case 0:
//             exit(0);
//             break;
//         case 1:
//             addData();
//             break;
//         case 2:
//             searchData();
//             break;
//         case 3:
//             top3();
//             break;
//         default:
//             break;
//         }
//         // system("pause");
//     } while (ch);
// }

// int main()
// {
//     std::ofstream ofs;
//     ofs.open("Students.dat", std::ofstream::out | std::ofstream::trunc);
//     ofs.close();
//     project();
// }


#include <bits/stdc++.h>
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
// #define ll long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
// #define mod 1000000007
// #define M 998244353
using namespace std;
#define int long long
// #define debug for(int i=0)
#define endl '\n'

inline void debug(vector<int>&arr)
{
    cout<<"arr: [";
    for(auto it:arr)
    {
        cout<<it<<",";
    }
    cout<<"]";
    cout<<endl;
}

inline void debug(int x)
{
    cout<<x<<endl;
}

inline void debug(int arr[],int n)
{
    cout<<"arr: [";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<"]";
    cout<<endl;
}


int32_t main()
{
// #ifndef ONLINE_JUDGE
//     freopen("inputf.in", "r", stdin);
//     freopen("outputf.out", "w", stdout);
// #endif
    fast();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        unordered_map<int,priority_queue<int>>mp;
        int mx=0;
        vector<bool>visited(1000,false);
        for(int i=0;i<n;i++)
        {
            // cout<<"h"<<endl;
            int a,b;
            cin>>a>>b;
            mx=max(mx,a);
            visited[b]=true;
            mp[a].push(b);
            // cout<<mx<<endl;
        }
        // cout<<"N"<<endl;
        // for(auto it:mp)
        // {
        //     cout<<it.first<<"-->";
        //     while(!it.second.empty())
        //     {
        //         cout<<it.second.top()<<",";
        //         it.second.pop();
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // cout<<mx<<endl;
        string str="";
        int prev=-1;
        int flag=0;
        // cout<<"H"<<endl;
        for(int i=0;i<=mx;i++)
        {
            // cout<<"H"<<endl;
            if(!visited[i])
            {
                str+="R";
            }
            else if(visited[i])
            {
                int x=i;
                int y=mp[i].top();
                // cout<<y<<endl;
                if(y<prev)
                {
                    flag=1;
                    break;
                }
                else if(y>prev)
                {
                    string s(y,'U');
                    // cout<<s<<endl;
                    str+=s;
                }
                else
                {
                    str+='R';
                }
                prev=y;
            }
        }
        if(flag==1)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<str<<endl;
        }
    }
    return 0;
}
