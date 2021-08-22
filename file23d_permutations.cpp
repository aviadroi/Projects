// A program which takes an array of integers and returns an arryay of all the permutations of those integers.
// The algorithm here is my alternative to the classical way of iterating through lists of numbers.
// Instead, there is an iteration through indices of adjacent integers which permute with each other.

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

using namespace std;

void check(int &count,vector<vector<int>> &m2) {
int tic=0;
int id=0;
for (int p=0;p<count;++p) {
for (int s=0;s<m2[0].size();++s) {
if (m2[p][s]==m2[count][s]) ++id;
}
if (id==m2[0].size()) tic=1;
id=0;
}
count=count+(tic==0);
}

void perm(vector<vector<int>> &m2, vector<int> m3, int &count, int index) {
if (index==m3.size()-1) {
m2[count]=m3;
++count;
perm(m2,m3,count,index-1);
}
//m3=m2[count-1];
if (index>0) perm(m2,m3,count,index-1);
if (index>-1) {
for (int q=index;q<m3.size()-1;++q) {
for (int k=0;k<m3.size();++k) {
if (k!=q) {
m2[count][k]=m3[k];
}
else {
m2[count][k]=m3[k+1];
m2[count][k+1]=m3[k];
++k;
}
}
m3=m2[count];
check(count,m2);
if (index>0) perm(m2,m3,count,index-1);
}
}
}

vector<vector<int>> getPermutations(vector<int> m3) {
int count=0;
int m5 = tgamma(m3.size()+1), n = m3.size();
if (m3.size()>5) ++m5;
vector<vector<int>> m2(m5*100, vector<int> (n, 0));
cout << "index" << m3.size()-1 << "\n";
perm(m2,m3,count,m3.size()-1);
vector<vector<int>> mres(m5, vector<int> (n, 0));
for (int y=0;y<count;++y) {
for (int x=0;x<m3.size();++x) {
mres[y][x]=m2[y][x];
}
}
return mres;
}

int main() 
{
int h;
vector<int> m1 {1,2,3,4,5,6,7,8};
vector<vector<int>> m;
m=getPermutations(m1);
ofstream myfile2;
myfile2.open("txtout1.txt");
for (int i=0;i<m.size();++i) {
for (int j=0;j<m[0].size();++j) {
myfile2 << m[i][j] << " ";
}
myfile2 << "\n";
}
myfile2.close();
cout << "total size:" << m.size() << "\n";
cout << "vector size:" << m1.size() << "\n";
cout << "m5:" << tgamma(m1.size()+1) << "\n";
return 0;
}
