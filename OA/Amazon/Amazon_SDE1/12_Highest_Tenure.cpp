// #include<bits/stdc++.h>
// using namespace std;

// Sol: 1
// struct Employee
// {
//     int val;
//     vector<Employee*>();
// };

// pair<int, int> rec(Employee *curr, pair<float, Employee*> &best) {
//     int sum = curr->val, divisor = 1;

//     if (curr->child.size() == 0)
//         return {curr->val, 1};
//     for (auto c: curr->child) {
//         auto tmp = rec(c, best);
//         sum += tmp.first;
//         divisor += tmp.second;
//     }

//     double mean = (double)sum / divisor;

//     if (best.first < mean)
//         best = {mean, curr};
//     return {sum, divisor};
// }

// Employee *highestTenure(Employee *curr) {
//     pair<float, Employee *> c = {0, curr};
//     rec(curr, c);
//     return c.second;
// }

#include <bits/stdc++.h>
using namespace std;




// Sol :2 
// struct Node
// {
//     int data;
//     vector<Node *> child;
//     Node(int k)
//     {
//         data = k;
//     }
// };
// struct ary
// {
//     int sze;
//     int total;
//     ary(int s, int c)
//     {
//         sze = s;
//         total = c;
//     }
// };
// double ans = 0;
// ary solve(Node *root)
// {
//     if (root == NULL)
//         return ary(0, 0);
//     ary children(0, 0);
//     vector<int>sum;
//     vector<int>cnt;
//     for (auto ch : root->child)
//     {
//         children = solve(ch);
//         cnt.push_back(children.sze);
//         sum.push_back(children.total);
//     }
//     if (children.sze == 0 && children.total == 0)
//         return ary(1, root->data);
//     float c = 1;
//     int s = root->data;
//     for (int i = 0; i < sum.size(); ++i)
//     {
//         c += cnt[i];
//         s += sum[i];
//     }

//     double temp = s / c;
//     ans = max(ans, temp);
//     return ary(c, s);
// }
// int main()
// {
//     Node *root = new Node(20);
//     (root->child).push_back(new Node(12));
//     (root->child).push_back(new Node(18));
//     (root->child[0]->child).push_back(new Node(11));
//     (root->child[0]->child).push_back(new Node(2));
//     (root->child[0]->child).push_back(new Node(3));
//     (root->child[1]->child).push_back(new Node(15));
//     (root->child[1]->child).push_back(new Node(8));
//     solve(root);
//     cout << ans;
//     return 0;
// }




// Sol :3
// struct EmployeeNode {
//     int val;
//     vector<EmployeeNode*> children;
//     explicit EmployeeNode(int v) : val(v) {}
// };

// pair<double, int> FindMaxTenure(EmployeeNode* employee, pair<double, int>& max_team_tenure) {
//     // recursion base-case, the employee isn't manager
//     if (employee->children.size() == 0) {
//         return {employee->val, 1.0};
//     }

//     int total_tenure = employee->val;
//     int total_employees = 1;

//     // iterate through the manager employees and keep track of total tenure and total employees
//     for (int i = 0; i < employee->children.size(); ++i) {
//         auto [tenure, employees] = FindMaxTenure(employee->children[i], max_team_tenure);
//         total_tenure += tenure;
//         total_employees += employees;
//     }

//     // calculate team tenure
//     double avg = total_tenure / static_cast<double>(total_employees);

//     // check if team tenure is higher than current max tenure
//     if (avg > max_team_tenure.first) {
//         max_team_tenure.first = avg;
//         max_team_tenure.second = employee->val;
//     }
//     return {total_tenure, total_employees};
// }

// int GetMaxTeamTenure(EmployeeNode* employee) {
//     pair<double, int> max_team_tenure {/* tenure = */ 0, /* manager = */ 0};
//     FindMaxTenure(employee, max_team_tenure);
//     return max_team_tenure.second;
// }

// EmployeeNode* MakeEmploymentTree() {
//     auto tree = new EmployeeNode(20);
//     tree->children.emplace_back(new EmployeeNode(12));
//     tree->children[0]->children.emplace_back(new EmployeeNode(11));
//     tree->children[0]->children.emplace_back(new EmployeeNode(2));
//     tree->children[0]->children.emplace_back(new EmployeeNode(3));
//     tree->children.emplace_back(new EmployeeNode(18));
//     tree->children[1]->children.emplace_back(new EmployeeNode(15));
//     tree->children[1]->children.emplace_back(new EmployeeNode(8));
//     return tree;
// }

// int main() {
//     auto president = MakeEmploymentTree();
//     cout << GetMaxTeamTenure(president) << '\n';
//     return 0;
// }




// Sol :4
struct Node {
    int val;
    vector<Node *> employees;
    Node(int v) : val(v) {};
    Node(int v, vector<Node*> e) : val(v), employees(e) {};
};

class Solution {
private:
    pair<int, Node*> oldest; // mean, node
    pair<int, int> rec(Node *head) {
        if (head->employees.size() == 0)
            return {head->val, 1};
        
        int cnt = 0, n = 0;
        for (int i = 0; i < head->employees.size(); i++) {
            pair<int, int> r = rec(head->employees[i]);
            cnt += r.first;
            n += r.second;
        }
        oldest = (oldest.first < (cnt/n) ? make_pair(cnt/n, head) : oldest);
        return {cnt, n};
    }
public:
    Node* findHighestTenure(Node *president) {
        oldest = make_pair(INT_MIN, new Node(0));
        rec(president);
        return oldest.second;
    }
};