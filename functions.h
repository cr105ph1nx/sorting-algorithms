#define MAXWORD 100

typedef struct Node{
  char elt[MAXWORD];
  struct Node *next;
}Node;

char **matrixStr = NULL;
int **matrixInt = NULL;
int *array = NULL;
char **arrayChar = NULL;

char evaString[MAXWORD], currentString[MAXWORD];
int option, size, rows, columns;
int nbComp = 0, nbPerm = 0;

int AscendingOrDescending(){
  printf("\n Do You want to sort Ascendingly or Descendinly?\n\t(0) Ascendingly\n\t(else) Descendinly\n>> ");
  scanf("%d",&option);
  nbComp++;
  if(option == 0)
    return 0;
  else
    return 1;
}

//Matrix of int functions
void displayMatrixInt(int **matrixInt){
  printf("\n Your matrix:\n");
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
  nbPerm++;
  displayMatrixInt(matrixInt);
}
int **createMatrixInt(){
  int i, j;
  //Asking for number of rows
  do{
    printf(" What is the number of rows? ");
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
    printf(" What is the number of columns? ");
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
void matrixIntSelectionSort(int **matrixInt){
  int i, j, k, tmp, Pos, minmax;
  if(AscendingOrDescending() == 0){
    nbComp++;
    printf("i = %d\n", i);
    for(i = 0 ; i < rows ; i++){ //every row
      nbComp++;
      for(j = 0 ; j < columns ; j++){ //every column
        nbComp++;
        printf("j = %d\n", j);
        minmax = matrixInt[i][j];
        Pos = j;
        for(k = j+1 ; k < columns ; k++){//search min
          nbComp++;
          printf("k = %d\n", k);
          if(matrixInt[i][k] < minmax){
            nbComp++;
            minmax  = matrixInt[i][k];
            Pos = k;
          }
        }
        swapMatrixInt(matrixInt, i, j, Pos);
      }
    }
  }else{
    nbComp++;
    for(i = 0 ; i < rows ; i++){ //every row
      nbComp++;
      printf("i = %d\n", i);
      for(j = 0 ; j < columns ; j++){ //every column
        nbComp++;
        printf("j = %d\n", j);
        minmax = matrixInt[i][j];
        Pos = j;
        for(k = j+1 ; k < columns ; k++){//search min
          nbComp++;
          printf("k = %d\n", k);
          if(matrixInt[i][k] > minmax){
            nbComp++;
            minmax  = matrixInt[i][k];
            Pos = k;
          }
        }
        swapMatrixInt(matrixInt, i, j, Pos);
      }
    }
  }
}
void matrixIntBubbleSort(int **matrixInt){
  int i, j, k;
  if(AscendingOrDescending() == 0){
    nbComp++;
    for(i = 0 ; i < rows ; i++){ //every row
      nbComp++;
      printf("i = %d\n", i);
      for(j = 0 ; j < columns-1 ; j++){ //every column
        nbComp++;
        printf("j = %d\n", j);
        for(k = 0 ; k < columns-j-1 ; k++){//search min
          nbComp++;
          printf("k = %d\n", k);
          if(matrixInt[i][k] > matrixInt[i][k+1]){
            nbComp++;
            swapMatrixInt(matrixInt, i, k, k+1);
          }
        }
      }
    }
}else{
    nbComp++;
    for(i = 0 ; i < rows ; i++){ //every row
      nbComp++;
      printf("i = %d\n", i);
      for(j = 0 ; j < columns-1 ; j++){ //every column
        nbComp++;
        printf("j = %d\n", j);
        for(k = 0 ; k < columns-j-1 ; k++){//search min
          nbComp++;
          printf("k = %d\n", k);
          if(matrixInt[i][k] < matrixInt[i][k+1]){
            nbComp++;
            swapMatrixInt(matrixInt, i, k, k+1);
          }
        }
      }
    }
  }
}
void matrixIntInsertionSort(int **matrixInt){
  int i, j, k, key;

  if(AscendingOrDescending() == 0){
    nbComp++;
    for(k = 0 ; k < rows ; k++){
      nbComp++;
      printf("k = %d\n", k);
      for (i = 1; i < columns ; i++) {
        nbComp++;
          printf("i = %d\n", i);
          key = matrixInt[k][i];
          j = i - 1;
          printf("j = %d\n", j);

          while (j >= 0 && matrixInt[k][j] > key) {
            nbComp = nbComp + 2;
              matrixInt[k][j + 1] = matrixInt[k][j];
              j = j - 1;
              printf("j = %d\n", j);
              displayMatrixInt(matrixInt);
          }
          matrixInt[k][j + 1] = key;
          displayMatrixInt(matrixInt);
      }
    }
  }else{
    nbComp++;
    for(k = 0 ; k < rows ; k++){
      nbComp++;
      printf("k = %d\n", k);
      for (i = 1; i < columns ; i++) {
        nbComp++;
          printf("i = %d\n", i);
          key = matrixInt[k][i];
          j = i - 1;
          printf("j = %d\n", j);

          while (j >= 0 && matrixInt[k][j] < key) {
            nbComp = nbComp + 2;
              matrixInt[k][j + 1] = matrixInt[k][j];
              j = j - 1;
              printf("j = %d\n", j);
              displayMatrixInt(matrixInt);
          }
          matrixInt[k][j + 1] = key;
          displayMatrixInt(matrixInt);
      }
    }
  }
}

//Array functions
void displayArray(int *array, int size) {
  int i;
    printf("\n Your Array:\n\t");
    for (i = 0 ; i < size ; i++)
        printf("%d\t", array[i]);
    printf("\n");
}
void swapArray(int *array, int x, int y, int isArray){
  int temp;
  temp = array[x];
  array[x] = array[y];
  array[y] = temp;
  nbPerm++;
  if(isArray == 1)
    displayArray(array, size);
  else
    displayMatrixInt(matrixInt);
}
int *arraySelectionSort(int *array, int size, int isArray){
  int i, j, minmax, Pos;
  if(AscendingOrDescending() == 0){
    nbComp++;
    //selction sort Ascendingly.
    for(i = 0 ; i < size ; i++){
      nbComp++;
      printf("i = %d\n", i);
      minmax = array[i];
      Pos = i;
      for(j = i+1 ; j < size ; j++){
        nbComp++;
        if(array[j] < minmax){
          nbComp++;
          minmax = array[j];
          Pos = j;
          printf("j = %d\n", j);
        }
        swapArray(array, i, Pos, isArray);
    }
  }
  }else{
    nbComp++;
    for(i = 0 ; i < size ; i++){
      nbComp++;
      printf("i = %d\n", i);
      minmax = array[i];
      Pos = i;
      for(j = i+1 ; j < size ; j++){
        nbComp++;
        if(array[j] > minmax){
          nbComp++;
          minmax = array[j];
          Pos = j;
          printf("j = %d\n", j);
        }
        swapArray(array, i, Pos, isArray);
    }
  }
  }
  return(array);
}
int *arrayBubbleSort(int *array, int size, int isArray){
  int i, j;
  if(AscendingOrDescending()==0){
    nbComp++;
    //Selection sort Ascendinly.
   for(i = 0 ; i < size-1 ; i++){
       nbComp++;
       printf("i = %d\n", i);
       for(j = 0 ; j < size-i-1 ; j++){
         nbComp++;
         printf("j = %d\n", j);
           if (array[j] > array[j+1]){
             nbComp++;
             swapArray(array, j, j+1, isArray);
             displayArray(array, size);
           }
        }
    }
  }else{
    nbComp++;
    //Selection sort Descendinly.
    for(i = 0 ; i < size-1 ; i++){
        nbComp++;
        printf("i = %d\n", i);
        for(j = 0 ; j < size-i-1 ; j++){
          nbComp++;
          printf("j = %d\n", j);
            if (array[j] < array[j+1]){
              nbComp++;
              swapArray(array, j, j+1, isArray);
              displayArray(array, size);
            }
         }
     }
  }
  return(array);
}
int *arrayInsertionSort(int *array, int size, int isArray){
  int i, key, j;
  if(AscendingOrDescending()==0){
      nbComp++;
       for (i = 1; i < size ; i++) {
           nbComp++;
           printf("i = %d\n", i);
           key = array[i];
           j = i - 1;
           while (j >= 0 && array[j] > key) {
               nbComp = nbComp + 2;
               printf("j = %d\n", j);
               array[j + 1] = array[j];
               j = j - 1;
               nbPerm++;
           }
           array[j + 1] = key;
           nbPerm++;
           if(isArray == 1)
            displayArray(array, size);
          else
            displayMatrixInt(matrixInt);
       }
  }else{
    nbComp++;
    for (i = 1; i < size ; i++) {
        nbComp++;
        printf("i = %d\n", i);
        key = array[i];
        j = i - 1;
        while (j >= 0 && array[j] < key) {
            nbComp = nbComp + 2;
            printf("j = %d\n", j);
            array[j + 1] = array[j];
            j = j - 1;
            nbPerm++;
        }
        array[j + 1] = key;
        nbPerm++;
        if(isArray == 1)
         displayArray(array, size);
       else
         displayMatrixInt(matrixInt);
    }
  }
  return(array);
}
int *quickSortInt(int *array, int low, int high, int option, int isArray){
  int partition (int *array, int low, int high, int option, int isArray){
    if(option == 0){
      nbComp++;
      int pivot = array[high];    // pivot
      int i = (low - 1);
      printf("i = %d\n", i); // Index of smaller element
      for (int j = low; j <= high-1; j++){
        nbComp++;
        printf("j = %d\n", j);
            // If current element is smaller than the pivot
        if (array[j] < pivot){
          nbComp++;
          i++;    // increment index of smaller element
          printf("i = %d\n", i);
          swapArray(array, i, j, isArray);
        }
      }
      swapArray(array, i+1, high, isArray);
      return (i + 1);
    }else{
      nbComp++;
      int pivot = array[high];    // pivot
      int i = (low - 1);
      printf("i = %d\n", i); // Index of smaller element
      for (int j = low; j <= high-1; j++){
        nbComp++;
        printf("j = %d\n", j);
            // If current element is smaller than the pivot
        if (array[j] > pivot){
          nbComp++;
          i++;    // increment index of smaller element
          printf("i = %d\n", i);
          swapArray(array, i, j, isArray);
          }
      }
      swapArray(array, i+1, high, isArray);
      return (i + 1);
    }
  }
  if (low < high){
    nbComp++;
    int pi = partition(array, low, high, option, isArray);
    quickSortInt(array, low, pi - 1, option, isArray);
    quickSortInt(array, pi + 1, high, option, isArray);
  }
  return(array);
}

//Matrix of char functions
void displayMatrixStr(char **matrixStr){
  printf("\n Your Matrix:\n");
  int l, m;
  for (l = 0 ; l < rows ; l++){
    for(m = 0 ; m < columns ; m++){
      printf("\t%c", matrixStr[l][m]);
    }
    printf("\n");
  }
  printf("\n");
}
void swapMatrix(char **matrixStr, int i,int j){
  int tmp, k;
  for (k = 0; k < rows; k++){
    tmp = matrixStr[i][k];
    matrixStr[i][k] = matrixStr[j][k];
    matrixStr[j][k] = tmp;
    nbPerm++;
    nbComp++;
  }
  displayMatrixStr(matrixStr);
}
void updateString(char word[MAXWORD], char **matrixStr, int i){
  int k;
  for(k = 0 ; k < columns ; k++){
    nbComp++;
    word[k] = matrixStr[i][k];
  }
  word[k]='\0';
}
void fillmatrixStrRow(char word[MAXWORD], char **matrixStr, int i){
  int k;
  for(k = 0; word[k]!='\0'; k++){
    nbComp++;
    matrixStr[i][k] = word[k];
  }
}
char **createMatrixStr(){
  char word[MAXWORD];
  //Asking for number of rows
  do{
    printf(" How many words? ");
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
    printf(" What is the length? ");
    scanf("%d", &columns);
  }while(columns <= 0);
  ///Filling matrixStr.
  for(int i = 0 ; i < rows ; i++){
    //allocating space for number of columns.
    matrixStr[i] = malloc(columns*sizeof(char));
    //Asking for word
    do{
      printf(" Enter word number %d >> ", i+1);
      scanf("%s", &word);
    }while(strlen(word)-1>columns);
    //decomposing the word by char and putting each char in column
    fillmatrixStrRow(word, matrixStr, i);
  }
  return(matrixStr);
}
void matrixStrSelectionSort(char **matrixStr){
  int i, j, k, Pos;
  char evaString[MAXWORD], currentString[MAXWORD];

  if(AscendingOrDescending() == 0){ //selection sort Ascendingly.
    nbComp++;
    for(i = 0 ; i < rows ; i++){
      nbComp++;
      printf("i = %d\n", i);
      //evaString = matrixStr[i][0]
      Pos = i;
      updateString(evaString, matrixStr, i);
       //searches for min string and saves its position.
      for(k = i+1 ; k < rows ; k++){
        nbComp++;
        printf("j = %d\n", k);
        //currentString = matrixStr[k][0]
        updateString(currentString, matrixStr, k);
        //if currentString comes first alphabetically then min = currentString and save position of min.
        if(strcmp(currentString, evaString) < 0){
          nbComp++;
          Pos = k;  // save position of the min.
          updateString(evaString, matrixStr, k);
        }
      }
      //swapMatrix current row with min
      swapMatrix(matrixStr, i, Pos);
    }
  }else{
    nbComp++;
    for(i = 0 ; i < rows ; i++){
      nbComp++;
      printf("i = %d\n", i);
      //evaString = matrixStr[i][0]
      Pos = i;
      updateString(evaString, matrixStr, i);
       //searches for min string and saves its position.
      for(k = i+1 ; k < rows ; k++){
        nbComp++;
        printf("j = %d\n", k);
        //currentString = matrixStr[k][0]
        updateString(currentString, matrixStr, k);
        //if currentString comes last alphabetically then min = currentString and save position of min.
        if(strcmp(currentString, evaString) > 0){
          nbComp++;
          Pos = k;  // save position of the min.
          updateString(evaString, matrixStr, k);
        }
      }
      //swapMatrix current row with min
      swapMatrix(matrixStr, i, Pos);
    }
  }
}
void matrixStrBubbleSort(char **matrixStr){
  int i, j, k;
  char evaString[MAXWORD], currentString[MAXWORD];

   if(AscendingOrDescending() == 0){
     nbComp++;
    // Selection sort Ascendinly.
    for(i = 0 ; i < rows-1 ; i++){
      nbComp++;
      printf("i = %d\n", i);
      for(j = 0 ; j < rows-i-1 ; j++){
        nbComp++;
        printf("j = %d\n", j);
        updateString(evaString, matrixStr, j);
        updateString(currentString, matrixStr, j+1);
        if(strcmp(evaString, currentString) > 0){
          nbComp++;
          swapMatrix(matrixStr, j, j+1);
        }
      }
    }
  //displaymatrixStr(matrixStr);
}else{
  nbComp++;
    //Selection sort Descendinly.
    for(i = 0 ; i < rows-1 ; i++){
      nbComp++;
      printf("i = %d\n", i);
      for(j = 0 ; j < rows-i-1 ; j++){
        nbComp++;
        printf("j = %d\n", j);
        updateString(evaString, matrixStr, j);
        updateString(currentString, matrixStr, j+1);
        if(strcmp(evaString, currentString) < 0){
          nbComp++;
          swapMatrix(matrixStr, j, j+1);
        }
      }
    }
  }
}
void matrixStrInsertionSort(char **matrixStr){
  int i, j;
  char key[MAXWORD], evaString[MAXWORD], currentString[MAXWORD];

  if(AscendingOrDescending() == 0){
    nbComp++;
    //selction sort Ascendingly.
    for (i = 1; i < rows ; i++) {
      nbComp++;
        printf("i = %d\n", i);
       //evaString=matrixStr[i]
        updateString(evaString, matrixStr, i);
        updateString(key, matrixStr, i);

        j = i - 1;
        printf("j = %d\n", j);
        //currentString=matrixStr[j]
        updateString(currentString, matrixStr, j);
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && strcmp(evaString, currentString) < 0) {
          nbComp = nbComp + 2;
             //matrixStr[j+1]=currentString
             fillmatrixStrRow(currentString, matrixStr, j+1);
             displayMatrixStr(matrixStr);
             updateString(evaString, matrixStr, i);
             j = j - 1;
             printf("j = %d\n", j);
        }
        //matrixStr[j+1]=matrixStr[i]
        fillmatrixStrRow(key, matrixStr, j+1);
        displayMatrixStr(matrixStr);
    }
  }else{
    nbComp++;
    //Selection sort Descendinly.
    for (i = 1; i < rows ; i++) {
      nbComp++;
        printf("i = %d\n", i);
       //evaString=matrixStr[i]
        updateString(evaString, matrixStr, i);
        updateString(key, matrixStr, i);

        j = i - 1;
        printf("j = %d\n", j);
        //currentString=matrixStr[j]
        updateString(currentString, matrixStr, j);
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && strcmp(evaString, currentString) > 0) {
          nbComp = nbComp + 2;
             //matrixStr[j+1]=currentString
             fillmatrixStrRow(currentString, matrixStr, j+1);
             displayMatrixStr(matrixStr);
             updateString(evaString, matrixStr, i);
             j = j - 1;
             printf("j = %d\n", j);
        }
        //matrixStr[j+1]=matrixStr[i]
        fillmatrixStrRow(key, matrixStr, j+1);
        displayMatrixStr(matrixStr);
    }
  }
}
char **quickSortChar(char **matrixStr, int low, int high, int option){
  int i, j;
  int partition (char **matrixStr, int low, int high, int option){
    if(option == 0){
      nbComp++;
      updateString(evaString, matrixStr, high);// pivot
      int i = (low - 1);  // Index of smaller element
      printf("i = %d\n", i);
      for (int j = low; j <= high-1; j++){
        nbComp++;
        printf("j = %d\n", j);
            // If current element is smaller than the pivot
        updateString(currentString, matrixStr, j);
        if (strcmp(currentString, evaString) < 0){
          nbComp++;
          i++;
            // increment index of smaller element
          swapMatrix(matrixStr, i, j);
        }
      }
      swapMatrix(matrixStr, i+1, high);
      return (i + 1);
    }else{
      nbComp++;
      updateString(evaString, matrixStr, high);// pivot
      int i = (low - 1);  // Index of smaller element
      printf("i = %d\n", i);
      for (int j = low; j <= high-1; j++){
        nbComp++;
        printf("j = %d\n", j);
            // If current element is smaller than the pivot
        updateString(currentString, matrixStr, j);
        if (strcmp(currentString, evaString) > 0){
          nbComp++;
          i++;
            // increment index of smaller element
          swapMatrix(matrixStr, i, j);
        }
      }
      swapMatrix(matrixStr, i+1, high);
      return (i + 1);
    }
  }

  if (low < high){
    nbComp++;
    int pi = partition(matrixStr, low, high, option);
    quickSortChar(matrixStr, low, pi - 1, option);
    quickSortChar(matrixStr, pi + 1, high, option);
  }
  return(matrixStr);
}

