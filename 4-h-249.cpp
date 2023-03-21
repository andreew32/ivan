#include <iostream>

int main() {
    unsigned n, m, k;
    std::cin >> n;
    unsigned* a = new unsigned[n];
    for (unsigned i = 0; i < n; i++)
        std::cin >> a[i];
    std::cin >> m;
    unsigned* b = new unsigned[m];
    for (unsigned i = 0; i < m; i++)
        std::cin >> b[i];
    std::cin >> k;
    unsigned* c = new unsigned[k];
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
