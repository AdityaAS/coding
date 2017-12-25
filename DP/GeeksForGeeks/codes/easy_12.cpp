#include<iostream>
using namespace std;

int maximum(int a,int b){
	return a>b?a:b;
}

int main(int argc, char const *argv[])
{
	
	int N;
	cin>>N;
	int* prices = new int[N];
	for (int i = 0; i < N ; ++i)
	{
		cin>>prices[i];
	}

	int* dp = new int[N+1];
	dp[0] = 0;
	for(int i=1;i<=N;i++)
		dp[i]=0;

	for(int j=1;j<=N;j++){
		for (int i = j; i<=N; ++i)
		{
			if((i-j)>=0){
				dp[i] = maximum(dp[i],dp[i-j]+prices[j-1]);
			}
		}
	}

	for (int i = 0; i <=N; ++i)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	cout<<dp[N];
	return 0;
}