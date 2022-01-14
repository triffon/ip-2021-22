#include <iostream>

// двоично търсене
bool isMember(const int* array, int n, int element)
{
	int start = 0;
	int end = n - 1;

	while (start <= end)
	{
		// внимание!
		int middle = (start + end) / 2;

		if (array[middle] == element)
		{
			return true;
		}
		else if (array[middle] < element)
		{
			start = middle + 1;
		}
		else
		{
			end = middle - 1;
		}
	}
	
	return false;
}

// премахване на елемент от масив
void removeElem(int* array, int& n, int index)
{
	if (index < 0 || index >= n)
		return;

	for (int j = index + 1; j < n; ++j)
	{
		array[j - 1] = array[j];
	}

	--n;
}

// завъртане наляво с една позиция
void rotate(int* array, int n)
{
	int oldFirst = array[0];

	for (int i = 1; i < n; ++i)
	{
		array[i - 1] = array[i];
	}

	array[n - 1] = oldFirst;
}

// завъртане наляво times пъти
void rotate(int* array, int n, int times)
{
	for (int i = 1; i <= times; ++i)
	{
		rotate(array, n);
	}
}

// премахване на най-големия елемент от k,
// който не се среща в l
void removeBiggestNotMemberOfL(int* k, int& m, const int* l, int n)
{
	for (int i = m - 1; i >= 0; --i)
	{
		if (!isMember(l, n, k[i]))
		{
			removeElem(k, m, i);
			return;
		}
	}
}

void print(const int* array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		std::cout << array[i] << ' ';
	}
}

// int** - при динамична памет за матрицата
void rotate(int matrix[][20], int n, int* b)
{
	for (int i = 0; i < n; ++i)
	{
		rotate(matrix[i], n, b[i]);
	}
}

// таблица с имена на хора и имената на техните родители
char* mother(char*** database, int n, const char* person)
{
	for (int i = 0; i < n; ++i)
	{
		// database[i][0] -> char*
		int resultComp = strcmp(database[i][0], person);

		if (resultComp == 0)
		{
			return database[i][1];
		}

		if (resultComp > 0)
			return nullptr;
	}

	return nullptr;
}

int main()
{
	//int k[] = { 1, 2, 3, 4, 5 };
	//int m = sizeof(k) / sizeof(int);

	//int l[] = { 1, 2, 3, 5, 7, 8 };
	//int n = sizeof(l) / sizeof(int);

	//removeBiggestNotMemberOfL(k, m, l, n);

	//print(k, m);

	//rotate(k, m, 3);
	//print(k, m);

	const int NAME_MAX_SIZE = 25;

	int n = 3;

	char*** database = new char** [n] {};
	for (int i = 0; i < n; ++i)
	{
		database[i] = new char* [3]{};

		for (int j = 0; j < 3; ++j)
		{
			database[i][j] = new char[NAME_MAX_SIZE];
			std::cin.getline(database[i][j], NAME_MAX_SIZE);
		}
	}

	char* mothersName = mother(database, n, "Ivan Ivanov");
	if (mothersName == nullptr)
	{
		std::cout << "The name of the mother is not specified!\n";
	}
	else
	{
		std::cout << "Mother: " << mothersName << std::endl;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			delete[] database[i][j];
		}

		delete[] database[i];
	}

	delete[] database;

	database = nullptr;
	
	return 0;
}