#include<iostream>
#include<cmath>

int main() {
	int a = 0, b = 0, c = 0;
	std::cin >> a >> b >> c;

	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				//0*x^2 + 0*x + 0 = 0
				std::cout << "Every x is a solution!" << std::endl;
			}
			else {
				//0*x^2 + 0*x + c = 0
				std::cout << "No x is a solution!" << std::endl;
			}
		}
		else {
			if (c == 0) {
				//0*x^2 + b*x + 0 = 0
				std::cout << "x = 0" << std::endl;
			}
			else {
				//0*x^2 + b*x + c = 0
				std::cout << "x = " << (-c / b) << std::endl;
			}
		}
	}
	else {
		if (b == 0) {
			if (c == 0) {
				//a*x^2 + 0x + 0 = 0
				std::cout << "x = 0" << std::endl;
			}
			else {
				//a*x^2 + 0x + c = 0
				if (c > 0 && a > 0 || c < 0 && a < 0) {
					//Can't sqrt numbers less than zero. if c > 0 && a > 0 we have sqrt(-c/a); which is sqrt of negative number.
					std::cout << "No real solutions!" << std::endl;
				}
				else {
					std::cout << sqrt(-c / a) << std::endl;
				}
			}
		}
		else {
			if (c == 0) {
				//ax^2 + bx + 0 = 0
				std::cout << "x1 = 0 and x2 = " << -b / a << std::endl;
			}
			else {
				//ax^2 + bx + c = 0
				double det = ((b * b) - (4 * a * c));
				if (det < 0) {
					std::cout << "No real roots!" << std::endl;
				}
				else if (!det) {
					std::cout << "x1 = x2 = " << (-b / (2 * a)) << std::endl;
				}
				else {
					std::cout << "x1 = " << ((-b - sqrt(det)) / (2 * a))
						<< " x2 = " << ((-b + sqrt(det)) / (2 * a));
				}
			}
		}
	}
}
