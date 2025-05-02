#include<iostream>
#include<vector>
using namespace std;
bool checkcycle(int n,vector<vector<int> > g,vector<bool>& visited, vector<bool> path)
{
    visited[n] = true;
    path[n] = true;
    for(int e : g[n])
    {
        if(!visited[e])
        {
           if(checkcycle(e,g,visited,path))
            return true;
        }
        else if(path[e] == true)
            return true;
    }
    return false;
}
bool isCyclic(vector<vector<int> > g, int v)
{
    vector<bool> visited(v,false);
    vector<bool> path(v,false);
    for(int i = 0;i<v;i++)
    {
        if(!visited[i])
        {
            if(checkcycle(i,g,visited,path))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n,e;
    cin >> n;
    cin >> e;
    vector< vector<int> > g(n);
    for(int i = 0;i<e;i++)
    {
        int s,d;
        cin >> s >> d;
        g[s].push_back(d);
    }
    if(isCyclic(g,n))
    {
        cout << "cyclic";
    }
    else
        cout << "Not cyclic";
}