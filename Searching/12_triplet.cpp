#include<vector>
#include<iostream>
using namespace std;
bool pointer(vector<int>& a,int st,int end,int target){
    while(st<=end){
        int sum=a[st]+a[end];
        if(sum==target) return true;
        else if(sum>target) {
            end--;
        }else {
            st++;
        }
    }
    return false;
}
bool triplet(vector<int>& a,int n,int target){
    for(int i=0;i<n-2;i++){
        if(pointer(a,i+1,a.size(),target-a[i])){
            return true;
        }
    }
    return false;
}
int main(){

}