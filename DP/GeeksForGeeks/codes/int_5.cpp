#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
	int n,k;
	cin>>n>>k;
	int **arr = new int*[n+1];
	for(int i=0;i<=n;i++){
		arr[i] = new int[k+1];
	}

	arr[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(j==0){
				arr[i][j] =0;
			}
			else if(j>i){
				arr[i][j]=0;
			}
			else{
				arr[i][j] = (j*arr[i-1][j]) + arr[i-1][j-1];
			}

			// cout<<i<<" "<<j<<" "<<arr[i][j]<<endl;
		}
	}

	cout<<arr[n][k]<<endl;
	return 0;
}