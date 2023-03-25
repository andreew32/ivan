#include <iostream>
#include <cstdint>

class Vect
{
private:
    bool allocated;
    int32_t* a;
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
};

int main() {
    Vect a = new Vect(); //создание массивов
    Vect* b = new Vect[2];
    Vect c = new Vect();

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

    //обработка

    if (a.l > b.l) {std::swap(a, b);} //b всегда должен быть больше a

    //максимальное число одновременно хранимых
    uint8_t sumn;
    uin16_t totaln = a.l * b.l, maxn = 60000000;
    Vect* sum;
    if (totaln > maxn) {
        sum = new Vect[2];
        sum[0].l = maxn;
        sum[1].l = totaln -
    }




    delete a; //удаляем все три массива из памяти
    delete b;
    delete c;
    return 0;
}
