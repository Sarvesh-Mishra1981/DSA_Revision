#include<vector>
#include<iostream>
using namespace std;
vector<pair<int,int>> solve(vector<pair<int,int>>& a){
    sort(a.begin(),a.end(),[&](pair<int,int>& c,pair<int,int>& d){
        return c.first<d.first;
    });
    vector<pair<int,int>> res;
    int prev=0;
    res.push_back(a[0]);
    for(int i=1;i<a.size();i++){
        if(a[i].first>a[prev].second){
            res.push_back(a[i]);
            prev=i;
        }
    }
    return res;
}
int main(){
    vector<pair<int, int>> a = {{1, 3}, {2, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}};
    vector<pair<int,int>> result = solve(a);

    cout << "Selected activities:\n";
    for (auto& p : result) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    cout << "Maximum number of activities: " << result.size() << endl;

    return 0;
}