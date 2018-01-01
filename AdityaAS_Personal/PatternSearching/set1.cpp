#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Time Complexity: O(m*(n-m+1)) worst case. I like to think of it as O(n*m) worst case.
// Space complexity: O(1). Input / Output space is not measure in Space Complexity.

// Naive pattern searching.
vector<int> searchNaive(string pattern, string main)
{
	vector<int> occurances;
	int m = pattern.length();
	int n = main.length();
	
	for(int start=0;start<n;start++)
	{
		int j = 0;
		while(j<m && start+j<n && main[start+j] == pattern[j])
		{
			j++;
		}
		if(j==m)
		{
			occurances.push_back(start);
		}
	}
	return occurances;
}

int main(int argc, char const *argv[])
{
	
	vector<int> ans = searchNaive("AABA", "AABAACAADAABAABA");
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << endl;
	}
	return 0;
}