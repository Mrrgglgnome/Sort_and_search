
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

int main()
{
    vector<char> input;
    for (int i = 0; i < 5; i++) {
        char in;
        cin >> in;
        input.push_back(in);
    }

    vector<char> sorted = selection(input);

    for (int i = 0; i < 5; i++) {
        cout << sorted[i] << " ";
    }
}