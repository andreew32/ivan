#include <iostream>
#include <cmath>

class Point {
private:
    int x, y;
    double r, a;
    static int partition(Point vec[], int lt, int rt) {
        Point pivot(vec[rt]);
        int i = lt - 1;
        for (int j = lt; j <= rt - 1; j++) {
            if (vec[j] < pivot) {
                i++;
                std::swap(vec[i], vec[j]);
            }
        }
        std::swap(vec[i + 1], vec[rt]);
        return i + 1;
    }
    static void quickSort(Point vec[], int lt, int rt) {
        if (lt < rt) {
            int mid = partition(vec, lt, rt);
            quickSort(vec, lt, mid - 1);
            quickSort(vec, mid + 1, rt);
        }
    }
    friend bool operator < (Point const& p1, Point const& p2) {
        return p1.a < p2.a;
    }
    void polarPoint() {
        r = sqrt(x * x + y * y);
        a = atan2(y,x);
    }
public:
    Point(const Point& p) {
        x = p.x;
        y = p.y;
        r = p.r;
        a = p.a;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
        polarPoint();
    }
    Point() {}
    void get(int& x, int& y) {
        x = this->x;
        y = this->y;
    }
    static void sort(Point vec[], int n) {
        quickSort(vec, 0, n - 1);
    }
};
int main()
{
    unsigned n;
    std::cin >> n;
    Point* p = new Point[n];
    for (unsigned i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        p[i] = Point(x, y);
    }
    sort(p, n);
    for (unsigned i = 0; i < n; i++) {
        p
    }
    delete[] p;
    return 0;
}
