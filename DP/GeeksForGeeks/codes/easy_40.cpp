#include<iostream>
using namespace std;

int maximum(int a,int b){
	return a>b?a:b;
}

int main(int argc, char const *argv[])
{
	int N;
	cin>>N;
	int *arr = new int[N];
	int *lis = new int[N];
	int *lds = new int[N];

	for(int i=0;i<N;i++){
		cin>>arr[i];
		// cout<<arr[i]<<" ";
	}

	cout<<endl;

	lis[0] = arr[0];

	// cout<<lis[0]<<" ";

	for(int i=1;i<N;i++){
		lis[i]=0;
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]){
				lis[i] = maximum(lis[i],lis[j]);
			}
		}

		lis[i] = lis[i]+arr[i];

		// cout<<lis[i]<<" ";
	}

	// cout<<endl;

	lds[N-1]=arr[N-1];
	// cout<<lds[N-1]<<" ";

	for(int i=N-2;i>=0;i--){
		lds[i]=0;
		for(int j=i+1;j<N;j++){
			if(arr[i]>arr[j]){
				lds[i] = maximum(lds[i],lds[j]);
			}
		}

		lds[i] = lds[i]+arr[i];

		// cout<<lds[i]<<" ";
	}

	for (int i = N-2; i>=0; --i)
	{
		lds[i] = maximum(lds[i],lds[i+1]);
	}

	// cout<<endl;

	int max =0;
	for(int i=0;i<N-1;i++){
		int sum = lis[i]+lds[i+1];
		max = maximum(max,sum);
	}

	cout<<max<<endl;
	return 0;
}