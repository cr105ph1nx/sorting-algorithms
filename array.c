#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i, j, temp, min, max, option;

int AscendingOrDescending(){
  printf("Do You want to sort Ascendingly or Descendinly?\n\t(0) Ascendingly\n\t(else) Descendinly\n>>");
  scanf("%d",&option);
  if(option==0)
    return 0;
  else
    return 1;
}

void arraySelectionSort(int array[1000], int length){
  if(AscendingOrDescending()==0){
    //selction sort Ascendingly.
    for(i=0;i<length;i++){
      min=array[i];
      for(j=i+1;j<length;j++)
        if(array[j]<min){
          min=array[j];
        }
      temp = array[i];
      array[i] = min;
      min = array[i];
    }
    //print sorted list.
    for(i=0;i<length;i++){
      printf("%d\n", array[i]);
    }
  }else{
    for(i=0;i<length;i++){
      max=array[i];
      for(j=i+1;j<length;j++)
        if(array[j]>max){
          max=array[j];
        }
      temp = array[i];
      array[i] = max;
      max = array[i];
    }
    //print sorted list.
    for(i=0;i<length;i++){
      printf("%d\n", array[i]);
    }
  }

}
void arrayBubbleSort(int array[1000], int length){
  if(AscendingOrDescending()==0){
    //selction sort Ascendingly.
    printf("hello world.\n");
  }else{
    //Selection sort Descendinly.
    printf("hello world.\n");
  }
}
void arrayInsertionSort(int array[1000], int length){
  if(AscendingOrDescending()==0){
    //selction sort Ascendingly.

    printf("hello world.\n");
  }else{
    //Selection sort Descendinly.
    printf("hello world.\n");
  }
}

int main(){
  int array[1000];
  //Set length of the array, equivalently ask the user for the value.
  int length=1000;
  //Creates array of random numbers, equivalently ask the user to fill the array.
  srand(0);
  int i;
  for (i = 0; i < 100; i++) {
      array[i] = rand();
  }

  printf("Choose a sorting option:\n\t(1) Selection Sort\n\t(2) Bubble Sort\n\t(3) Insertion Sort\n>>");
  do {
      scanf("%d",&option);
  } while(option<1 || option>3);
  switch (option) {
      case 1:arraySelectionSort(array, length);break;
      case 2:arrayBubbleSort(array, length);break;
      case 3:arrayInsertionSort(array, length);break;
      default:printf("Invalid entry!\n");
  }
  return 0;
}
