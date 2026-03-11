#include<vector>
#include<iostream>
using namespace std;
int solve(vector<int>& a,int n){
    vector<int> res;
   for(int i = 0; i < n; i++){
    int it = lower_bound(res.begin(), res.end(), a[i]) - res.begin();

    if(it == res.size()){
        res.push_back(a[i]);
    }else{
        res[it] = a[i];
    }
}
return res.size();
}
int main(){
    vector<int> a = {5, 4, 3, 6, 7, 8, 1};
    int n = a.size();
    cout<<solve(a,n)<<endl;
}