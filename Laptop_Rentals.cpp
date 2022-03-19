// You're given a list of time intervals during
// which students at a school need a laptop.
// These time intervals are represented by pairs
// of integers [start, end] , where
// 0 <= start < end . However, start and
// end don't represent real times; therefore,
// they may be greater than 24 .
// No two students can use a laptop at the same
// time, but immediately after a student is done
// using a laptop, another student can use that
// same laptop. For example, if one student rents
// a laptop during the time interval [0, 2] ,
// another student can rent the same laptop
// during any time interval starting with 2 .
// Write a function that returns the minimum
// number of laptops that the school needs to
// rent such that all students will always have
// access to a laptop when they need one.

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
