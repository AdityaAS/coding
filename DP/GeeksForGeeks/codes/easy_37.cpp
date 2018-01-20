#include<iostream>
#include<vector>
using namespace std;

int maximum(int a,int b,int c){
	return (a>b && a>c)?a:(b>c?b:c);
}

int main(int argc, char const *argv[])
{
	int N,temp;
	cin>>N;
	vector<int> arr;
	vector<int> dp(N,0);
	for(int i=0;i<N;i++){
		cin>>temp;
		arr.push_back(temp);
	}

	dp[0] = arr[0];
	dp[1] = maximum(arr[1],dp[0],arr[0]+arr[1]);
	dp[2] = maximum(arr[2],dp[1],arr[1]+arr[2]);

	for(int i=3;i<N;i++){

		//dnt select dp[i-1]
		//select then two cases dp[i-3] + arr[i-1]+arr[i], or dp[i-2]+arr[i]
		dp[i] = maximum(dp[i-1],dp[i-3]+arr[i]+arr[i-1],dp[i-2]+arr[i]);
	}
	cout<<dp[N-1]<<endl;
	return 0;
}