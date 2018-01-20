#include<iostream>
using namespace std;

int maximum(int a,int b,int c){
	return (a>b && a>c)?a:(b>c?b:c);
}

int main(int argc, char const *argv[])
{
	string str1,str2,str3;
	cin>>str1;
	cin>>str2;
	cin>>str3; 

	int m = str1.length();
	int n = str2.length();
	int o = str3.length();

	int ***arr = new int**[m+1];

	for(int i=0;i<m+1;i++){
		arr[i] = new int*[n+1];

		for(int j=0;j<=n;j++)
			arr[i][j] = new int[o+1];
	}

	for(int j=0;j<=n;j++){
		for(int k=0;k<=o;k++){
			arr[m][j][k] =0;
		}
	}

	for(int i=0;i<=m;i++){
		for(int k=0;k<=o;k++){
			arr[i][n][k] =0;
		}
	}

	for(int j=0;j<=n;j++){
		for(int i=0;i<=m;i++){
			arr[i][j][o] =0;
		}
	}

	for(int i=m-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			for(int k=o-1;k>=0;k--){
				if(str1[i]==str2[j] && str2[j]==str3[k]){
					arr[i][j][k] = 1 +arr[i+1][j+1][k+1];
				}
				else{
					arr[i][j][k] = maximum(arr[i+1][j][k],arr[i][j+1][k],arr[i][j][k+1]);
				}
			}
		}
	}
	cout<<arr[0][0][0]<<endl;
	return 0;
}