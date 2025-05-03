#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int maxdishes(vector<int>& Arr) 
{
    unordered_map<int,int>count;
    for (int dish:Arr) 
    {
        count[dish]++;
    }
    vector<int>freq;
    for (auto& pair:count) 
    {
        freq.push_back(pair.second);
    }
    sort(freq.begin(),freq.end(),greater<int>());
    int maxEaten = 0;
    for (int start=0;start<freq.size();start++) 
    {
        int total=0;
        int cur=freq[start];
        for (int i=start;i<freq.size() && cur>0;i++) 
        {
            if (freq[i]>=cur) 
            {
                total+=cur;
                cur*=2; 
            } 
            else
            break;
        }
        maxEaten=max(maxEaten,total);
    }
    return maxEaten;
}
int main() 
{
    int N;
    cin>>N;
    vector<int>Arr(N);
    for (int i=0;i<N;i++) 
    {
        cin>>Arr[i];
    }
    cout<<maxdishes(Arr)<<endl;
    return 0;
}