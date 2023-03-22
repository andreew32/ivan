#include <iostream>
#include <cmath>
#include <fstream>

std::ifstream in;
std::ofstream out;

#define _USE_MATH_DEFINES
int glob = 0;
class Point {
private:
    double x, y;
    double r, a;
    int index;
    static int partition(Point arr[], int start, int end) {
        out << "glob " << glob << std::endl;
        glob++;
        Point pivot = Point(arr[start]);
        int count = 0;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] <= pivot)
                count++;
        }

        // Giving pivot element its correct position
        int pivotIndex = start + count;
        std::swap(arr[pivotIndex], arr[start]);

        // Sorting left and right parts of the pivot element
        int i = start, j = end;

        while (i < pivotIndex && j > pivotIndex) {

            while (arr[i] <= pivot) {
                i++;
            }

            while (arr[j] > pivot) {
                j--;
            }

            if (i < pivotIndex && j > pivotIndex) {
                std::swap(arr[i++], arr[j--]);
            }
        }

        return pivotIndex;
    }

    static void quickSort(Point arr[], int start, int end)
    {

        // base case
        if (start >= end)
            return;

        // partitioning the array
        int p = partition(arr, start, end);

        // Sorting the left part
        quickSort(arr, start, p - 1);

        // Sorting the right part
        quickSort(arr, p + 1, end);
    }

    friend bool operator <= (Point const& p1, Point const& p2) {
        return p1.a <= p2.a;
    }
    friend bool operator > (Point const& p1, Point const& p2) {
        return p1.a > p2.a;
    }
    void init(double x, double y) {
        this->x = x;
        this->y = y;
    }
public:
    Point(Point const& p) {
        this->x = p.x;
        this->y = p.y;
        this->r = p.r;
        this->a = p.a;
        this->index = p.index;
    }
    Point(double x, double y) {
        init(x, y);
    }
    Point(double x, double y, unsigned i) {
        init(x, y);
        this->index = i;
    }
    Point() {}
    void polarPoint(Point& c) {
        double x = this->x - c.x;
        double y = this->y - c.y;
        r = sqrt(x * x + y * y);
        a = atan2(y,x);
        if (a < 0)
            a += 2 * M_PI;
    }
    void get(double& x, double& y) {
        x = this->x;
        y = this->y;
    }
    static void sort(Point vec[], int n) {
        quickSort(vec, 0, n - 1);
    }
    static Point average(Point vec[], int n) {
        double xs = 0, ys = 0;
        for (unsigned i = 0; i < n; i++) {
            double x, y;
            vec[i].get(x, y);
            xs += x;
            ys += y;
        }
        return Point(xs/(n*1.0), ys/(n*1.0));
    }
    unsigned i() {
        return this->index;
    }
    void setIndex(unsigned i) {
        this->index = i;
    }
};
int main() {
    in.open("in.txt", std::ios::in);
    out.open("out.txt", std::ios::out);
    unsigned n;
    in >> n;
    Point* p = new Point[n];
    for (unsigned i = 0; i < n; i++) {
        int x, y;
        in >> x >> y;
        p[i] = Point(x, y, i + 1);
    }
    for (unsigned i = 0; i < n; i++) {
        out << p[i].i() << " ";
    }
    out << std::endl;
    Point center = Point::average(p, n);
    for (unsigned i = 0; i < n; i++) {
        out << p[i].i() << " ";
    }
    out << std::endl;
    for (unsigned i = 0; i < n; i++)
        p[i].polarPoint(center);
    for (unsigned i = 0; i < n; i++) {
        out << p[i].i() << " ";
    }
    out << std::endl;
    Point::sort(p, n);
    for (unsigned i = 0; i < n; i++) {
        out << p[i].i() << " ";
    }
    out << std::endl;
    in.close();
    out.close();
    delete[] p;
    return 0;
}
