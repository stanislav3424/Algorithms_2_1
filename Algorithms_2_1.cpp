#include <iostream>

void fibonacci(int lastNumber = 0)
{
    static int counter = 0;
    static long long first = 0;
    static long long second = 1;

    if (lastNumber != 0)
    {
        counter = lastNumber;
    }

    if (counter <= 0)
        return;

    std::cout << first << std::endl;
    static long long next = first + second;
    first = second;
    second = next;

    counter--;
    fibonacci();
}

int main()
{
    setlocale(LC_ALL, "");

    int lastNumber = 0;
    std::cout << "¬ведите n: ";
    std::cin >> lastNumber;
    fibonacci(lastNumber);

    return 0;
}