#include<iostream>
#include<vector>
using namespace std;
int biotonic(vector<int>& a,int n){
    int st=0,end=n;
    while(st<=end){
        int mid=(end-st)/2+st;
        if(a[mid]>a[mid+1]){
            end=mid;
        }else{
            st=mid+1;
        }
    }
    return st;
}
int main(){

}