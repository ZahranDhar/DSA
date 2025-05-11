#include<stdio.h>

int binarySearch(int arr[],int start, int end, int key);

int main(){

  int arr[9]={1,4,7,10,15,23,25,66,90};
  int keys[2]={4,90};
  int i;


  for(i=0;i<2;i++){

    int index=binarySearch(arr,0,8,keys[i]);
    if(index==-1) printf("%d was not found\n", keys[i]);
    else printf("%d was found at index %d\n", keys[i],index);

  } 

  return 0;
}

int binarySearch(int arr[],int start, int end, int key){

  if(end==start)
  {
    if(arr[start]==key) return start;
    else return -1;
  }

  int mid=start+((end-start)/2);
  
  if(arr[mid]==key) return mid;
  else if(key>arr[mid]) return binarySearch(arr,mid+1,end,key);
  else return binarySearch(arr,start,mid-1,key);


}