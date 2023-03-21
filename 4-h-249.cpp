#include <iostream>
#include <fstream>

std::ifstream in;
std::ofstream out;

int main() {
    in.open("in.txt", std::ios::in);
    out.open("out.txt", std::ios::out);
    unsigned n;
    in >> n;
    std::cout << n << std::endl;
    int* a = new int[n];
    for (unsigned i = 0; i < n; i++)
        in >> a[i];
    unsigned m;
    in >> m;
    std::cout << m << std::endl;
    int* b = new int[m];
    for (unsigned i = 0; i < m; i++)
        in >> b[i];
    unsigned k;
    in >> k;
    std::cout << k << std::endl;
    int* c = new int[k];
    for (unsigned i = 0; i < k; i++)
        in >> c[i];
    for (unsigned i = 0; i < k; i++) {
        bool found = false;
        for (unsigned j = 0; j < n && !found; j++)
            for (unsigned t = 0; t < m && !found; t++)
                if (a[j] + b[t] == c[i])
                    found = true;
        if (found)
            out << "YES";
        else
            out << "NO";
        out << std::endl;
    }
    in.close();
    out.close();
    delete[] a;
    delete[] b;
    delete[] c;
    return 0;
}
