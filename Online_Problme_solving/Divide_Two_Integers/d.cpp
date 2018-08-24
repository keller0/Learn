#include <iostream>
#include <climits>
#include <cmath>

using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
	if(dividend == 0) return 0;
	long long result=double(exp(log(fabs(dividend))-log(fabs(divisor))));
	if((dividend<0) ^ (divisor<0))  result=-result;
	if(result>INT_MAX)  result=INT_MAX;
        return result;
    }
};

int main() {
    auto s = Solution();
    cout<<s.divide(7, -3)<<endl;
    cout<<s.divide(10, 3)<<endl;
}
