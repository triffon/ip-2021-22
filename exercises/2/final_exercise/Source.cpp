#include <iostream>

struct Person {
	int age;
	char* name;
	char* facultyNumber;
	char* adress;
};

void movePointerToNextWord(char*& pointerComparer)
{
	while ((*pointerComparer >= 'a' && *pointerComparer <= 'z') || (*pointerComparer >= 'A' && *pointerComparer <= 'Z') || (*pointerComparer >= '0' && *pointerComparer <= '9') || *pointerComparer == '-' && *pointerComparer != '\0')
	{
		pointerComparer++;
	}
	while (!((*pointerComparer >= 'a' && *pointerComparer <= 'z') || (*pointerComparer >= 'A' && *pointerComparer <= 'Z') || (*pointerComparer >= '0' && *pointerComparer <= '9')) && *pointerComparer != '\0')
	{
		pointerComparer++;
	}
}


char* minWord(char* sentence)
{
	char* minPointer = sentence, * pointerComparer = sentence;

	movePointerToNextWord(pointerComparer);

	while (*pointerComparer != '\0')
	{
		if (*pointerComparer < *minPointer)
		{
			minPointer = pointerComparer;
		}
		movePointerToNextWord(pointerComparer);

	}

	return minPointer;
}

void bubbleSort(char arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

bool checkAnagram(char* arrA, char* arrB)
{
	char newArrA[32];
	char newArrB[32];
	int sizeOfA = strlen(arrA);
	int sizeOfB = strlen(arrB);
	int index = 0;

	for (int i = 0; i < sizeOfA; i++)
	{
		if ((arrA[i] >= 'A' && arrA[i] <= 'Z') || (arrA[i] >= 'a' && arrA[i] <= 'z'))
		{
			if ((arrA[i] >= 'A' && arrA[i] <= 'Z'))
			{
				arrA[i] = (char)(arrA[i] + 32);
			}
			newArrA[index++] = arrA[i];
		}
	}
	newArrA[index] = '\0';
	index = 0;

	for (int i = 0; i < sizeOfB; i++)
	{
		if ((arrB[i] >= 'A' && arrB[i] <= 'Z') || (arrB[i] >= 'a' && arrB[i] <= 'z'))
		{
			if ((arrB[i] >= 'A' && arrB[i] <= 'Z'))
			{
				arrB[i] = (char)(arrB[i] + 32);
			}
			newArrB[index++] = arrB[i];
		}
	}
	newArrB[index] = '\0';

	bubbleSort(newArrA, strlen(newArrA));
	bubbleSort(newArrB, strlen(newArrB));

	if (!(strlen(newArrA) == strlen(newArrB)))
	{
		return false;
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			if (!newArrA[i] == newArrB[i])
			{
				return false;
			}
		}
		return true;
	}
}

double recursiveResult(double* arr, int index, int& result)
{
	if (index == 0)
	{
		return result;
	}
	if (index == 1)
	{
		if (arr[index] > 0)
		{
			if (arr[index] < arr[index - 1])
			{
				return result * arr[index];
			}
			else
			{
				return result;
			}
		}
		else
		{
			return result;
		}

	}
	if (arr[index] > 0)
	{
		if (arr[index] < arr[index - 1])
		{
			result *= arr[index];
			return recursiveResult(arr, --index, result);
		}
		else
		{
			return recursiveResult(arr, --index, result);
		}
	}
	else
	{
		return recursiveResult(arr, --index, result);
	}
}

void backwardWords(char* sentence, int counter, int& it)
{
	if (sentence[counter] == '\0')
	{
		return;
	}
	if (sentence[counter] == ' ') {
		return;
	}
	else
	{
		backwardWords(sentence, counter + 1, ++it);
		if (counter == 0)
		{
			std::cout << sentence[counter] << ' ';
			if (sentence[it] == '\0') return;
			int position = it + 1;
			it = 0;
			backwardWords(sentence + position, 0, it);
		}
		else
		{
			std::cout << sentence[counter];
			return;
		}
	}
}


int main() {

	//Person person;

	//person.age = 22;

	//std::cout << person.age;

	//Задача 1 от контролно 2:

	//char sentence[64];

	//std::cin.getline(sentence, 64);

	//std::cout << minWord(sentence);

	//char sentence[32];
	//char sentence2[32];

	//std::cin.getline(sentence, 32);
	//std::cin.getline(sentence2, 32);

	//std::cout << std::boolalpha << checkAnagram(sentence, sentence2);

	//double arr[8] = {2.1, 0, 9.9, 3, 1, -1, 14.5, 7};
	//int result = 1;

	//std::cout << recursiveResult(arr, 7, result);

	//"iskam da pisha shestici" -> "maksi ad ahsip icitsehs"

	char sentence[32];
	std::cin.getline(sentence, 32);
	int it = 0;

	backwardWords(sentence, 0, it);

	return 0;
}


//Задача 1. (1, 0) Да се реализира функция minWord, която приема като параметър низ и връща указател към началото на лексикографски най - малка непразна дума в него.Дума е непрекъсната последователност от малки и големи латински букви и цифри, всички останали символи се считат за разделители.
//Задача 2. (1, 5) Дадена е квадратна матрица matrix от цели числа с размерност n × n, за 1 ≤ n ≤ 30. Да се реализира функция collect, която приема matrix и числото n връща едномерен масив, съдържащ онези елементи на матрицата, в десетичния запис на които има повтарящи се цифри.Едномерният масив трябва да бъде динамично заделен, с точно толкова елемента, колкото трябва да се съхраняват в него.Да се реализира програма, която въвежда от стандартния вход квадратна матрица, извиква функцията collect по подходящ начин и извежда върнатия като резултат масив на стандартния изход.
//Добавянето на елементите трябва да става спрямо техния ред при обхождането на матрицата по диагоналите успоредни на главния диагонал, започвайки от долния ляв ъгъл, съгласно схемата по - долу:
//Задача 3. (1, 5) Алгебричен израз е зададен с низ, състоящ се от малки латински букви, разделени с единичен знак '.' (умножение)или '+' (събиране).Всяка буква означава цяло число, като съответствието е зададено с два масива от n букви letters и n числа values, като на буквата letters[i] съответства числото values[i].Да се реализира функция calculate, която приема коректно зададен израз, число n и масиви letters и values и връща пресметнатата стойността на израза, спазвайки приоритета на операциите.Ако в израза се среща латинска буква, за която не е зададена стойност, тя да се приеме за 0.
//Упътване: Можете да използвате една променлива, която натрупва текущото произведение и една променлива, която натрупва общата сума.
