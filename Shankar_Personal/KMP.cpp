// Knuth Morris Pratt Algorithm
#include<iostream>
using namespace std;

int* getPattern(string pattern){
	int length = pattern.length();
	int* patternArr = new int[length];

	patternArr[0]=0;
	int i=1;
	int j=0;

	while(i<pattern.length()){
		if(pattern[i]==pattern[j]){
			patternArr[i++] = ++j;
		}
		else{
			if(j>0){
				j = patternArr[j-1];
			}
			else{
				patternArr[i++] =0;
				j=0;
			}
		}
	}

	return patternArr;
}

int main(int argc, char const *argv[])
{
	/* code */
	string input;
	string pattern;


	cin>>input;
	cin>>pattern;

	int* patternArr = getPattern(pattern);

	int i=0;
	int j=0;


	int index =-1;

	while(i<input.length()){
		if(input[i]==pattern[j]){
			i++;
			j++;
			if(j==pattern.length()){
				index = (i-pattern.length());
				break;
			}
		}
		else{
			if(j>0){
				j = patternArr[j-1];
			}
			else{
				i++;
				j=0;
			}
		}
	}

	cout<<"Index :: "<<index<<endl;
	return 0;
}

