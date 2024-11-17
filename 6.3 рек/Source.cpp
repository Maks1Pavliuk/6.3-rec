#include <iostream>
#include <vector>
#include <stdexcept>

// Рекурсивна функція для виведення масиву
template <typename T>
void printArrayRecursive(const std::vector<T>& arr, int index) {
    if (index == arr.size()) { // Базовий випадок: якщо індекс досяг кінця масиву
        std::cout << std::endl;
        return;
    }
    std::cout << arr[index] << " "; // Виводимо поточний елемент
    printArrayRecursive(arr, index + 1); // Рекурсивний виклик для наступного елемента
}

// Рекурсивна функція для знаходження мінімального елемента в масиві
template <typename T>
T findMinRecursive(const std::vector<T>& arr, int index) {
    if (index == arr.size() - 1) { // Базовий випадок: якщо це останній елемент
        return arr[index];
    }
    // Рекурсивний виклик для пошуку мінімуму в підмасиві
    T minInRest = findMinRecursive(arr, index + 1);
    return (arr[index] < minInRest) ? arr[index] : minInRest;
}

// Рекурсивна функція для обчислення середнього значення
template <typename T>
T sumRecursive(const std::vector<T>& arr, int index) {
    if (index == arr.size()) { // Базовий випадок: якщо індекс досяг кінця масиву
        return 0;
    }
    return arr[index] + sumRecursive(arr, index + 1); // Сума поточного елемента та решти
}

// Рекурсивна функція для підрахунку кількості елементів
int countRecursive(int size, int index = 0) {
    if (index == size) { // Базовий випадок: якщо індекс дорівнює розміру
        return 0;
    }
    return 1 + countRecursive(size, index + 1); // Рекурсивний підрахунок
}

int main() {
    std::vector<int> arr = { 3, -1, 4, -5, 2 }; // Масив для демонстрації

    // Рекурсивне виведення масиву
    std::cout << "array: ";
    printArrayRecursive(arr, 0);

    // Рекурсивне знаходження мінімального елемента
    try {
        int minElement = findMinRecursive(arr, 0);
        std::cout << "smallest element " << minElement << std::endl;

        // Рекурсивне обчислення середнього
        int sum = sumRecursive(arr, 0);
        int count = countRecursive(arr.size());
        double average = (double)sum / count;
        std::cout << "average value: " << average << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
