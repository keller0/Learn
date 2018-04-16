// Implementation of Manacher's algorithm (see http://johanjeuring.blogspot.com/2007/08/finding-palindromes.html )
// Thanks to Frederick Akalin (see http://www.akalin.cx/2007/11/28/finding-the-longest-palindromic-substring-in-linear-time/ )
// Brian Bi (bbi5291), 2010-11-14
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <class RAI1,class RAI2>
void fastLongestPalindromes(RAI1 seq,RAI1 seqEnd,RAI2 out)
{
	int seqLen=seqEnd-seq;
	int i=0,j,d,s,e,lLen,k=0;
	int palLen=0;
	while (i<seqLen)
	{
		if (i>palLen && seq[i-palLen-1]==seq[i])
		{
			palLen+=2;
			i++;
			continue;
		}
		out[k++]=palLen;
		s=k-2;
		e=s-palLen;
		bool b=true;
		for (j=s; j>e; j--)
		{
			d=j-e-1;
			if (out[j]==d)
			{
				palLen=d;
				b=false;
				break;
			}
			out[k++]=min(d,out[j]);
		}
		if (b)
		{
			palLen=1;
			i++;
		}
	}
	
	out[k++]=palLen;
	lLen=k;
	s=lLen-2;
	e=s-(2*seqLen+1-lLen);
	for (i=s; i>e; i--)
	{
		d=i-e-1;
		out[k++]=min(d,out[i]);
	}
}

int main()
{
	string s; cin >> s;
	int orilen = s.length();
	string s2 = s+s;
	vector<int> V(2*s2.length()+1);
	int best = 0;
	fastLongestPalindromes(s2.begin(),s2.end(),V.begin());
	for (int i=0; i<V.size(); i++)
	{
		//cout<<V[i]<<endl;
		if(V[i] > orilen)
			continue;
		best=max(best,V[i]);
	}
	cout<< "Longest palindrome has length " << best << endl;
	return 0;
}
