/*
For piegon hole principle we have to check first the value of each componen


Pigeonhole principle strong form –

Theorem: Let q1, q2, . . . , qn be positive integers.
If q1+ q2+ . . . + qn – n + 1 objects are put into n boxes, then either the 1st box contains at 
least q1 objects, or the 2nd box contains at least q2 objects, . . ., 
the nth box contains at least qn objects.
 
Application of this theorem is more important, so let us see how we apply this theorem 
in problem solving.

Example – 1: In a computer science department, a student club can be formed with either 10 
members from first year or 8 members from second year or 6 from third year or 4 from final year.
 What is the minimum no. of students we have to choose randomly from department to ensure that
a student club is formed?


Solution: we can directly apply from the above formula where,
q1 =10, q2 =8, q3 =6, q4 =4 and n=4
Therefore the minimum number of students required to ensure department club to be formed is
10 + 8 + 6 + 4 – 4 + 1 = 25



Example – 2: 
A box contains 6 red, 8 green, 10 blue, 12 yellow and 15 white balls. 
What is the minimum no. of balls we have to choose randomly from the box to ensure that we get
9 balls of same color?

Solution: 
Here in this we cannot blindly apply pigeon principle. First we will see what happens 
if we apply above formula directly.
From the above formula we have get answer 47 because 6 + 8 + 10 + 12 + 15- 5 + 1 = 47
But it is not correct. In order to get the correct answer we need to include only blue, 
yellow and white balls because red and green balls are less than 9. But we are picking randomly
 so we include after we apply pigeon principle.
i.e., 9 blue + 9 yellow + 9 white – 3 + 1 = 25
Since we are picking randomly so we can get all the red and green balls before the above 25 
balls. Therefore we add 6 red + 8 green + 25 = 39
We can conclude that in order to pick 9 balls of same color randomly, one has to pick 39 balls 
from a box.



Remember here , while making the commitee and while chooseing the balls from the bag


.. ....variation

*/