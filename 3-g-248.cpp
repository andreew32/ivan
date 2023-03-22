#include <iostream>
#include <cmath>

//чтобы пользоваться числом Pi
#define _USE_MATH_DEFINES

//класс точки
class Point {
private:
    double x, y; //стандартные координаты
    double r, a; //полярные координаты
    int index; //порядковый номер точки от начала ввода в программу
    //для метода быстрой сортировки метод деления
    static int partition(Point arr[], int start, int end) {
        Point pivot = Point(arr[start]);
        int count = 0;
        for (int i = start + 1; i <= end; i++) {
            if (arr[i] <= pivot)
                count++;
        }

        //задаем осевому элементу его правильную позицию
        int pivotIndex = start + count;
        std::swap(arr[pivotIndex], arr[start]);

        //сортируем по левую и по правую сторону от осевого элемента
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
    //метод быстрой сортировки
    static void quickSort(Point arr[], int start, int end)
    {

        //базовый случай
        if (start >= end)
            return; //сразу выходим из сортировки

        //разбиваем массив
        int p = partition(arr, start, end);

        //сортируем левую часть
        quickSort(arr, start, p - 1);

        //сортируем правую часть
        quickSort(arr, p + 1, end);
    }
    //перегрузка оператора сравнения для удобства написания сортировки
    friend bool operator <= (Point const& p1, Point const& p2) {
        return p1.a <= p2.a; //сравниваем только по углу
    }
    friend bool operator > (Point const& p1, Point const& p2) {
        return p1.a > p2.a;
    }
    //метод вызывается несколькими конструкторами
    void init(double x, double y) {
        this->x = x;
        this->y = y;
    }
public:
    //создание копии существующей точки
    Point(Point const& p) {
        this->x = p.x;
        this->y = p.y;
        this->r = p.r;
        this->a = p.a;
        this->index = p.index;
    }
    //создание точки с координатами без порядкового номера
    Point(double x, double y) {
        init(x, y);
    }
    //создание точки с координатами и порядковым номером
    Point(double x, double y, unsigned i) {
        init(x, y);
        this->index = i;
    }
    //заглушка конструктора
    Point() {}
    //перевод в полярные координаты
    void polarPoint(Point& c) {
        double x = this->x - c.x;
        double y = this->y - c.y;
        r = sqrt(x * x + y * y);
        a = atan2(y,x);
        if (a < 0) //если отрицательный угол, то переводим в положительный
            a += 2 * M_PI;
    }
    //вывод координат в две заданные переменные
    void get(double& x, double& y) {
        x = this->x;
        y = this->y;
    }
    //сортировка быстрой сортировкой по углу
    static void sort(Point vec[], int n) {
        quickSort(vec, 0, n - 1);
    }
    //нахождение геометрического центра совокупности заданных точек
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
    //получение порядкового номера точки
    unsigned i() {
        return this->index;
    }
    //установка порядкового номера
    void setIndex(unsigned i) {
        this->index = i;
    }
};
int main() {
    unsigned n;
    std::cin >> n; //ввод количества точек
    Point* p = new Point[n];
    for (unsigned i = 0; i < n; i++) { //ввод точек
        int x, y;
        std::cin >> x >> y;
        p[i] = Point(x, y, i + 1); //c++ считает от нуля, поэтому +1
    }

    Point center = Point::average(p, n); //нахождение середины точек
    for (unsigned i = 0; i < n; i++) //добавление полярных координат точкам
        p[i].polarPoint(center);

    Point::sort(p, n); //сортировка точек по углам
    for (unsigned i = 0; i < n; i++) {
        std::cout << p[i].i() << " ";
    }
    std::cout << std::endl;
    delete[] p; //очищение памяти от точек
    return 0;
}
