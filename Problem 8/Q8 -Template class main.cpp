/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/


#include <iostream>
#include <math.h>
#include <memory>
#include <random>
#include <string>
#include <vector>

// for some compilers that's don't support nested templates with the same parameter
template <typename T>
auto dist() -> typename std::enable_if<std::is_integral<T>::value, std::uniform_int_distribution<T> >::type;

template <typename T>
auto dist() -> typename std::enable_if<std::is_floating_point<T>::value, std::uniform_real_distribution<T> >::type;

template<typename T>
class Random
{
public:
    Random(const T& min, const T& max)
        : mUnifomDistribution(min, max)
    {}
    Random(const Random<T>&) = delete;
    Random(const Random<T>&&) = delete;
    Random<T>& operator = (const Random<T>&) = delete;
    T operator()()
    {
        return mUnifomDistribution(mEngine);
    }

private:
    std::default_random_engine mEngine{ std::random_device()() }; // <-- here the doubt - is it seeding?
    //template <typename T>
    //static auto dist() -> typename std::enable_if<std::is_integral<T>::value, std::uniform_int_distribution<T> >::type;

    //template <typename T>
    //static auto dist() -> typename std::enable_if<std::is_floating_point<T>::value, std::uniform_real_distribution<T> >::type;

    using type = decltype(dist<T>());
    type mUnifomDistribution;
};

int main() 
{
    ::Random<int> s(0, 9);
    for (int i = 0; i<9; ++i)
        std::cout << s() << '\n';
}
