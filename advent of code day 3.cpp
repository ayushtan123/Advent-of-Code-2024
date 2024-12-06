#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int dont=0, Do=0;
bool karSolve=1;

ll solve(string& s){
    ll lsum=0;
    int i=0, n=s.length();

    while(i<n){
        if(karSolve==1 && i+3<n && s[i]=='m' && s[i+1]=='u' && s[i+2]=='l' && s[i+3]=='('){
            int j=i+4;
            int x=0,y=0,cnt=0;
            while(j<n && cnt<3 && isdigit(s[j])){
                x=(x*10)+s[j]-'0';
                j++;
                cnt++;
                if(j==n){return lsum;}
            }

            if(s[j]==','){
                j++;
                if(j==n){return lsum;}

                cnt=0;
                while(cnt<3 && isdigit(s[j])){
                    y=(y*10)+s[j]-'0';
                    j++;
                    cnt++;
                    if(j==n){return lsum;}
                }
                if(s[j]==')'){
                    cout<<x<<" "<<y<<endl;
                    lsum += x*y;
                    i=j;
                }
            }
        }
        else if(i+3<n && s[i]=='d' && s[i+1]=='o' && s[i+2]=='(' && s[i+3]==')'){
            karSolve=1;
            Do++;
            i+=3;
        }
        else if(i+6<n && s[i]=='d' && s[i+1]=='o' && s[i+2]=='n' && s[i+4]=='t' && s[i+5]=='(' && s[i+6]==')'){
            karSolve=0;
            i+=6;
            dont++;
        }
        i++;
    }
    return lsum;
}

int main() {
    fastIO();
    int t;
    cin>>t;
    cin.ignore();

    while(t--){
        string line;
        ll sum=0;
        while (getline(cin, line) && !line.empty()) {
            stringstream ss(line);
            string num;

            // Parse integers from the line
            while(ss>>num){
                sum += solve(num);
            }
        }
        cout<<"Ans: "<<sum<<endl;
        cout<<"do: "<<Do<<endl;
        cout<<"dont: "<<dont;
    }
    return 0;
}