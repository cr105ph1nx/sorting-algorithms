#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"functions.h"

void arrayOption(){
  int *createArray(int n){
    int i;
    if (n > 0){
        array = malloc(n * sizeof(int)); // On alloue de la mémoire pour le tableau
        if (array == NULL){ // On vérifie si l'allocation a marché ou non
            exit(0); // On arrête tout
        }
        for (i = 0 ; i < n ; i++){
            printf(" Enter element number %d >> ", i + 1);
            scanf("%d", &array[i]);
        }
    }

    return(array);
  }
  printf(" How many elements? ");
  scanf("%d", &size);

  array = createArray(size);

  printf("\n Choose a sorting option:\n\t(1) Selection Sort\n\t(2) Bubble Sort\n\t(3) Insertion Sort\n\t(4) Quick Sort\n>> ");
  do {
      scanf("%d",&option);
  } while(option<1 || option>4);
  switch (option) {
      case 1:array = arraySelectionSort(array, size, 1);break;
      case 2:array = arrayBubbleSort(array, size, 1);break;
      case 3:array = arrayInsertionSort(array, size, 1);break;
      case 4:
      if(AscendingOrDescending() == 0)
        array = quickSortInt(array, 0, size-1, 0, 1);
      else
        array = quickSortInt(array, 0, size-1, 1, 1);
      break;
  }
  free(array);
}
void matrixOption(int checkStr, int checkByRows){
  //utility functions
  int *createArrayFromMatrix(int checkByRows, int row){
    int i, j, n, k = 0;

    if(checkByRows == 0){//if whole matrix
      n = rows*columns;
      array = malloc(n * sizeof(int)); // On alloue de la mémoire pour le tableau
      if (array == NULL){ // On vérifie si l'allocation a marché ou non
        exit(0); // On arrête tout
      }
      for(i = 0 ; i < rows ; i++){
        for(j = 0 ; j < columns ; j++){
          array[k] = matrixInt[i][j];
          k++;
        }
      }
    }else{//turn given row into array
      if(array == NULL){ // On vérifie si l'allocation a marché ou non
        exit(0); // On arrête tout
      }
      for(j = 0 ; j < columns ; j++){
        array[j] = matrixInt[row][j];
        }
      }
      return(array);
    }
  void arrayToMatrix(int checkByRows, int row){
    int i, j, k = 0;
    if(checkByRows == 1){//row by row
      for(j = 0 ; j < columns ; j++){
        matrixInt[row][j] = array[j];
      }
    }else{//whole matrix
      for(i = 0 ; i < rows ; i++){
        for(j = 0 ; j < columns ; j++){
          matrixInt[i][j] = array[k];
          k++;
        }
      }
    }
  }
  int i, j, k = 0;
  //if user chose matrix of strings
  printf("\n Choose a sorting option:\n\t(1) Selection Sort\n\t(2) Bubble Sort\n\t(3) Insertion Sort\n\t(4) Quick Sort\n>> ");
  do {
      scanf("%d",&option);
  } while(option<1 || option>4);

  if (checkStr == 1){
    switch (option) {
        case 1:matrixStrSelectionSort(matrixStr);break;
        case 2:matrixStrBubbleSort(matrixStr);break;
        case 3:matrixStrInsertionSort(matrixStr);break;
        case 4:
          if(AscendingOrDescending() == 0)
            matrixStr = quickSortChar(matrixStr, 0, rows-1, 0);
          else
            matrixStr = quickSortChar(matrixStr, 0, rows-1, 1);
          break;
        }
    free(matrixStr);
  }//end of matrix of strings
  //if user chose matrix of integers
  else{
    //if user wanted to sort by rows
      if(checkByRows == 1){
        switch (option) {
            case 1:matrixIntSelectionSort(matrixInt);break;
            case 2:matrixIntBubbleSort(matrixInt);break;
            case 3:matrixIntInsertionSort(matrixInt);break;
            case 4:
            array = malloc(columns * sizeof(int));
            if(AscendingOrDescending() == 0)
              option = 0;
            else
              option = 1;
            for(i = 0 ; i < rows ; i++){
              array = createArrayFromMatrix(1, i);
              array = quickSortInt(array, 0, columns-1, option, 0);
              arrayToMatrix(1, i);
              displayMatrixInt(matrixInt);
            }
            break;
        }}//end of rows sort.
      //if user wanted to sort the whole matrix
      else{
        array = createArrayFromMatrix(0, 0);
        switch (option) {
            case 1: array = arraySelectionSort(array, rows*columns, 0); break;
            case 2: array = arrayBubbleSort(array, rows*columns, 0); break;
            case 3: array = arrayInsertionSort(array, rows*columns, 0); break;
            case 4:
            if(AscendingOrDescending() == 0)
              array = quickSortInt(array, 0, rows*columns-1, 0, 0);
            else
              array = quickSortInt(array, 0, rows*columns-1, 1, 0);
            break;
        }
        arrayToMatrix(0, 0);
      }
  free(matrixInt); //end of whole matrix sort.
  }//end of matrix of integers
}
void listOption(){
  Node  *head, *p;

  head = createList();
  displayList(head);

  printf("\n Choose a sorting option:\n\t(1) Selection Sort\n\t(2) Insertion Sort\n>> ");
  do {
      scanf("%d",&option);
  } while(option<1 || option>3);
  switch (option) {
      case 1: head = nodeInsertionSort(head);break;
      case 2: head = nodeInsertionSort(head);break;
  }
  displayList(head);
}

void main(){
  int checkStr = 0, checkByRows = 0;
  printf("\n Hello professor.\n Choose a structure to sort:\n\t(1) An Array\n\t(2) A Matrix\n\t(3) A Linked List\n>> ");
  do {
      scanf("%d",&option);
  } while(option<1 || option>3);
  switch (option) {
      case 1: arrayOption(); break;
      case 2:
        printf("\n Choose a matrix type:\n\t(1) Type Integer\n\t(2) Type String\n>> ");
        do {
            scanf("%d", &option);
        } while(option<1 || option>2);
        switch(option){
            case 1:
              matrixInt = createMatrixInt();
              displayMatrixInt(matrixInt);
              printf("\n Choose a sorting option:\n\t(1) Row by Row\n\t(2) The Whole Matrix\n>> ");
              do {
                  scanf("%d",&option);
              } while(option<1 || option>2);
              switch (option) {
                  case 1: checkByRows = 1; break;
                  case 2: checkByRows = 0; break;
              }
            break;
            case 2:
              matrixStr = createMatrixStr();
              displayMatrixStr(matrixStr);
              checkStr = 1;
            break;
        }
        matrixOption(checkStr, checkByRows);
        break;

      case 3: listOption(); break;
  }

  printf("\n\t______________________________\n\n");
  printf("- Number of swappings: %d\n", nbPerm);
  nbPerm = 0;
  printf("- Number of comparisons: %d\n\n", nbComp);
  nbComp = 0;
  printf(" Thanks for trying out our program. --Mehamli & Djelloul.\n\n");

}
