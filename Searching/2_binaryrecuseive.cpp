#include<iostream>
#include<vector>
using namespace std;
int binary(vector<int>& a,int target,int st,int end){
    int mid=(end-st)/2+st;
    if(st>end) return -1;
    if(a[mid]==target) return mid;
    else if(a[mid]>target) return binary(a,target,st,mid-1);
    else return binary(a,target,mid+1,end);
}
int main(){
vector<int> a= {10, 20, 30, 40, 50, 60};

    cout<<binary(a,25,0,a.size());
}