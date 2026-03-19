#include<vector>
#include<iostream>
#include<map>
using namespace std;
int solve2(map<pair<int,int>,int>& maxi,int n,int st,int end){
    if(st>=end) return 0;
    int ans=INT_MAX;
    for(int i=st;i<end;i++){
        ans+=max(ans,maxi[{st,i}]*maxi[{i+1,end}]+solve2(maxi,n,st,i)+solve2(maxi,n,i+1,end));
    }
    return ans;
}
int solve(vector<int>& a,int n){
    map<pair<int,int>,int> maxi;
    for(int i=0;i<n;i++){
        maxi[{i,i}]=a[i];
        for(int j=i+1;j<n;j++){
            maxi[{i,j}]=max(a[i],maxi[{i,j}]);
        }
    }
    return solve2(maxi,n,0,n-1);

}
int main(){
    vector<int> a={3,6,4,7,2,5};
    cout<<solve(a,a.size())<<endl;
}