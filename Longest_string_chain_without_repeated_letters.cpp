#include <iostream>
#include <cmath>
#include <cstdlib> 
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <iterator> 
#include <string>
#include <iostream> 
#include <fstream> 
#include <time.h>

using namespace std;

int const n=10;

bool checkmult(vector<string> &A, unordered_map<string,int> &memoize) {  
	int pos=0;
	string test={};
	for (auto w : memoize)
	test=test+w.first;
	for (int y=0;y<test.size();++y) {
	for (int x=y+1;x<test.size();++x) {
		if (test[x]==test[y]) pos=1;
}
}

if (pos==0) {
return false;
}
else return true;
}

void addTerms(vector<string> &A, unordered_map<string,int> &memoize,int &count,int ind) {
	unordered_map<string,int>::iterator it;
	for (int q=0;q<n;++q) {
		if (memoize.find(A[q]) == memoize.end()) {
			memoize[A[q]]=ind;
			if (checkmult(A,memoize)==false) {			
			++count;
			if (ind<A.size()-1) {
			++ind;
			addTerms(A,memoize,count,ind);
			--ind;
		}
}
memoize.erase(A[q]);
}
}
}

int solution(vector<string> &A) {
	string test;
	unordered_map<string,int> memoize;
	vector<string> B=A;
	int pos=0;
	int tot=0;
	int count=0;
	int ind=0;
	addTerms(A,memoize,count,ind);
return count;
}


int main() 
{
int t;
vector<string> A {"ab","cd","ef","gh","ij","kl","mn","op","qr","st"};
t=solution(A);
cout << "solution:" << t << "\n";
return 0;
}
