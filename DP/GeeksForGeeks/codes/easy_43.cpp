#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int *arr = new int[n+1];
	arr[1]=1;
	arr[2]=2;

	for(int i=3;i<=n;i++){
		arr[i] = arr[i-1]+arr[i-2]*(i-1);
	}

	cout<<arr[n];
}