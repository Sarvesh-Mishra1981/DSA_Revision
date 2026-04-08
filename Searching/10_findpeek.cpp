#include<vector>
#include<iostream>
using namespace std;
int findpeek(vector<int>&a,int n){
    int st=0,end=n;
    while(st<=end){
        int mid=(end-st)/2+st;
        if((mid==0 || a[mid-1]<a[mid]) && (mid==n-1 || a[mid+1]<a[mid])){
            return mid;
        }
        else if(mid>0 && a[mid-1]>a[mid]){
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return -1;
}
int main(){

}