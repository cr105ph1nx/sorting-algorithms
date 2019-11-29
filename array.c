#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int option;
int AscendingOrDescending(){
  printf("Do You want to sort Ascendingly or Descendinly?\n\t(0) Ascendingly\n\t(else) Descendinly\n>>");
  scanf("%d",&option);
  if(option==0)
    return 0;
  else
    return 1;
}

void arraySelectionSort(int array[1000]){
  if(AscendingOrDescending()==0){
    //selction sort Ascendingly.
    printf("hello world.\n");
  }else{
    //Selection sort Descendinly.
    printf("hello world.\n");
  }

}
void arrayBubbleSort(int array[1000]){
  if(AscendingOrDescending()==0){
    //selction sort Ascendingly.
    printf("hello world.\n");
  }else{
    //Selection sort Descendinly.
    printf("hello world.\n");
  }
}
void arrayInsertionSort(int array[1000]){
  if(AscendingOrDescending()==0){
    //selction sort Ascendingly.
    printf("hello world.\n");
  }else{
    //Selection sort Descendinly.
    printf("hello world.\n");
  }
}

int main(){
  //Creates array of random numbers.
  int array[1000];
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
      case 1:arraySelectionSort(array);break;
      case 2:arrayBubbleSort(array);break;
      case 3:arrayInsertionSort(array);break;
      default:printf("Invalid entry!\n");
  }
  return 0;
}
