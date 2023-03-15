#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
int n,m,p,q;
int parent[2][100001];
struct edge{
    int a,b;
    ll c;
    int d;
    friend bool operator<(edge &a, edge &b){
        return a.c < b.c;
    }
};
vector<edge> edges;
int findParent(int i, int v){
    if(parent[i][v] == v)return v;
    return parent[i][v] = findParent(i,parent[i][v]);
}
bool isConnected(int i, int a, int b){
    return findParent(i,a)==findParent(i,b);
}
void connect(int i, int a, int b){
    parent[i][findParent(i,a)] = findParent(i,b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m>>p>>q;
    ll total = 0;
    for(int i = 0; i<p; i++){
        int a,b;ll c;cin>>a>>b>>c;
        total+=c*n;
        edges.push_back((edge){a,b,c,0});
    }
    for(int i = 0; i<q; i++){
        int a,b;ll c;cin>>a>>b>>c;
        total+=c*m;
        edges.push_back((edge){a,b,c,1});
    }
    for(int i = 0; i<100001; i++){
        parent[0][i] = i;
        parent[1][i] = i;
    }
    sort(edges.begin(), edges.end());
    int cnt[2]; cnt[0]=0;cnt[1]=0;
    ll mst = 0;
    for(auto cur : edges){
        // cout<<cur.a<<" "<<cur.b<<" "<<cur.c<<" "<<cur.d<<'\n';
        if(cnt[0]==n-1&&cnt[1]==m-1)break;
        if(!cur.d&&cnt[0]==m-1)continue;
        if(cur.d&&cnt[1]==n-1)continue;
        if(!cur.d&&!isConnected(1,cur.a,cur.b)){
            connect(1,cur.a,cur.b);
            mst+=(n-cnt[1])*cur.c;
            cnt[0]++;
        }
        if(cur.d&&!isConnected(0,cur.a,cur.b)){
            connect(0,cur.a,cur.b);
            mst+=(m-cnt[0])*cur.c;
            cnt[1]++;
        }
    }
    cout<<total-mst<<'\n';
}