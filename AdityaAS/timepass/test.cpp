#include <iostream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int getMSD(int a)
{
    while(a/10 != 0){
        a = a/10;
    }
    return a;
}

string largestNumber(vector<int>& nums) 
{
    vector< vector<int> > buckets(10);
    string result  = "";
    for(int i=0; i<nums.size(); i++)
    {
        int x = getMSD(nums[i]);
        buckets[x].push_back(nums[i]);
    }
    
    for(int i=buckets.size()-1;i>=0;i--)
    {
        for(int j=0;j<buckets[i].size();j++)result = result + to_string(buckets[i][j]);    
    }
    
    return result;

}


int main(int argc, char const *argv[])
{
	// cout << getMSD(944577322) << endl;
	vector<int> a;
	a.push_back(10);
	a.push_back(9);
	a.push_back(20);
	a.push_back(22);
	a.push_back(58);

	cout << largestNumber(a) << endl;

	return 0;
}
