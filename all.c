#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXWORD 100

typedef struct Node{
  char elt[MAXWORD];
  struct Node *next;
}Node;

char **matrixStr = NULL; // This pointer will become the matrix after calling malloc.
int **matrixInt = NULL; // This pointer will become the matrix after calling malloc.
int *array = NULL;

char evaString[MAXWORD], currentString[MAXWORD];
int option, size, rows, columns;

int AscendingOrDescending(){
  printf("Do You want to sort Ascendingly or Descendinly?\n\t(0) Ascendingly\n\t(else) Descendinly\n>>");
  scanf("%d",&option);
  if(option==0)
    return 0;
  else
    return 1;
}

//Array functions
int *createArray(int n){
  int i;
  if (n > 0){
      array = malloc(n * sizeof(int)); // On alloue de la mémoire pour le tableau
      if (array == NULL){ // On vérifie si l'allocation a marché ou non
          exit(0); // On arrête tout
      }
      for (i = 0 ; i < n ; i++){
          printf("What is the value %d ? ", i + 1);
          scanf("%d", &array[i]);
      }
  }

  return(array);
}
void printArray(int *array, int size) {
  int i;
    for (i = 0 ; i < size ; i++)
        printf("%d ", array[i]);
    printf("\n");
}
void swapArray(int *array, int x, int y){
  int temp;
  temp = array[x];
  array[x] = array[y];
  array[y] = temp;
}
int *arraySelectionSort(int *array, int size){
  int i, j, minmax, Pos;
  if(AscendingOrDescending() == 0){
    //selction sort Ascendingly.
    for(i = 0 ; i < size ; i++){
      minmax = array[i];
      Pos = i;
      for(j = i+1 ; j < size ; j++)
        if(array[j] < minmax){
          minmax = array[j];
          Pos = j;
        }
        swapArray(array, i, Pos);
    }
  }else{
    for(i = 0; i < size ; i++){
      minmax = array[i];
      Pos = i;
      for(j = i+1 ; j < size ; j++)
        if(array[j] > minmax){
          minmax = array[j];
          Pos = j;
        }
      swapArray(array, i, Pos);
    }
  }
  return(array);
}
int *arrayBubbleSort(int *array, int size){
  int i, j;
  if(AscendingOrDescending()==0){
    //Selection sort Ascendinly.
   for(i = 0 ; i < size-1 ; i++)
       for(j = 0 ; j < size-i-1 ; j++)
           if (array[j] > array[j+1])
              swapArray(array, j, j+1);
  }else{
    //Selection sort Descendinly.
    for (i = 0 ; i < size-1 ; i++)
        for (j = 0 ; j < size-i-1 ; j++)
            if (array[j] < array[j+1])
               swapArray(array, j, j+1);
  }
  return(array);
}
int *arrayInsertionSort(int *array, int size){
  int i, key, j;
  if(AscendingOrDescending()==0){
       for (i = 1; i < size ; i++) {
           key = array[i];
           j = i - 1;

           while (j >= 0 && array[j] > key) {
               array[j + 1] = array[j];
               j = j - 1;
           }
           array[j + 1] = key;
       }
  }else{
       for (i = 1; i < size ; i++) {
           key = array[i];
           j = i - 1;

           while (j >= 0 && array[j] < key) {
               array[j + 1] = array[j];
               j = j - 1;
           }
           array[j + 1] = key;
       }
  }
  return(array);
}

