#include<iostream>
using namespace std;

int minimum(int a,int b){
	return a<b?a:b;
}

int main(int argc, char const *argv[])
{
	int N,W;
	cin>>N;
	cin>>W;

	int* cost = new int[N+1];
	int* dp = new int[W+1];

	for(int i=1;i<=N;i++)
		cin>>cost[i];

	for(int i=0;i<=W;i++)
		dp[i] =-1;

	dp[0]=0;
	for(int i=1;i<=N;i++){
		for(int w=0;w<=W;w++){
			int value = i+w;
			if(value>W)
				break;
			if(dp[w]!=-1){
				if(dp[value]==-1)
					dp[value] = dp[w]+cost[i];
				else
					dp[value]= minimum(dp[value],dp[w]+cost[i]);
			}
		}
	}

	cout<<dp[W]<<endl;
	return 0;
}