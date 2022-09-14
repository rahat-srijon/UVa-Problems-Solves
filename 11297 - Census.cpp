#include<bits/stdc++.h>
using namespace std;
#define ll long long
struct seg {
	int mn, mx;
	seg operator=(seg X){
		mn=X.mn;
		mx=X.mx;
		return *this;
	}
	seg operator+(seg X){
		return{
			min(this->mn,X.mn),
			max(this->mx,X.mx)
		};
	}
} t[4 * 505 + 5][4 * 505 + 5];
int a[505 + 5][505 + 5], n;
void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = {a[lx][ly],a[lx][ly]};
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy*2, ly, my);
        build_y(vx, lx, rx, vy*2+1, my+1, ry);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}
void build_x(int vx, int lx, int rx) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        build_x(vx*2, lx, mx);
        build_x(vx*2+1, mx+1, rx);
    }
    build_y(vx, lx, rx, 1, 0, n-1);
}
seg get_y(int vx, int vy, int tly, int try_, int ly, int ry) {
    if (ly > ry) 
        return {INT_MAX,INT_MIN};
    if (ly == tly && try_ == ry)
        return t[vx][vy];
    int tmy = (tly + try_) / 2;
    return get_y(vx, vy*2, tly, tmy, ly, min(ry, tmy))
         + get_y(vx, vy*2+1, tmy+1, try_, max(ly, tmy+1), ry);
}
seg get_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
    if (lx > rx)
        return {INT_MAX,INT_MIN};
    if (lx == tlx && trx == rx)
        return get_y(vx, 1, 0, n-1, ly, ry);
    int tmx = (tlx + trx) / 2;
    return get_x(vx*2, tlx, tmx, lx, min(rx, tmx), ly, ry)
         + get_x(vx*2+1, tmx+1, trx, max(lx, tmx+1), rx, ly, ry);
}
void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y, int new_val) {
    if (ly == ry) {
        if (lx == rx)
            t[vx][vy] = {new_val,new_val};
        else
            t[vx][vy] = t[vx*2][vy] + t[vx*2+1][vy];
    } else {
        int my = (ly + ry) / 2;
        if (y <= my)
            update_y(vx, lx, rx, vy*2, ly, my, x, y, new_val);
        else
            update_y(vx, lx, rx, vy*2+1, my+1, ry, x, y, new_val);
        t[vx][vy] = t[vx][vy*2] + t[vx][vy*2+1];
    }
}
void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
    if (lx != rx) {
        int mx = (lx + rx) / 2;
        if (x <= mx)
            update_x(vx*2, lx, mx, x, y, new_val);
        else
            update_x(vx*2+1, mx+1, rx, x, y, new_val);
    }
    update_y(vx, lx, rx, 1, 0, n-1, x, y, new_val);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	build_x(1, 0, n - 1);
	int q;
	scanf("%d", &q);
	while (q--) {
		char O[2];
		scanf("%s", O);
		if (O[0] == 'c') {
			int x, y, v;
			scanf("%d %d %d", &x, &y, &v);
			update_x(1, 0, n - 1, x-1, y-1, v);
		}
		else {
			int x1, y1, x2, y2;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			seg ans = get_x(1, 0, n - 1, x1-1, x2-1, y1-1, y2-1);
			printf("%d %d\n", ans.mx, ans.mn);
		}
	}
	return 0;
}
