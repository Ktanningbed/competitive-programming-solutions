#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,T;cin>>n>>T;
    ll box[n][5];
    set<ll> x,y;
    map<ll,ll> mx,my,xx,yy;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<5; j++){
            cin>>box[i][j];
        }
        x.insert(box[i][0]);x.insert(box[i][2]);
        y.insert(box[i][1]);y.insert(box[i][3]);
    }
    int idxx = 0, idxy = 0;
    for(auto i:x){//c
        xx[idxx] = i;
        mx[i] = idxx++;
    }
    for(auto i:y){//r
        yy[idxy] = i;
        my[i] = idxy++;
    }
    for(int i = 0; i<n; i++){
        box[i][0] = mx[box[i][0]];//c
        box[i][1] = my[box[i][1]];//r
        box[i][2] = mx[box[i][2]];//c
        box[i][3] = my[box[i][3]];//r
    }
    ll diff[idxy+1][idxx+1];
    memset(diff,0,sizeof diff);
    for(int i = 0; i<n; i++){
        ll r1 = box[i][1], r2 = box[i][3], c1 = box[i][0], c2 = box[i][2], t = box[i][4];
        for(int j = r1; j<r2; j++){
            diff[j][c1]+=t;
            diff[j][c2]-=t;
        }
    }
    for(int i = 0; i<idxy+1; i++){
        for(int j = 1; j<idxx+1; j++){
            diff[i][j] += diff[i][j-1];
        }
    }
    ll cnt = 0;
    for(int i = 0; i<idxy+1; i++){
        for(int j = 0; j<idxx+1; j++){
            if(diff[i][j]>=T){
                cnt+=(xx[j+1]-xx[j])*(yy[i+1]-yy[i]);
            }
        }
    }
    cout<<cnt<<'\n';
}