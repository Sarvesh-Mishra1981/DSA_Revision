#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>& a,int n){
    //since this is the sorted array hence we will get the 1 continous in the array. 
    //hence we just need to find the first occ of the 1
    int st=0;
    int end=n;
    while(st<=end){
        int mid=(end-st)/2+st;
        if(a[mid]==1){
            return n-mid;
        }
        else if(a[mid]<1){
            st=mid+1;
        }else{
            end=mid-1;
        }
    }
    return 0;
}
int main(){
    vector<int> a={0,0,0,1,1,1,1,1};
    cout<<solve(a,a.size())+1;
}