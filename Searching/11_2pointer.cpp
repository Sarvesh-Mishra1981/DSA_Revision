#include<iostream>
#include<vector>
using namespace std;
bool twopointer(vector<int>& a,int target){
    int st=0,end=a.size();
    while(st<=end){
        int sum=a[st]+a[end];
        if((sum)==target) return true;
        else if(sum<target){
            st++;
        }else{
            end--;
        }
    }
    return false;
}
int main(){

}