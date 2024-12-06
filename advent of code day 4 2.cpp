#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int solve(vector<vector<char>>&v){
    int m=v.size(), n=v[0].size();
    int cnt=0;
    for(int i=1;i<m-1;i++){
        for(int j=1;j<n-1;j++){
            if(v[i][j]=='A'){
                if( ((v[i-1][j-1]=='M' && v[i+1][j+1]=='S') || (v[i-1][j-1]=='S' && v[i+1][j+1]=='M')) && ( (v[i-1][j+1]=='M' && v[i+1][j-1]=='S') || (v[i-1][j+1]=='S' && v[i+1][j-1]=='M') ) )
                {cnt++;}
            }
        }
    }
    return cnt;
}

// MAS in X form

int main() {
    fastIO();
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string line;
        vector<vector<char>>v;
        int xmas=0;
        while(getline(cin,line)  && !line.empty()){
            vector<char>arr;
            for(char& ch:line){
                arr.push_back(ch);
            }
            v.push_back(arr);
        }
        xmas=solve(v);
        cout<<xmas;
    }
    return 0;
}