//Matrix string functions
void fillmatrixStrRow(char word[MAXWORD], char **matrixStr, int i){
  int k;
  for(k = 0; word[k]!='\0'; k++){
    matrixStr[i][k] = word[k];
  }
}
char **createMatrixStr(){
  int i;
  char word[MAXWORD];
  //Asking for number of rows
  do{
    printf("How many words do you wanna enter? ");
    scanf("%d", &rows);
  }while(rows <= 0);
  //allocating space for number of rows.
  matrixStr = malloc(rows*sizeof(char));
  //Confirm whether the allocation worked.
  if (matrixStr == NULL){
  exit(0); //stop everything in case not.
  }
  //Asking for number of columns
  do{
    printf("What is the length of the words? ");
    scanf("%d", &columns);
  }while(columns <= 0);
  ///Filling matrixStr.
  for(i = 0 ; i < rows ; i++){
    //allocating space for number of columns.
    matrixStr[i] = malloc(columns*sizeof(char));
    //Asking for word
    do{
      printf("Enter word number %d >> ", i+1);
      scanf("%s", &word);
    }while(strlen(word)-1>columns);
    //decomposing the word by char and putting each char in column
    fillmatrixStrRow(word, matrixStr, i);
  }
  return(matrixStr);
}
void displayMatrixStr(char **matrixStr){
  printf("\nYour matrixStr:\n");
  int l, m;
  for (l = 0 ; l < rows ; l++){
    for(m = 0 ; m < columns ; m++){
      printf("\t%c", matrixStr[l][m]);
    }
    printf("\n");
  }
}
void updateString(char word[MAXWORD], char **matrixStr, int i){
  int k;
  for(k = 0 ; k < columns ; k++){
    word[k] = matrixStr[i][k];
  }
  word[k]='\0';
}
void swapMatrix(char **matrixStr, int i,int j){
  int tmp, k;
  for (k=0; k<rows; k++){
    tmp = matrixStr[i][k];
    matrixStr[i][k] = matrixStr[j][k];
    matrixStr[j][k] = tmp;
  }
}
void matrixStrSelectionSort(char **matrixStr){
  int i, j, k, Pos;
  char evaString[MAXWORD], currentString[MAXWORD];

  if(AscendingOrDescending()==0){ //selection sort Ascendingly.
    for(i = 0 ; i < rows ; i++){
      //evaString = matrixStr[i][0]
      Pos = i;
      updateString(evaString, matrixStr, i);
       //searches for min string and saves its position.
      for(k = i+1 ; k < rows ; k++){
        //currentString = matrixStr[k][0]
        updateString(currentString, matrixStr, k);
        //if currentString comes first alphabetically then min = currentString and save position of min.
        if(strcmp(currentString, evaString)<0){
          Pos = k;  // save position of the min.
          updateString(evaString, matrixStr, k);
        }
      }
      //swapMatrix current row with min
      swapMatrix(matrixStr, i, Pos);
    }
    displayMatrixStr(matrixStr);
  }else{
    for(i = 0 ; i < rows ; i++){
      //evaString = matrixStr[i][0]
      Pos = i;
      updateString(evaString, matrixStr, i);
       //searches for min string and saves its position.
      for(k = i+1 ; k < rows ; k++){
        //currentString = matrixStr[k][0]
        updateString(currentString, matrixStr, k);
        //if currentString comes last alphabetically then min = currentString and save position of min.
        if(strcmp(currentString, evaString)>0){
          Pos = k;  // save position of the min.
          updateString(evaString, matrixStr, k);
        }
      }
      //swapMatrix current row with min
      swapMatrix(matrixStr, i, Pos);
    }
  displayMatrixStr(matrixStr);
  }

}
void matrixStrBubbleSort(char **matrixStr){
  int i, j, k;
  char evaString[MAXWORD], currentString[MAXWORD];

   if(AscendingOrDescending()==0){
    // Selection sort Ascendinly.
    for(i = 0 ; i < rows-1 ; i++){
      for(j = 0 ; j < rows-i-1 ; j++){
        updateString(evaString, matrixStr, j);
        updateString(currentString, matrixStr, j+1);
        if(strcmp(evaString, currentString) > 0){
          swapMatrix(matrixStr, j, j+1);
          displayMatrixStr(matrixStr);
        }
      }
    }
  //displaymatrixStr(matrixStr);
}else{
    //Selection sort Descendinly.
    for(i = 0 ; i < rows-1 ; i++){
      for(j = 0 ; j < rows-i-1 ; j++){
        updateString(evaString, matrixStr, j);
        updateString(currentString, matrixStr, j+1);
        if(strcmp(evaString, currentString)<0){
          swapMatrix(matrixStr, j, j+1);
          displayMatrixStr(matrixStr);
        }
      }
    }
  }
}
void matrixStrInsertionSort(char **matrixStr){
  int i, j;
  char key[MAXWORD], evaString[MAXWORD], currentString[MAXWORD];

  if(AscendingOrDescending()==0){
    //selction sort Ascendingly.
    for (i = 1; i < rows ; i++) {
       //evaString=matrixStr[i]
        updateString(evaString, matrixStr, i);
        printf("%s\n", evaString);
        updateString(key, matrixStr, i);

        j = i - 1;
        //currentString=matrixStr[j]
        updateString(currentString, matrixStr, j);
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && strcmp(evaString, currentString) < 0) {
             //matrixStr[j+1]=currentString
             fillmatrixStrRow(currentString, matrixStr, j+1);
             updateString(evaString, matrixStr, i);
             j = j - 1;
        }
        //matrixStr[j+1]=matrixStr[i]
        fillmatrixStrRow(key, matrixStr, j+1);
        displayMatrixStr(matrixStr);
    }
    displayMatrixStr(matrixStr);
  }else{
    //Selection sort Descendinly.
    for (i = 1; i < rows ; i++) {
       //evaString=matrixStr[i]
        updateString(evaString, matrixStr, i);
        updateString(key, matrixStr, i);

        j = i - 1;
        //currentString=matrixStr[j]
        updateString(currentString, matrixStr, j);
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && strcmp(evaString, currentString) > 0) {
             //matrixStr[j+1]=currentString
             fillmatrixStrRow(currentString, matrixStr, j+1);
             updateString(evaString, matrixStr, i);
             j = j - 1;
        }
        //matrixStr[j+1]=matrixStr[i]
        fillmatrixStrRow(key, matrixStr, j+1);
        displayMatrixStr(matrixStr);
    }
       displayMatrixStr(matrixStr);
  }
}

