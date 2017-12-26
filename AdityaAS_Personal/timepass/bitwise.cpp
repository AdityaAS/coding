#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

// Efficient bitwise tricks

// 1. Count number of ones in a number in better than Logn time
int countOnes(int n){
	int count = 0;
	while(n!=0){
		count++;
		n = n&(n-1);
	}
	return count;
}
// 2. Check if a number is a powerOf Four without repeatedly dividing
bool isPowerOfFour(int n){
	return !(n&(n-1)) && (n&0x55555555);
}
// 3. Computer sum of 2 numbers without using arithmetic operators
int getSum(int a, int b){
	if(b==0)return a;
	else{
		getSum( a^b, (a&b)<<1 );
	}
}

// Arrays 1..N consists distinct integers in the range [0,N] Find the number missing from the array in the range [0,N]
int missingNumber(vector<int>& nums)
{
	int mnum = 1;
	for(int i=0;i<nums.size();i++){
		mnum = mnum^nums[i];
		mnum = mnum^i;
	}
	return mnum^nums.size();
}

unsigned int reverseBits1(unsigned int n){
	unsigned int mask = 1 << 31;
	unsigned int res = 0;
	for(int i=0;i<32;i++){
		if(n&1) res = res | mask;
		mask = mask >> 1;
		n = n >> 1;
	} 
	return res;
}

// Find the largest power of 2 (most significant bit in binary form), which is less than or equal to the given number N.
// long largest_power(long N) {
//     //changing all right side bits to 1.
//     N = N | (N>>1);
//     N = N | (N>>2);
//     N = N | (N>>4);
//     N = N | (N>>8);
//     N = N | (N>>16);
//     return (N+1)>>1;
// }

// unsigned int reverseBits2(unsigned int x){
// 	x = ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1);
// 	x = ((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2);
// 	x = ((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4);
// 	x = ((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8);
// 	x = ((x & 0xffff0000) >> 16) | ((x & 0x0000ffff) << 16);

// 	return x;
// }
// int rangeBitwiseAnd(int m, int n) {
//     int a = 0;
//     while(m != n) {
//         m >>= 1;
//         n >>= 1;
//         a++;
//     }
//     return m<<a; 
// }

// Majority Element
// Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times. (bit-counting as a usual way, but here we actually also can adopt sorting and Moore Voting Algorithm)
// Solution
// int majorityElement(vector<int>& nums) {
//     int len = sizeof(int)*8, size = nums.size();
//     int count = 0, mask = 1, ret = 0;
//     for(int i = 0; i < len; ++i) {
//         count = 0;
//         for(int j = 0; j < size; ++j)
//             if(mask & nums[j]) count++;
//         if(count > size/2) ret |= mask;
//         mask <<= 1;
//     }
//     return ret;
// }


//inspired by logical circuit design and boolean algebra;
//counter - unit of 3;
//current   incoming  next
//a b            c    a b
//0 0            0    0 0
//0 1            0    0 1
//1 0            0    1 0
//0 0            1    0 1
//0 1            1    1 0
//1 0            1    0 0
//a = a&~b&~c + ~a&b&c;
//b = ~a&b&~c + ~a&~b&c;
//return a|b since the single number can appear once or twice;
// Single Number III

// Given an array of integers, every element appears three times except for one. Find that single one. (Still this type can be solved by bit-counting easily.) But we are going to solve it by digital logic design

// int singleNumber(vector<int>& nums) {
//     int t = 0, a = 0, b = 0;
//     for(int i = 0; i < nums.size(); ++i) {
//         t = (a&~b&~nums[i]) | (~a&b&nums[i]);
//         b = (~a&b&~nums[i]) | (~a&~b&nums[i]);
//         a = t;
//     }
//     return a | b;
// }


// Maximum Product of Word Lengths

// Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

//     Example 1:
//     Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
//     Return 16
//     The two words can be "abcw", "xtfn".

//     Example 2:
//     Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
//     Return 4
//     The two words can be "ab", "cd".

//     Example 3:
//     Given ["a", "aa", "aaa", "aaaa"]
//     Return 0
//     No such pair of words.

// Solution

// Since we are going to use the length of the word very frequently and we are to compare the letters of two words checking whether they have some letters in common:

