#include <bits/stdc++.h>

using namespace std;
int multiply(int x, int res[], int r_size) {
	int carry = 0;
	for(int i=0; i<r_size; i++) {
		int prod = res[i] *x +carry;
		res[i] = prod%10;
		carry = prod/10;
	}
	while(carry) {
		res[r_size] = carry%10;
		carry /= 10;
		r_size++;
	}
	return r_size;
}
void extraLongFactorials(int n) {
    int res[1000];
	res[0] = 1;
	int r_size = 1;
	for(int x=2; x <= n; x++)
		r_size = multiply(x, res, r_size);

	for(int i=r_size-1; i>=0; i--)
		cout<<res[i];
}

int main() {
    int n;
    cin >> n;
    extraLongFactorials(n);
    return 0;
}
