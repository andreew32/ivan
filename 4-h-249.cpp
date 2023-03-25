#include <iostream>
#include <cstdint>
#include <fstream>

std::ifstream in;
std::ofstream out;

class Vect
{
private:
    bool allocated;
    static uint32_t partition(int32_t arr[], uint32_t start, uint32_t end)
    {
        int32_t pivot = arr[start];
        uint32_t count = 0;
        for (uint32_t i = start + 1; i <= end; i++) {
            if (arr[i] <= pivot)
                count++;
        }

        //задаем осевому элементу его правильную позицию
        uint32_t pivotIndex = start + count;
        std::swap(arr[pivotIndex], arr[start]);

        //сортируем по левую и по правую сторону от осевого элемента
        uint32_t i = start, j = end;

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
    static void quickSort(int32_t arr[], uint32_t start, uint32_t end)
    {

        //базовый случай
        if (start >= end)
            return; //сразу выходим из сортировки

        //разбиваем массив
        uint32_t p = partition(arr, start, end);

        //сортируем левую часть
        quickSort(arr, start, p - 1);

        //сортируем правую часть
        quickSort(arr, p + 1, end);
    }
public:
    uint32_t l;
    int32_t* a;
    int32_t& operator[](uint32_t i) {return a[i];}
    void allocate() {
        a = new int32_t[l];
        allocated = true;
    }
    Vect() {
        allocated = false;
    }
    ~Vect() {
        if (allocated)
            delete[] this->a;
    }
    void sort() {quickSort(this->a, 0, l - 1);}
    //выделить место и заполнить массив сумм двух массивов, отсортировать
    static Vect* sum(Vect* v1, Vect* v2)
    {
        Vect* s = new Vect();
        s->l = v1->l * v2->l;
        s->allocate();
        for (uint32_t i = 0, sumi = 0; i < v1->l; i++) //берем элемент v1
        {

            for (uint32_t j = 0; j < v2->l; j++, sumi++) //пройти v2 и sumi
                (*s)[sumi] = (*v1)[i] + (*v2)[j];
        }
        s->sort(); //отсортировать массив сумм
        return s;
    }
    void find(Vect* v2, bool r[]) //найти в массиве числа из b и записать в r
    {
        for (uint32_t i = 0; i < this->l; i++)
            if (!r[i]) //ищем элемент из this в b, если он еще не был найден
                r[i] = v2->binarySearch(this->a[i]);
    }

    //найти числа v3 среди сумм массивов v1 и v2 и записать ответы в found
    static void findInSum(Vect* v1, Vect* v2, Vect* v3, bool found[])
    {
        Vect* s = sum(v1, v2);
        v3->find(s, found); //с ищет в себе элементы совпадающие с sum
        delete s;
    }
    bool binarySearch(int32_t n)
    {
        bool found = false;
        uint32_t step = this->l / 2;
        for (uint32_t index = step; step > 0 && !found;)
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


const uint32_t maxn = 5000; //максимум элементов во втором массиве

int main() {
    out.open("bin/out.txt", std::ios::out);
    in.open("bin/generated.txt", std::ios::in);

    Vect* a = new Vect(); //создание массивов
    Vect* b = new Vect();
    Vect* d = new Vect();
    Vect* c = new Vect();
    bool longb = false;

    //ввод массивов

    in >> a->l;
    a->allocate();
    for (uint32_t i = 0; i < a->l; i++)
        in >> (*a)[i];

    in >> b->l;
    b->allocate();
    for (uint32_t i = 0; i < b->l; i++)
        in >> (*b)[i];

    in >> c->l;
    c->allocate();
    for (uint32_t i = 0; i < c->l; i++)
        in >> (*c)[i];

    bool* found = new bool[c->l]; //массив с ответами
    for (uint32_t i = 0; i < c->l; i++)
        found[i] = false;


    //обработка

    if (a->l > maxn) //если в a оказался длинный массив, назвать его вторым (b)
    {
        Vect* z = a;
        a = b;
        b = z;
    }

    if (b->l > maxn) //если в b длинный массив, то разбить его
    {
        longb = true;
        d->l = b->l - maxn;
        b->l = maxn;
        d->a = b->a + maxn * 4;
    }

    //в первом проходе работаем только с первой частью b, а не с d
    Vect::findInSum(a, b, c, found);
    if (longb) //если b оказался длинным, то делаем второй проход
    {
        Vect::findInSum(a, d, c, found);
    }

    for (uint32_t i = 0; i < c->l; i++)
    {
        if (found[i])
            out << "YES" << std::endl;
        else
            out << "NO" << std::endl;
    }
    delete a; //удаляем все три массива из памяти
    delete b;
    delete d;
    delete c;
    delete[] found;
    out.close();
    in.close();
    return 0;
}
