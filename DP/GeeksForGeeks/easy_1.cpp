#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int f0 =1; int f1 =1;
	int f2 = 1;
	n-=2;
	while(n>0){
		f2 = f0+f1;
		f0 = f1;
		f1 = f2;
		n--;
	}
	cout<<f2<<endl;
	return 0;
}