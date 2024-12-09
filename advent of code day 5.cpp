#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

void solve(string& s,vector<int>&v,set<int>& present){
    int i=0,n=s.length();
    int num=0;
    while(i<n){
        while(i<n && s[i]!=','){
            num=num*10+(s[i]-'0');
            i++;
        }
        v.push_back(num);
        present.insert(num); 
        num=0;
        i++;
    }
}

int solve1(vector<int>&v, map<int,set<int>>&edges){    
    int n=v.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(edges[v[i]].find(v[j]) == edges[v[i]].end()){
                return -1;
            }
        }
    }
    return v[(n-1)/2];
}

//  find topo sort for set present
vector<int> getTopo(map<int,set<int>>& edges, set<int>&st){

    map<int,int>mp;
    for(auto wt:st){
        for(int e:edges[wt]){    
            if(st.find(e) != st.end()){   // check if e is in present set
                mp[e]++;
            }
        }
    }

    queue<int>q;
    for(auto wt:st){
        if(mp[wt]==0){
            q.push(wt);
        }
    }

    vector<int>ans;
    while(!q.empty()){
        int el=q.front();
        q.pop();
        ans.push_back(el);

        for(int e:edges[el]){
            mp[e]--;
            if(mp[e]==0){
                q.push(e);
            }
        }
    }
    return ans;
}

int main() {
    fastIO();
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string line;
        map<int,set<int>>edges;    // dont need vector

        while(getline(cin,line) && !line.empty()){
            int i=0,len=line.length();
            int x=0,y=0;
            while(line[i]!='|'){
                x=(x*10)+(line[i]-'0');
                i++;
            }
            i++;
            while(i<len){
                y=(y*10)+(line[i]-'0');
                i++;
            }
            edges[x].insert(y);
        }

        cin.ignore();
        ll sum=0, incorrect_sum=0;

        while(getline(cin,line) && !line.empty()){
            vector<int>v;
            set<int>present;   
            solve(line,v,present);

            int val=solve1(v,edges);
            if(val!=-1){
                sum += val;
            }
            else{
                vector<int>t = getTopo(edges,present);
                incorrect_sum += t[(t.size()-1)/2];
            }
        }
        // find middle value sum of updates
        cout<<"Valid updates = "<<sum<<endl;
        cout<<"Incorrect updates = "<<incorrect_sum<<endl;
    }
    return 0;
}


// Valid updates = 5964
// Incorrect updates = 4719