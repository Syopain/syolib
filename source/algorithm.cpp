#include "algorithm.h"

namespace syo {

    std::string toString(int num, int base)
    {
        if (num == 0) {
            return "0";
        }
        std::string ret;
        while (num) {
            int mod = num % base;
            ret = static_cast<char>((mod < 10) ? (mod + '0') : (mod - 10 + 'A')) + ret;
            num /= base;
        }
        return ret;
    }

    std::string toString(double num, int base, int place)
    {
        std::string ret = toString(static_cast<int>(num), base);
        num -= static_cast<int>(num);
        ret += '.';
        while (place--) {
            int overflow = num * base;
            ret += static_cast<char>((overflow < 10) ? (overflow + '0') : (overflow - 10 + 'A'));
            num *= base;
            num -= static_cast<int>(num);
        }
        return ret;
    }

    void print_combination(int arr[], int n, int r, int cur)
    {
        if (cur == r) {
        for (int i = 0; i < r; ++i) {
        std::cout << arr[i];
        }
        std::cout << std::endl;
        }
        for (int i = n; i > 0; --i) {
        arr[cur] = i;
        print_combination(arr, i - 1, r, cur + 1);
        }
    }

    void print_combination(int n, int r)
    {
        int* arr = new int[r];
        print_combination(arr, n, r, 0);
        delete[] arr;
    }

    void print_permutation(int arr[], int s[], int n, int cur)
    {
        if (cur == n) {
        for (int i = 0; i < n; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
        }
        for (int i = 0; i < n; ++i) {
        int ok = 1;
        for (int j = 0; j < cur; ++j)
            if (s[i] == arr[j]) ok = 0;
        if (ok) {
            arr[cur] = s[i];
            print_permutation(arr, s, n, cur + 1);
        }
        }
    }

    void print_permutation(int s[], int n)
    {
        int* arr = new int[n];
        print_permutation(arr, s, n, 0);
        delete[] arr;
    }

    void print_yh_triangle(int row)
    {
        if (row > 0)
            std::cout << "i = 0" << std::string(3 * row, ' ') << "  1" << std::endl;
        if (row > 1)
            std::cout << "i = 1" << std::string(3 * (row - 1), ' ') << "  1     1" << std::endl;
        else
            return;

        int* arr = new int[row * (1+row) / 2]();
        arr[0] = arr[1] = 1;
        int p = 2;
        int q;
        while (p < row) {
            arr[p] = 1;
            for (q = p - 1; q > 0; --q) {
                arr[q] += arr[q-1];
            }
            std::cout << "i = " << p << std::string(3*(row-p), ' ');
            for (int i = 0; i < p+1; ++i) {
                //std::cout << arr[i] << "   ";
                printf("%3d   ", arr[i]);
            }
            std::cout << std::endl;
            ++p;
        }
        delete[] arr;
    }
}
