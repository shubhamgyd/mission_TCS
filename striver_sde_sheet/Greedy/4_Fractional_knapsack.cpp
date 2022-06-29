/*
Approach: 

The greedy method to maximize our answer will be to pick up the items with higher values. 
Since it is possible to break the items as well we should focus on picking up items having 
higher value /weight first. To achieve this, items should be sorted in decreasing order with 
respect to their value /weight. Once the items are sorted we can iterate. Pick up items with 
weight lesser than or equal to the current capacity of the knapsack. In the end, 
if the weight of an item becomes more than what we can carry, break the item 
into smaller units. Calculate its value according to our current capacity and add this 
new value to our answer.
*/

#include <bits/stdc++.h>

using namespace std;

struct Item {
   int value;
   int weight;
};
class Solution {
   public:
      bool static comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }
   // function to return fractionalweights
   double fractionalKnapsack(int W, Item arr[], int n) {

      sort(arr, arr + n, comp);

      int curWeight = 0;
      double finalvalue = 0.0;

      for (int i = 0; i < n; i++) {

         if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalvalue += arr[i].value;
         } else {
            int remain = W - curWeight;
            finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
            break;
         }
      }

      return finalvalue;

   }
};
int main() {
   int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}

// Time Complexity: O(n log n + n). O(n log n) to sort the items and O(n) to iterate through all the items for calculating the answer.
// Space Complexity: O(1), no additional data structure has been used.