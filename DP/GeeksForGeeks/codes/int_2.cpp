#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	string str;
	cin>>str;
	int count[26];
	for(int i=0;i<26;i++)
		count[i]=0;

	int i=0;
	int start =0;
	int max =0;	

	while(i<str.length()){
		int index = str[i]-65;
		count[index]++;
		if(count[index]>1){

			int length = i-start;
			if(length>max)
				max =length;

			char ch = str[i];

			while(str[start]!=ch){
				int ind = str[start]-65;
				count[ind]--;
				start++;
			}
			start++;
			count[index]--;
		}
		i++;
	}

	int length = i-start;
	if(length>max)
		max =length;

	cout<<max<<endl;

	return 0;
}