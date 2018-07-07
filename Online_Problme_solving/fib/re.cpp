#include <bits/stdc++.h>
using namespace std;

int fib(int c) {
	return c<=1 ? 1 :fib(c-1)+fib(c-2);
}

int main() {

	int c;
	
	cin>>c;

	cout<<fib(c)<<endl;
}
        
