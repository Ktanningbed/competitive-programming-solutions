#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k,n,m;
    cin>>k>>n>>m;
    vector<pair<int, pii>> edges[n];
    for(int i = 0; i<m; i++){
        int a,b,t,h;cin>>a>>b>>t>>h;
        a--;b--;
        edges[a].push_back({b,{t,h}});
        edges[b].push_back({a,{t,h}});
    }   
    int A,B;cin>>A>>B;
    A--;B--;
    int dist[n][k+1];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<k+1; j++){
            dist[i][j]=1e9;
        }
    }
    priority_queue<pair<int,pii>> q;
    dist[A][0] = 0;
    q.push({A,{0,0}});
    while(!q.empty()){
        pair<int,pii> cur = q.top();
        q.pop();
        if(cur.second.first>dist[cur.first][cur.second.second])continue;
        for(pair<int,pii> edge : edges[cur.first]){
            if(cur.second.second+edge.second.second<k&&dist[edge.first][cur.second.second+edge.second.second]>cur.second.first+edge.second.first){
                dist[edge.first][cur.second.second+edge.second.second]=cur.second.first+edge.second.first;
                q.push({edge.first,{dist[edge.first][cur.second.second+edge.second.second],cur.second.second+edge.second.second}});
            }
        }
    }
    int ans = 1e9;
    for(int i = 0; i<=k; i++){
        // cout<<dist[B][i]<<'\n';
        ans = min(ans, dist[B][i]);
    }
    cout<<(ans==1e9?-1:ans)<<'\n';
}