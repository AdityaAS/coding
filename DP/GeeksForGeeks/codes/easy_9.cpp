#include<iostream>
using namespace std;

int minimum(int a,int b,int c){
	return (a<b && a<c)?a:(b<c?b:c);
}

int main(int argc, char const *argv[])
{
	int m,n;
	cin>>m>>n;
	int **arr = new int*[m];
	int **dp = new int*[m];
	for(int i=0;i<m;i++){
		arr[i] = new int[n];
		dp[i] = new int[n];
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin>>arr[i][j];
			dp[i][j] = arr[i][j];
		}
	}

	for(int j=1;j<n;j++)
		dp[0][j] = dp[0][j-1]+arr[0][j];

	for(int i=1;i<n;i++)
		dp[i][0] = dp[i-1][0]+arr[i][0];

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			dp[i][j] = arr[i][j] + minimum(dp[i-1][j],dp[i][j-1],dp[i-1][j-1]);
		}
	}


	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<dp[m-1][n-1]<<endl;

	return 0;
}