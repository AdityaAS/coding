#include<iostream>

using namespace std;


int read(int index, int *tree){
	int sum =0;
	while(index>0){
		sum += tree[index];
		index -= ((-index)&index);
	}
	return sum;
}

void update(int index,int *tree,int length, int value){

	while(index<=length){
		tree[index] +=value;
		index += (index & -index);
		// cout<<index<<endl;
	}
}

int readSingle(int index, int *tree){
	int sum = tree[index];
	if(index>0){
		int z = index -(index &(-index));
		index--;
		while(index!=z){
			sum -=tree[index];
			index -= (index &(-index));
		}
	}
	return sum;
}

void scale(int scaleFactor, int *tree, int length){

	for (int i = 0; i < length; ++i)
	{
		tree[i] = tree[i]*scaleFactor;
	}
}

int getBitMask(int length){
	if(length ==0)
		return 0;

	int bit =1;
	while((bit<<1)<=length){
		bit = bit<<1;
	}
	return bit;
}

int find(int cumFre,int *tree,int length){
	int bitMask = getBitMask(length);
	int index =0;
	while(bitMask!=0 && index<length){
		int tIdx = index + bitMask;
		if(tree[tIdx] == cumFre)
			return tIdx;
		if(cumFre>tree[tIdx]){
			index = tIdx;
			cumFre -= tree[tIdx];
		}

		bitMask = bitMask>>1;
	}

	if(cumFre!=0)
		return -1;
	return index;
}

int main(int argc, char const *argv[])
{
	int maxLength = 10;
	int *freq = new int[maxLength];
	int *tree = new int[maxLength+1];

	for (int i = 0; i <=maxLength; ++i)
	{
		tree[i]=0;
	}

	for(int i=0;i<maxLength;i++){
		freq[i] = i+1;
		update(i+1,tree,maxLength,freq[i]);
	}
	int sum =0;
	for (int i = 0; i < maxLength; ++i)
	{
		sum += freq[i];
		cout<<sum<<" ";
	}
	cout<<endl;

	for (int i = 0; i < maxLength; ++i)
	{
		cout<<read(i+1,tree)<<" ";
	}
	cout<<endl;

	cout<<"Finding 15 in "<<find(15,tree,maxLength)<<endl;
	cout<<"Finding 16 in "<<find(16,tree,maxLength)<<endl;

	return 0;
}
