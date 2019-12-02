#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXWORD 100

char evaString[MAXWORD], currentString[MAXWORD];
int i, j, k, rows, columns, option;
int Pos;

int **matrix = NULL; // This pointer will become the matrix after calling malloc.

void updateString(char word[MAXWORD], int **matrix, int i){
  int j;
  for(j = 0 ; j < columns ; j++){
    word[j] = matrix[i][j];
  }
}
void swap(int **matrix, int i,int j){
  int tmp, k;
  for (k=0; k<rows; k++){
    tmp = matrix[i][k];
    matrix[i][k] = matrix[j][k];
    matrix[j][k] = tmp;
  }
}
int AscendingOrDescending(){
  printf("Do You want to sort Ascendingly or Descendinly?\n\t(0) Ascendingly\n\t(else) Descendinly\n>> ");
  scanf("%d",&option);
  if(option==0)
    return 0;
  else
    return 1;
}

void displayMatrix(int **matrix){
  printf("\nYour matrix:\n");
  for (i = 0 ; i < rows ; i++){
    for(j = 0 ; j < columns ; j++){
      printf("\t%c", matrix[i][j]);
    }
    printf("\n");
  }
}
int **createMatrix(){
  char word[MAXWORD];
  //Asking for number of rows
  do{
    printf("How many words do you wanna enter? ");
    scanf("%d", &rows);
  }while(rows <= 0);
  //allocating space for number of rows.
  matrix = malloc(rows*sizeof(char));
  //Confirm whether the allocation worked.
  if (matrix == NULL){
  exit(0); //stop everything in case not.
  }
  //Asking for number of columns
  do{
    printf("What is the length of the words? ");
    scanf("%d", &columns);
  }while(columns <= 0);
  ///Filling matrix.
  for(i = 0 ; i < rows ; i++){
    //allocating space for number of columns.
    matrix[i] = malloc(columns*sizeof(char));
    //Asking for word
    do{
      printf("Enter word number %d >> ", i+1);
      scanf("%s", &word);
    }while(strlen(word)-1>columns);
    //decomposing the word by char and putting each char in column
    for(j = 0; j < columns ; j++){
      matrix[i][j] = word[j];
    }
  }
  return(matrix);
}

void matrixSelectionSort(int **matrix){
  if(AscendingOrDescending()==0){ //selection sort Ascendingly.
    for(i = 0 ; i < rows ; i++){
      //evaString = matrix[i][0]
      Pos=i;
      updateString(evaString, matrix, i);
       //searches for min string and saves its position.
      for(k = i+1 ; k < rows ; k++){
        //currentString = matrix[k][0]
        updateString(currentString, matrix, k);
        //if currentString comes first alphabetically then min = currentString and save position of min.
        if(strcmp(currentString, evaString)<0){
          Pos = k;  // save position of the min.
          updateString(evaString, matrix, k);
        }
      }
      //swap current row with min
      swap(matrix, i, Pos);
    }
    displayMatrix(matrix);
  }else{
    for(i = 0 ; i < rows ; i++){
      //evaString = matrix[i][0]
      Pos = i;
      updateString(evaString, matrix, i);
       //searches for min string and saves its position.
      for(k = i+1 ; k < rows ; k++){
        //currentString = matrix[k][0]
        updateString(currentString, matrix, k);
        //if currentString comes last alphabetically then min = currentString and save position of min.
        if(strcmp(currentString, evaString)>0){
          Pos = k;  // save position of the min.
          updateString(evaString, matrix, k);
        }
      }
      //swap current row with min
      swap(matrix, i, Pos);
    }
  displayMatrix(matrix);
  }

}
void matrixBubbleSort(int **matrix){
   if(AscendingOrDescending()==0){
    // Selection sort Ascendinly.
    for(i = 0 ; i < rows-1 ; i++){
      for(j = 0 ; j < rows-i-1 ; j++){
        swap(matrix, j, j++);
      }
    }
  }
  //displayMatrix(matrix);
}else{
    //Selection sort Descendinly.
    for(i = 0 ; i < rows-1 ; i++){
      updateString(evaString, matrix, i);
      for(j = 1 ; j < rows-i ; j++)
        updateString(currentString, matrix, j);
        if(strcmp(currentString, evaString)>0)
         swap(matrix, i, j);
      }
      displayMatrix(matrix);
  }
}
void matrixInsertionSort(int **matrix){
  if(AscendingOrDescending()==0){
    //selction sort Ascendingly.
    printf("hello world.\n");
  }else{
    //Selection sort Descendinly.
    printf("hello world.\n");
  }
}

int main(){
  matrix = createMatrix(); //Creates matrix.
  displayMatrix(matrix);
  printf("Choose a sorting option:\n\t(1) Selection Sort\n\t(2) Bubble Sort\n\t(3) Insertion Sort\n>> ");
  do {
      scanf("%d",&option);
  } while(option<1 || option>3);
  switch (option) {
      case 1:matrixSelectionSort(matrix);break;
      case 2:matrixBubbleSort(matrix);break;
      case 3:matrixInsertionSort(matrix);break;
  }

  free(matrix);
  return 0;
}
