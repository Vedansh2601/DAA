#include <bits/stdc++.h>
using namespace std;

void floyd(vector<vector<int> >& a,int v)
{
    for(int i = 0;i<v;i++)
    {
        for(int j = 0;j<v;j++)
        {
            if(a[i][j] == -1 && i!= j)
                a[i][j] = INT_MAX;
        }
    }
    
    for(int vi = 0; vi<v;vi++)
    {
        for(int i = 0;i<v;i++)
        {
            for(int j = 0;j<v;j++)
            {
                if (a[i][vi] != INT_MAX && a[vi][j] != INT_MAX)
                {
                    a[i][j] = min(a[i][j], a[i][vi] + a[vi][j]);
                }
            }
        }
    }
    
    for(int i = 0;i<v;i++)
    {
        for(int j = 0;j<v;j++)
        {
            if(a[i][j] == INT_MAX && i!=j)
                a[i][j] = -1;
        }
    }
    cout << endl;
    for(int i = 0;i<v;i++)
    {
        for(int j = 0;j<v;j++)
        {
            cout << a[i][j] <<" ";
        }
        cout << endl;
        
    }
}
int main()
{
    int v;
    cin >> v;
    vector<vector<int> > a(v,vector<int>(v));
    for(int i = 0;i<v;i++)
    {
        for(int j = 0;j<v;j++)
        {
            cin >>a[i][j];
        }
    }
    floyd(a,v);
    return 0;
}
