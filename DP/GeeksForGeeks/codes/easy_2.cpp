#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	int combination[n+1][k+1];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0 || j==i)
				combination[i][j]=1;
			else
				combination[i][j] = combination[i-1][j]+combination[i-1][j-1];
			// cout<<i<<" "<<j<<" "<<combination[i][j]<<endl;
		}
	}
	cout<<combination[n][k]<<endl;
	return 0;
}