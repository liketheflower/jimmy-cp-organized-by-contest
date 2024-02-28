#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main(){
   int n;cin>>n;
   vector<int>a(n);
   for (int i =0; i <n;++i)cin>>a[i];
   long long ret = 0;
   if (n <= 1){ret = 0;cout << ret <<endl; return 0;} 

   multiset<int> ms(a.begin(), a.end());
   while (true){
       int f = *ms.begin();
      int l = *ms.rbegin();
    //cout << f << " before "<<l<<endl;
      ms.erase(ms.begin());
      ms.erase(--ms.end());
     if (l - f <= 1)break;
     int sub = (l - f) / 2;
     sub = (float)(sub)*((rand()%100 + 60)/100.0);
    ret += (long long)(sub);
    f += sub;
    l -= sub;
    //cout << f << " "<<l<<endl;
    ms.insert(f);
   ms.insert(l); 
   }
   cout << ret <<endl;
return 0;
  }
