#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::sort;
using std::vector;

bool is_prime(int n)
{   
    if (n == 2 || n == 3) return true; // fixed this
    if ((n % 2 == 0 || n % 3 == 0 || n % 5 == 0)) return false;
    // check through all numbers of the form i = 6k - 1 and i = 6k + 1
    for (int i = 5; i * i < n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false; // n is divisible by i or i + 2
    }
    return true; // no divisor within [5, n) found
}

template <class T>
T median(std::vector<T> vec)
{
    using vec_sz = typename vector<T>::size_type;
    vec_sz size = vec.size();
    if (size == 0) throw std::domain_error("median of an empty vector");
    if (size == 1) return vec[0];

    sort(vec.begin(), vec.end());

    const auto mid = size / 2;
    return size % 2 != 0? vec[mid] : (vec[mid - 1] + vec[mid]) / 2;
}

int main()
{   
    cout << "======================1.1======================" << endl;
    cout << "Enter the upper limit: ";
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++) { // fixed this
        // cout << i << endl;
        if (is_prime(i)) cout << i << endl;
    }

    cout << endl;
    cout << "======================1.2======================" << endl;
    std::vector<int> vec_sample {1, 2, 3, 4, 5, 6, 7, 8, 10, 10, 11, 12, 13, 14, 15};

    cout << "Median: " << median<int>(vec_sample) << endl;

    return 0;
}
