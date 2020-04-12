#include<bits/stdc++.h>
#define rep(i,n) for (i = 0; i < (n); ++i) 
#define REP(i,k,n) for (i = (k); i <= (n); ++i) 
#define REPR(i,k,n) for (i = (k); i >= (n); --i) 
using namespace std;

// void solve(){
// }

int main(){
    std::ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif 


    string s;
    cin>>s;
    int n = s.length();
    cout<<n<<endl;
    int i=0;
    int flag =1;
    int j= n-1;
    while(j>=i){
        if(s[i]!=s[j])
            flag = 0;
        i++;
        j--;
    }
    if(flag)
        cout<<"palindrome"<<endl;
    else
    {
        cout<<"not palindrome"<<endl;
    }
    
    // solve();
    return 0;


}