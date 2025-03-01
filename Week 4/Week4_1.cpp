#include<iostream>
using namespace std;
void merge(int arr[],int l, int m, int r,int& count)
{
	int n1 = (m-l+1), n2 = r-m;
	int L[n1], R[n2];
	int k = l;
	for(int i = 0; i < n1; i++)
	{
		L[i] = arr[l+i];
	}
	for(int i = 0; i < n2; i++)
	{
		R[i] = arr[m+1+i];
	}
	int i = 0, j =0;
	while(i < n1 && j < n2)
	{
		count++;
		if(L[i] < R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	while(i<n1)
		arr[k++] = L[i++];
	while(j<n2)
		arr[k++] = R[j++];
}
void mergesort(int arr[],int l,int r,int& count)
{
	if(l<r)
	{
		int m = l + (r-l)/2;
		mergesort(arr,l,m,count);
		mergesort(arr,m+1,r,count);
		merge(arr,l,m,r,count);
	}
}
int main()
{
	int arr[8] = {23,65,21,76,46,89,45,32};
	int count = 0;
	mergesort(arr,0,7,count);
	for(int i : arr)
		cout << i << " ";
	cout << "\n" << count;
}
