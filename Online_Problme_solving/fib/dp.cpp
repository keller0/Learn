#include <bits/stdc++.h>
using namespace std;

int fib(int c) {
	if(c <= 1)
		return 1;
	int f1 =1,  f2 = 1, ans;
	for(int i =1; i <c; i++) {
		ans = f1 + f2;
		f1 = f2;
		f2 = ans;
	}
	return ans;
}

int main() {

	int c;

	cin>>c;

	cout<<fib(c)<<endl;
}
        
