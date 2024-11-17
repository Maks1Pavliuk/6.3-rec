#include "pch.h"
#include "CppUnitTest.h"
#include "../6.3 рек/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestFindMinRecursive)
        {
            std::vector<int> arr = { 3, -1, 4, -5, 2 };
            int result = findMinRecursive(arr, 0);
            Assert::AreEqual(-5, result); // Очікуємо, що мінімальний елемент -5
        }

        TEST_METHOD(TestSumRecursive)
        {
            std::vector<int> arr = { 3, -1, 4, -5, 2 };
            int result = sumRecursive(arr, 0);
            Assert::AreEqual(3, result); // Сума елементів: 3 + (-1) + 4 + (-5) + 2 = 3
        }

        TEST_METHOD(TestCountRecursive)
        {
            int size = 5; // Кількість елементів у масиві
            int result = countRecursive(size);
            Assert::AreEqual(5, result); // Очікуємо, що кількість елементів 5
        }

        TEST_METHOD(TestCalculateAverageRecursive)
        {
            std::vector<int> arr = { 3, -1, 4, -5, 2 };
            int sum = sumRecursive(arr, 0);
            int count = countRecursive(arr.size());
            double average = (double)sum / count;
            Assert::AreEqual(0.6, average, 0.001); // Середнє: 3 / 5 = 0.6
        }
    };
}
