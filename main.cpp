#include <iostream>
#include <ctime>
#include <random>
#include <chrono>
#include <vector>

// task 3

void printMatrix(int **matrix, int n, int m) { // функция для вывода матрицы в консоль
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void fillMatrix(int** arr, int n, int m) { // заполняем матрицу
    std::mt19937 mt_engine(
            std::chrono::system_clock::now().
                    time_since_epoch().count()
    );
    std::uniform_int_distribution<int> dist(1, 70);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = dist(mt_engine);
        }
    }
}

int sumDiagonal(int **matrix, int n, int m) { // интовая функция нахождения суммы диагонали
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += matrix[i][n - 1 - i];
    }
    return ans;
}

void task3(){
    int n, m;
    std::cout << "Input matrix size NxM: " << std::endl;
    std::cin >> n >> m;
    int** matrix = new int*[n];
    for (int i = 0; i < n; ++i) {
        matrix[i] = new int[m];
    }

    fillMatrix(matrix, n, m);
    printMatrix(matrix, n, m);

    std::cout << sumDiagonal(matrix, n, m) << std::endl;

    for (int i = 0; i < n; ++i) {
        delete[] matrix[i];
    }
};

// task 4

#include <iostream>
template <typename T>
void fillArrayKB(T *arr, int n) { // заполняем массив с клавиатуры
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
}

template <typename T>
void printArray(T* arr, int n) { // выводим массив в консоль
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

template <typename T>
T sum(T *arr, int left, int right) {
    T ans = 0;
    for (int i = left; i < right; ++i) {
        ans += arr[i];
    }
    return ans;
}

template <typename T>
T solve(T *arr, int n, int k) {
    T maxSum = 100000000;

    for (int i = 0; i < n - k + 1; ++i) {
        T currSum = sum(arr, i, i + k);
        if (currSum < maxSum) {
            maxSum = currSum;
        }
    }
    return maxSum;
}

void task4(){
    int n, k;
    std::cout << "Input size:" << std::endl;
    std::cin >> n;
    int *arr = new int[n];
    fillArrayKB(arr, n);
    printArray(arr, n);
    std::cout << "Input k:" << std::endl;
    std::cin >> k;

    double ans = solve(arr, n, k);
    std::cout << ans / k << std::endl;

    delete[] arr;
};

void task5() {
    vector<Vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            if(i==0 || (i>0 && nums[i-1]!=nums[i])){
                int newTarget=0-nums[i];
                int left=i+1;
                int right=n-1;
                while(left<right){
                    if(nums[left]+nums[right]==newTarget){
                        int x=nums[left++];
                        int y=nums[right--];
                        ans.push_back({nums[i],x,y});
                        while(left<right && nums[left]==x) left++;
                        while(left<right && nums[right]==y) right--;
                    }else if(nums[left]+nums[right] > newTarget)
                        right--;
                    else left++;
                };
            };
        };
        return ans;
    };


    int main() {
    task3();
    task4();
    task5();

return 0;
}