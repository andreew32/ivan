#include <iostream>

//для функции быстрой сортировки функция деления
int partition(int arr[], int start, int end) {
    int pivot = arr[start];
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
//функция быстрой сортировки
void quickSort(int arr[], int start, int end)
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

int main()
{
    unsigned n, k; //создаем общие переменные
    int a, b, c, r; //переменные генератора
    std::cin >> n >> k;
    k--; //c++ считает от нуля, поэтому делаем сдвижку
    int* x = new int[n]; //создаем массив
    std::cin >> x[0] >> x[1]; //вводим первые значения массива
    std::cin >> a >> b >> c >> r; //вводим данные генератора
    for (unsigned i = 2; i < n; i++) //генерируем последовательность
        x[i] = (a * x[i - 2] + b * x[i - 1] + c) % r;
    quickSort(x, 0, n - 1); //сортируем
    std::cout << x[k] << std::endl; //вывод ответа
    delete[] x; //очищение памяти
    return 0;
}
