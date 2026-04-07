// so if we cnt the first and the last occ then we can do it by just find the first occ and then find the last occ and once it is done subtract both

//we need to find the first occ of the number
#include<iostream>
#include<vector>
using namespace std;
int binarylast(vector<int>& a,int n,int target){
    int st=0;
    int end=n;
    while(st<=end){
        int mid=(end-st)/2+st;
        if(a[mid]>target){
            end=mid-1;
        }else if(a[mid]<target){
            st=mid+1;
        }else{
            if(mid==n-1 || a[mid]!=a[mid+1]) return mid;
            else {
                st=mid+1;
            }
        }
    }
    return -1;
}
int binaryfirst(vector<int>& a,int n,int target){
    int st=0;
    int end=n;
    while(st<=end){
        int mid=(end-st)/2+st;
        if(a[mid]>target){
            end=mid-1;
        }else if(a[mid]<target){
            st=mid+1;
        }else{
            if(mid==0 || a[mid-1]!=a[mid]) return mid;
            else {
                end=mid-1;
            }
        }
    }
    return -1;
}
int main(){
    vector<int> a={2,3,4,5,5,5,5,5,6,7,8,8,9};
    int target=5;
    cout<<binarylast(a,a.size(),5)-binaryfirst(a,a.size(),5)+1;
}