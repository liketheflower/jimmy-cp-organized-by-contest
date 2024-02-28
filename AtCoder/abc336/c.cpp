#include<iostream>
#include<vector>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
int main(){
    int n, k;
    cin >> n >> k;
    vector<int>vals(k, 0);
    for (int i = 0; i < k; ++i)cin >> vals[i];
    vector<int>colors(2*n -k, 0);
    int j = 0;
    int idx = 0;
    for (int i =1 ; i <= n; ++i){
	if (j < k && i == vals[j]){
	    colors[idx++] = i;
	    j++;
	}else{
	    colors[idx++] = i;
	    colors[idx++] = i;
	}
    }
    int M = 2*n - k;
    int H = M /2;
    int ret = INF;
    int this_ret;
    if (M &1){
	vector<int>rets1(H, 0);
	vector<int>rets2(H, 0);

	for (int i = 0; i < H; ++i){
	rets1[i] = colors[(i<<1) + 1] - colors[i<<1];
	rets2[i] = colors[(i<<1) + 2] - colors[(i<<1) + 1];
         }
	vector<LL>cusum1(H + 1, 0);
	vector<LL>cusum2(H + 1, 0);
	for (int i = 0; i < H; ++i){
	    cusum1[i+1] = cusum1[i] +(LL) rets1[i];
	    cusum2[i+1] = cusum2[i] +(LL) rets2[i];
	}
	for (int i = 0 ; i < M; ++i){
	    int left, right;
	    int this_left, this_right;
	    if (i&1){
		left = (i >> 1) - 1;

		right = (i + 2) >> 1;
		if (left == -1)                                                      
		    this_left = 0;                                                           
		else                                                                       
		    this_left = cusum1[left];                                            
		this_right = cusum2.back()- cusum2[right];

		this_ret = this_left + this_right + colors[i + 1] - colors[i - 1];
	    }else{
		left = i >> 1;
		right = i >>1;
		this_left = cusum1[left];
		this_right = cusum2.back() - cusum2[right];
		this_ret = this_left + this_right;

	    }
	    ret = min(ret, this_ret);
	}
    }	else {
	ret = 0;
	for (int i = 0; i < H; ++i){
	    ret += colors[(i << 1) + 1] - colors[i<<1];  
	}	    
    }
    cout << ret <<endl;
}

/*
   n, k = [int(c) for c in input().split()]
   vals = [int(c) for c in input().split()]
   colors = []
   j = 0
   debug = False
   for i in range(1, n + 1):
   if j < k and i == vals[j]:
   j += 1
   colors.append(i)
else:
colors += [i, i]

M = len(colors)
if debug:
print(colors)
ret = 0 
H = M // 2
if M % 2 == 0:
for i in range(0, H):
ret += colors[i*2 + 1] - colors[i*2]
else:
rets = []
rets1 = [colors[i*2 + 1] - colors[i*2] for i in range(H)]
cusum1 = [0]*(H + 1)
cusum2 = [0]*(H + 1)
rets2 = [colors[i*2 + 2] - colors[i*2 + 1] for i in range(H)]
for i in range(H):
cusum1[i+1] = cusum1[i] + rets1[i]
cusum2[i+1] = cusum2[i] + rets2[i]
if debug:
print(rets1)
print(rets2)
print(cusum1)
print(cusum2)
for i in range(M):
# skip current one
if i % 2 == 0:
"""
0 1 (2) 3 4
"""
left = i // 2
right = i // 2
if left  >= H:
this_left = cusum1[-1]
else:
this_left = cusum1[left]
this_right = cusum2[-1] - cusum2[right]
# print("left, right, this left, this rith", left, right, this_left, this_right)
rets.append(this_left + this_right)
else:
"""
0 1 2 (3) 4 5
I have to connect 2 and 4
"""
left = (i // 2) - 1
right = (i + 2) // 2
if left == -1:
this_left = 0
else:
if left>= H:
this_left = cusum1[-1]
else:
this_left = cusum1[left]
this_right = cusum2[-1] - cusum2[right]
rets.append(this_left + this_right + colors[i + 1] - colors[i - 1])
#print(i, rets[-1])
ret = min(rets)
print(ret)

*/




