#include<iostream>
using namespace std;

int maximum(int a,int b){
	return a>b?a:b;
}

int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	int *lis = new int[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
		lis[i]=1;
	}

	int ones =0;
	int twos =0;

	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i])
				lis[i]= maximum(lis[i],lis[j]+1);
		}

		if(lis[i]==1)
			ones++;
		else if(lis[i]==2)
			twos++;
	}

	for(int i=0;i<n;i++){
		cout<<lis[i]<<" ";
	}

	cout<<endl;

	int diff = ones-twos;

	cout<<diff<<endl;
}