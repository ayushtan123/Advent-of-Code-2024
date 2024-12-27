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
            map<int,pair<int,int>>mp;

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
            cout<<id<<endl;
            // print 
            // for(auto s:arr){cout<<s;}
            // cout<<endl;

            int j=arr.size()-1;

            while(j>=0){
                int i=0;
                while(i<=j){
                    while(arr[i]!="."){i++;}   // never crosses j
                    while(arr[j]=="."){j--;}

                    int ss=0;
                    int idc=0;
                    string idt=arr[j];
                    int p=i,q=j;

                    while(arr[p]=="."){
                        p++;
                        ss++;
                    }
                    while(arr[q]==idt){
                        q--;
                        idc++;
                    }
                    // cout<<id<<" "<<idc<<" "<<ss<<" "<<p<<" "<<q<<endl;
                    
                    if(ss>=idc && p<=q){
                        while(idc--){
                            arr[i]=idt;
                            arr[j]=".";
                            i++,j--;
                        }
                        i=p;
                    }
                    // for(auto s:arr){cout<<s;}
                    // cout<<endl;
                    j=q;
                }
            }

            // cout<<endl;
            // for(auto s:arr){cout<<s;}
            // cout<<endl;

            ll ans=0;
            int idx=0;
            while(idx<arr.size()){
                if(arr[idx]=="."){idx++; continue;}
                ll num=stoll(arr[idx]);
                ans += (idx*num*1LL);
                idx++;
            }
            cout<<ans;
        }        
    }
    return 0;
}

// part 2: 