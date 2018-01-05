#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int N;
	cin>>N;
	int* dp = new int[N+1];

	for(int i=1;i<=N;i++)
		dp[i] =0;
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<=N;i++){
		for(int left=0;left<=i;left++){
			dp[i] = dp[i] + (dp[i-left]*dp[left]);
		}
	}
	cout<<dp[N]<<endl;
	return 0;
}