#include <iostream>

int main()
{
    unsigned n, k; //переменные катушек и вышивальных нитей
    std::cin >> n >> k;
    unsigned* a = new unsigned[n]; //создание и ввод массива катушек
    for (unsigned int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    unsigned max = a[0]; //поиск максимальной катушки
    for (unsigned i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i]; //j будет равняться самой большой катушке
    unsigned z; //переменная для хранения ответа
    bool found = false; //цикл поиска остановится при значении true
    for (unsigned j = max, p = 0; !found; j--, p = 0)
        if (p < k && j > 0) { //уменьшаем j пока p меньше числа катушек
            z = j; //сохраняем j в ответ
            for (unsigned i = 0; i < n; i++)
                p += a[i] / j; //наращиваем p на частное катушки и j
        }
        else //выходим из цикла, если p оказалось больше числа нитей
            found = true; //если j дошло до 0
    std::cout << z << std::endl; //вывод ответа
    delete[] a; //очистка памяти
    return 0;
}
