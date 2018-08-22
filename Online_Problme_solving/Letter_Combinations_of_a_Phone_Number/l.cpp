#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> letterCombinations(string digits) {
    if(digits.empty()) return vector<string>();
    vector<string> result;
    static const vector<string> v = {
		"", "", "abc", "def",
		"ghi", "jkl", "mno",
		"pqrs", "tuv", "wxyz"
	};
    result.push_back("");   
    for(int i = 0 ; i < digits.size(); ++i) {
        int num = digits[i]-'0';
        if(num < 0 || num > 9) break;
        const string& candidate = v[num];
        //if(candidate.empty()) continue;
        vector<string> tmp;
        for(int j = 0 ; j < candidate.size() ; ++j) {
            for(int k = 0 ; k < result.size() ; ++k) {
                tmp.push_back(result[k] + candidate[j]);
            }
        }
        result.swap(tmp);
    }
    return result;
}

int main() {
	string l;
	cin>>l;
	for(auto a : letterCombinations(l)){
		cout<<a<<endl;
	}
}
