#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

// go in eight directions
int solve(vector<vector<char>>&v){
    int m=v.size(), n=v[0].size();
    int cnt=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]=='X'){
                // E
                if(j+3<n && v[i][j+1]=='M' && v[i][j+2]=='A' && v[i][j+3]=='S'){cnt++;}
                // W
                if(j-3>=0 && v[i][j-1]=='M'&& v[i][j-2]=='A' && v[i][j-3]=='S'){cnt++;}
                // N
                if(i-3>=0 && v[i-1][j]=='M'&& v[i-2][j]=='A' && v[i-3][j]=='S'){cnt++;}
                // S
                if(i+3<m && v[i+1][j]=='M'&& v[i+2][j]=='A' && v[i+3][j]=='S'){cnt++;}
                // NE
                if(i-3>=0 && j+3<n && v[i-1][j+1]=='M'&& v[i-2][j+2]=='A' && v[i-3][j+3]=='S'){cnt++;}
                // NW
                if(i-3>=0 && j-3>=0 && v[i-1][j-1]=='M'&& v[i-2][j-2]=='A' && v[i-3][j-3]=='S'){cnt++;}
                // SE
                if(i+3<m && j+3<n && v[i+1][j+1]=='M'&& v[i+2][j+2]=='A' && v[i+3][j+3]=='S'){cnt++;}
                // SW
                if(i+3<m && j-3>=0 && v[i+1][j-1]=='M'&& v[i+2][j-2]=='A' && v[i+3][j-3]=='S'){cnt++;}
            }
        }
    }
    return cnt;
}

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