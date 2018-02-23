#include <bits/stdc++.h>
using namespace std;
namespace pnoi2704{
struct pt{
    int x,y;
};
bool cmp1(pt p1,pt p2){
    return (p1.x==p2.x)?(p1.y>p2.y):(p1.x>p2.x);
}
bool cmp2(pt p1,pt p2){
    return !cmp1(p1,p2);
}
vector<pt> pts,ans;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        pt p;
        cin>>p.x>>p.y;
        pts.push_back(p);
    }
    sort(pts.begin(),pts.end(),cmp1);
    int lim=-1,l=pts.size();
    for(int i=0;i<l;i++){
        if(pts[i].y>lim){
            ans.push_back(pts[i]);
            lim=pts[i].y;
        }
    }
    sort(ans.begin(),ans.end(),cmp2);
    l=ans.size()-1;
    for(int i=0;i<l;i++)printf("(%d,%d),",ans[i].x,ans[i].y);
    printf("(%d,%d)",ans[l].x,ans[l].y);
    return 0;
}
}
