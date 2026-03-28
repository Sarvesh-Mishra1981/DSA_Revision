#include<vector>
#include<iostream>
#include<queue>
using namespace std;
class Triplet{
    public:
    int val;
    int apos;
    int vpos;
    Triplet(int x,int y,int z){
        val=x;
        apos=y;
        vpos=z;
    }
};
class Mycmp{
    public:
    bool operator()(Triplet &a,Triplet& b){
        return a.val>b.val;
    }
};
vector<int> MergeKsorted(vector<vector<int>>& a,int n){
    priority_queue<Triplet,vector<Triplet>,Mycmp> pq;
    for(int i=0;i<n;i++){
        pq.push(Triplet(a[i][0],i,0));
    }
    vector<int> ans;
    while(!pq.empty()){
        int top=pq.top().val;
        int apo=pq.top().apos;
        int pos=pq.top().vpos;
        pq.pop();
        ans.push_back(top);
        if((pos+1)<a[apo].size()){
            pq.push(Triplet(a[apo][pos+1],apo,pos+1));
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> arr = {
        {1, 4, 7},
        {2, 5, 8},
        {3, 6, 9}
    };

    int k = arr.size();
    vector<int> ans=MergeKsorted(arr,k);
     cout << "Merged array: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;

}