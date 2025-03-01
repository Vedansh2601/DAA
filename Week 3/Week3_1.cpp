#include<iostream>
using namespace std;
void insort(int a[], int n, int &c, int &s)
{
	int i,j,temp;
	c = 0;
	s = 0;
	for(i=1;i<n;i++)
	{
		temp = a[i];
		j = i-1;
		while(j >= 0 && a[j] > temp)
		{
			a[j+1] = a[j--];
			c++;
			s++;
		}
		a[j+1] = temp;
		s++;
	}
}
int main()
{
	int a[20],x,n,c,s;
	cout << "Enter no of arrays - ";
	cin >> x;
	for(int i = 0; i < x; i++)
	{
		c=0;
		s=0;
		cout << "Enter size of " << (i+1) << " array - ";
		cin >> n;
		cout << "Enter elements - ";
		for(int j = 0; j < n; j++)
		{
			cin >> a[j];
		}
		insort(a,n,c,s);
		cout << "Sorted array - ";
		for(int j = 0; j < n; j++)
		{
			cout << a[j] << " ";
		}
		cout << "\nComparision - " << c;
		cout << "\nShifts - " << s <<"\n";
	}
}
