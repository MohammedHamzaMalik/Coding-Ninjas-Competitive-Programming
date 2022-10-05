/*
Game of Nim
Send Feedback
Game of Nim Rules :
1. Given a number of piles,each pile contains some numbers of stones. 
2. The players take alternate turns. If the bitwise XOR of all piles equals 0 before a player's turn, then that player wins the game.
3. In his/her turn, a player must choose one of the remaining piles and remove it. (Note that if there are no piles, that player already won.)
Decide which player wins, given that both play optimally.
Input Format :
Line 1 : n, the number of piles.
Line 2 : n space-separated integers a1,..,an - the sizes of piles.
Output Format :
print "First" ( if the first player wins) or "Second" (if the second player wins).
Constraints :
1 ≤ N ≤ 1000
1 ≤ ai ≤ 1000
Sample Input 1:
3
2 3 1
Sample Output 1:
First
Sample Input 2:
3 
2 3 3
Sample Output 2:
second
*/



void findWinner(int * piles, int n ){
	//code - here
	int xorSum=0;
    
    //Taking Xor of all piles
    for(int i=0;i<n;i++){
        xorSum^=piles[i];
    }
    if(xorSum!=0){
        // return 1;
        cout<<"First"<<endl;
    }
    // else return 0;
    else cout<<"Second"<<endl;
}
