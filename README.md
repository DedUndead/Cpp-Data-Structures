# Little-Cpp-Solutions
There are the solutions to C++ tasks I find interesting.

### Sum of two Integers 

<b>Filename</b>: TwoSum.cpp / Twosum.txt <br><br>
In short, we need to find two integers from sorted integer array such that they sum up to given X. <br>
I came up with the solution to reduce number of iterations to <b>[1; N/2 + 1]</b> <br>
The solution is simple, but interesting and performing. I reckon it is not unique and may be found in someone else's interpretation, but my implementation can be seen in "Solutions" folder. 

* Create to pointers: one pointing to the last element, another to the first
* If their sum > X, move the right pointer to the left
* Else, move the left pointer to the right
* If right == left, then there is no such pair in the array

In the worst case scenario, when the pair is not found, maximum number of iterations is N/2 + 1.
