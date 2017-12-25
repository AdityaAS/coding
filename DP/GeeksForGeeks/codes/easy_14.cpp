#include<iostream>
#include<climits>
using namespace std;

int minimum(int a,int b){
	return a<b?a:b;
}

int main(int argc, char const *argv[])
{
	int N;
	cin>>N;
	int* arr = new int[N];
	int* dp = new int[N];
	for(int i=0;i<N;i++){
		cin>>arr[i];
		dp[i]=INT_MAX;
	}
	dp[0]=0;

	for(int i=0;i<N;i++){
		int jumps = arr[i];
		for(int j=1;j<=jumps;j++){
			dp[i+j] = minimum(dp[i+j],1+dp[i]);
		}
	}

	cout<<dp[N-1]<<endl;
	return 0;
}