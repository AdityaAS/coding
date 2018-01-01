#include <iostream>
#include <string>
#include <vector>
using namespace std;

// When there are no repeating characters in the pattern, we can improve the naive pattern matching algorithm to come up 
// with a better algorithm

// What is this algorithms complexity?
// Time Complexity: O(n) worst case. I like to think of it as O(n*m) worst case.
// Space complexity: O(1). Input / Output space is not measure in Space Complexity.

// Naive pattern searching enhanced

vector<int> searchNaiveEnhanced(string pattern, string main)
{
	vector<int> occurances;
	int m = pattern.length();
	int n = main.length();
	int j;
	for(int start=0;start<n;)
	{
		j = 0;
		while(j<m && start+j<n && main[start+j] == pattern[j])
		{
			j++;
		}
		if(j==m)
		{
			occurances.push_back(start);
		}

		if(j==0)start++;
		else{
			start+=j;
		}
	}
	return occurances;
}

int main(int argc, char const *argv[])
{
	vector<int> ans = searchNaiveEnhanced("ABC", "AABCAACAADAABAABA");
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << endl;
	}
	return 0;
}