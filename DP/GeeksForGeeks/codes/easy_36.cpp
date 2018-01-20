#include<iostream>
#include<vector>
using namespace std;


int main(int argc, char const *argv[])
{
	int N,temp,K;
	cin>>N;
	cin>>K;
	vector<int> arr;
	vector<int> dp(N,0);
	for(int i=0;i<N;i++){
		cin>>temp;
		arr.push_back(temp);
	}

	sort(arr.begin(), arr.end());
	dp[0] = 0;
	if((arr[1]-arr[0])<K)
		dp[1] = arr[1]+arr[0];
	else
		dp[1]=0;
	int val;

	for(int i=2;i<N;i++){
		if((arr[i]-arr[i-1])<K){
			dp[i] = dp[i-2]+(arr[i]+arr[i-1]);
		}
		else
			dp[i] = dp[i-1];
	}

	cout<<dp[N-1]<<endl;

	return 0;
}