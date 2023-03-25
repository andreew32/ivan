#include <iostream>

int main()
{
    unsigned n, k; //переменные катушек и вышивальных нитей
    std::cin >> n >> k;
    unsigned* a = new unsigned[n]; //создание и ввод массива катушек
    for (unsigned int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    unsigned max = 0; //поиск максимальной катушки
    for (unsigned i = 1; i < n; i++)
        if (a[i] > a[max])
            max = i; //j будет равняться самой большой катушке
    bool found = false; //цикл поиска остановится при значении true
    unsigned len = a[max]; //длина нитки
    do
    {
        unsigned sum = 0; //количество отрезков
        for (unsigned t = 0; t < n; t++)
        {
            sum += a[t] / len; //получаем отрезки ниток с каждой катушки
        }
        if (sum >= k) //как только число отрезков достаточно, выходим
            found = true;
        else
            len--; //иначе укорачиваем отрезок
    } while (!found && len > 0); //если длина отрезка ноль, то тоже выходим
    std::cout << len << std::endl; //вывод ответа
    delete[] a; //очистка памяти
    return 0;
}
