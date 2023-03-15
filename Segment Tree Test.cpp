#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
vector<int> arr(100000);
map<int, vector<int>> mapp;
struct node{
    int m,g;
};
vector<node> seg(500001);
int gcd (int a, int b) {
    return b ? gcd (b, a % b) : a;
}
void build(int l, int r, int v){
    if(l==r){
        mapp[arr[l]].push_back(l);
        seg[v].g = arr[l];
        seg[v].m = arr[l];
        return;
    }
    int mid = (l+r)/2;
    build(l,mid,v*2);
    build(mid+1,r,v*2+1);
    seg[v].m = min(seg[v*2+1].m,seg[v*2].m);
    seg[v].g = gcd(seg[v*2].g,seg[v*2+1].g);
}
void update(int l, int r, int v, int idx, int val){
    if(r<idx||l>idx)return;
    if(l==r){
        mapp[seg[v].m].erase(find(mapp[seg[v].m].begin(), mapp[seg[v].m].end(),l));
        seg[v].m = val;
        seg[v].g = val;
        mapp[val].push_back(l);
        return;
    }
    int mid = (l+r)/2;
    update(l,mid,v*2,idx,val);
    update(mid+1,r,v*2+1,idx,val);
    seg[v].m = min(seg[v*2+1].m,seg[v*2].m);
    seg[v].g = gcd(seg[v*2+1].g,seg[v*2].g);
}
int queryM(int l, int r, int v, int mi, int ma){
    if(r<mi||l>ma)return (int)1e10;
    if(mi<=l&&ma>=r){
        return seg[v].m;
    }
    int mid = (l+r)/2;
    return min(queryM(l,mid,v*2,mi,ma),queryM(mid+1,r,v*2+1,mi,ma));
}
int queryG(int l, int r, int v, int mi, int ma){
    if(r<mi||l>ma)return -1;
    if(mi<=l&&ma>=r)return seg[v].g;
    int mid = (l+r)/2;
    int a = queryG(l,mid,v*2,mi,ma), b = queryG(mid+1,r,v*2+1,mi,ma);
    if(a==-1||b==-1)return max(a,b);
    else return gcd(a,b);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;cin>>n>>m;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    build(0,n-1,1);
    for(int i = 0; i<m; i++){
        char a;int l,r;
        cin>>a>>l>>r;
        switch(a){
            case 'C':
                update(0,n-1,1,l-1,r);
                break;
            case 'M':
                cout<<queryM(0,n-1,1,l-1,r-1)<<'\n';
                break;
            case 'G':
                cout<<queryG(0,n-1,1,l-1,r-1)<<'\n';
                break;
            case 'Q':
                int gcd = queryG(0,n-1,1,l-1,r-1);
                int cnt = 0;
                for(auto j : mapp[gcd]){
                    if(j>=l-1&&j<=r-1){
                        cnt++;
                    }
                }
                cout<<cnt<<'\n';
                break;
        }
    }
}