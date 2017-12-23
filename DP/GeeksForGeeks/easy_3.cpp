#include<iostream>
using namespace std;
#define maximum(a,b,c) ((a>b && a>c)?a:(b>c)?b:c)
int main(int argc, char const *argv[])
{
	
	string str1,str2;
	cin>>str1>>str2;
	int m = str1.length();
	int n = str2.length();

	int lcs[m+1][n+1];
	for(int j=0;j<=n;j++)
		lcs[m][j]=0;
	for(int i=0;i<=m;i++)
		lcs[i][n]=0;

	for(int i=m-1;i>=0;i--){
		for(int j=n-1;j>=0;j--){
			if(str1[i] == str2[j]){
				lcs[i][j] = 1+ lcs[i+1][j+1];
			}
			else
				lcs[i][j] = lcs[i+1][j+1];
			lcs[i][j] = maximum(lcs[i][j],lcs[i+1][j],lcs[i][j+1]);
		}
	}
	cout<<lcs[0][0]<<endl;
	return 0;
}