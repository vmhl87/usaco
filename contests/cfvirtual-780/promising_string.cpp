#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

void test_case(){
	int n;cin>>n;
	// off, down
	multiset<int> dp[3];
	int off=0;
	long long ret=0;
	for(int i=0;i<n;++i){
		char c;cin>>c;
		if(c=='-')--off;
		else ++off;
		if(off%3==0&&off<=0)++ret;
		int l=(3+(off%3))%3;
		auto lb=lower_bound(dp[l].begin(),dp[l].end(),off);
		ret+=distance(lb,dp[l].end());
		dp[l].insert(off);
	}
	cout<<ret<<'\n';
}

int main(){
	int t;cin>>t;
	while(t--)test_case();
}
