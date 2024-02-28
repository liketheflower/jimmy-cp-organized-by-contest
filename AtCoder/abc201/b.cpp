#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


void getInput(vector<pair<int, string>>& mountains)
{
  int N;
  cin >> N;
  int height;
  string name;
  while (N--) 
  {
    cin >> name;
    cin >> height;
    mountains.emplace_back(height, name);
  }
  sort(mountains.rbegin(), mountains.rend());
  cout << mountains[1].second << endl;
  return;
}
int main()
{
  vector<pair<int, string>> mountains;
  mountains.reserve(100000);
  getInput(mountains);
  return 0;
}
