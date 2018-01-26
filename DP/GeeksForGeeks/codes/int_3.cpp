#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int m,n;
	cin>>m>>n;
	vector< vector<int> > arr;
	for(int i=0;i<m;i++){
		vector<int> temp;
		int t;
		for(int i=0;i<n;i++){
			cin>>t;
			temp.push_back(t);
		}
		arr.push_back(temp);
	}

	bool foundBlock = false;


	for(int j=0;j<n;j++){
		if(foundBlock == true){
			arr[0][j]=0;
		}
		else{
			if(arr[0][j]==-1){
				arr[0][j]=0;
				foundBlock = true;
			}
			else
				arr[0][j]=1;
		}
	}


	foundBlock = false;

	for(int i=0;i<m;i++){
		if(foundBlock == true)
			arr[i][0]=0;
		else{
			if(arr[i][0]==-1){
				arr[i][0]=0;
				foundBlock = true;
			}
			else
				arr[i][0]=1;
		}
	}


	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			if(arr[i][j]==-1)
				arr[i][j]=0;
			else{
				arr[i][j]=arr[i-1][j]+arr[i][j-1];
			}
		}
	}


	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

	cout<<arr[m-1][n-1]<<endl;
	return 0;
}
