#include <iostream>

int main() {
    unsigned n; //создание и ввод первого массива
    std::cin >> n;
    int* a = new int[n];
    for (unsigned i = 0; i < n; i++)
        std::cin >> a[i];

    unsigned m; //создание и ввод второго массива
    std::cin >> m;
    int* b = new int[m];
    for (unsigned i = 0; i < m; i++)
        std::cin >> b[i];

    unsigned k; //создание и ввод третьего массива
    std::cin >> k;
    int* c = new int[k];
    for (unsigned i = 0; i < k; i++)
        std::cin >> c[i];

    for (unsigned i = 0; i < k; i++) { //нахождение сумм простым перебором
        bool found = false; //искать, пока не станет true
        for (unsigned j = 0; j < n && !found; j++)
            for (unsigned t = 0; t < m && !found; t++)
                if (a[j] + b[t] == c[i]) //если нашли сумму, то ставим флаг
                    found = true;
        if (found) //сразу выводим ответ и переходим к следующему элементу
            std::cout << "YES";
        else
            std::cout << "NO";
        std::cout << std::endl;
    }
    delete[] a; //удаляем все три массива из памяти
    delete[] b;
    delete[] c;
    return 0;
}