//     using an array of int to pre-store the length of each word reducing the frequently measuring process;
//     since int has 4 bytes, a 32-bit type, and there are only 26 different letters, so we can just use one bit to indicate the existence of the letter in a word.

// int maxProduct(vector<string>& words) {
//     vector<int> mask(words.size());
//     vector<int> lens(words.size());
//     for(int i = 0; i < words.size(); ++i) lens[i] = words[i].length();
//     int result = 0;
//     for (int i=0; i<words.size(); ++i) {
//         for (char c : words[i])
//             mask[i] |= 1 << (c - 'a');
//         for (int j=0; j<i; ++j)
//             if (!(mask[i] & mask[j]))
//                 result = max(result, lens[i]*lens[j]);
//     }
//     return result;
// }


// Sets

// All the subsets
// A big advantage of bit manipulation is that it is trivial to iterate over all the subsets of an N-element set: every N-bit value represents some subset. Even better, if A is a subset of B then the number representing A is less than that representing B, which is convenient for some dynamic programming solutions.

// It is also possible to iterate over all the subsets of a particular subset (represented by a bit pattern), provided that you don’t mind visiting them in reverse order (if this is problematic, put them in a list as they’re generated, then walk the list backwards). The trick is similar to that for finding the lowest bit in a number. If we subtract 1 from a subset, then the lowest set element is cleared, and every lower element is set. However, we only want to set those lower elements that are in the superset. So the iteration step is just i = (i - 1) & superset.

// vector<vector<int>> subsets(vector<int>& nums) {
//     vector<vector<int>> vv;
//     int size = nums.size(); 
//     if(size == 0) return vv;
//     int num = 1 << size;
//     vv.resize(num);
//     for(int i = 0; i < num; ++i) {
//         for(int j = 0; j < size; ++j)
//             if((1<<j) & i) vv[i].push_back(nums[j]);   
//     }
//     return vv;
// }


// Bitset

// A bitset stores bits (elements with only two possible values: 0 or 1, true or false, ...).
// The class emulates an array of bool elements, but optimized for space allocation: generally, each element occupies only one bit (which, on most systems, is eight times less than the smallest elemental type: char).

// // bitset::count
// #include <iostream>       // std::cout
// #include <string>         // std::string
// #include <bitset>         // std::bitset

// int main () {
//   std::bitset<8> foo (std::string("10110011"));
//   std::cout << foo << " has ";
//   std::cout << foo.count() << " ones and ";
//   std::cout << (foo.size()-foo.count()) << " zeros.\n";
//   return 0;
// }
        
int divide(int dividend, int divisor) {

    long long n = dividend, m = divisor;
    int sign = n < 0 ^ m < 0 ? -1 : 1;

    n = abs(n), m = abs(m);

    long long q = 0;

    for (long long t = 0, i = 31; i >= 0; i--)
        if (t + (m << i) <= n)
            t += m << i, q |= 1LL << i;

    // assign back the sign
    if (sign < 0) q = -q;

    // check for overflow and return
    return q >= INT_MAX || q < INT_MIN ? INT_MAX : q;
}    

// Modification to incorporates lurker's comment.

int divide2(int numerator, int denominator) 
{
	int mask = 0x1;
	int quotient = 0;
	while (denominator <= numerator) 
	{
		denominator <<= 1;
		mask <<= 1;
	}
	while (mask > 1) 
	{
		denominator >>= 1;
		mask >>= 1;
		if (numerator >= denominator) 
		{
			numerator -= denominator;
			quotient |= mask;
		}
	}
	return quotient;
}

bool isPowerOfTwo (int x)
{
  /* First x in the below expression is for the case when x is 0 */
  return x && (!(x&(x-1)));
}

// Function to calculate xor of numbers 1 to n
long computeXOR(const int n)
{
    switch(n & 3) // n % 4 is same as n & 3. Only suitable for powers of 2 in binary system. 
    {
	    case 0: return n;     // if n is multiple of 4
	    case 1: return 1;     // If n % 4 gives remainder 1  
	    case 2: return n + 1; // If n % 4 gives remainder 2    
	    case 3: return 0;     // If n % 4 gives remainder 3  
    }
}

int main(int argc, char const *argv[])
{
	int a = 0x55555555;
	cout << binary_conversion(a) << endl;
	cout << 'Z' - 'A' << endl;
	return 0;
}