//Matrix int functions
int **createMatrixInt(){
  int i, j;
  //Asking for number of rows
  do{
    printf("What is the number of rows? ");
    scanf("%d", &rows);
  }while(rows <= 0);
  //allocating space for number of rows.
  matrixInt = malloc(rows*sizeof(int));
  //Confirm whether the allocation worked.
  if (matrixInt == NULL){
  exit(0); //stop everything in case not.
  }
  //Asking for number of columns
  do{
    printf("What is the number of columns? ");
    scanf("%d", &columns);
  }while(columns <= 0);
  ///Filling matrix.
  for(i = 0 ; i < rows ; i++){
    //allocating space for number of columns.
    matrixInt[i] = malloc(columns*sizeof(int));
    //Asking for elements
    for(j = 0 ; j < columns ; j++){
      printf("Enter element [%d][%d] >> ", i+1, j+1);
      scanf("%d", &matrixInt[i][j]);
    }
  }
  return(matrixInt);
}
void displayMatrixInt(int **matrixInt){
  printf("\nYour matrix:\n");
  int l, m;
  for (l = 0 ; l < rows ; l++){
    for(m = 0 ; m < columns ; m++){
      printf("\t%d", matrixInt[l][m]);
    }
    printf("\n");
  }
}
void swapMatrixInt(int **matrixInt, int i, int x, int y){
  int temp;
  temp = matrixInt[i][x];
  matrixInt[i][x] = matrixInt[i][y];
  matrixInt[i][y] = temp;

}
int *createArrayFromMatrix(){
  int i, j, n, k = 0;

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
  return(array);
}
void matrixIntSelectionSort(int **matrixInt){
  int i, j, k, tmp, Pos, minmax;

  if(AscendingOrDescending() == 0){
    for(i = 0 ; i < rows ; i++){ //every row
      for(j = 0 ; j < columns ; j++){ //every column
        minmax = matrixInt[i][j];
        Pos = j;
        for(k = j+1 ; k < columns ; k++){//search min
          if(matrixInt[i][k] < minmax){
            minmax  = matrixInt[i][k];
            Pos = k;
          }
        }
        swapMatrixInt(matrixInt, i, j, Pos);
      }
    }
  }else{
    for(i = 0 ; i < rows ; i++){ //every row
      for(j = 0 ; j < columns ; j++){ //every column
        minmax = matrixInt[i][j];
        Pos = j;
        for(k = j+1 ; k < columns ; k++){//search min
          if(matrixInt[i][k] > minmax){
            minmax  = matrixInt[i][k];
            Pos = k;
          }
        }
        swapMatrixInt(matrixInt, i, j, Pos);
        displayMatrixInt(matrixInt);
      }
    }
  }
}
void matrixIntBubbleSort(int **matrixInt){
  int i, j, k;

  if(AscendingOrDescending() == 0){
    for(i = 0 ; i < rows ; i++){ //every row
      for(j = 0 ; j < columns-1 ; j++){ //every column
        for(k = 0 ; k < columns-j-1 ; k++){//search min
          if(matrixInt[i][k] > matrixInt[i][k+1]){
            swapMatrixInt(matrixInt, i, k, k+1);
          }
        }
      }
    }
}else{
    for(i = 0 ; i < rows ; i++){ //every row
      for(j = 0 ; j < columns-1 ; j++){ //every column
        for(k = 0 ; k < columns-j-1 ; k++){//search min
          if(matrixInt[i][k] < matrixInt[i][k+1]){
            swapMatrixInt(matrixInt, i, k, k+1);
          }
        }
      }
    }
  }
}
void matrixIntInsertionSort(int **matrixInt){
  int i, j, k, key;

  if(AscendingOrDescending()==0){
    for(k = 0 ; k < rows ; k++){
      for (i = 1; i < columns ; i++) {
          key = matrixInt[k][i];
          j = i - 1;

          while (j >= 0 && matrixInt[k][j] > key) {
              matrixInt[k][j + 1] = matrixInt[k][j];
              j = j - 1;
          }
          matrixInt[k][j + 1] = key;
      }
    }
  }else{
    for(k = 0 ; k < rows ; k++){
      for (i = 1; i < columns ; i++) {
          key = matrixInt[k][i];
          j = i - 1;

          while (j >= 0 && matrixInt[k][j] < key) {
              matrixInt[k][j + 1] = matrixInt[k][j];
              j = j - 1;
          }
          matrixInt[k][j + 1] = key;
      }
    }
  }
}

