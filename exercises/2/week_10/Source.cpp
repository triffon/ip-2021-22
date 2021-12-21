#include <iostream>

using namespace std;

void evilReturnArray(int* array) {
	for (int i = 0; i < 3; i++)
	{
		array[i] += 1;
	}
}

void passByReference(int& b)
{
	int l = 7;
	b = 20;
	b = l;
}



int main() {

	int n = 5, m = 8;

	//cout << &n;

	//int* p = &n;
	//p = &m;

	int* pointer = &n;
	//double* l = &n;

	//int a[] = { 1, 1, 6 }; // нека а има адрес 100
	//int* p = &a[0]; // p сочи адрес 100
	//p += 1; // p вече сочи адрес 104, а не 101
	//cout << *(p + 1); // 

	//int* p = &a[0], * q = &a[1];
	//if (p < q) cout << "Yes";
	//cout << q - p;
	//cout << (p == q);

	//cin >> *pointer;
	//*p = 123; //- грешка по време на изпълнение
	//if (p != nullptr) *p = 123; // или if (p)
	//int* p = nullptr;
	//*p = 123; //- грешка по време на изпълнение. Винаги на инициализиран първо
	int const* p = nullptr;


	//int a[] = { 1, 10, 6 }; // нека а има адрес 100
	//int b[3]; // нека а има адрес 100

	//cout << *(a + 2);
	//int array[3] = { 1,2,3 };
	//evilReturnArray(array);
	//cout << array[0] + array[1] + array[2] << endl; // отпечатва "15"
	//double d[1000] = { 0 };
	//cout << array[0] + array[1] + array[2]; // отпечатва ужас


	int a = 5;

	cout << a;
	passByReference(a);

	cout << a;

	return 0;
}