#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
typedef pair<int, int> PII;

vector<PII> norm(vector<PII> ret){
    vector<PII>fin_ret; 
    int min_i = 100, min_j = 100;
    for (auto [i, j]:ret){
	min_i = min(i, min_i);
	min_j = min(j, min_j);
    }
    for (auto [a, b]: ret){
	fin_ret.emplace_back(a - min_i, b - min_j);
    }
    sort(fin_ret.begin(), fin_ret.end());
    return fin_ret;
}
vector<PII> get_p(vector<string>grid){
    vector<PII>ret;
    vector<PII>fin_ret;
    for (int i = 0; i < 4;++i){
	for (int j = 0; j < 4;++j){
	    if (grid[i][j] == '.')continue;
	    ret.emplace_back(i, j);
	}
    }
    return norm(ret);
}

vector<PII>rotate_90(vector<PII>&pattern){
    vector<PII>ret;
    for (auto [y, x]: pattern){
	/*
	   90° clockwise rotation: (𝑥,𝑦)
	   becomes (𝑦,−𝑥)
	   */
	ret.emplace_back(-x, y);
    }
    return norm(ret);
}


set<vector<PII>> get_c(vector<PII>pattern){
    set<vector<PII>> ret;
    ret.insert(pattern);
    auto new_pattern90 = rotate_90(pattern);
    auto new_pattern180 = rotate_90(new_pattern90);
    auto new_pattern270 = rotate_90(new_pattern180);
    auto new_pattern360 = rotate_90(new_pattern270);
    ret.insert(new_pattern90);
    ret.insert(new_pattern180);
    ret.insert(new_pattern270);
    ret.insert(new_pattern360);
    return ret;
}

void update_c(vector<PII>&c, vector<vector<int>> &seen, int i, int j, int v){
    for (auto [di, dj]:c){
	seen[i + di][j + dj] = v;
    }
}
bool can_put(vector<PII>&c, vector<vector<int>> &seen, int i, int j){
    for (auto [di, dj]:c){
	int ii = i + di, jj = j +dj;
	if (ii < 0 || ii >= 4 || jj <0 || jj >= 4 || seen[ii][jj])return false;
    }
    return true;
}
bool dfs(vector<vector<vector<PII>>>&steps,  vector<vector<int>> &seen, vector<int>&seen_step){
    for (int i = 0; i < 4;++i){
	for (int j = 0; j < 4; ++j){
	    if (seen[i][j])continue;
	    for (int step = 0; step < 3; ++step){
		if (seen_step[step])continue;
		for (auto c: steps[step]){
		    if (can_put(c, seen, i, j)){
			seen_step[step] = 1;
			if (seen_step[0] == 1 && seen_step[1] == 1 && seen_step[2] == 1)return true;
			update_c(c, seen, i, j, 1);
			if (dfs(steps, seen, seen_step)){
			    return true;
			}
			seen_step[step]=false;
			update_c(c, seen, i, j, 0);
		    }
		}
	    }
	}
    }
    return false;
}
int main(){
    vector<string>grid(4);
    vector<vector<PII>> patterns;
    int cnt = 0;
    for (int i = 0; i <3;++i){
	for (int j = 0; j < 4;++j){
	    cin >> grid[j];
	    for (int jj = 0; jj < 4;++jj){
		if (grid[j][jj] == '#')cnt ++;
	    }
	}
	patterns.push_back(get_p(grid));
    }
    if (cnt != 16){
	cout <<"No"<<endl;
	return 0;
    }
    vector<set<vector<PII>>> candidates(3);
    for (int i = 0; i < 3; ++i){
	candidates[i] = get_c(patterns[i]);
    }
    vector<vector<vector<PII>>> steps(3);
    for (int i = 0; i < 3;++i){
	for (auto c: candidates[i]){
	    steps[i].push_back(c);
	}
    }
    vector<vector<int>> seen(4, vector<int>(4, 0));
    vector<int>seen_step(3, 0);
    auto ret = dfs(steps, seen, seen_step);
    string fin_ret = ret?"Yes":"No";
    cout << fin_ret << endl;
    return 0;
}
