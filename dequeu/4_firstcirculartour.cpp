#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int solve(vector<int> ptr,vector<int> dis,int n){
    int st=0,curr_ptr=0,prev_ptr=0;
    for(int i=0;i<n;i++){
        curr_ptr+=ptr[i]-dis[i];
        if(curr_ptr<0){
            prev_ptr+=curr_ptr;
            curr_ptr=0;
            st+=1;
        }
    }
    return (curr_ptr+prev_ptr>=0?st:-1);
}
int main(){
vector<int> petrol{50,10,60,100};
vector<int> dis{30,20,100,10};
cout<<solve(petrol,dis,dis.size());
return 0;
}