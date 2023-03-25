#include <iostream>
#include <cstdint>

class Vect
{
private:
    bool allocated;
    static uint16_t partition(int32_t arr[], uint16_t start, uint16_t end)
    {
        int32_t pivot = arr[start];
        uint16_t count = 0;
        for (uint16_t i = start + 1; i <= end; i++) {
            if (arr[i] <= pivot)
                count++;
        }

        //задаем осевому элементу его правильную позицию
        uint16_t pivotIndex = start + count;
        std::swap(arr[pivotIndex], arr[start]);

        //сортируем по левую и по правую сторону от осевого элемента
        uint16_t i = start, j = end;

        while (i < pivotIndex && j > pivotIndex)
        {
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

    //функция быстрой сортировки
    static void quickSort(int32_t arr[], uint16_t start, uint16_t end)
    {

        //базовый случай
        if (start >= end)
            return; //сразу выходим из сортировки

        //разбиваем массив
        uint16_t p = partition(arr, start, end);

        //сортируем левую часть
        quickSort(arr, start, p - 1);

        //сортируем правую часть
        quickSort(arr, p + 1, end);
    }
public:
    uint16_t l;
    int32_t* a;
    int32_t& operator[](uint16_t i) {return a[i];}
    void allocate() {
        a = new int32_t[l];
        allocated = true;
    }
    Vect() {
        allocated = false;
    }
    ~Vect() {
        if (allocated)
            delete[] a;
    }
    sort() {quickSort(a, 0, l - 1);}
    Vect sum(Vect& v1, Vect& v2)
    {
        Vect s = new Vect();
        s.l = a.l * b.l;
        s.allocate();
        for (uint16_t i = 0, sumi = 0; i < v1.l; i++) //берем элемент a
        {
            for (uint16_t j = 0; j < v2.l; j++, sumi++) //взять b и пройти sumi
            {
                s[sumi] = a[i] + b[i];
            }
        }
        s.sort();
        return s;
    }
    void find(Vect& v2, bool r[]) //найти в массиве числа из b и записать в r
    {
        for (uint16_t i = 0; i < this->l; i++)
            if (!r[i]) //ищем элемент из this в b, если он еще не был найден
                r[i] = v2.binarySearch(this->a[i]);
    }
    static void findInSum(Vect& v1, Vect& v2, bool r[])
    {
        Vect s = sum(v1, v2);
        c.find(s, found); //с ищет в себе элементы совпадающие с sum
        delete s;
    }
    bool binarySearch(int32_t n)
    {
        bool found = false;
        uint16_t step = this->l / 2;
        for (uint16_t index = step; step > 0 && !found;)
        {
            step /= 2;
            if (this->a[index] > n)
                index -= step;
            else
                if (this->a[index] < n)
                    index += step;
                else //this->a[index] == n
                    found = true;
        }
        return found;
    }
};


const uint16_t maxn = 5000; //максимум элементов во втором массиве

int main() {
    Vect a = new Vect(); //создание массивов
    Vect b = new Vect();
    Vect d = new Vect();
    Vect c = new Vect();
    Vect sum;
    bool longb = false;

    //ввод массивов

    std::cin >> a.l;
    a.allocate();
    for (uint16_t i = 0; i < a.l; i++)
        std::cin >> a[i];

    std::cin >> b[0].l;
    b[0].allocate();
    for (uint16_t i = 0; i < b.l; i++)
        std::cin >> b[i];

    std::cin >> c.l;
    c.allocate();
    for (uint16_t i = 0; i < c.l; i++)
        std::cin >> c[i];

    bool* found = bool[c.l]; //массив с ответами
    for (uint16_t i = 0; i < c.l; i++)
        found[i] = false;

    //обработка

    if (a.l > maxn) //если в a оказался длинный массив, назвать его вторым (b)
    {
        Vect z = a;
        a = b;
        b = z;
    }

    if (b.l > maxn) //если в b длинный массив, то разбить его
    {
        longb = true;
        d.l = b.l - maxn;
        b.l = maxn;
        d.a = b.a + maxn * 4;
    }

    //в первом проходе работаем только с первой частью b, а не с d
    Vect::findInSum(a, b, found);
    if (longb)
    {
        Vect::findInSum(a, d, found);
    }

    delete a; //удаляем все три массива из памяти
    delete b;
    delete d;
    delete c;
    delete[] found;
    return 0;
}
