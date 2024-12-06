#include <bits/stdc++.h>
#define ll long long
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
bool isOK(vector<int>& A){     // part 1
    int slope = (A[0] < A[1]) ? 1 : -1; // Determine initial slope (ascending or descending)

    for (int j = 0; j < A.size() - 1; j++) {
        if (slope == 1) { // Ascending
            if (!(A[j] < A[j + 1] && abs(A[j] - A[j + 1]) >= 1 && abs(A[j] - A[j + 1]) <= 3)) {
                return false;
            }
        } else { // Descending
            if (!(A[j] > A[j + 1] && abs(A[j] - A[j + 1]) >= 1 && abs(A[j] - A[j + 1]) <= 3)) {
                return false;
            }
        }
    }   // 242
    return true;
}
bool isSafeSlope(vector<int>& A) {    //311
    bool anyOK=false;
    auto consider=[&](int i){
        vector<int>b=A;
        b.erase(b.begin()+i);
        if(isOK(b)){
            anyOK=true;
        }
    };
    int n=A.size();
    consider(0);
    for(int i=0;i<n-1;i++){
        int diff=A[i+1]-A[i];
        if(abs(diff)<1 || abs(diff)>3){
            consider(i);
            consider(i+1);
            break;
        }
        if(i+2<n){
            int diff2=A[i+2]-A[i+1];
            if((diff>0) != (diff2>0)){
                consider(i);
                consider(i+1);
                consider(i+2);
                break;
                // valley 5 10 8 or 10 5 8
            }
        }
    }
    return anyOK;
}

int main() {
    fastIO();

    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // To handle the newline after the number of test cases

    while (t--) {
        int safe = 0; // Count of safe arrays
        string line;

        while (getline(cin, line) && !line.empty()) {
            vector<int> A;
            stringstream ss(line);
            int num;

            // Parse integers from the line
            while(ss>>num){
                A.push_back(num);
            }

            if(!A.empty() && isSafeSlope(A)){
                safe++;
            }
        }
        cout << safe;
    }
    return 0;
}


/*
day 1 problem 2
while(t--){
    unordered_map<ll,ll>v1,v2;
    for(int i=0;i<2000;i++){
        ll x; cin>>x;
        if(i%2==0){
            v1[x]++;
        }
        else{v2[x]++;}
    }
    ll score=0;
    for(auto& it:v1){
        score += v2[it.first]*it.second*it.first;
    }
    cout<<score;
}
*/