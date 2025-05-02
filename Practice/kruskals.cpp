#include <bits/stdc++.h>
using namespace std;

int findp(int s,vector<int>& parent)
{
    if(s == parent[s])
        return s;
    else
        return parent[s] = findp(parent[s],parent);
}

void uniong(int s,int d,vector<int>& parent,vector<int>& rank)
{
    int sp = findp(s,parent);
    int dp = findp(d,parent);
    if(rank[sp] > rank[dp])
    {
        parent[dp] = sp;
    }
    else if(rank[sp] < rank[dp])
    {
        parent[sp] = dp;
    }
    else
    {
        parent[dp] = sp;
        rank[sp]++;
    }
}

vector<pair<int,pair<int,int> > > kruskals(vector<pair<int,pair<int,int> > > g, int e, int v)
{
    vector<pair<int,pair<int,int> > > sol;
    sort(g.begin(),g.end());
    vector<int> parent(v);
    vector<int> rank(v,0);
    int ec = 0;
    for(int i = 0;i<v;i++)
    {
        parent[i] = i;
    }
    for(int i =0;(i<e) && (ec < v-1);i++)
    {
        int s = g[i].second.first , d = g[i].second.second;
        if(findp(s,parent) != findp(d,parent))
        {
            sol.push_back(g[i]);
            uniong(s,d,parent,rank);
            ec++;
        }
    }
    return sol;
}
int main()
{
    int v,e;
    cin >> v >> e;
    vector<pair<int,pair<int,int> > > g(e);
    for(int i = 0; i<e; i++)
    {
        cin >> g[i].first >> g[i].second.first >> g[i].second.second;
    }
    vector<pair<int,pair<int,int> > > sol = kruskals(g,e,v);
    for(int i = 0;i<v-1;i++)
    {
        cout << sol[i].first <<" "<< sol[i].second.first <<" "<< sol[i].second.second << endl;
    }
}