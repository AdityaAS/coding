#include<iostream>
using namespace std;

int minimum(int a,int b,int c){
	return (a<b && a<c)?a:((b<c)?b:c);
}

int main(int argc, char const *argv[])
{
	/* code */
	int n;
	cin>>n;

	int *arr = new int[n+1];
	arr[1]=0;
	arr[2]=1;
	arr[3]=1;

	for(int i=4;i<=n;i++){
		int min1 = INT_MAX;
		int min2 = INT_MAX;
		int min3 = INT_MAX;

		if(i%2==0){
			min1 = arr[i/2];
		}
		if(i%3==0)
			min2 = arr[i/3];

		min3 = arr[i-1];

		arr[i] = minimum(min1,min2,min3)+1;
	}

	cout<<arr[n]<<endl;
	return 0;
}