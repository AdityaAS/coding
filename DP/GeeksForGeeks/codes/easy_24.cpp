#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int N,rhs;
	cin>>N;
	int* coeff = new int[N];
	for(int i=0;i<N;i++)
		cin>>coeff[i];
	cin>>rhs;
	int* dp = new int[rhs+1];
	dp[0]=1;
	for(int j=1;j<=rhs;j++)
		dp[j]=0;
	for(int i=0;i<N;i++){
		for(int j=1;j<=rhs;j++){
			int val = j-coeff[i];
			if(val>=0){
				dp[j] += dp[val];
			}
		}
	}
	cout<<dp[rhs]<<endl;
	return 0;
}