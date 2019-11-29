#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int i, j, min, max, option;

void printArray(int array[], int size) {
    for (i=0;i<size;i++)
        printf("%d ", array[i]);
    printf("\n");
}
void swap(int *x, int *y){
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}
int AscendingOrDescending(){
  printf("Do You want to sort Ascendingly or Descendinly?\n\t(0) Ascendingly\n\t(else) Descendinly\n>>");
  scanf("%d",&option);
  if(option==0)
    return 0;
  else
    return 1;
}

void arraySelectionSort(int array[], int size){
  if(AscendingOrDescending()==0){
    //selction sort Ascendingly.
    for(i=0;i<size;i++){
      min=array[i];
      for(j=i+1;j<size;j++)
        if(array[j]<min){
          min=array[j];
        }
        swap(&array[i], &min);
    }
  }else{
    for(i=0;i<size;i++){
      max=array[i];
      for(j=i+1;j<size;j++)
        if(array[j]>max){
          max=array[j];
        }
      swap(&array[i], &max);
    }
  }
}
void arrayBubbleSort(int array[], int size){
  if(AscendingOrDescending()==0){
    //Selection sort Ascendinly.
   for(i=0;i<size-1;i++)
       for(j=0;j<size-i-1;j++)
           if (array[j] > array[j+1])
              swap(&array[j], &array[j+1]);
  }else{
    //Selection sort Descendinly.
    for (i=0;i<size-1;i++)
        for (j=0;j<size-i-1;j++)
            if (array[j] < array[j+1])
               swap(&array[j], &array[j+1]);
  }
}
void arrayInsertionSort(int array[], int size){
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
  //Set size of the array, equivalently ask the user for the value.
  int size=1000;
  //Creates array of random numbers.
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
      case 1:arraySelectionSort(array, size);break;
      case 2:arrayBubbleSort(array, size);break;
      case 3:arrayInsertionSort(array, size);break;
      default:printf("Invalid entry!\n");
  }
  return 0;
}
