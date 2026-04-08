#include<iostream>
#include<vector>
using namespace std;
int sqroot(int n){
    int low=0,high=n;
    int ans=-1;
    while(low<=high){
       int mid=(high-low)/2+low;
       int val=mid*mid;
       if(n==val) return mid;
       else if(n<val){
        high=mid-1;
       }
       else{
                low=mid+1;
        ans=mid;
       }
    }
return ans;
}
int main(){
    cout<<sqroot(10)<<endl;
}