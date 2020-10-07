#include <iostream>
#include <random>
#include <algorithm>

int main()
{
    int ar[10][2];

    std::random_device rd;
    std::default_random_engine rng(rd());
    std::uniform_int_distribution<> dist(1,20);
    std::for_each(std::begin(ar), std::end(ar),
        [&](int (&ar)[2]){ ar[0] = dist(rng); ar[1] = dist(rng); });

    std::cout << "Before Sort..." << '\n';
    std::for_each(std::begin(ar), std::end(ar),
        [](const int(&ar)[2]) { std::cout << ar[0] << ',' << ar[1] << '\n';});

    std::qsort(ar, 10, sizeof(*ar),
        [](const void *arg1, const void *arg2)->int
        {
            int const *lhs = static_cast<int const*>(arg1);
            int const *rhs = static_cast<int const*>(arg2);
            return (lhs[0] < rhs[0]) ? -1
                :  ((rhs[0] < lhs[0]) ? 1
                :  (lhs[1] < rhs[1] ? -1
                :  ((rhs[1] < lhs[1] ? 1 : 0))));
        });

    std::cout << "After Sort..." << '\n';
    std::for_each(std::begin(ar), std::end(ar),
        [](const int(&ar)[2]) { std::cout << ar[0] << ',' << ar[1] << '\n';});

    return 0;
}
