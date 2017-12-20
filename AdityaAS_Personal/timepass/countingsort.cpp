#include <iostream>
#include <vector>

using namespace std;

/*
Input:
Range
Number of Elements
Element1 Element2 Element3 Element4 . . . . . . . 
*/
int main(int argc, char const *argv[])
{
	
	int range;
	cin >> range;
	
	int k;
	cin >> k;
	
	vector<int> v;
	
	while(k--){
		int t;
		cin >> t;
		v.push_back(t);
	}
    
    int counts[range] = {0};

    for(int i=0;i<v.size();i++){
    	counts[v[i]]++;
    }

    for(int i=0;i<range;i++){
    	while(counts[i] != 0){
    		cout << i << " ";
    		counts[i]--;
    	}
    }
    
    cout << endl;
	return 0;
}