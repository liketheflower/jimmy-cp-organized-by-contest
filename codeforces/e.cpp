#include<iostream>
using namespace std;

const int WIN = 0, LOSE = 1, TIE = 2;
const int ALICE = 0;
bool win(int l1, int r1, int l2, int r2){
    if (l1 - l2 <= 1 && r1 - r2 >= -1)return true;
    return false;
    if ((r2 - l2) > 2){
	return false;
    }
    if ((r2-l2) == 1){
	return (l1<=l2 && r1 >= l2 ) || (l1<=r2 && r1 >= r2);
    } else if ((r2-l2) == 0){
//	cout <<"l1<=l2 && r1 >= l2" << (l1<=l2 && r1 >= l2) <<endl;
	return (l1<=l2 && r1 >= l2);
    } else/*=3*/ {
	l2++;
	return (l1<=l2 && r1 >= l2 );
    }
}
void solve(){
int h, w, i1, j1, i2, j2;cin>>h>>w>>i1>>j1>>i2>>j2;
int ret = 0;
int l1 = j1, r1 = j1;
int l2 = j2, r2 = j2;
int turn = 0;
while (true){
   // cout <<"turn"<<turn<<" i1 "<<i1<<" l1 "<<l1<<" r1 "<<r1<<endl;
   // cout <<"turn"<<turn<<" i2 "<<i2<<" l2 "<<l2<<" r2 "<<r2<<endl;
    if (i2 == 1 || i1 == h){
	ret = TIE;
	break;
    }
    if ((i2 - i1) == 1){
	if (turn%2 ==ALICE){
	    if (win(l1, r1, l2, r2)){
	    ret = WIN;
	    break;
	    }
	} else {
	    if (win(l2, r2, l1, r1)){
	    ret = LOSE;
	    break;
	    }
	}
    }
    if (turn %2==ALICE){
    l1--;r1++;
    l1 = max(1, l1);
    r1 = min(r1, w);
    i1++;
    }else{
    l2--;r2++;
    l2 = max(1, l2);
    r2 = min(r2, w);
    i2--;
    }
    turn++;
}

if (ret == WIN){
cout <<"Alice"<<endl;
}else if (ret==LOSE){
cout <<"Bob"<<endl;
}else {
    cout <<"Draw"<<endl;
}

}
int main(){
int T; cin >> T;
while (T--){
solve();
}
    return 0;
}
