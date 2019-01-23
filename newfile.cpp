#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
#include <numeric>
#include <algorithm>

template<typename N>
std::vector<N> range(N start, N end, N step=1) {
    std::vector<N> range;
    for(N i=start;i < end;i+= step){
        range.push_back(i);
    }
    return range;
}

std::vector<int> randGen(int min, int max, int numOfItems){
    srand(time(NULL));
    std::vector<int> randNums;
    int newNum;
    for(int i: range(0,numOfItems)){
        newNum = min + (std::rand() % (max - min));
        randNums.push_back(newNum);
    }
    return randNums;
}

template<typename N>
double mean(std::vector<N> arr) {
    return std::accumulate(arr.begin(),arr.end(),0.0) / arr.size();
}

template<typename N>
double pow2(N num) {
    return num * num;
}

template<typename N>
double stddev(std::vector<N> arr, bool population=false){
    std::vector<N> sum_diff = arr;
    double avg = mean(arr);
    std::for_each(sum_diff.begin(),sum_diff.end(),[=](N &num) {pow2(num - avg);});
    int n = population ? sum_diff.size() : sum_diff.size() - 1;
    N avg_sum_diff = std::accumulate(sum_diff.begin(),sum_diff.end(),0.0) / n;
    return std::sqrt(avg_sum_diff);
}

int main() {
    std::vector<int> arr = randGen(20,25000,100);
    int min = *std::min_element(arr.begin(),arr.end());
    int max = *std::max_element(arr.begin(),arr.end());
    
    std::cout << "The Average is: " << mean(arr) << "\n";
    std::cout << "The Standard Deviation is: " << stddev(arr, true) << "\n";
    std::cout << "LSL = " << mean(arr) - (3 * stddev(arr, true)) << " USL = " << mean(arr) + (3 * stddev(arr, true))<< "\n";
    std::cout << "MIN = " << min << " MAX = " << max<< "\n";

    return 0;
}
