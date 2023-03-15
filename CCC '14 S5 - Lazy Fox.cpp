#include <bits/stdc++.h>
using namespace std;
#define ppi pair<int, pair<int,int>>
int dist(ppi a, ppi b) {
  int x = a.second.first-b.second.first, y = a.second.second-b.second.second;
  return x*x+y*y;
}
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin>>n;
  ppi points[n+1];
  points[0] = {0,{0,0}};
  vector<ppi> dis;
  for(int i = 1; i<=n; i++) {
    int a,b;
    cin>>a>>b;
    points[i] = {0,{a,b}};
  }
  for(int i = 0; i<=n; i++) {
    for(int j = i+1; j<=n; j++) {
      if(i!=j) {
        int d = dist(points[i],points[j]);
        dis.push_back({d,{i,j}});
      }
    }
  }
  sort(dis.begin(), dis.end());
  vector<vector<int>> dp(n+1,vector<int> (3,0)); 
  for(auto i : dis) {
    if(dp[i.second.first][2]!=i.first) {
      dp[i.second.first][2] = i.first;
      dp[i.second.first][1] = dp[i.second.first][0];
    }
    if(dp[i.second.second][2]!=i.first) {
      dp[i.second.second][2] = i.first;
      dp[i.second.second][1] = dp[i.second.second][0];
    }
    if(i.second.first==0) {//ending point, must end here
      dp[0][0] = max(dp[0][0], dp[i.second.second][1]);
    }
    else {
      dp[i.second.first][0] = max(dp[i.second.second][1]+1,dp[i.second.first][0]);
      dp[i.second.second][0] = max(dp[i.second.first][1]+1,dp[i.second.second][0]);
    }
  }
  cout<<dp[0][0]+1<<'\n';

}