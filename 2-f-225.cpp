#include <iostream>
#include <fstream>

std::ifstream in;
std::ofstream out;

int main()
{
    in.open("in.txt", std::ios::in);
    out.open("out.txt", std::ios::out);
    unsigned n, k;
    in >> n >> k;
    unsigned* a = new unsigned[n];
    for (unsigned int i = 0; i < n; i++) {
        in >> a[i];
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
    out << z << std::endl;
    in.close();
    out.close();
    delete[] a;
    return 0;
}
