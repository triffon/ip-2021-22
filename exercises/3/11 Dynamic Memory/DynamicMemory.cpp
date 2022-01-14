#include <iostream>

int* allocate(unsigned size)
{
	int* array = new int[size] {};
	return array;
}

void deallocate(int*& array)
{
	delete[] array;
	array = nullptr;
}

void read(int* array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cin >> array[i];
	}
}

void resize(int*& array, int size, int newCapacity)
{
	if (newCapacity <= size)
		return;

	int* buffer = new int[newCapacity] {};
	for (int i = 0; i < size; ++i)
	{
		buffer[i] = array[i];
	}

	delete[] array;

	array = buffer;
}

bool isPalindrome(int* array, int n)
{
	int* start = &array[0]; // array
	int* end = &array[n - 1]; // array + n - 1;

	while (start < end)
	{
		if (*start != *end)
			return false;

		++start;
		--end;
	}

	return true;
}

int** allocateMatrix(unsigned width, unsigned height)
{
	int** matrix = new int* [height];
	for (unsigned i = 0; i < height; ++i)
	{
		matrix[i] = new int[width];
	}

	return matrix;
}

void deallocateMatrix(int**& matrix, unsigned height)
{
	for (unsigned i = 0; i < height; ++i)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
	matrix = nullptr;
}

// ïîñëåäîâàòåëíà ïàìåò
int* allocateMatrixAsSingleRow(unsigned height, unsigned width)
{
	int* matrix = new int[height * width];
	return matrix;
}

// òðÿáâà äà ñå ïîãðèæèì çà äîñòúïà äî åëåìåíòèòå
int& elementAt(int* matrix, unsigned width, unsigned i, unsigned j)
{
	return matrix[width * i + j];
}

void deallocateÌatrixAsSingleRow(int*& matrix)
{
	delete[] matrix;
	matrix = nullptr;
}


int main()
{
	// åäíîìåðåí ìàñèâ
	int* arr = allocate(5);
	
	read(arr, 5);
	resize(arr, 5, 10);

	std::cout << arr[8] << std::endl;

	deallocate(arr);

	// ìàòðèöà
	unsigned size = 3;
	int* matrix = allocateMatrixAsSingleRow(size, size);

	for (unsigned i = 0; i < size; ++i)
	{
		for (unsigned j = 0; j < size; ++j)
		{
			std::cin >> elementAt(matrix, size, i, j);
		}
	}

	for (unsigned i = 0; i < size; ++i)
	{
		for (unsigned j = 0; j < size; ++j)
		{
			std::cout << elementAt(matrix, size, i, j) << ' ';
		}

		std::cout << '\n';
	}

	deallocateÌatrixAsSingleRow(matrix);

	return 0;
}