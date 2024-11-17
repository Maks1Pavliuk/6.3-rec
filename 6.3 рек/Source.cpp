#include <iostream>
#include <vector>
#include <stdexcept>

// ���������� ������� ��� ��������� ������
template <typename T>
void printArrayRecursive(const std::vector<T>& arr, int index) {
    if (index == arr.size()) { // ������� �������: ���� ������ ����� ���� ������
        std::cout << std::endl;
        return;
    }
    std::cout << arr[index] << " "; // �������� �������� �������
    printArrayRecursive(arr, index + 1); // ����������� ������ ��� ���������� ��������
}

// ���������� ������� ��� ����������� ���������� �������� � �����
template <typename T>
T findMinRecursive(const std::vector<T>& arr, int index) {
    if (index == arr.size() - 1) { // ������� �������: ���� �� ������� �������
        return arr[index];
    }
    // ����������� ������ ��� ������ ������ � �������
    T minInRest = findMinRecursive(arr, index + 1);
    return (arr[index] < minInRest) ? arr[index] : minInRest;
}

// ���������� ������� ��� ���������� ���������� ��������
template <typename T>
T sumRecursive(const std::vector<T>& arr, int index) {
    if (index == arr.size()) { // ������� �������: ���� ������ ����� ���� ������
        return 0;
    }
    return arr[index] + sumRecursive(arr, index + 1); // ���� ��������� �������� �� �����
}

// ���������� ������� ��� ��������� ������� ��������
int countRecursive(int size, int index = 0) {
    if (index == size) { // ������� �������: ���� ������ ������� ������
        return 0;
    }
    return 1 + countRecursive(size, index + 1); // ����������� ���������
}

int main() {
    std::vector<int> arr = { 3, -1, 4, -5, 2 }; // ����� ��� ������������

    // ���������� ��������� ������
    std::cout << "array: ";
    printArrayRecursive(arr, 0);

    // ���������� ����������� ���������� ��������
    try {
        int minElement = findMinRecursive(arr, 0);
        std::cout << "smallest element " << minElement << std::endl;

        // ���������� ���������� ����������
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
