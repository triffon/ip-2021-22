const int MAX_COLUMNS = 100;
const int MAX_LENGTH  = 100;

// извежда матрицата a с размерност m x n в табличен вид
void printMatrix(int a[][MAX_COLUMNS], int m, int n);

// въвежда от клавиатурата масив от низове и връща въведения брой низове
unsigned readStringArray(char (*arr)[MAX_LENGTH]);