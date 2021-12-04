// #include<bits/stdc++.h>
// using namespace std;

// int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
//     unordered_map<int, int> counts;
//     vector<int> heap;
//     for (auto n : arr)
//         ++counts[n];
//     for (auto &p: counts)
//         heap.push_back(p.second);
//     make_heap(begin(heap), end(heap), greater<int>());
//     while (k > 0) {
//         k -= heap.front();
//         pop_heap(begin(heap), end(heap), greater<int>());
//         if (k >= 0)
//             heap.pop_back();
//     }
//     return heap.size();
// }
// int main()
// {
//     int n;
//     cin>>n;
//     vector<int>res;
//     for(int i=0;i<n;i++)
//     {
//         int a;
//         cin>>a;
//         res.push_back(a);
//     }
//     int rem;
//     cin>>rem;
//     cout<<findLeastNumOfUniqueInts(res,rem)<<endl;
//     return 0;
// }

// int* replaceValues(int* arr,int len)
// {
//     int i,j;
//     if(len%2==0)
//     {
//         for(i=0;i<len;i++)
//         {
//             arr[i]=0;
//         }
//     }
//     else{
//         for(j=0;j<len;j++)
//         {
//             arr[j]=1;
//         }
//     }
//     return arr;
// }

// int countOccurance(int* arr,int len,int value)
// {
//     int i=0,count=0;
//     while(i<len)
//     {
//         if(arr[i]=value)
//         {
//             count+=1;
//         }
//         i++;
//     }
//     return count;

// }

// char CheckGrade(int score)
// {
//     if(score<=60)
//     {
//         return 'D';
//     }
//     else
//     {
//         if(score>=61 && score<=75)
//         {
//             return 'C';
//         }
//         else
//         {
//             if(score>=76 && score<=90)
//             {
//                 return 'B';
//             }
//             else{
//                 return 'A';
//             }
//         }
//     }

// }

// if(num%2==0)
//     {
//         int i=0;
//         int ct=0;
//         while(ct!=num)
//         {
//             cout<<i<<" ";
//             ct++;
//             i+=2;
//         }
//     }
//     else
//     {
//         int ct=0;
//         int i=1;
//         while(ct!=num)
//         {
//             cout<<i<<" ";
//             i+=2;
//             ct++;
//         }
//     }

#include<bits/stdc++.h>
using namespace std;

// void printCharacterPattern(int n)
// {
//     char ch='a';
//     string str="a";
//     for(int i=0;i<n;i++)
//     {
//         cout<<str<<endl;
//         ch++;
//         str+=ch;
//     }
// }

int most_k_chars(string &s, int k) {
    if (s.size() == 0) {
        return 0;
    }
    unordered_map<char, int> table;
    int num = 0, left = 0;
    for (int i = 0; i < s.size(); i++) {
        table[s[i]]++;
        while (table.size() > k) {
            table[s[left]]--;
            if (table[s[left]] == 0) {
                table.erase(s[left]);
            }
            left++;
        }
        num += i - left + 1;
    }
    return num;
}

int countKDistinctSubstrings(string inputString, int num) {
    return most_k_chars(inputString, num) - most_k_chars(inputString, num - 1);
}

struct ComponentNode
{
    ComponentNode* value;
    vector<ComponentNode*>res;
};

int cNodes(ComponentNode* x) {
    if (x->components.size() == 0) {
        return 1;
    }
    int sum = 0;
    for (auto y: x->components) {
        sum += cNodes(y);
    }
    return 1 + sum;
}
int cValues(ComponentNode* x) {
    if (x->components.size() == 0) {
        return x->value;
    }
    int sum = 0;
    for (auto y: x->components) {
        sum += cValues(y);
    }
    return x->value + sum;
}
boolean isLeaf(ComponentNode* node) {
    return (node->components.size() == 0);
}
boolean AboveLeaf(ComponentNode* node) {
    if (isLeaf(node)) {
        return false;
    }
    for (auto y: node.components) {
        if (y->components.size() != 0) {
            return false;
        }
    }
    return true;
}
double Rate(ComponentNode* node) {
    double count = (1.0 + cNodes(node));
    double value = (node->value + cValues(node));
    return value / count;
}

//Function signature begins...
ComponentNode findMaxNode(ComponentNode* root) {
    if (AboveLeaf(root)) {
        return root;
    }
    ComponentNode* mxNode = root;
    double mxChangeRate = Rate(root);
    for (auto y: node->components) {
        if (!isLeaf(y)) {
            ComponentNode* mxSubNode = findMaxNode(y);
            double subChangeRate = Rate(mxSubNode);
            if (subChangeRate > mxChangeRate) {
                mxChangeRate = subChangeRate;
                mxNode = mxSubNode;
            }
        }
    }
    return mxNode;
}

int main()
{

}

// 2. To check String is palindrome or not
// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string str;
//     cin >> str;
//     int flag = 0;
//     for (int i = 0; i < str.length() / 2; i++)
//     {
//         if (str[i] != str[str.length() - i - 1])
//         {
//             flag = 1;
//             break;
//         }
//     }
//     if (flag)
//     {
//         cout << "String is not palindrome" << endl;
//     }
//     else
//     {
//         cout << "String is Palindrome" << endl;
//     }
//     return 0;
// }