#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<cstdlib>
#include<omp.h>

int find_median(std::vector<int>& arr, int left, int right) {
    if (left == right) {
        return arr[left];
    }

    if (left + 1 == right) {
        return std::max(arr[left], arr[right]);
    }

    int mid = left + (right - left) / 3;
    int a = find_median(arr, left, mid);
    int b = find_median(arr, mid + 1, right);
    int c = find_median(arr, left + (right - left) / 3, right - (right - left) / 3);

    return std::max({a, b, c});
}

int quickselect(std::vector<int>& arr, int left, int right, int k) {
    std::stack<std::pair<int, int>> stk;
    stk.push({left, right});

    while (!stk.empty()) {
        std::pair<int, int> range = stk.top();
        stk.pop();

        if (range.first == range.second) {
            return arr[range.first];
        }

        int pivot_index = range.first + rand() % (range.second - range.first + 1);
        std::swap(arr[pivot_index], arr[range.second]);
        int pivot = arr[range.second];

        int i = range.first;
        for (int j = range.first; j< range.second; j++) {
            if (arr[j] >= pivot) {
                std::swap(arr[i], arr[j]);
                i++;
            }
        }
        std::swap(arr[i], arr[range.second]);

        if (k == i) {
            return arr[k];
        } else if (k< i) {
            stk.push({range.first, i - 1});
        } else {
            stk.push({i + 1, range.second});
        }
    }

    return -1;
}

int main() {
    std::vector<int> arr = {3, 2, 1, 5, 6, 4};
    int k = 2;

    #pragma omp parallel
    {
        #pragma omp single
        {
            int result = quickselect(arr, 0, arr.size() - 1, k - 1);
            #pragma omp critical
            {
                std::cout << "The " << k << "th largest element is: "<< result<< std::endl;
            }
        }
    }

    return 0;
}