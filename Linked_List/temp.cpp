// #include <bits/stdc++.h>
// using namespace std;

// struct Node
// {
//     int data;
//     Node *next;

//     Node(int val)
//     {
//         data = val;
//         next = NULL;
//     }
// };

// void Insert(Node *&head1, Node *&last, int data)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (last == NULL)
//     {
//         head1 = newNode;
//     }
//     else
//     {
//         last->next = newNode;
//     }
//     last = newNode;
// }

// Node* Reverse(Node *head)
// {
//     Node *curr = head;
//     vector<int> res;
//     while (curr != NULL)
//     {
//         res.push_back(curr->data);
//         curr = curr->next;
//     }
//     int n = res.size();
//     int k = n / 2 - 1;
//     vector<int> ans;
//     int i;
//     for (i = 0; i < k; i++)
//     {
//         ans.push_back(res[i]);
//     }
//     reverse(ans.begin(), ans.end());
//     ans.insert(ans.begin(), res[i++]);
//     ans.insert(ans.begin() + 1, res[i++]);
//     for (i; i < n; i++)
//     {
//         ans.insert(ans.begin(), res[i]);
//     }
//     Node *head1;
//     Node *last = NULL;
//     for (auto it : ans)
//     {
//         Insert(head1, last, it);
//     }
//     return head1;
// }

// int main()
// {
//     int n, num;
//     cin >> n;

//     Node *head, *tail;
//     cin >> num;
//     head = tail = new Node(num);

//     for (int i = 0; i < n - 1; i++)
//     {
//         cin >> num;
//         tail->next = new Node(num);
//         tail = tail->next;
//     }
//     Node* head1=Reverse(head);
//     while(head1!=NULL)
//     {
//         cout<<head1->data<<" ";
//         head1=head1->next;
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;

// int FindMaxSum(int arr[], int n)
// {

//     if (n == 1)
//     {
//         return arr[0];
//     }
//     if (n == 2)
//     {
//         return max(arr[0], arr[1]);
//     }
//     int dp[n + 1];
//     dp[1] = arr[0];
//     dp[2] = max(arr[0], arr[1]);
//     for (int i = 3; i <= n; i++)
//     {
//         dp[i] = max(dp[i - 1], dp[i - 2] + arr[i - 1]);
//     }
//     return dp[n];
// }
// int main()
// {

//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++)
//     {
//         cin>>arr[i];
//     }
//     cout<<FindMaxSum(arr,n)<<endl;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }
    int min=0;
    int max=0;
    for(int j=0;j<n;j++)
    {
        if(j%2==0)
        {
            min+=A[j];
        }
        else
        {
            max+=A[j];
        }
    }
    if(max>=min)
        cout<<max;
    else
        cout<<min;
}