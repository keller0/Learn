#include <bits/stdc++.h>

using namespace std;
//https://www.hackerrank.com/challenges/counting-valleys/problem
int countingValleys(int n, string s) {
	int v = 0, sum = 0;

	for(int i=0; i<n; i++) {
		int a = sum;
		s[i] == 'D' ? sum--: sum++;
		if(a >= 0 && sum < 0) {
			v++;
		}
		cout<<sum<<" "<<v<<endl;
	}
	return v;
}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int result = countingValleys(n, s);
    cout << result << endl;
    return 0;
}

