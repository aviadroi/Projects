#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cstdlib> 
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <iterator> 
#include <iostream> 
#include <fstream> 
#include <time.h>
#include <bits/stdc++.h>

using namespace std;

void add(int ind, vector<vector<int>> &m1, vector<int> m2, int &score, int sum) {
if (m1[0][ind]>m2.back()) {
	m2.push_back(m1[0][ind]);
	sum=sum+m1[0][ind];
}
	while (ind<m1[0].size()-1) {
	add(ind+1,m1,m2,score,sum);
	++ind;
}
if ((sum>score) && (ind==m1[0].size()-1)) {
score=sum;
m1[1]=m2;
list<int> mylist;
mylist.insert(mylist.begin(), m1[1].begin()+1, m1[1].end());
m1[1]={};
m1[1].insert(m1[1].begin(), mylist.begin(), mylist.end());
}
}

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
vector<vector<int>> m1 {{0},{0}};
m1[0]=array;
int score=-100000,ind=0;
vector<int> m2 {};
for (int r=0;r<array.size();++r) {
m2.push_back(-100000);
add(r,m1,m2,score,0);
m2={};
}
return {{score},m1[1]};
}

int main() 
{
//vector<int> array {10, 15, 4, 5, 11, 14, 31, 25, 31, 23, 25, 31, 50};
//vector<int> array {5,4,3,2,1};
//vector<int> array {1,2,10,3,5,6};
vector<int> array {10, 15, 4, 5, 11, 14};
//vector<int> array {-1};
vector<vector<int>> result;
result=maxSumIncreasingSubsequence(array);
cout << "score: " << result[0][0] << "\n";
cout << "resulting array: ";
for (int t=0;t<result[1].size();++t)
cout << result[1][t] << " ";
cout << "\n";
return 0;
}
