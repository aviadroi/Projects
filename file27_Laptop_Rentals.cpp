#include <iostream>
#include <cstdlib> 
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <iterator> 
#include <string>
#include <fstream> 
#include <time.h>

using namespace std;

vector<int> sort(vector<int> list) {
cout << "before:\n";
	for (int w=0;w<list.size();++w) {
		cout << list[w] << " ";
}
cout << "\n";
for (int q=list.size()-2;q>-1;--q) {
if (list[q]>list[q+1]) iter_swap(list.begin()+q,list.begin()+q+1);
}
cout << "after:\n";
	for (int w=0;w<list.size();++w) {
		cout << list[w] << " ";
}
cout << "\n";
return list;
}

int laptopRentals(vector<vector<int>> times) {
  vector<int> begin,end;
  int index=0,count=0,maxcount=0;
  for (int i=0;i<times.size();++i) {
	begin.push_back(times[i][0]);
	end.push_back(times[i][1]);
	begin=sort(begin);
	end=sort(end);
  }
  for (int j=0;j<times.size();++j) {
	  ++count;
	while (begin[j]>=end[index]) {
	--count;
	++index;
}
if (count>maxcount) maxcount=count;
}
  return maxcount;
}


int main() 
{
vector<vector<int>> times {{0, 5},
    {2, 4},
    {4, 7},
    {5, 7},
    {9, 20},
    {3, 15},
    {6, 10}};
int solution;
solution=laptopRentals(times);
cout << "solution" << solution << "\n";
return 0;
}
