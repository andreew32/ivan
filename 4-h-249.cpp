#include <iostream>

int main() {
    unsigned n;
    std::cin >> n;
    std::cout << n << std::endl;
    int* a = new int[n];
    for (unsigned i = 0; i < n; i++)
        std::cin >> a[i];
    unsigned m;
    std::cin >> m;
    std::cout << m << std::endl;
    int* b = new int[m];
    for (unsigned i = 0; i < m; i++)
        std::cin >> b[i];
    unsigned k;
    std::cin >> k;
    std::cout << k << std::endl;
    int* c = new int[k];
    for (unsigned i = 0; i < k; i++)
        std::cin >> c[i];
    for (unsigned i = 0; i < k; i++) {
        bool found = false;
        for (unsigned j = 0; j < n && !found; j++)
            for (unsigned t = 0; t < m && !found; t++)
                if (a[j] + b[t] == c[i])
                    found = true;
        if (found)
            std::cout << "YES";
        else
            std::cout << "NO";
        std::cout << std::endl;
    }
    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}
