#include <bits/stdc++.h>
#include<vector>
using namespace std;
int position(vector<int>& arr, int l,int h)
{
	int x =  rand()%(h+l-1)+l;
    swap(arr[x],arr[h]);
    int p = arr[h];
	int i = l-1,j = l;
	for(j = l; j < h; j++)
	{
		if(arr[j] < p)
        {
			swap(arr[++i],arr[j]);
        }
	}
	swap(arr[i+1],arr[h]);
	return(i+1);
}
void qsort(vector<int>& arr,int l,int h)
{
	if(l<h)
	{
	    int pi = position(arr,l,h);
	    qsort(arr,l,pi-1);
	    qsort(arr,pi+1,h);
	}
}
int main()
{
    vector<int> arr = {23,65,21,76,46,89,45,32};
    qsort(arr,0,7);
    for(int i : arr)
        cout << i <<" ";
}