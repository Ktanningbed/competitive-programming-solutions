#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
int a[3001], b[101];
int n,m;
int dp[3001][2][101][101];
int recurse(int idx, int good, int l, int r){
    if(dp[idx][good][l][r]!=-1)return dp[idx][good][l][r];
    if(idx==n){
        if(l<=r){
            if(good){
                return dp[idx][good][l][r]=b[r]+recurse(idx,0,l,r-1);
            }
            return dp[idx][good][l][r] = recurse(idx,1,l+1,r);
        }
        return dp[idx][good][l][r] = 0;
    }
    if(good){
        dp[idx][good][l][r] = max(recurse(idx,0,l,r), a[idx]+recurse(idx+1,0,l,r));
        if(l<=r)dp[idx][good][l][r] = max(b[r]+recurse(idx,0,l,r-1),dp[idx][good][l][r]);
    }
    else{
        dp[idx][good][l][r] = recurse(idx+1,1,l,r);
        if(l<=r){
            dp[idx][good][l][r] = max(dp[idx][good][l][r], recurse(idx,1,l+1,r));
        }
    }
    return dp[idx][good][l][r];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i = 0; i<n; i++){
        cin>>a[i];
    }
    cin>>m;
    for(int i = 0; i<m; i++){
        cin>>b[i];
    }
    sort(b,b+m);
    memset(dp,-1,sizeof dp);
    cout<<recurse(0,1,0,m-1)<<'\n';
}