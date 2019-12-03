#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXWORD 100

char **matrix = NULL; // This pointer will become the matrix after calling malloc.
char evaString[MAXWORD], currentString[MAXWORD];
int option, rows, columns, Pos;

void updateString(char word[MAXWORD], char **matrix, int i){
  int k;
  for(k = 0 ; k < columns ; k++){
    word[k] = matrix[i][k];
  }
  word[k]='\0';
}
void swap(char **matrix, int i,int j){
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
void fillMatrixRow(char word[MAXWORD], char **matrix, int i){
  int k;
  for(k = 0; word[k]!='\0'; k++){
    matrix[i][k] = word[k];
  }
}
void displayMatrix(char **matrix){
  printf("\nYour matrix:\n");
  int l, m;
  for (l = 0 ; l < rows ; l++){
    for(m = 0 ; m < columns ; m++){
      printf("\t%c", matrix[l][m]);
    }
    printf("\n");
  }
}
char **createMatrix(){
  int i;
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
    fillMatrixRow(word, matrix, i);
  }
  return(matrix);
}
void matrixSelectionSort(char **matrix){
  int i, j, k;
  char evaString[MAXWORD], currentString[MAXWORD];

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
void matrixBubbleSort(char **matrix){
  int i, j, k;
  char evaString[MAXWORD], currentString[MAXWORD];

   if(AscendingOrDescending()==0){
    // Selection sort Ascendinly.
    for(i = 0 ; i < rows-1 ; i++){
      for(j = 0 ; j < rows-i-1 ; j++){
        updateString(evaString, matrix, j);
        updateString(currentString, matrix, j+1);
        if(strcmp(evaString, currentString) > 0){
          swap(matrix, j, j+1);
          displayMatrix(matrix);
        }
      }
    }
  //displayMatrix(matrix);
}else{
    //Selection sort Descendinly.
    for(i = 0 ; i < rows-1 ; i++){
      for(j = 0 ; j < rows-i-1 ; j++){
        updateString(evaString, matrix, j);
        updateString(currentString, matrix, j+1);
        if(strcmp(evaString, currentString)<0){
          swap(matrix, j, j+1);
          displayMatrix(matrix);
        }
      }
    }
  }
}
void matrixInsertionSort(char **matrix){
  int i, j;
  char key[MAXWORD], evaString[MAXWORD], currentString[MAXWORD];

  if(AscendingOrDescending()==0){
    //selction sort Ascendingly.
    for (i = 1; i < rows ; i++) {
       //evaString=matrix[i]
        updateString(evaString, matrix, i);
        printf("%s\n", evaString);
        updateString(key, matrix, i);

        j = i - 1;
        //currentString=matrix[j]
        updateString(currentString, matrix, j);
        while (j >= 0 && strcmp(evaString, currentString) < 0) {
             //matrix[j+1]=currentString
             fillMatrixRow(currentString, matrix, j+1);
             updateString(evaString, matrix, i);
             j = j - 1;
        }
        //matrix[j+1]=matrix[i]
        fillMatrixRow(key, matrix, j+1);
        displayMatrix(matrix);
    }
    displayMatrix(matrix);
  }else{
    //Selection sort Descendinly.
    for (i = 1; i < rows ; i++) {
       //evaString=matrix[i]
        updateString(evaString, matrix, i);
        updateString(key, matrix, i);

        j = i - 1;
        //currentString=matrix[j]
        updateString(currentString, matrix, j);
        while (j >= 0 && strcmp(evaString, currentString) > 0) {
             //matrix[j+1]=currentString
             fillMatrixRow(currentString, matrix, j+1);
             updateString(evaString, matrix, i);
             j = j - 1;
        }
        //matrix[j+1]=matrix[i]
        fillMatrixRow(key, matrix, j+1);
        displayMatrix(matrix);
    }
       displayMatrix(matrix);
  }
}
int main(){
  matrix = createMatrix();
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
