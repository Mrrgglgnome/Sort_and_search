
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<char> selection_sort(vector<char> unsorted) {
    int last_index = unsorted.size() - 1;           // Индекс последнего элемента для записи в конец найденого максимального элемента
    while (last_index != 0) {
        char max = CHAR_MIN;
        int index_max = 0;                          // Индекс максимального элемента
        for (int i = 0; i <= last_index; i++) {
            if (max < unsorted[i]) {
                max = unsorted[i];
                index_max = i;
            }
        }
        unsorted[index_max] = unsorted[last_index]; // Обмен местами максимального элемента с последним в неотсортированной части массива
        unsorted[last_index--] = max;
    }
    return unsorted;
}

vector<char> quick_sort(vector<char> unsorted) {
    int size = unsorted.size();
    while (true) {
        vector<char> half_1, half_2;
        char comparand = accumulate(unsorted.begin(), unsorted.end(), 0) / size;                        // Вычисление компаранда как среднее арифмет. массива
        for (int i = 0; i < size; i++)
            unsorted[i] <= comparand ? half_1.push_back(unsorted[i]) : half_2.push_back(unsorted[i]);   // Разделение массива на два с теми, что меньше и теми, что больше компаранда
        if (half_2.empty())     // Проверка для выхода из рекурсии
            return unsorted;
        vector<char> sorted_1 = quick_sort(half_1), sorted_2 = quick_sort(half_2);                      // Рекурсивное повторение
        sorted_1.insert(sorted_1.end(), sorted_2.begin(), sorted_2.end());                              // Слияние массивов в отсортированный
        return sorted_1;
    }
}

int binary_search(vector<char> vector, char find) {
    int half = vector.size() / 2;
    int index = half;
    while (vector[index] != find && half != 0) {
        if (vector[index] > find)
            index -= half;
        else
            index += half;
    }
        half /= 2;
    if (half == 0) {
        cout << "element not found";
        return NAN;
    }
    else {
        cout << "element at index: " << index;
        return index;
    }
}

int main()
{
    vector<char> input;
    for (int i = 0; i < 10; i++) {
        char in;
        cin >> in;
        input.push_back(in);
    }

    binary_search(input, '0');
    /*
    for (int i = 0; i < 5; i++) {
        cout << sorted[i] << " ";
    }*/
}