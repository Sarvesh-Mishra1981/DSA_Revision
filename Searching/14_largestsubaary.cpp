#include<iostream>
#include<vector>
using namespace std;
int lengthofsubarray(vector<int>& a,int target){
    int st=0,end=0;
    int ans=0;
    int sum=0;
    int n=a.size();
    while(end<n){
        sum+=a[end];
        while(sum>target){
            sum-=a[st];
            st+=1;
        }
        if(sum<=target){
            ans=max(ans,end-st+1);
        }
        end+=1;
    }
    return ans;
}
int main(){

}
