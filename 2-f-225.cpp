#include <iostream>

int main()
{
    unsigned n, k;
    std::cin >> n >> k;
    unsigned* a = new unsigned[n];
    for (unsigned int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    unsigned max = a[0];
    for (unsigned i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    unsigned z;
    bool found = false;
    for (unsigned j = max, p = 0; !found; j--, p = 0)
        if (p < k && j > 0) {
            z = j;
            for (unsigned i = 0; i < n; i++)
                p += a[i] / j;
        }
        else
            found = true;
    std::cout << z << std::endl;
    delete[] a;
    return 0;
}
