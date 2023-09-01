/*
You have a hypothetical network of distributed systems which can be represented in the form of a two dimensional grid s, consisting of '#' and '.' only, where '#' represents that there is a system at this location.

Two systems located at cells (r1,c1) and (r2, c2) respectively have a connectivity strength equal to abs(r1-r2) + abs(c1-c2).

You need to select a group of systems for your use case such that it meets the following conditions:
• The difference between the column numbers of any two computers in the set should not exceed a gyen integer k.
• The total sum of connectivity strength between all ordered pairs of systems should be maximized.

NOTE: If a set contains only one system, then the connectivity strength of the group is 0.

Input Format
Locked stub code in the editor reads the following input from stdin and passes it to the function:
The first and second line contains 2 integers n & m, denoting the number of rows and columns in grid s.
Each line i of the n subsequent lines (where 1<=i<=n) contains m space- separated character, where jth character describing s[i][j](where 1<=j<=m).
The last line contains integer k.

Constraints:
• 2<=n,m<=1000
• s[i][j] = {'.', '#'}
• 1<=k<m

Output Format
The function must return a long integer denoting the max connectivity strength sum that can be obtained from any one of these groups. This is printed to stdout by locked stub code in the editor.

Sample Input 0:
3
3
Row 1 - . # .
Row 2 - . # .
Row 3 - # . #
2

Sample Output 0:
13

Explanation 0:
The positions of '#' in the grid are - (1,2), (2,2), (3,1), (3,3) [1-based Indexing] and k=2. The optimal case would be to consider all the systems as maximum and minimum column numbers are 3 and 1 respectively and 3 - 1 = 2. The pairs with the connectivity strength between them in this group are :

(1,2), (2,2) -> |2-1|+|2-2| = 1.
(1,2), (3,1) -> |3-1|+|1-2| = 3.
(1,2), (3,3) -> |3-1|+|3-2| = 3.
(2,2), (3,1) -> |2-3|+|2-1| = 2.
(2,2), (3,3) -> |3-2|+|3-2| = 2.
(3,1), (3,3) -> |3-3|+|3-1| = 2.
Therefore the sum is 1+3+3+2+2+2 = 13.
Sample Input 1:
3
4
Row 1 - # # . .
Row 2 - . . # .
Row 3 - . # . #
2

Sample Output 1:
14

Explanation 1:
The positions of '#' in the grid are - (1,1), (1,2), (2,3), (3,2), (3,4) [1-based Indexing] and k is 2. Possible groups:

Group1 connectivity strength sum: 1+3+3+2+2+2 = 13

(1,1), (1,2) -> |1-1|+|2-1| = 1.
(1,1), (2,3) -> |2-1|+|3-1| = 3.
(1,1), (3,2) -> |3-1|+|2-1| = 3.
(1,2), (2,3) -> |2-1|+|3-2| = 2.
(1,2), (3,2) -> |3-1|+|2-2| = 2.
(2,3), (3,2) -> |3-2|+|2-3| = 2.
Group2 connectivity strength sum: 2+2+4+2+2+2 = 14

(1,2), (2,3) -> |2-1|+|3-2| = 2.
(1,2), (3,2) -> |3-1|+|2-2| = 2.
(1,2), (3,4) -> |3-1|+|4-2| = 4.
(2,3), (3,2) -> |3-2|+|2-3| = 2.
(2,3), (3,4) -> |3-2|+|4-3| = 2.
(3,2), (3,4) -> |3-2|+|3-4| = 2.
Group2 has maximum connectivity strength sum which is equal to 14.

Sample Input 2:
2
2
Row 1 - . #
Row 2 - # .
1

Sample Output 2:
2

Explanation 2:
The positions of '#' in the grid are - (1,2), (2,1) [1-based Indexing] and k=1. In this case, there will be only one group(the complete array itself). The systems in this group are:

(1,2), (2,1) -> |2-1|+|1-2| = 2.
Therefore the connectivity strength sum is 2.
*/
