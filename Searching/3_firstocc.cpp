//we need to find the first occ of the number
#include<iostream>
#include<vector>
using namespace std;
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

}