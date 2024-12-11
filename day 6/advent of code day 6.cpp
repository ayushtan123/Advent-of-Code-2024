#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int cnt=0;
int m,n;
int gi,gj;
int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};   // 90 deg right

bool isValid(int i,int j,int& m,int& n){
    return i>=0 && i<m && j>=0 && j<n;
}

void Mprint(vector<vector<char>>& v){
    for(auto A:v){
        for(char ch:A){
            cout<<ch;
        }
        cout<<endl;
    }
}

void dfs(int i,int j,int k,vector<vector<char>>& v){   // part 1
    if(v[i][j]=='.'){
        cnt++;
        v[i][j]='X';
    }

    int r=i+dir[k][0], c=j+dir[k][1];
    if(r<0 || r>=m || c<0 || c>=n){return;}

    while(v[r][c]=='#'){    // never a infinite loop
        k++;
        if(k==4){k=0;}
        r=i+dir[k][0], c=j+dir[k][1];
    }
    dfs(r,c,k,v);
}


bool solveCycle(vector<vector<char>>& v){
    vector<bool>vis(m*n*4,false);
    int x=gi,y=gj,k=0;

    while(true){
        int hash = (x*n + y)*4 + k;
        if(vis[hash]){return true;}

        vis[hash]=true;   // marked visited
        int r=x+dir[k][0], c=y+dir[k][1];
        if(r<0 || r>=m || c<0 || c>=n){return false;}

        if(v[r][c]=='.'){
            x=r, y=c;
        }
        else{
            k = (k+1)%4;
        }
    }
    return false;
}

int main() {
    fastIO();
    int t;
    cin>>t;
    cin.ignore();

    while(t--){
        string line;
        vector<vector<char>>v;
        int row=0;
        gi=-1,gj=-1;
        
        while(getline(cin,line) && !line.empty()){
            vector<char>curr;
            int col=0;

            for(char ch:line){
                curr.push_back(ch);
                if(ch=='^'){
                    gi=row, gj=col;
                }
                col++;
            }

            v.push_back(curr);
            row++;
        }
        m=v.size(),n=v[0].size();
        v[gi][gj]='.';


        ll answer=0;
        // part 2 code
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]=='.' && make_pair(i,j) != make_pair(gi,gj)){
                    v[i][j]='#';        // make obstacle
                    if(solveCycle(v)){
                        answer++;
                    }
                    v[i][j]='.';
                }
            }
        }

        dfs(gi,gj,0,v);     // part 1  (this changes v, so run after part 2)
        cout<<"Positions Visited: "<<cnt<<endl;
        cout<<"Obstructions: "<<answer<<endl;


        v[gi][gj]='^';
        // Mprint(v);
    }
    return 0;
}

// Positions Visited: 5409
// Obstructions: 2022
