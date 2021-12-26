#pragma once

// проверява дали element е сред елементите на array
bool isMember(int array[], int n, int element);

// намира позицията на минималния елемент след дадена позиция start
int findIndexOfMin(int array[], int n, int start);

// сортиране по метода на пряката селекция
void sort(int array[], int n);

// намира позицията, на която се среща element в array, 
// като се използва алгоритъмът за двоично търсене
// array е сортиран във възходящ ред
// ако елементът не се среща в масива, то се връща -1
int findElementsPosition(int array[], int n, int element);

// намира множеството от елементи, върху което е пострен масивът
void findSet(int array[], int n, int set[], int& count);
