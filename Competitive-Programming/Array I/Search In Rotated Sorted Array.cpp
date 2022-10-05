/*
Search In Rotated Sorted Array

https://www.codingninjas.com/codestudio/problems/search-in-rotated-sorted-array_1082554

*/

int getPivot(vector<int>& arr, int n){
    int start = 0;
    int end = n-1;
    int mid;
    while (start<end){
        mid = start + (end-start)/2;
        if(arr[mid]>=arr[0]){
            start = mid+1;
        }
        else{
            end = mid;
        }
    }
    return start;    
}

int binarySearch(vector<int>& arr, int s, int e, int key) {
    int start = s;
    int end = e;
    int mid;
    while(start <= end) {
        mid = start + (end-start)/2;
        if(arr[mid] == key) {
            return mid;
        }

        if(key > arr[mid]) {
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

int findPosition(vector<int>& arr, int n, int k){
    int pivot = getPivot(arr, n);
    if( k >= arr[0] && k <= arr[pivot-1]){//BS on second line
        return binarySearch(arr, 0, pivot - 1, k);
    }
    else{//BS on first line
        return binarySearch(arr, pivot, n-1, k);
    }
}