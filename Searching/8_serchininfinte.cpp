#include<iostream>
#include<vector>
using namespace std;
int binarysearch(vector<int>& a,int target,int st,int end){
        if(st>end) return -1;
         int mid=(end-st)/2+st;
         if(a[mid]==target) return mid;
         else if(a[mid]>target) return binarysearch(a,target,st,mid-1);
         else return binarysearch(a,target,mid+1,end);
}
int searchininfinte(vector<int>& a,int target){
    //here we donot have the vector defined of the definit size hence what we will do is that we will crete the segment where we can find the num
    int i=0;
    while(a[i]<target){
        i=i*2;
    }
    return binarysearch(a,target,(i/2)+1,i-1);
}
int main(){

}