#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
vector<int>digits;  
bool solve1(int i,ll val,vector<ll>& arr,ll& tar){
    if(i==arr.size()){return val==tar;}
    if(val>tar){return false;}
    
    return solve1(i+1,val*arr[i],arr,tar) || solve1(i+1,val+arr[i],arr,tar);
}

bool solve2(int i,ll val,vector<ll>& arr,ll& tar){
    if(i==arr.size()){return val==tar;}
    if(val>tar){return false;}
    
    return  solve2(i+1,val*arr[i],arr,tar) || 
            solve2(i+1,val+arr[i],arr,tar) || 
            solve2(i+1,(val*pow(10,digits[i])*1LL)+arr[i],arr,tar);
}

int main() {
    fastIO();
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string line;
        ll part1=0, part2=0;
        while(getline(cin,line) && !line.empty()){
            int i=0,len=line.length();

            ll testV=0;
            while(line[i]!=':'){
                testV = (testV*10) + (line[i]-'0');
                i++;
            }
            i+=2;   // colon and space

            vector<ll>arr;
            while(i<len){
                int val=0;
                int cnt=0;
                while(i<len && line[i]!=' '){
                    val = (val*10) + (line[i]-'0');
                    i++;
                    cnt++;
                }
                arr.push_back(val);
                digits.push_back(cnt);
                // cout<<val<<" "<<cnt<<endl;
                i++;
            }

            if(solve1(1,arr[0],arr,testV)){
                part1 += testV;
            }
            if(solve2(1,arr[0],arr,testV)){
                part2 += testV;
            }
            digits.clear();
        }

        cout<<"Part 1: "<<part1<<endl;
        cout<<"Part 2: "<<part2<<endl;
    }
    return 0;
}

// Part 1: 3351424677624
// Part 2: 204976636995111