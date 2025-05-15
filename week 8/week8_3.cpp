#include <bits/stdc++.h>
using namespace std;

void prims(vector<vector<pair<int,int> > > g,int v)
{
    priority_queue<pair<int,int> > pq;
    
    vector<bool> visited(v,false);
    
    int weight = 0;
    
    pq.push({0,0});
    while(!pq.empty())
    {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        if(visited[u] == true)
            continue;
        visited[u] = true;
        weight += w;
        for (auto edge : g[u])
        {
            int c = edge.first;
            int wt = edge.second;
            if(!visited[c])
            {
                pq.push({wt,c});
            }
        }
    }
    cout <<"Maximum sapnning weight: " <<weight;
}
int main()
{
    int v,e;
    cin >> v >> e;
    vector<vector<pair<int,int> > > g(v);
    for(int i = 0; i<e;i++)
    {
        int s,d,w;
        cin >> s >> d >> w;
        g[s].push_back({d,w});
        g[d].push_back({s,w});
    }
    prims(g,v);
}