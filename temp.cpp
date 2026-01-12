#include <bits/stdc++.h>
using namespace std;
int dp[31][31];
int main(){
    for(int i=0;i<31;i++){
        for(int j=0;j<31;j++){
            if(i < j)dp[i][j] = 0;
            else if(j==0)dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int d=0;
        while(n%2==0){
            d++;
            n/=2;
        }
        int ans=0;
        for(int i=0;i<d;i++){
            for(int j=1;j<=i+1;j++){
                if(i+ j <= k)continue;
                ans += dp[i][j-1];
            }
        }
        if (d + 1 > k) ++ans;
        cout<<ans<<endl;
    }

    return 0;
}





*/