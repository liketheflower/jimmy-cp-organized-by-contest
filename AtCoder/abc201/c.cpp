#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int fact(int n)
{
  if (n <= 1) return 1;
  return fact(n-1)*n;
}

int helper(vector<int> cnt, int fact4) 
{
  int ret = fact4;
  for (int i = 0; i < 10; ++i)
  {
    if (cnt[i] > 1)
    {
        ret /= fact(cnt[i]);
    }
  }
  return ret;
}

int pickup_(vector<int> cnt, vector<int>& possible, int sum,int pickup, int fact4)
{
  int rest = 4 - sum;
  int thisret = 0;
  const int n = possible.size();
  if (pickup == 1) 
  {
      for (auto x : possible) 
      {
          vector<int> newcnt;
          newcnt = cnt;
          newcnt[x] += rest;
          thisret += helper(newcnt, fact4);
      }
  }
  if (pickup == 2)                                                                      
  {  
     for (int i = 0; i < n - 1; ++i)
     for (int j = i + 1; j < n; ++j)
     {
       vector<int> newcnt;
       newcnt = cnt;
       int thissum = sum;
       auto a = possible[i];
       auto b = possible[j];
       newcnt[a]++;
       newcnt[b]++;
       thisret += helper(newcnt, fact4); 
       int thisrest = 4 - (thissum - 2);
       if (thisret == 0)
       {
         thisret += helper(newcnt, fact4); 
         break;
       }
       for (int r = 1; r <= thisrest; ++r){
         if (r == 1)
         {
           vector<int> newcnt1;
           newcnt1 = newcnt;
           newcnt1[a]++;
           thisret += helper(newcnt1, fact4); 
           newcnt1[a]--;
           newcnt1[b]++;
           thisret += helper(newcnt1, fact4); 
         }
         if (r == 2)
         {
           vector<int> newcnt1;
           newcnt1 = newcnt;
           newcnt1[a]++;
           newcnt1[b]++;
           thisret += helper(newcnt1, fact4); 
         }
       }
     }                                                                    
  }      
  if (pickup == 3)                                                                      
  {  
     for (int i = 0; i < n - 2; ++i)
     for (int j = i + 1; j < n - 1; ++j)
     for (int k = j + 1; k < n; ++k)
     {
       vector<int> newcnt;
       newcnt = cnt;
       auto a = possible[i];
       auto b = possible[j];
       auto c = possible[k];
       newcnt[a]++;
       newcnt[b]++;
       newcnt[c]++;
       thisret += helper(newcnt, fact4); 
       int thisrest = 4 - (sum - 3);
       if (thisret == 0)
       {
         thisret += helper(newcnt, fact4); 
         break;
       }
       vector<int> newcnt1;                                                         
           newcnt1 = newcnt;                                                            
           newcnt1[a]++;                                                                
           thisret += helper(newcnt1, fact4);                                           
           newcnt1[a]--;                                                                
           newcnt1[b]++;                                                                
           thisret += helper(newcnt1, fact4); 
           newcnt1[b]--;                                                                
           newcnt1[c]++;                                                                
           thisret += helper(newcnt1, fact4); 
     }                                                                    
  }      
  if (pickup == 4)                                                                      
  {  
     for (int i = 0; i < n - 3; ++i)
     for (int j = i + 1; j < n - 2; ++j)
     for (int k = j + 1; k < n - 1; ++k)
     for (int q = k + 1; q < n; ++q)
     {
       vector<int> newcnt;
       newcnt = cnt;
       auto a = possible[i];
       auto b = possible[j];
       auto c = possible[k];
       auto d = possible[q];
       newcnt[a]++;
       newcnt[b]++;
       newcnt[c]++;
       newcnt[d]++;
       thisret += helper(newcnt, fact4); 
     }
  }                                                                    
  return thisret;
}

void count(vector<int> cnt, vector<int>& possible)
{
    for (auto p: possible) cout << p<< endl;
    int sum = 0, ret = 0;
    const int n = possible.size();
    for (int i = 0; i < 10; ++i) sum += cnt[i];
    int fact4 = fact(4);
    if (sum == 4) 
    { 
      cout << fact4;
      return;
    }
    /*
    sum = 0, pickup 1, 2, 3, 4
    sum = 1, pickup 1, 2, 3
    sum = 2, pickup 1, 2
    sum = 3, pickup 1
    */
    for (int pickup = 1; pickup <= min(4 - sum, n);++pickup)
    {
       auto thisret = pickup_(cnt, possible, sum, pickup, fact4);
       cout<< "pickup" << pickup << " " << thisret<<endl;
       ret += thisret;
    }
    cout << ret << endl;
    return;
}     

void solve(string key) 
{
  int ret = 0;
  vector<int> must;
  vector<int> possible;
  for (int i = 0; i < 10; ++i) 
  { 
    if (key[i] == 'o') must.push_back(i);
    if (key[i] == '?') possible.push_back(i);
  }
  const int m = must.size(), n = possible.size();
  if (m > 4 || (m ==0 && n == 0))
  {
     cout << ret << endl;
     return;
  }
  vector<int> currKey = must;
  vector<int> cnt(10, 0);
  for (auto x: must) 
  {
    cnt[x]++;
    possible.push_back(x);
  }
  count(cnt, possible);
}

int main()
{
  string key;
  cin >> key;
  solve(key);
  return 0;
}
