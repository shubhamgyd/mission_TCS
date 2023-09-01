// // #include <bits/stdc++.h>
// // using namespace std;

// // vector<pair<int, int>> resort;

// // priority_queue<int, vector<int>, greater<int>> nums[10];
// // int used[30001];
// // int n;
// // int getSum(int index)
// // {
// //     int sum = 0;
// //     while (index > 0)
// //     {
// //         sum += used[index];
// //         index -= index & (-index);
// //     }
// //     return sum;
// // }

// // void updateBIT(int index, int val)
// // {
// //     while (index <= n)
// //     {
// //         used[index] += val;
// //         index += index & (-index);
// //     }
// // }

// // string minInteger(string num, int k)
// // {
// //     memset(used, 0, sizeof(used));

// //     int ctr = 0;
// //     n = num.size();
// //     for (int i = 0; i < n; i++)
// //     {
// //         nums[num[i] - '0'].push(i + 1);
// //     }
// //     string res;
// //     while (ctr < n && k > 0)
// //     {
// //         for (int i = 0; i <= 9; i++)
// //         {
// //             if (!nums[i].empty())
// //             {
// //                 int cur = nums[i].top();

// //                 int holes = getSum(cur - 1);
// //                 int act = cur - holes;
// //                 if (act - 1 <= k)
// //                 {
// //                     res += ('0' + i);
// //                     k -= (act - 1);
// //                     updateBIT(cur, 1);
// //                     nums[i].pop();
// //                     break;
// //                 }
// //             }
// //         }
// //         ctr++;
// //     }

// //     for (int i = 0; i <= 9; i++)
// //     {
// //         while (!nums[i].empty())
// //         {
// //             resort.emplace_back(nums[i].top(), i);
// //             nums[i].pop();
// //         }
// //     }

// //     sort(resort.begin(), resort.end());
// //     for (auto &p : resort)
// //     {
// //         res += ('0' + p.second);
// //     }
// //     return res;
// // }

// // int main()
// // {
// //     string str;
// //     cin >> str;
// //     int k;
// //     cin >> k;
// //     cout << minInteger(str, k) << endl;
// // }



// #include <bits/stdc++.h>
// using namespace std;

// vector<pair<int, int>> resort;

// priority_queue<int, vector<int>, greater<int>> nums[10];
// int used[30001];
// int n;
// int getSum(int index)
// {
//     int sum = 0;
//     while (index > 0)
//     {
//         sum += used[index];
//         index -= index & (-index);
//     }
//     return sum;
// }

// void updateBIT(int index, int val)
// {
//     while (index <= n)
//     {
//         used[index] += val;
//         index += index & (-index);
//     }
// }

// string minInteger(string num, int k)
// {
//     memset(used, 0, sizeof(used));

//     int ctr = 0;
//     n = num.size();
//     for (int i = 0; i < n; i++)
//     {
//         nums[num[i] - '0'].push(i + 1);
//     }
//     string res;
//     while (ctr < n && k > 0)
//     {
//         for (int i = 0; i <= 9; i++)
//         {
//             if (!nums[i].empty())
//             {
//                 int cur = nums[i].top();

//                 int holes = getSum(cur - 1);
//                 int act = cur - holes;
//                 if (act - 1 <= k)
//                 {
//                     res += ('0' + i);
//                     k -= (act - 1);
//                     updateBIT(cur, 1);
//                     nums[i].pop();
//                     break;
//                 }
//             }
//         }
//         ctr++;
//     }

//     for (int i = 0; i <= 9; i++)
//     {
//         while (!nums[i].empty())
//         {
//             resort.emplace_back(nums[i].top(), i);
//             nums[i].pop();
//         }
//     }

//     sort(resort.begin(), resort.end());
//     for (auto &p : resort)
//     {
//         res += ('0' + p.second);
//     }
//     return res;
// }

// int main()
// {
//     string str;
//     cin >> str;
//     int k;
//     cin >> k;
//     cout << minInteger(str, k) << endl;
// }


#include <bits/stdc++.h>
using namespace std;


void print(vector<int>&arr, int n)
{
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
	cout << endl;
}

void swapMax(vector<int>&arr, int target_position,int current_position)
{
	int aux = 0;
	for (int i = current_position;
		i > target_position; i--) {
		aux = arr[i - 1];
		arr[i - 1] = arr[i];
		arr[i] = aux;
	}
}

void maximizeArray(vector<int>&arr,int length, int swaps)
{

	if (swaps == 0)
		return;


	for (int i = 0; i < length; i++) {
		int max_index = 0, max = INT_MIN;

		int limit = (swaps + i) > length ?length : swaps + i;

		for (int j = i; j <= limit; j++) {
			if (arr[j] > max) {
				max = arr[j];
				max_index = j;
			}
		}
		swaps -= (max_index - i);
		swapMax(arr, i, max_index);

		if (swaps == 0)
			break;
	}
}

// Driver code
int main()
{
    int num;
    cin>>num;
    int swaps;
    cin>>swaps;
    vector<int>arr;
    int cnt=0;
    while(num)
    {
        int rem=num%10;
        num/=10;
        arr.push_back(rem);
        cnt++;
    }
    reverse(arr.begin(),arr.end());
	// int arr[] = { 1,2,3,4};
	// int length = sizeof(arr) / sizeof(int);
	// int swaps = 2;
	maximizeArray(arr, cnt, swaps);

	print(arr, cnt);

	return 0;
}
