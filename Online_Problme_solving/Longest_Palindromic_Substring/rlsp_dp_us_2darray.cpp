#include <bits/stdc++.h>

using namespace std;

vector<int> circularPalindromes(string oris) {
	int maxdis = oris.size();
	string s = oris+oris;
	vector<int> V(maxdis);
	int a[s.size()][s.size()] = {0};
  	for(int srow=0; srow<maxdis; srow++) {
		int maxpslen = 1;
		int maxindex = 0;
		if(srow == 0) {
			for(int dis=0; dis<maxdis; dis++) {
				for(int i=srow; i+dis<srow+maxdis; i++) {
					if(dis == 0) {
						a[i][i+dis] = 1;
					}else if(dis == 1) {
						a[i][i+dis] = s[i] == s[i+dis]?2:1;
					}else if(s[i] == s[i+dis] && a[i+1][i+dis-1] == (dis-1)) 
						a[i][i+dis] = a[i+1][i+dis-1]+2;
					else
						a[i][i+dis] = max(a[i][i+dis-1],a[i+1][i+dis]);
					if(maxpslen < a[i][i+dis]) {
						maxpslen = a[i][i+dis];
						maxindex = i;
					}
				}
			}
			V[srow] = maxpslen;
		}
		else{
			int e = srow+maxdis-1;
			for(int dis = 0; dis < maxdis; dis++) {
				if(dis == 0)
					a[e][e] = 1;
				else if(dis == 1)
					a[e-dis][e] = s[e] == s[e-dis]?2:1;
				else if(s[e] == s[e-dis] && a[e-dis+1][e-1] == (dis-1)) 
					a[e-dis][e] = a[e-dis+1][e-1]+2;
				else
					a[e-dis][e] = max(a[e-dis+1][e],a[e-dis][e-1]);
				if(maxpslen < a[e-dis][e]) {
					maxpslen = a[e-dis][e];
					maxindex = e;
				}
			}
			V[srow] = maxpslen;
		}
	}
	// for(int i = 0; i<s.size(); i++) {
	// 	for(int j = 0; j<s.size(); j++) {
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<endl;
	
	return V;
}

int main() {
	//	int n; cin>>n;
	string s;cin>>s;
	vector<int> result = circularPalindromes(s);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        cout<< result[result_itr]<<endl;
    }

    return 0;
}
