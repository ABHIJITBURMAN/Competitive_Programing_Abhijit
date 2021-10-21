#include<bits/stdc++.h>
using namespace std;

// Problem Link: https://leetcode.com/problems/smallest-string-with-swaps/
// class based union_find code

class DSU{
private:
    vector<int> parent;
    vector<int> size;
public:
    void init(int n){
        for(int i=0;i<n;i++){
            parent.push_back(i);
            size.push_back(1);
        }
    }
    int find(int a){
        if(parent[a] == a){
            return a;
        }
        return parent[a] = find(parent[a]);
    }
    void dsuUnion(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b){
            return ;
        }
        if(size[a]<size[b]){
            parent[a] = b;
            size[b]+=size[a];
        }
        else{
            parent[b] = a;
            size[a]+=size[b];
        }
    }
    
};


class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& a) {
        DSU dsu;
        int n = a.size();
        int m = s.size();
        dsu.init(m);
        deque<char> v[m];
        for(int i=0;i<n;i++){
            int x = a[i][0];
            int y = a[i][1];
            dsu.dsuUnion(x,y);
        }
        
        for(int i=0;i<m;i++){
            int p = dsu.find(i);
            v[p].push_back(s[i]);
        }
        for(int i=0;i<m;i++){
            if(v[i].size()>0){
                sort(v[i].begin(),v[i].end());
            }
        }
        for(int i=0;i<m;i++){
            int p = dsu.find(i);
            s[i] = v[p].front();
            v[p].pop_front();
        }
        return s;
    }
};

int main(){
    string s;
    cin>>s;
    int m;
    cin>>m;
    vector<vector<int>> q(m, vector<int>(2));

    for(int i=0;i<m;i++){
        cin>>q[i][0]>>q[i][1];
    }
    Solution ob;
    string ans = ob.smallestStringWithSwaps(s,q);

    cout<<ans<<endl;
}