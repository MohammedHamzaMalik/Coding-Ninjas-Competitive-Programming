/*
METEOR GARDEN
Send Feedback
Ninja owns a garden which is in a rectangular shape on a planet named ‘Asgard’. He somehow manages to get information that his garden is the target of the coming meteor which is in a circular shape and ninja knows the radius and the coordinates of the center of the circle so he wants to know whether the meteor will overlap with his garden or not.
So your task is to check whether the meteor will overlap with the garden or not. You were provided with the coordinates of the bottom left corner and top right corner of the garden which is rectangular in shape and the center coordinates and radius of a meteor which is circular in shape.
Note :
If any point of the circle lies on the rectangle or inside the rectangle we say the circle is overlapping the rectangle.
Input Format :
The first line contains an integer 'T' which denotes the number of test cases or queries to be run.

The first line of each test case contains seven space-separated integers ‘xC’, ‘yC’, ‘RAD’, ‘X1’, ‘Y1’, ‘X2’, ‘Y2’ where ‘xC’ and ‘yC’ represents the center coordinates of a circle and ‘RAD’ represents the radius of the circle and ‘X1’, ‘Y1’ represents the coordinates of the bottom left corner and ‘X2’, ‘Y2’ represents the coordinates of the top right corner of the rectangle respectively.
Output Format :
For each test case, print a single line containing ‘True’ if the meteor overlaps with the garden else, print ‘False’.
The output of each test case will be printed in a separate line.
Note :
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 5
1 <= RAD <= 2000
-10^4 <= xC, yC, X1, Y1, X2, Y2 <= 10^4
X1 < X2, Y1 < Y2

Where ‘T’ is the number of test cases, ‘xC’ and ‘yC’ represents the center coordinates of a circle and ‘RAD’ represents the radius of the circle and ‘X1’, ‘Y1’ represents the coordinates of the bottom left corner and ‘X2’, ‘Y2’ represents the coordinates of the top right corner of the rectangle.

Time Limit: 1 sec
Sample Input 1 :
2
0 0 2 1 0 3 2
0 0 1 1 -1 3 1
Sample Output 1 :
True
True
Explanation for sample input 1 :
Test Case 1 :
Example

As you can observe the radius of the circle is ‘2’ and according to their coordinates, we can say they will collapse so we return ‘True’ as the answer.

Test Case 2 :
Example

As you can see in the picture there is a common point (1, 0) that lies both on the circle and rectangle so we return ‘True’ for this case.
Sample Input 2 :
1
0 0 1 3 2 6 4
Sample Output 2 :
False
Explanation for sample input 2 :
Test Case 1:
Example

As you can observe, rectangles and circles have no common points so we can say they will not collapse so we return ‘False’ as the answer.
*/



/*
    Time complexity: O(1)
    Space complexity: O(1) 
*/

bool meteorGarden(int xC, int yC, int rad, int x1, int y1, int x2, int y2) 
{
	// Using formula for finding nearest point.
	int xN = max(x1, min(xC, x2));
	int yN = max(y1, min(yC, y2));
	
	// Checking whether distance is smaller than or equal to radius or not.
	if( ( (xC - xN) * (xC - xN) ) + ( (yC - yN) * (yC - yN) ) <= (rad * rad))
	{
		return true;
	}
	
	// If distance is greater than radius.
	else
	{
		return false;
	}
}
