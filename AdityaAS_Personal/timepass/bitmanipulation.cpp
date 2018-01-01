#include <iostream>
#include <climits>

using namespace std;


int countOnes(int n)
{
	// Count the number of ones in the boolean representation of a number....
	// Logic: The difference between n and n-1 is that
	// 		-> All the numbers upto (not including) the right most 1 are same between n and n-1 and all the numbers to the right of the right most one (including) are complements
	// Complexity  = O(k) where k is the number of ones in the number.
	int count = 0;
	while(n!=0)
	{
		n = n & (n-1);
		count++;
	} 
	return count;
}

// bool isPowerOfFour(){

// }

// int getSum(int a, int b){

// }

// int missingNumber(vector<int>& A){

// }

// int reverseBits(int a){

// }

// // Given a range [m, n] where 0 <= m <= n <= 2147483647, 
// // return the bitwise AND of all numbers in this range, inclusive. For example, given the range [5, 7], you should return 4.
// int rangeBitwise(int m, int n){

// }

// int hammingWeight(int n){

// }

int main(int argc, char const *argv[])
{
	cout << (4 ^ (4|~4)) +1 << endl;
	cout << (4 ^ 0) << endl;
	
	return 0;
}