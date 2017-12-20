#include <iostream>
#include <vector>

using namespace std;
int main(int argc, char const *argv[])
{
	int k;
	cin >> k;
	
	vector<int> A;
	
	while(k--){
		int t;
		cin >> t;
		A.push_back(t);
	}

	//Insertion Sort begins...
	for(int i=1; i<A.size(); i++)
	{
		
		int temp = A[i];
		int j = i-1;

		while(j>=0 && temp < A[j])
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = temp;
	}
    
    for(int i=0;i<A.size();i++){
    	cout << A[i] << " ";
    }
    cout << endl;
}