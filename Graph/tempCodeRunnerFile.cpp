// Intuition behind this problem is,
//1. First we check the connectivity of all nodes present in the graph
//.....a) Means we apply dfs on graph and check wheather it is connected or not means if any list of node is not 
//      visited then this graph is not eulerian graph
//.....b) After that we count the degree of each node  ..i.e odd gegree means nodes which have odd number of incoming and outgoing edges
//      if odd==0---> except end nodes Graph is Eulerian Graph (Eulerian Circuit)
//      if odd==1---> Graph is Semi-Eulerain  (Eulerain Path)
//      if odd>2 ---> Not Eulerain Graph