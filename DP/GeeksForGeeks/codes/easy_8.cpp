#include<iostream>
using namespace std;

int maximum(int a,int b){
	return a>b?a:b;
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int* arr = new int[n];
	int* lis = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		lis[i]=1;
	}
	int max =1;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j])
				lis[i] = maximum(lis[i],1+lis[j]);
		}

		max = maximum(max,lis[i]);
	}
	cout<<max<<endl;
	return 0;
}