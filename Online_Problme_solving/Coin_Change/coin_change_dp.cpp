#include <bits/stdc++.h>

using namespace std;
int main() {
    int target, c_num;
    cin >> target >> c_num;
    vector <long> changes(c_num);
    for (int i=0;i<c_num;i++) cin >> changes[i];

    vector <long> ways(target+1); // ways[x] => how many ways to get x
    ways[0]=1;
    
    for (auto icha = changes.begin(); icha != changes.end(); ++icha) {
        for (int j=*icha; j<=target; j++) {
			// eg. *icha = 2,target= 5
			// first j=2, ways[2] += ways[2-2]
			// ways[2] = ways[0] = 1
			// j++ => j=3, ways[3] += ways[3-2]
			// ways[3] = ways[1] = 0 
			ways[j] += ways[ j - *icha ];
        }
    }    

    cout << ways[target]<<endl;
    return 0;
}
