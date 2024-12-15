#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int m,n;
int locations=0;

string myhash(int r,int c){
    return to_string(r)+"#"+to_string(c);
}

vector<int>getVal(string s){
    int i=0, n=s.length();
    int row=0,col=0;;
    while(s[i]!='#'){
        row=row*10+(s[i]-'0');
        i++;
    }
    i++;
    while(i<n){
        col=col*10+(s[i]-'0');
        i++;
    }
    return {row,col};
}

bool isValid(int r,int c){
    return r>=0 & r<m && c>=0 && c<n;
}

void mPrint(auto arr){
    for(auto t:arr){
        for(auto y:t){
            cout<<y<<" "; 
        }
        cout<<endl;
    }
}

void solve(int idx,vector<vector<char>>& A,vector<vector<string>>& vp){
    vector<string>curr=vp[idx];

    for(int i=0;i<curr.size();i++){
        for(int j=i+1;j<curr.size();j++){

            vector<int>b=getVal(curr[i]);
            vector<int>d=getVal(curr[j]);

            bool slope= ((b[1]-d[1]<0) == (b[0]-d[0]<0)) ? 1 : -1;  // \ =1
            vector<int>lower,upper;

            if(b[0]>d[0]){upper=d, lower=b;}
            else{lower=d, upper=b;}

            int hD,vD;
            int nxU=-1, nyU=-1, nxL=-1, nyL=-1;

            if(slope==1){
                vD=lower[0]-upper[0];
                hD=lower[1]-upper[1];

                nxU=upper[0]-vD;
                nyU=upper[1]-hD;

                nxL=lower[0]+vD;
                nyL=lower[1]+hD;
            }
            else{
                hD=lower[0]-upper[0];
                vD=upper[1]-lower[1];

                nxU=upper[0]+vD;
                nyU=upper[1]-hD;

                nxL=lower[0]+vD;
                nyL=lower[1]-hD;
            }

            // if char is a . then replace, otherwise inc count only when char != '#'

            if(isValid(nxL,nyL) && A[nxL][nyL]!='#'){
                // cout<<nxL<<" "<<nyL<<endl;
                A[nxL][nyL]='#';
                locations++;
            }

            if(isValid(nxU,nyU) && A[nxU][nyU]!='#'){
                // cout<<nxU<<" "<<nyU<<endl;
                A[nxU][nyU]='#';
                locations++;
            }
        }
    }
}

// checked python solution of people
void check(vector<vector<string>>& vp, set<string>& st){
    for(auto p:vp){
        for(int i=0;i<p.size();i++){
            for(int j=0;j<p.size();j++){
                if(i==j){continue;}
                vector<int>a1=getVal(p[i]);
                vector<int>a2=getVal(p[j]);

                int dr=a2[0]-a1[0], dc=a2[1]-a1[1];
                int r=a1[0], c=a1[1];

                // lie on same line and check if added or not

                while(isValid(r,c)){
                    st.insert(myhash(r,c));
                    r+=dr, c+=dc;
                }
            }
        }
    }
}

int main() {
    fastIO();
    int t;
    cin>>t;
    cin.ignore();
    
    while(t--){
        string line;
        ll part1=0, part2=0;
        int row=0;
        vector<vector<string>>vp(256);
        vector<vector<char>>arr;

        while(getline(cin,line) && !line.empty()){
            int col=0;
            vector<char>temp;
            for(char& ch:line){
                if(ch != '.'){
                    vp[ch-'0'].push_back(myhash(row,col));
                }
                temp.push_back(ch);
                col++;
            }
            arr.push_back(temp);
            row++;
        }

        m=arr.size(), n=arr[0].size();

        for(int i=0;i<256;i++){
            if(vp[i].size()>1){
                // cout<<i<<endl;
                solve(i,arr,vp);
            }
        }

        set<string>antenna;
        check(vp,antenna);


        // while(getline(cin,line) && !line.empty()){
        //     for(char& ch:line){
        //         cout<<ch<<" ";
        //     }
        //     cout<<endl;
        // }

        // print 
        // mPrint(arr);
        part2=antenna.size();

        cout<<"Part 1: "<<locations<<endl;
        cout<<"Part 2: "<<part2<<endl;
    }
    return 0;
}

// Part 1: 273
// Part 2: 1017

/*
test comparison
0 6
0 11
1 3
2 4
2 10
3 2
4 9
5 1
6 3
7 0
7 7
10 10
11 10


0 6
0 11
1 3
2 4
2 10
3 2
4 9
5 1
6 3
7 0
7 7
10 10
11 10
*/