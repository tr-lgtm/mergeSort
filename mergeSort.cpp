#include <iostream>

void merge(int arr[],int low, int middle, int high){
    int sizeLeftArr = middle - low + 1;  // +1 мы захватываем эл-т middle
    int sizeRightArr = high - middle;
    
    int* leftArr = new int[sizeLeftArr];
    int* rightArr = new int[sizeRightArr];
    
    for(int i = 0; i < sizeLeftArr ; i++){
        leftArr[i]=arr[low + i];
    }
    for(int j = 0; j <= sizeRightArr; j++){
        rightArr[j]=arr[middle + 1 + j];
    }
    
    int i{};
    int j{};
    while(i < sizeLeftArr && j < sizeRightArr){
        if(leftArr[i] < rightArr[j]){
            arr[low++] = leftArr[i++];
        }
        else{
            arr[low++] = rightArr[j++];
        }
    }
    while(i < sizeLeftArr){
        arr[low++] = leftArr[i++];
    }
    while(j < sizeRightArr){
        arr[low++] = rightArr[j++];
    }
    
    delete[] leftArr;
    delete[] rightArr;
}


void mergeSort(int arr[],int low,int high){
    if(low < high){
        int middle = low + (high - low)/2;
        
        mergeSort(arr,low,middle);
        mergeSort(arr,middle + 1,high);
        
        merge(arr,low,middle,high);
    }
}
int main() {

    std::cout << "qsort = ";
    int32_t arr[]{1,3,6,32,444,1,0,0,0,0,7,44,22,1,3};
    mergeSort(arr,0,14);
    for(int i = 0; i < 15; i++){
        std::cout << arr[i] << ' ';
    }
    

    return 0;
}
