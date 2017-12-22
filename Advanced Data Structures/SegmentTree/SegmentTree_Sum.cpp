#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

//All ranges are inclusive.

void initialize(int node, int start, int end, int* M, int* A)
{
  if(start > end)return;

  if (start == end) //leaf
      M[node] = A[start];
  else
  {
      initialize(2 * node, start, (start + end) / 2, M, A);
      initialize(2 * node + 1, (start + end) / 2 + 1, end, M, A);

      M[node] = M[node*2] + M[2*node + 1];
  }
} 

int getSum(int node, int start, int end, int rstart, int rend, int* M)
{
   if(start > end)return 0;

	if(rend < start || rstart > end) return 0;

	if(start == end)return M[node];

	int a = getSum(2*node, start, (start+end)/2, rstart, rend, M);
	return a + getSum(2*node+1, (start+end)/2 + 1, end, rstart, rend, M);
}

void update(int node, int start, int end, int index, int value, int* M)
{
	if(start > end)return;

	if(index < start || index > end)return;

	if(start==end){
		M[node]=value;
		return;
	}

  update(2 * node, start, (start + end) / 2, index,value, M);
  update(2 * node + 1, (start + end)/2 + 1, end, index,value, M);

  M[node] = M[node*2] + M[2*node + 1];

}

void printSegmentTree(int node, int start, int end, int* M)
{
	if(start > end)return;

	cout << start << "-" << end << "\t" << M[node] << "\t" << node << endl;
	if(start == end)return;
	printSegmentTree(2*node, start, (start+end)/2, M);
	printSegmentTree(2*node+1, (start+end)/2 + 1, end, M);
}

int main(int argc, char const *argv[])
{

	int asize = 10;
	int msize = 2*pow(2, ceil(log2(asize))) - 1;

	int* A = (int*)malloc(sizeof(int)*asize+1);
	for(int i=1;i<=asize;i++)A[i] = i;

	//Array representation of the Tree
	int* M = (int*)malloc(sizeof(int)*msize+1);
	for(int i=1;i<=msize;i++)M[i] = -1;

	initialize(1, 1, asize, M, A);

	printSegmentTree(1, 1, asize, M);

	cout << getSum(1, 1, asize, 3, 8, M) << endl;

	update(1, 1, asize, 1, 5, M);
	cout << "update" << endl;
	printSegmentTree(1, 1, asize, M);


	return 0;
}