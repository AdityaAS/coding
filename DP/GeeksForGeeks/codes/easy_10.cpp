#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	
	int N;
	cin>>N;
	int numberOfCoins;
	cin>>numberOfCoins;
	int* coins = new int[numberOfCoins];
	for (int i = 0; i < numberOfCoins; ++i)
	{
		cin>>coins[i];
	}

	int* dp = new int[N+1];
	dp[0] = 1;
	for(int i=1;i<=N;i++)
		dp[i]=0;

	for(int j=0;j<numberOfCoins;j++){
		for (int i = 1; i <= N; ++i)
		{
			if((i-coins[j])>=0){
				dp[i] = dp[i] + dp[i-coins[j]];
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