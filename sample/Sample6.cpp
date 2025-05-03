#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void smalestvec(vector<int>& v,int k)
{
    int n = v.size();
    int m,mi;
    for(int i = 0; i < n; i++)
    {
        m = v[i];
        mi = i;
        for(int j = i+1; j < min(n, (i + k + 1)); j++)
        {
            if(v[j] <= m)
            {
                m = v[j];
                mi = j;
            }
        }
        if(mi!=i)
        {
            swap(v[i],v[mi]);
            break;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i<n;i++)
    {
        cin >> v[i];
    }
    int k;
    cin >> k;
    smalestvec(v,k);
    for(int i = 0;i<n;i++)
    {
        cout << v[i] << " ";
    }
}