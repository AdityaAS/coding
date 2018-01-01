#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Rabin Karp Pattern Searching Algorithm - RKP Algorithm
// Time Complexity: O(mn) worst case, O(m+n) average case
// Space Complexity: O(1)

// n - Length of text
// m - Length of pattern being searched
int prime = 101;

// Is there a possibility of overflow in this code? During the calculation of the hash value / rehash value
long long hash(string str, int end)
{
	long long hash = 0;
	for(int i=0;i<end;i++)
	{
		hash += str[i]*pow(prime, i);
	}
	return hash;
}

long long rehash(string str, int oldindex, int newindex, long oldHash, int patternLength)
{
	long long hash = oldHash - str[oldindex];
	hash = hash / prime;
	hash = hash + str[newindex]*pow(prime, patternLength-1);
	return hash;
}

bool equal(string main, int startm, int endm, string pattern, int startp, int endp)
{
	if(endm - startm != endp - startp)
	{
		cout << "Error!!" << endl;
        return false;
    }
    while(startm < endm && startp < endp)
    {
        if(main[startm] != pattern[startp])
        {
            return false;
        }
        startm++;
        startp++;
    }
	return true;
}

vector<int> searchRKP(string pattern, string main)
{
	vector<int> occurances;
	int m = pattern.length();
	int n = main.length();
	long long patternHash = hash(pattern, m);
	long long mainHash = hash(main, m);
	int i = 0;
	while(i <= n - m + 1)
	{
		if( patternHash == mainHash && equal(main, i, i + m, pattern, 0, m) )
		{
			occurances.push_back(i);
		}
		mainHash = rehash(main, i, i + m, mainHash, m);
		i++;
	}
	return occurances;
}

int main(int argc, char const *argv[])
{

	vector<int> ans = searchRKP("AABA", "AABAACAADAABAABA");
	for(int i=0; i<ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}