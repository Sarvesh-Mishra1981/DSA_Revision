#include<iostream>
#include<vector>
using namespace std;
int seacrhinrotated(vector<int>& a,int n,int target){
    //so the basic idea is that one side will be always sorted hence we will use that logic
    int st=0,end=n;
    while(st<=end){
        int mid=(end-st)/2+st;
        if(a[mid]==target) return mid;
        if(a[mid]>a[0]){
            //left sorted
            if(target<=a[mid] && target>=a[0]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }else{
            if(target>=a[mid] && target<=a[n-1]){
                st=mid+1;
            }else{
                end=mid-1;
            }

        }
    }
    return -1;
}
int main(){

}