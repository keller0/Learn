#include <vector>
#include <iostream>
#include <map>

using namespace std;
// not efficient enough yet
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
  map<int,int> m;
  int rank = 1;
  for(vector<int>::size_type i=0; i<scores.size(); i++) {
	int sco = scores[i];
	if(m.count(sco) > 0)
	  continue;
	else{
	  m[sco] = rank++;
	}
  }
  for(vector<int>::size_type i=0; i<alice.size(); i++) {
	int val = alice[i];
	int ran;
	for (auto it = m.begin(); it != m.end(); ++it) {
	  if(val >= it->first)
		ran = it->second;
	  else if(val < it->first){
		ran = it->second+1;
		break;
	  }
	}
	alice[i] = ran;
  }
  return alice;
}
int main() {
  vector<int> s = {100,100,90,80};
  vector<int> ali = {99,80,20};
  vector<int> a;
  a = climbingLeaderboard(s,ali);
  for(vector<int>::size_type i=0; i<a.size(); i++)
	cout<<a[i]<<endl;
  return 0;
}
