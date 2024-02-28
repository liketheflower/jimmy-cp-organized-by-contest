#include<vector>
#include<iostream>
#include<set>
using namespace std;
const int car = 0;
const int train = 1;
const long long INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int, int> PII;
typedef long long LL;
int main(){
    LL ret=0;
    int n, A, B, C;
    cin >> n >>A>>B>>C;
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i){
	for (int j = 0; j < n; ++j){
	    cin >> grid[i][j];
	}}
    vector<LL>dis_car(n, INF);
    vector<LL>dis_train(n, INF);
    dis_car[0] = 0;
    dis_train[0] = 0;
    set<pair<LL, PII>> candidate;
    for (int i = 1; i < n;++i){
	candidate.insert(make_pair(INF, make_pair(i, car)));
	candidate.insert(make_pair(INF, make_pair(i, train)));
    }
    candidate.insert(make_pair(0,make_pair(0, train)));
    candidate.insert(make_pair(0,make_pair(0, car)));
    while (!candidate.empty()){
	auto [cost, idx_type] = *candidate.begin();candidate.erase(candidate.begin());
	auto [i, type] = idx_type;
	//cout << "i -----" <<i<< " type" << type << endl;
	for (int j = 0; j < n; ++j){
	    // if train can not take car
	    LL this_cost_by_train = (LL)grid[i][j] * (LL)B + (LL)C;
	    // can only take train
	    if (cost + this_cost_by_train < dis_train[j]){
		candidate.erase(make_pair(dis_train[j], make_pair(j, train)));
		dis_train[j] = cost + this_cost_by_train;
		candidate.insert(make_pair(dis_train[j], make_pair(j, train)));
	    }
	    if (type == car) {
		// can also take car
		LL this_cost_by_car = (LL)grid[i][j]*(LL)A;
		//cout << "j" << j <<"this_cost_by_car " <<this_cost_by_car << " "<<dis_car[j]<<endl; 
		if (cost + this_cost_by_car < dis_car[j]){
		    candidate.erase(make_pair(dis_car[j], make_pair(j, car)));
		    dis_car[j] = cost + this_cost_by_car;
		    candidate.insert(make_pair(dis_car[j], make_pair(j, car)));
		}
	    }
	}
    }
    /*
    for (int i = 0; i < n; ++i){
	cout << i <<" car "<<dis_car[i] <<" train: " << dis_train[i] <<endl;
    }
    */
    cout << min(dis_train[n-1], dis_car[n-1])<<endl;


    return 0;
}
