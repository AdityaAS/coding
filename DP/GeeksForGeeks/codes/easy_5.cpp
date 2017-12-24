#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int* arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int sum =0;
	int maxSum = 0;
	for(int i=0;i<n;i++){
		sum +=arr[i];
		if(sum>0){
			if(maxSum<sum)
				maxSum = sum;
		}
		else{
			sum =0;
		}
	}

	cout<<maxSum<<endl;
	return 0;
}