//Linked Lists functions
Node *createNode( ){
  Node  *p= (Node *) malloc(sizeof(Node)) ;
  if (p == NULL){
    printf("erreur: Plus d'espace memoire disponible\n") ;
    exit(EXIT_FAILURE);
  }
    return p;
}
void displayList(Node *head){
  Node *p = head;
  printf(" List Elements :\n");
  while(p != NULL){
    printf("%s\t", p->elt);
    p = p->next;
  }
  printf("\n");
}
Node *addAfter(Node  *prev, char v[MAXWORD]){
  Node *p = createNode();
  int i;

  for(i = 0 ; v[i]!='\0' ; i++){
      p->elt[i] = v[i];
  }

  p->next = prev->next;
  prev->next = p;
  return p;
}
Node *createList(){
  Node tmp;
  Node *prev ;
  int n, i;
  char v[MAXWORD];

  printf("What is the number of elts in the list? ");
  scanf("%d",&n);
  tmp.next = NULL;
  prev = &tmp;
  for(i = 1 ; i <= n; i++){
    printf("Give the value number %d > ", i);
    scanf("%s", &v);
    prev = addAfter(prev, v);
   }
   return tmp.next;
}
Node *searchAdr(Node *p, int tmp){
  Node  *p1, *pMinMax = p;

  if (p == NULL)
    return NULL;
    p1 = p->next;

  if(tmp == 0){
    while (p1 != NULL){
      if (strcmp(p1->elt, pMinMax->elt) < 0)
        pMinMax = p1;
        p1 = p1->next;
       }
  }else{
    while (p1 != NULL){
      if (strcmp(p1->elt, pMinMax->elt) > 0)
        pMinMax = p1;
        p1 = p1->next;
       }
  }
  return pMinMax;
}
Node *sortedInsert(Node *head, Node *new_node, int tmp){
    Node *prev, *p;

    if(tmp == 0){
      /* Cas speciale ou le noeud est a inserer en head de liste */
      if (head == NULL || strcmp(head->elt, new_node->elt) >= 0){
          new_node->next = head;
          head = new_node;
      }
      else{
          /* Localiser le prevedent apres qui le noeud new_node doit etre inserer */
          prev = head;
          p = head->next;
          while (p!=NULL && strcmp(p->elt, new_node->elt) < 0){
              prev = p;
              p = p->next;
          }
          new_node->next = prev->next;
          prev->next = new_node;
      }
    }else{
      /* Cas speciale ou le noeud est a inserer en head de liste */
      if (head == NULL || strcmp(head->elt, new_node->elt) <= 0){
          new_node->next = head;
          head = new_node;
      }
      else{
          /* Localiser le prevedent apres qui le noeud new_node doit etre inserer */
          prev = head;
          p = head->next;
          while (p!=NULL && strcmp(p->elt, new_node->elt) > 0){
              prev = p;
              p = p->next;
          }
          new_node->next = prev->next;
          prev->next = new_node;
      }
    }
    return head;
}
Node *nodeSelectionSort(Node *head){
  Node *pMinMax, *p = head;
  char temp[MAXWORD];

  if(AscendingOrDescending() == 0){
    while (p->next != NULL){
      pMinMax = searchAdr(p, 0);
      /* permuter les elts dans p et pMin si p est # de pMin */
      if (p != pMinMax){
        strcpy(temp, p->elt);
        strcpy(p->elt, pMinMax->elt);
        strcpy(pMinMax->elt, temp);
      }
      p = p->next;
    }
  }else{
    while (p->next != NULL){
      pMinMax = searchAdr(p, 0);
      /* permuter les elts dans p et pMin si p est # de pMin */
      if (p != pMinMax){
        strcpy(temp, p->elt);
        strcpy(p->elt, pMinMax->elt);
        strcpy(pMinMax->elt, temp);
      }
      p = p->next;
    }
  }
  return(head);
}
Node *nodeInsertionSort(Node *head){
    // Initialiser liste trie a NULL
    Node *pNext, *pCurrent, *pSorted = NULL;
    pCurrent = head;

    if(AscendingOrDescending() == 0){
      while (pCurrent != NULL){
        // Sauvegarder le next pour la prochaine iteration
          pNext = pCurrent->next;
          // inserer le courant dans la liste triee
          pSorted = sortedInsert(pSorted, pCurrent, 0);
          // Mettre a jour le courant
          pCurrent = pNext;
      }
    }else{
      while (pCurrent != NULL){
        // Sauvegarder le next pour la prochaine iteration
          pNext = pCurrent->next;
          // inserer le courant dans la liste triee
          pSorted = sortedInsert(pSorted, pCurrent, 1);
          // Mettre a jour le courant
          pCurrent = pNext;
      }
    }
    return(pSorted);
}

