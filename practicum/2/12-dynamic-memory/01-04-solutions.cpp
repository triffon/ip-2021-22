#include <iostream>
#include <cstring>

// 1.  Напишете функция, която по подаден размер заделя динамична памет за масив
// (от цели числа) с подадения размер и връща указател към него.
int* allocateArray(int size)
{
    return new (std::nothrow) int[size];
}


// 2. Напишете функция, която добавя елемент на края на динамично заделен масив.
int* addToArray(int*& arr, int size, int& capacity, int value)
{
	if (size >= capacity)
	{
		int* newArr = new (std::nothrow) int[size + 1];

		if (!newArr)
			return nullptr;

		for (int i = 0; i < capacity; i++)
		{
			newArr[i] = arr[i];
		}

		delete[] arr;
		arr = newArr;
		capacity = size+1;
	}

	arr[size] = value;
	return arr;
}


// 3. Напишете функция, която по подадени два символни низа връща указател към
// динамично заделен символен низ, който е конкатенацията на двата подадени низа.
// @returns dynamically allocated memory, or nullptr if no space
char* myStrCat(const char* str1, const char* str2)
{
	int newSize = strlen(str1) + strlen(str2) + 1;

	char* newStr = new (std::nothrow) char[newSize];
	if (!newStr)  // !newStr <==> (newStr == nullptr)    
		return nullptr;

	strcpy(newStr, str1);
	strcat(newStr, str2);

	newStr[newSize - 1] = '\0';

	return newStr;
}


// 4. Напишете функция, която по подадени размери заделя динамична памет 
// за матрица (от символи) с подадените размери и връща указател към нея.
char** allocMatrix( int rows, int cols );

// Напишете друга функция, която по подадена
// матрица освобождава заделената памет.
void deallocMatrix( char**& mat, int rows );


char** allocMatrix( int rows, int cols )
{
    // alloc an array of char*
    char** resMat = new (std::nothrow) char*[ rows ];
    if ( !resMat )
        return nullptr;

    // alloc each row
    for ( int i = 0; i < rows; i++ )
    {
        resMat[ i ] = new (std::nothrow) char[ cols ];

        // if allocating a row wasn't successful
        // don't forget too delete all the 
        // previously allocated memory!
        if ( !resMat[ i ] )
        {
            deallocMatrix( resMat, i );
            return nullptr;
        }
    }

    return resMat;
}

void deallocMatrix( char**& mat, int rows )
{
    // delete each row
    for ( int i = 0; i < rows; i++ )
        delete[] mat[ i ];
    
    // delete the mat ptr
    delete[] mat;
    mat = nullptr;
}

//------------------------------------------------------------------------------
int main()
{
    int cnt;
    std::cin >> cnt;

    // Task 1
    int* arr = allocateArray( cnt );
    if ( !arr )
    {
        std::cout << "Not enough memory for allocateArray!";
        return 1;
    }

    for ( int i = 0; i < cnt; i++ )
        std::cin >> arr[i];

    for ( int i = 0; i < cnt; i++ )
        std::cout << arr[ i ] << ' ';
    std::cout << '\n';

    // Task 2
    if ( !addToArray( arr, cnt, cnt, 42 ) )
    {
        std::cout << "Couldn't add 42 to arr - not enough memory.";
    }

    for ( int i = 0; i < cnt; i++ )
        std::cout << arr[ i ] << ' ';
    std::cout << '\n';

    // Task 3
    char* str = myStrCat("fmi", " is great!");
    if ( !str )
    {
        std::cout << "Not enough memory for myStrCat!";
    }
    else
    {
        std::cout << str << '\n';
    }

    // Don't forget to delete all allocated memory!
    delete[] str;
    delete[] arr;

	return 0;
}
