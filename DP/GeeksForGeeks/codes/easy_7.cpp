#include<iostream>
#define maximum(a,b) (a>b?a:b)
#define minimum3(a,b,c) ((a<b && a<c)?a:(b<c?b:c))
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int** arr = new int*[n];
	for(int i=0;i<n;i++)
		arr[i] = new int[n];


	int max =0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			max = maximum(arr[i][j],max);
		}
	}


	for(int i=1;i<n;i++){
		for(int j=1;j<n;j++){
			if(arr[i][j]==1){
				int cnt = 1 + minimum3(arr[i-1][j],arr[i][j-1],arr[i-1][j-1]);
				arr[i][j] = cnt;
				max = maximum(cnt,max);
			}
		}
	}


	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<arr[i][j]<<" ";
		cout<<endl;
	}

	cout<<max<<endl;
	return 0;
}