void arrayFunc(){
  printf("how many elements? ");
  scanf("%d", &size);

  array = createArray(size);

  printf("Choose a sorting option:\n\t(1) Selection Sort\n\t(2) Bubble Sort\n\t(3) Insertion Sort\n>>");
  do {
      scanf("%d",&option);
  } while(option<1 || option>3);
  switch (option) {
      case 1:array = arraySelectionSort(array, size);break;
      case 2:array = arrayBubbleSort(array, size);break;
      case 3:array = arrayInsertionSort(array, size);break;
  }
  printArray(array, size);
  free(array);
}
void matrix(int optionStr, int optionIntAll, int optionIntRows){
  int i, j, k = 0;
  //if user chose matrix of strings
  printf("Choose a sorting option:\n\t(1) Selection Sort\n\t(2) Bubble Sort\n\t(3) Insertion Sort\n>> ");
  do {
      scanf("%d",&option);
  } while(option<1 || option>3);

  if (optionStr == 1){
    switch (option) {
        case 1:matrixStrSelectionSort(matrixStr);break;
        case 2:matrixStrBubbleSort(matrixStr);break;
        case 3:matrixStrInsertionSort(matrixStr);break;
    }
    displayMatrixStr(matrixStr);
    free(matrixStr);
  }//end of matrix of strings
  //if user chose matrix of integers
  else{
    //if user wanted to sort by rows
      if(optionIntRows == 1){
        switch (option) {
            case 1:matrixIntSelectionSort(matrixInt);break;
            case 2:matrixIntBubbleSort(matrixInt);break;
            case 3:matrixIntInsertionSort(matrixInt);break;
        }
      }//end of rows sort.
      //if user wanted to sort the whole matrix
      else{
        array = createArrayFromMatrix();
        printf("%d\n", option);
        switch (option) {
            case 1: array = arraySelectionSort(array, rows*columns); break;
            case 2: array = arrayBubbleSort(array, rows*columns); break;
            case 3: array = arrayInsertionSort(array, rows*columns); break;
        }
        for(i = 0 ; i < rows ; i++){
          for(j = 0 ; j < columns ; j++){
            matrixInt[i][j] = array[k];
            k++;
          }
        }
      } //end of whole matrix sort.

  }//end of matrix of integers
  displayMatrixInt(matrixInt);
  free(matrixInt);
}
void linkedList(){
  Node  *head, *p;

  head = createList();
  displayList(head);

  printf("Choose a sorting option:\n\t(1) Selection Sort\n\t(2) Insertion Sort\n>>");
  do {
      scanf("%d",&option);
  } while(option<1 || option>3);
  switch (option) {
      case 1: head = nodeSelectionSort(head);break;
      case 2: head = nodeInsertionSort(head);break;
  }
  displayList(head);
}

int main(){
  int optionStr = 0, optionIntRows = 0, optionIntAll = 0;

  printf("Choose a structure to sort:\n\t(1) An Array\n\t(2) A Matrix\n\t(3) A Linked List\n>> ");
  do {
      scanf("%d",&option);
  } while(option<1 || option>3);
  switch (option) {
      case 1: arrayFunc(); break;

      case 2:
        printf("Choose a matrix type:\n\t(1) Type Integer\n\t(2) Type String\n>> ");
        do {
            scanf("%d", &option);
        } while(option<1 || option>2);
        switch (option) {
            case 1:
              matrixInt = createMatrixInt();
              displayMatrixInt(matrixInt);
              printf("Choose a sorting option:\n\t(1) Row by Row\n\t(2) The Whole Matrix\n>> ");
              do {
                  scanf("%d",&option);
              } while(option<1 || option>2);
              switch (option) {
                  case 1: optionIntRows = 1; break;
                  case 2: optionIntAll = 1; break;
              }
            break;
            case 2:
              matrixStr = createMatrixStr();
              displayMatrixStr(matrixStr);
              optionStr = 1;
            break;
        }
        matrix(optionStr, optionIntAll, optionIntRows);
        break;

      case 3: linkedList(); break;
  }

return 0;
}
