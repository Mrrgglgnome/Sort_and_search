
#include <iostream>
#include <vector>

using namespace std;

vector<char> selection(vector<char> unsorted) {
    int last_index = unsorted.size() - 1;
    while (last_index != 0) {
        char max = CHAR_MIN;
        int index_max = 0;
        for (int i = 0; i <= last_index; i++) {
            if (max < unsorted[i]) {
                max = unsorted[i];
                index_max = i;
            }
        }
        unsorted[index_max] = unsorted[last_index];
        unsorted[last_index--] = max;
    }
    return unsorted;
}

vector<char> quick_sort(vector<char> unsorted) {
    int size = unsorted.size();
    if (size > 1) {
        vector<char> half_1, half_2;
        char comparand = unsorted[size / 2];
        for (int i = 0; i < size; i++)
            unsorted[i] <= comparand ? half_1.push_back(unsorted[i]) : half_2.push_back(unsorted[i]);
        vector<char> sorted_1 = quick_sort(half_1), sorted_2 = quick_sort(half_2);
        sorted_1.insert(sorted_1.end(), sorted_2.begin(), sorted_2.end());
        return sorted_1;
    }
    else
        return unsorted;
}

int main()
{
    vector<char> input;
    for (int i = 0; i < 5; i++) {
        char in;
        cin >> in;
        input.push_back(in);
    }

    vector<char> sorted = quick_sort(input);

    for (int i = 0; i < 5; i++) {
        cout << sorted[i] << " ";
    }
}