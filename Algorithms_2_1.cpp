#include <iostream>
#include <vector>

void fibonacci1(int lastNumber, long long* result)
{
    static int counter = 0;
    static long long first = 0;
    static long long second = 1;

    if (lastNumber != 0)
    {
        counter = lastNumber;
    }

    if (counter <= 0)
    {
        *result = first;
        return;
    }

    static long long next = first + second;
    first = second;
    second = next;

    counter--;
    fibonacci1(0, result);
}

void fibonacci2(int lastNumber, std::vector<long long>& resultAllArr)
{
    static bool initialized = false;

    if (!initialized)
    {
        resultAllArr = {0, 1, 1};
        initialized = true;
    }

    if (resultAllArr.size() >= static_cast<size_t>(lastNumber))
    {
        initialized = false;
        return;
    }

    resultAllArr.push_back(resultAllArr[resultAllArr.size() - 2] + resultAllArr[resultAllArr.size() - 1]);
    fibonacci2(lastNumber, resultAllArr);
}

int main()
{
    setlocale(LC_ALL, "");

    long long fibonacciResult = 0;
    int lastNumber = 0;
    std::cout << "Введите n: ";
    std::cin >> lastNumber;

    // Задание 1
    fibonacci1(lastNumber, &fibonacciResult);
    std::cout << "Результат: " << fibonacciResult << std::endl;

    // Задание 2
    std::vector<long long> fibonacciResultArr;
    fibonacci2(lastNumber, fibonacciResultArr);

    std::cout << "Последовательность Фибоначчи: ";
    for (long long num : fibonacciResultArr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}