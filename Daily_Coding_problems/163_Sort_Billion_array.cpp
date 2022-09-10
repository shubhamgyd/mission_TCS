/*
This problem was asked by Amazon.

Given an array of a million integers between zero and a billion, out of order, 
how can you efficiently sort it? Assume that you cannot store an array of a billion elements in memory.
*/

/*
If you get a question like this, they are not looking for the answer. What they are trying 
to do is see how you think through a problem. Do you jump right in, or do you ask questions
 about the project requirements?

One question you had better ask is, "How optimal of solution does the problem require?" 
Maybe a bubble sort of records stored in a file is good enough, but you have to ask. 
Ask questions about what if the input changes to 64 bit numbers, should the sort process 
be easily updated? Ask how long does the programmer have to develop the program.

Those types of questions show me that the candidate is wise enough to see there is more 
to the problem than just sorting numbers.



Ans: 2
Use bit map. You need some 500 Mb to represent whole 32-bit integer range.
 For every integer in given array just set coresponding bit. Then simply scan your 
 bit map from left to right and get your integer array sorted.
*/