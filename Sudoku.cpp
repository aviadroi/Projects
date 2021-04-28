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

int const c=9;
int const d=3;

void fill(vector<vector<int>> &board, unordered_map<int,int> &hash1,unordered_map<int,int> &hash2,unordered_map<int,int> &hash3, int y, int x, int &z) {
	unordered_map<string,int>::iterator it;
	int t=0;
	int r=0;
	if (board[y][x]==0) {
		for (r=1;r<c+1;++r) {
			if ((hash1.find(100000*y+r)==hash1.end()) && (hash2.find(5000*x+r)==hash2.end()) && (hash3.find(300*y+15*x-(x%d)*15-(y%d)*300+r)==hash3.end())) {
				hash1[100000*y+r]=board[y][x];
				hash2[5000*x+r]=board[y][x];
				hash3[300*y+15*x-(x%d)*15-(y%d)*300+r]=board[y][x];
				board[y][x]=r;
				if ((y==c-1) && (x==c-1)) {
				r=c+1;
				z=1;
}
				else {
				y=y+(x==c-1);
				x=x+(x<c-1)-(c-1)*(x==c-1);
				t=1;
				fill(board,hash1,hash2,hash3,y,x,z);
				if (z==0) {
				y=y-(x==0);
				x=x-(x>0)+(c-1)*(x==0);
				hash1.erase(100000*y+r);
				hash2.erase(5000*x+r);
				hash3.erase(300*y+15*x-(x%d)*15-(y%d)*300+r);
				board[y][x]=0;
}
}
}
}
}
if ((t==0) && ((y<c-1) || (x<c-1)) && (r<c+1)) {
	y=y+(x==(c-1));
	x=x+(x<(c-1))-(c-1)*(x==(c-1));
	fill(board,hash1,hash2,hash3,y,x,z);
}
if ((y==c-1) && (x==c-1) && (t==1)) z=1;
}


vector<vector<int>> solveSudoku(vector<vector<int>> board) {
  unordered_map<int,int> hash1,hash2,hash3;
  unordered_map<int,int>::iterator it;
  int z=0,y=0,x=0;
  for (int n=0;n<board.size();++n) {
	  for (int m=0;m<board.size();++m) {
		  if (board[n][m]!=0) {
			  hash1[100000*n+board[n][m]]=board[n][m];
			  hash2[5000*m+board[n][m]]=board[n][m];
			  hash3[300*n+15*m-(x%d)*15-(y%d)*300+board[n][m]]=board[n][m];
}
}
}
fill(board,hash1,hash2,hash3,y,x,z);
return board;
}


int main() 
{
int t;
//vector<vector<int>> A {{0,2,0,0,9,0,1,0,0},{0,0,7,8,0,0,0,0,0},{0,0,0,0,0,0,3,6,0},{0,0,1,9,0,4,0,0,0},
//	{0,0,0,6,0,5,0,0,7},{8,0,0,0,0,0,0,0,9},{0,0,0,0,2,0,0,0,0},{7,0,0,0,0,0,0,8,5},{4,9,0,0,3,0,0,0,0}};
//vector<vector<int>> A {{0,0,9,0,0,0,0,4,0},{0,0,0,0,0,6,0,0,3},{0,0,6,0,0,0,0,0,9},{0,0,5,0,0,0,0,9,0},
//	{0,0,0,3,0,0,0,0,8},{0,4,0,0,0,1,0,0,0},{1,3,0,0,0,0,0,0,6},{0,0,0,0,5,2,0,0,0},{0,0,0,0,9,0,0,0,0}};
//vector<vector<int>> A {{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},
//	{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}};
vector<vector<int>> A {{0,0,0,0,0,6,0,0,5},{0,0,9,0,5,8,0,0,0},{0,0,1,0,0,0,9,2,0},{0,0,0,0,0,0,2,0,0},
	{7,4,0,0,0,0,3,0,0},{0,3,0,0,0,0,0,0,7},{9,0,0,0,1,3,0,7,0},{2,5,0,0,9,0,8,0,0},{0,0,0,0,0,0,0,4,0}};
vector<vector<int>> B=solveSudoku(A);
for (int y=0;y<B.size();++y) {
for (int x=0;x<B.size();++x) {
cout << B[y][x] << " ";
}
cout << "\n";
}
return 0;
}
