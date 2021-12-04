// #include<bits/stdc++.h>
// using namespace std;


// struct ComponentNode
// {
//     ComponentNode* x;
// };

// int countNodes(ComponentNode* x) {
//     if (x->components.size() == 0) {
//         return 1;
//     }
//     int sum = 0;
//     for (auto y: x->components) {
//         sum += countNodes(y);
//     }
//     return 1 + sum;
// }
// int countValues(ComponentNode* x) {
//     if (x->components.size() == 0) {
//         return x->value;
//     }
//     int sum = 0;
//     for (auto y: x->components) {
//         sum += countValues(y);
//     }
//     return x->value + sum;
// }
// boolean isLeaf(ComponentNode* node) {
//     return (node->components.size() == 0);
// }
// boolean isJustAboveLeaf(ComponentNode* node) {
//     if (isLeaf(node)) {
//         return false;
//     }
//     for (auto y: node.components) {
//         if (y->components.size() != 0) {
//             return false;
//         }
//     }
//     return true;
// }
// double avgChangeRate(ComponentNode* node) {
//     double count = (1.0 + countNodes(node));
//     double value = (node->value + countValues(node));
//     return value / count;
// }

// //Function signature begins...
// ComponentNode findMaxNode(ComponentNode* root) {
//     if (isJustAboveLeaf(root)) {
//         return root;
//     }
//     ComponentNode* maxNode = root;
//     double maxChangeRate = avgChangeRate(root);
//     for (auto y: node->components) {
//         if (!isLeaf(y)) {
//             ComponentNode* maxSubNode = findMaxNode(y);
//             double subChangeRate = avgChangeRate(maxSubNode);
//             if (subChangeRate > maxChangeRate) {
//                 maxChangeRate = subChangeRate;
//                 maxNode = maxSubNode;
//             }
//         }
//     }
//     return maxNode;
// }
