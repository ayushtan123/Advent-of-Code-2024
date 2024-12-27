#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main() {
    fastIO();
    int t;
    cin>>t;
    cin.ignore();

    while(t--){
        string line;
        while (getline(cin, line) && !line.empty()) {
            vector<string>arr;
            // generate id format

            int id=0;
            int spaces=0;
            for(int i=0;i<line.size();i++){
                if(i%2==0){    // file
                    string s=to_string(id);
                    arr.insert(arr.end(),(line[i]-'0'),s);
                    id++;
                }
                
                else{    // free space
                    arr.insert(arr.end(),(line[i]-'0'),".");
                    spaces+=(line[i]-'0');
                }
            }
            // print 
            // for(auto s:arr){cout<<s;}

            int j=arr.size()-1, i=0;

            while(arr[i]!="."){i++;}   // never crosses j
            while(arr[j]=="."){j--;}

            while(spaces>0){
                swap(arr[i],arr[j]);
                i++, j--;
                spaces--;
                while(i<j && arr[i]!="."){i++;}
                while(i<j && arr[j]=="."){j--;}
                if(i>=j){break;}
            }

            // cout<<endl;
            // for(auto s:arr){cout<<s;}

            ll ans=0;
            int idx=0;
            while(arr[idx]!="."){
                ll num=stoll(arr[idx]);
                ans += (idx*num*1LL);
                idx++;
            }
            cout<<ans;
        }        
    }
    return 0;
}

// part 1: 6288599492129