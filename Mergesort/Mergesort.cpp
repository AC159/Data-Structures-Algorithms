#include "Mergesort.h"

#include <vector>
#include <ctime>
#include <iostream>

using std::vector;

vector<int> mergeArrays(vector<int> &s1, vector<int> &s2)
{
    int i = 0;
    int j = 0;
    vector<int> sorted;

    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] < s2[j]) sorted.push_back(s1[i++]);
        else sorted.push_back(s2[j++]);
    }

    while (i < s1.size())
    {
        sorted.push_back(s1[i++]);
    }

    while (j < s2.size())
    {
        sorted.push_back(s2[j++]);
    }

    return sorted;
}

vector<int> mergeSort(vector<int> &nums, int low, int high)
{
    if (low == high)
    {
        return {nums[low]};
    }

    int mid = low + ((high - low) / 2);
    vector<int> lowHalf = mergeSort(nums, low, mid);
    vector<int> highHalf = mergeSort(nums, mid + 1, high);

    return mergeArrays(lowHalf, highHalf);
}

void mergesortMain()
{
    std::srand(time(NULL));

    int sequenceSize = 100;
    std::vector<int> nums(sequenceSize);

    for (int i = 0; i < sequenceSize; ++i)
    {
        nums[i] = std::rand() % 1000;
    }

    vector<int> sorted = mergeSort(nums, 0, nums.size() - 1);

    std::cout << "Sorted vector with mergesort: \n[";
    for (int i = 0; i < sequenceSize; ++i)
    {
        if (i % 10 == 0) std::cout << "\n";
        if (i != sequenceSize - 1) std::cout << sorted[i] << ", ";
        else std::cout << sorted[i];
    }
    std::cout << "]\n";
}
