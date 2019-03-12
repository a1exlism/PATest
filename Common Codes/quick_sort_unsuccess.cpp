#include <cstdio>
//  Min => Max 
void swap(int &a, int &b)
{ //  引用
  int tmp = a;
  a = b;
  b = tmp;
}

//  first index as pivot
int partition(int arr[], int low, int high)
{
  int pivot = arr[low];  //  pivot
  int j = low-1; //  j as lower index initIndex: NULL
  for (int i = low; i < high; i++)
  { //  i as traverse index
    if(arr[i] < pivot) {
      swap(arr[i], arr[++j]);
    }
  }
  //  ATTENTION: index HERE 
  swap(arr[j+1], pivot);
  return j+1;           //  return pivot index
}

/*
 * 严书
int partition2(int arr[], int low, int high)
{
  int pivot = arr[low];
  while(low < high) {
    while(low < high && arr[high] >= pivot)
      high--;
    arr[low] = arr[high];
    while(low < high && arr[low] <= pivot)
      low++;
    arr[high] = arr[low];
  }
  arr[low] = pivot;
  return low;   //  pivot postion
}
*/
void quick_sort(int arr[], int low, int high)
{
  if(low < high) {
    int pivot_pos = partition(arr, low, high);
    quick_sort(arr, low, pivot_pos-1);
    quick_sort(arr, pivot_pos+1, high);
    // int pivot_pos = partition2(arr, low, high);
    // quick_sort(arr, low, pivot_pos-1);
    // quick_sort(arr, pivot_pos+1, high);
  }
  
}

int main()
{
  int arr[] = {73, 68, 80, 85, 73, 74, 33, 49, 74, 90, 23, 22, 1, 0, 57, 11, 27, 35, 60, 45};

  int low = 0,
      high = sizeof(arr) / sizeof(arr[0]);
  quick_sort(arr, low, high);
  for(int i = low; i < high; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}