//Linked Lists functions
Node *createNode( ){
  Node  *p= (Node *) malloc(sizeof(Node)) ;
  if (p == NULL){
    printf("error: no memory space available.\n") ;
    exit(EXIT_FAILURE);
  }
    return p;
}
void displayList(Node *head){
  Node *p = head;
  printf("\n Your List:\n\t");
  while(p != NULL){
    printf("%s\t", p->elt);
    p = p->next;
  }
  printf("\n\n");
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

  printf("\n How many elements? ");
  scanf("%d",&n);
  tmp.next = NULL;
  prev = &tmp;
  for(i = 1 ; i <= n; i++){
    printf(" Enter element number %d >> ", i);
    scanf("%s", &v);
    prev = addAfter(prev, v);
   }
   return tmp.next;
}
Node *searchAdr(Node *p, int tmp){
  Node  *p1, *pMinMax = p;

  if (p == NULL)
    return NULL;
  nbComp++;
  if(tmp == 0){
    nbComp++;
    while (p1 != NULL){
      nbComp++;
      if (strcmp(p1->elt, pMinMax->elt) < 0)
        nbComp++;
        pMinMax = p1;
        p1 = p1->next;
       }
  }else{
    nbComp++;
    while (p1 != NULL){
      nbComp++;
      if (strcmp(p1->elt, pMinMax->elt) > 0)
        nbComp++;
        pMinMax = p1;
        p1 = p1->next;
       }
  }
  return pMinMax;
}
Node *sortedInsert(Node *head, Node *new_node, int tmp){
    Node *prev, *p;
    if(tmp == 0){
      nbComp++;
      /* Cas speciale ou le noeud est a inserer en head de liste */
      if (head == NULL || strcmp(head->elt, new_node->elt) >= 0){
          nbComp = nbComp + 2;
          new_node->next = head;
          head = new_node;
      }
      else{
          nbComp++;
          /* Localiser le prevedent apres qui le noeud new_node doit etre inserer */
          prev = head;
          p = head->next;
          while (p!=NULL && strcmp(p->elt, new_node->elt) < 0){
              nbComp = nbComp + 2;
              prev = p;
              p = p->next;
          }
          new_node->next = prev->next;
          prev->next = new_node;
          nbPerm++;
      }
    }
    else{
      /* Cas speciale ou le noeud est a inserer en head de liste */
      if (head == NULL || strcmp(head->elt, new_node->elt) <= 0){
          nbComp = nbComp + 2;
          new_node->next = head;
          head = new_node;
      }
      else{
          /* Localiser le prevedent apres qui le noeud new_node doit etre inserer */
          prev = head;
          p = head->next;
          while (p!=NULL && strcmp(p->elt, new_node->elt) > 0){
              nbComp = nbComp + 2;
              prev = p;
              p = p->next;
          }
          new_node->next = prev->next;
          prev->next = new_node;
          nbPerm++;
      }
    }
    return head;
}
Node *nodeSelectionSort(Node *head){
  Node *pMinMax, *p = head;
  char temp[MAXWORD];

  if(AscendingOrDescending() == 0){
    nbComp++;
    while (p->next != NULL){
      nbComp++;
      pMinMax = searchAdr(p, 0);
      /* permuter les elts dans p et pMin si p est # de pMin */
      if (p != pMinMax){
        nbComp++;
        strcpy(temp, p->elt);
        strcpy(p->elt, pMinMax->elt);
        strcpy(pMinMax->elt, temp);
        nbPerm++;
        displayList(head);
      }
      p = p->next;
    }
  }else{
    while (p->next != NULL){
      nbComp++;
      pMinMax = searchAdr(p, 1);
      /* permuter les elts dans p et pMin si p est # de pMin */
      if (p != pMinMax){
        nbComp++;
        strcpy(temp, p->elt);
        strcpy(p->elt, pMinMax->elt);
        strcpy(pMinMax->elt, temp);
        nbPerm++;
        displayList(head);
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
      nbComp++;
      while (pCurrent != NULL){
          nbComp++;
        // Sauvegarder le next pour la prochaine iteration
          pNext = pCurrent->next;
          // inserer le courant dans la liste triee
          pSorted = sortedInsert(pSorted, pCurrent, 0);
          // Mettre a jour le courant
          pCurrent = pNext;
          nbPerm++;
          displayList(head);
      }
    }else{
      nbComp++;
      while (pCurrent != NULL){
          nbComp++;
        // Sauvegarder le next pour la prochaine iteration
          pNext = pCurrent->next;
          // inserer le courant dans la liste triee
          pSorted = sortedInsert(pSorted, pCurrent, 1);
          // Mettre a jour le courant
          pCurrent = pNext;
          nbPerm++;
          displayList(head);
      }
    }
    return(pSorted);
}
