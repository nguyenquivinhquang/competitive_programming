#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
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
template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}
Point<double>  house[5], goat;
double len(Point<double> a, Point<double> b) {
    return sqrt((a.x - b.x)*(a.x - b.x)+(a.y - b.y)*(a.y - b.y));
}
double check(Point<double> a, Point<double> b) {
    double res = 0;
    if (lineInter(goat, a,a, b).second == a) {
         res = len(goat, a);
    }
    if (lineInter(goat, b,b, a).second == a) {
         res = max(len(goat, b),res);
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
   
    cin >> goat.x >> goat.y;
    cin >> house[1].x >> house[1].y >> house[3].x >> house[3].y;
    house[2].x = house[1].x; house[2].y = house[3].y;
    house[4].x = house[3].x; house[4].y = house[1].y;
    double res = 1e8;
    for (int i = 1; i <= 4;i++) res = min(res, len(goat,house[i]));
    if (house[1].x <= goat.x && goat.x < house[3].x) {
        Point<double> temp;
        temp.x = goat.x; temp.y = house[1].y;
        res  = min(res, len(temp,goat));
        temp.y = house[3].y;
        res  = min(res, len(temp,goat));
    }
    cerr << res << endl;
    if (house[1].y <= goat.y && goat.y < house[3].y) {
        Point<double> temp;
        temp.y = goat.y;
        temp.x = house[1].x;
        res  = min(res, len(temp,goat));
        temp.x = house[3].x;
        res  = min(res, len(temp,goat));
    }
    cout <<fixed << setprecision(3) << res;
    
}
