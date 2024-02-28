#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
   string name;cin>>name;
   unordered_map<string, int> m={{"tourist", 3858},
       {"ksun48", 3679},
       {"Benq", 3658},
{"Um_nik", 3648},
{"apiad" ,3638},
{"Stonefeang", 3630},
{"ecnerwala", 3613},
{"mnbvmar", 3555},
{"newbiedmy", 3516},
{"semiexp", 3481}};
   cout << m[name] <<endl;
return 0;
  }
