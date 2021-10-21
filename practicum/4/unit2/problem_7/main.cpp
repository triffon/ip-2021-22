/*
 * Задача 7
 * Създайте програма, която съдържа булеви променливи, които имат стойност true, ако следното е вярно, или false в противен случай:
   * Цяло число се дели на 5 и 3 ИЛИ на 7 и 11
   * Число е в интервала [a,b]
   * Уравнението ax^2+bx+c има реални корени
   * Точка с координати (x,y) се намира в кръг с радиус r и с център точката с координати (cx, cy)
   * Поне 2 цифри на едно четирицифрено цяло число са равни
 */
#include <cmath>

int main() {
	// Uncomment the section you would like to test (due to clashing variable names)

	// Whether a number is divisible by 5 and 3 OR by 7 and 11
	/*int n1;

	const bool div5 = n1 % 5 == 0;
	const bool div3 = n1 % 3 == 0;
	const bool div7 = n1 % 7 == 0;
	const bool div11 = n1 % 11 == 0;

	const bool result = (div5 && div3) || (div7 && div11);*/

	// Whether a number x is in the interval [a,b]
	/*int a, b, x;
	const bool insideInterval = x >= a && x <= b;*/

	// Whether the equation ax^2+bx+c has real roots
	/*float a, b, c;

	const bool isLinearWithoutRoots = (a == 0 && b == 0 && c != 0);
	const float discriminant = b * b - 4 * a*c;
	const bool result = !isLinearWithoutRoots && sqrt(discriminant) >= 0;*/

	// Whether a point with coordinates (x,y) is located inside a circle with radius r and center with coordinates (cx,cy)
	float x, y;
	float cx, cy;
	float r;
	
	const float distance = sqrt((x - cx)*(x - cx) + (y - cy)*(y - cy));
	const bool isInside = distance < r;

	// Whether at least 2 digits of a 4-digit integer are equal
	unsigned int num;

	const int digit1 = num / 1000;
	const int digit2 = num / 100 % 10;
	const int digit3 = num / 10 % 10;
	const int digit4 = num % 10;
	const bool result = (
		digit1 == digit2 || 
		digit1 == digit3 || 
		digit1 == digit4 || 
		digit2 == digit3 || 
		digit2 == digit4 || 
		digit3 == digit4
	);

}