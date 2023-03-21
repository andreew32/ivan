#include <iostream>
#include <fstream>

std::ifstream in;
std::ofstream out;

int main()
{
    in.open("in.txt", std::ios::in);
    out.open("out.txt", std::ios::out);
    unsigned n, k;
    int a, b, c, r;
    in >> n >> k;
    k--;
    int* x = new int[n];
    in >> x[0] >> x[1];
    in >> a >> b >> c >> r;
    for (unsigned i = 2; i < n; i++)
        x[i] = (a * x[i - 2] + b * x[i - 1] + c) % r;
    for (unsigned l = 0, j = n - 1; ; )
    {
        if (j <= l + 1)
        {
            // текущая часть состоит из 1 или 2 элементов -
            // легко можем найти ответ
            if (j == l + 1 && x[j] < x[l])
                std::swap(x[l], x[j]);
            //return x[k];
            break;
        }
        //упорядочиваем a[l], a[l + 1], a[j]
        unsigned mid = (l + j) >> 1;
        std::swap(x[mid], x[l + 1]);
        if (x[l] > x[j])
            std::swap(x[l], x[j]);
        if (x[l + 1] > x[j])
            std::swap(x[l + 1], x[j]);
        if (x[l] > x[l + 1])
            std::swap(x[l], x[l + 1]);

        // выполняем разделение
        // по границе x[l + 1] - медиане от x[l], x[l + 1], x[j]
        unsigned i = l + 1, t = j;
        const int cur = x[l + 1];
        for (;;)
        {
            while (x[++i] < cur);
            while (x[--t] > cur);
            if (i > t)
                break;
            std::swap(x[i], x[t]);
        }

        // вставляем раздел
        x[l + 1] = x[t];
        x[t] = cur;

        // продолжаем искать в том месте, в котором должна быть k-я пор. стат.
        if (t >= k)
            j = t - 1;
        if (t <= k)
            l = i;
    }
    out << x[k] << std::endl;
    in.close();
    out.close();
    delete[] x;
    return 0;
}
