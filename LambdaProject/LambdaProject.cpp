#include <iostream>
#include <typeinfo>

int Sum(int a, int b)
{
    int result = a + b;
    return result;
}

int Mult(int a, int b)
{
    return a * b;
}

int Min(int a, int b)
{
    return (a < b ? a : b);
}

int Calc(int a, int b, int(*funcPtr)(int, int))
{
    return funcPtr(a, b);
}

template <typename T1, typename T2>
auto Sum(T1 a, T2 b)
{
    return a + b;
}


int main()
{
    /*std::cout << Calc(10, 20, Sum) << "\n";
    std::cout << Calc(10, 20, Mult) << "\n";
    std::cout << Calc(10, 20, Min) << "\n";*/

    std::cout << Calc(10, 20, [](auto a, auto b) { return (a > b ? a : b); }) << "\n";

    int n = 10;
    int m = 20;

    auto lambda = [&](int a)
    {
        n = a + n + m;
    };

    lambda(100);

    std::cout << n;
    
    /*std::cout << Calc(10, 20, [](int a, int b)
                                            {
                                                return a - b;
                                            })
              << "\n";*/


    //std::cout << typeid(lambda).name() << "\n";

    /*auto x = 10;
    std::cout << typeid(x).name() << "\n";
    auto s = "Hello";
    std::cout << typeid(s).name() << "\n";*/



    
}
