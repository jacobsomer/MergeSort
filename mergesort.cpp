#include <iostream>
using namespace std;

//mergesort implementation by Jacob Somer

void merge(int arr[],int left, int middle, int right){
  int leftSize= middle-left+1;
  int rightSize=right-middle;
  int leftArr[leftSize],rightArr[rightSize];

  for (int i=0; i<leftSize;i++)
    leftArr[i]=arr[left+i];
  for(int j=0;j<rightSize;j++)
    rightArr[j]=arr[j+1+middle];

  int l=0;
  int r=0;
  int arrIndex=left;

  while(l<middle+1-left && r<right-middle){
    if (leftArr[l]<rightArr[r]){
      arr[arrIndex]=leftArr[l];
      l++;
    }
    else{
      arr[arrIndex]=rightArr[r];
      r++;
    }
    arrIndex++;
  }

  while (l < leftSize) {
        arr[arrIndex] = leftArr[l];
        l++;
        arrIndex++;
    }

  while (r < rightSize) {
      arr[arrIndex] = rightArr[r];
      r++;
      arrIndex++;
  }



}



void mergesort(int arr[],int left,int right){
  if (left>=right){
    return;
  }
  int middle= (left+right-1)/2; //get middle index
  mergesort(arr,left,middle);
  mergesort(arr,middle+1,right);
  merge(arr,left,middle,right);


}

void print(int arr[],int size)
{
    for (int i = 0; i<size ; i++)
        cout << arr[i] << " ";
}

int main(){
  int arr[] = {5,3,7,4,1,2,12,4,5,3,6};
  int size= sizeof(arr)/sizeof(arr[0]);
  cout << "\n Unsorted arrat array is \n";
  print(arr,size);
  mergesort(arr, 0, size-1);
  cout << "\nSorted array with mergesort is \n";
  print(arr,size);
  return 0;
}
