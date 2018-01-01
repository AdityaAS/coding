#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Knuth Morris Pratt Pattern Searching Algorithm - KMP Algorithm
// Time Complexity: O(n+m) worst case.
// Space Complexity: O(m) - for the auxillary array

// n - Length of text
// m - Length of pattern being searched

vector<int> makeAuxArray(string pattern)
{
	vector<int> array;
	array.resize(pattern.size());
	array[0] = 0;
	int j=0;
	int i=1;
	while(i < pattern.size())
	{
		if(pattern[i] == pattern[j])
		{
			array[i] = j+1;
			i++;
			j++;
		}
		else
		{
			if(j>0)j = array[j-1];
			if(j==0)i++;
		}
	}
	return array;
}

vector<int> searchKMP(string pattern, string main)
{
	int m = pattern.length();
	int n = main.length();
	vector<int> temp = makeAuxArray(pattern);
	vector<int> occurances;
	int i=0, j=0;
	while(i < n)
	{
		if(j < m && main[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			// Why j-1? If you don't know the answer to this, you don't know KMP
			if(j>0)j = temp[j-1];
			else i++;
		}

		if(j==m)
		{
			occurances.push_back(i-m);
		}
	}
	return occurances;
}


int main(int argc, char const *argv[])
{
	vector<int> ans = searchKMP("abcaby", "abxabcabcaby");
	for(int i=0;i<ans.size();i++)
	{
		cout << ans[i] << endl;
	}
	return 0;
}