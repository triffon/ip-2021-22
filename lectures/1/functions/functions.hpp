// въвеждане на точка point с име "pointName"
void readPoint(char pointName, double point[]);

// въвеждане на координата с име "coord" на точката с име "point"
double readCoordinate(char point, char coord);

// пресмятане на лице на триъгълник по три точки
double calculateTriangleArea(double A[1], double B[1], double C[1]);

// извеждане на лицето
void printTriangleArea(double area);

// пресмятане на дължина на отсечка с два края
double calculateDistance(double P[], double Q[]);

// пресмятане на лице на триъгълник по три страни
double heron(double a, double b, double c);
