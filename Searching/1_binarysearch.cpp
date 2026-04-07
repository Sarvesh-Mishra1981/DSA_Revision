#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int>& a,int target){
    int st=0;
    int end=a.size();
    while(st<=end){
        int mid=(end-st)/2 +st;
        if(a[mid]==target){
            return mid;
        }
        else if(a[mid]>target){
            end=mid-1;
        }else{
            st=mid+1;
        }
    }
    return -1;
}
int main(){
    // the idea of the binary search is that we will neglect the one half of the 
     vector<int> a= {10, 20, 30, 40, 50, 60};

    cout<<binarysearch(a,25);
}