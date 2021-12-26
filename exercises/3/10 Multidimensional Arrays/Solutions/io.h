#pragma once

constexpr int MAX_SIZE = 10;

void read(int array[], int n);
void print(int array[], int n);

void read(int matrix[][MAX_SIZE], int rows, int cols);
void printByRows(int matrix[][MAX_SIZE], int rows, int cols);
void printByColumns(int matrix[][MAX_SIZE], int rows, int cols);