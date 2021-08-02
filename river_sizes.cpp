// The program consists of a function which returns the "river" sizes in a matrix.
// It also writes the total number of the rivers.
// "A river" is defined as the collection of adjacent (horizontally or vertically) 
// matrix elemnts with the value 1 (the value 0 represents "land").

#include <iostream>
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


int checkriv(vector<vector<int>> &matrix, vector<vector<int>> &riv, int &count, int y, int x) {
	riv.push_back({y,x});
	if ((y>0) && (matrix[y-1][x]==1)&&(find(riv.begin(), riv.end(), (vector<int>){y-1,x}) == riv.end())) 
	checkriv(matrix,riv,++count,y-1,x);
	if ((y<matrix.size()-1) && (matrix[y+1][x]==1)&&(find(riv.begin(), riv.end(), (vector<int>){y+1,x}) == riv.end()))
	checkriv(matrix,riv,++count,y+1,x);
	if ((x>0) && (matrix[y][x-1]==1)&&(find(riv.begin(), riv.end(), (vector<int>){y,x-1}) == riv.end()))
	checkriv(matrix,riv,++count,y,x-1);
	if ((x<matrix[0].size()-1) && (matrix[y][x+1]==1)&&(find(riv.begin(), riv.end(), (vector<int>){y,x+1}) == riv.end()))
	checkriv(matrix,riv,++count,y,x+1);
	return count;
	}

vector<int> riverSizes(vector<vector<int>> matrix) {
	vector<vector<int>> riv;
	vector<int> coord;
	vector<int> cnt {};
	int count;

  for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
			    if ((matrix[i][j]==1) && (find(riv.begin(), riv.end(), (vector<int>){i,j}) == riv.end())) {
					count=1;
					cnt.push_back(checkriv(matrix, riv, count, i, j));
					count=0;
			}
			}
        }
    cout << "riv:\n";
    for (int i = 0; i < riv.size(); i++)
    {
        for (int j = 0; j < riv[i].size(); j++) {
			cout << riv[i][j] << " ";
	}
        cout << "\n";
	}
  return cnt;
}

int main() 
{
int h=1;
vector<int> m0{};
vector<vector<int>> m1
{
        {1, 0, 1, 0, 0, 0, 0},
        {1, 0, 1, 1, 1, 1, 0},
        {0, 0, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1}
};
m0=riverSizes(m1);
for (int j = 0; j < m0.size(); j++)
        {
            cout << m0[j] << " ";
        } 
cout << "\ncount=" << h << "\n";
return 0;
}
