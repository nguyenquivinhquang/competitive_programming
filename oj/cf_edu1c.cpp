// Jisoo so cute
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define double long double
const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
    
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};
vector<pair<Point<double>, int> > p, t;
int n;
bool cmp(pair<Point<double>, int> a, pair<Point<double>, int> b) {
    return a.first.angle() < b.first.angle();
}
int res1, res2;
double res = 100000000;
double _angle(Point<double> a, Point<double> b) {
    return abs(acos((a.x * b.x + a.y * b.y) / (a.dist() * b.dist())));
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        Point<double> point(x, y);
        p.push_back({point, i});
    }
    sort(p.begin(), p.end(), cmp);
    t = p;
    for (auto v : p) t.push_back(v);
    for (int i = 1; i < 2 * n; i++) {
        double angle = _angle(t[i].first, t[i-1].first);
        long long jisoo = angle / 360;
        angle   -= jisoo * 360.0;
        angle = abs(angle);
        angle = min(angle, 360.0 - angle);
        if (angle < res) {
            res = angle;
            res1 = t[i].second;
            res2 = t[i-1].second;
        }
    }
    cout << res1 << " " << res2;
    
}
