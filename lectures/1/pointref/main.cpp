#include <iostream>
using namespace std;

void testUndefinedPointer() {
    // !!!!!!!
    int* yolo;
    cout << yolo << endl;
    cout << *yolo << endl;
    *yolo = 5;
    cout << *yolo << endl;
}

void testPointers() {
    // !!!
    double d = 1.23;
    double *pd = nullptr;
    if (pd != nullptr)
        cout << *pd << endl;
    pd = &d;
    if (pd != nullptr)
        cout << *pd << endl;
    double *qd = pd;
    cout << d << ' ' << *pd << ' ' << *qd << ' ' << &d << ' ' << pd << ' ' << qd << endl;
    // !!! qd = &4.56;
    // *p = "вземи lvalue-то, което се сочи от p"
    // &x = "вземи адреса на lvalue-то x" = "указател към lvalue-то x"
    *qd = 4.56;
    cout << d << ' ' << *pd << ' ' << *qd << ' ' << &d << ' ' << pd << ' ' << qd << endl;
    d = 7.89;
    cout << d << ' ' << *pd << ' ' << *qd << ' ' << &d << ' ' << pd << ' ' << qd << endl;
    *pd = 1.23;
    cout << d << ' ' << *pd << ' ' << *qd << ' ' << &d << ' ' << pd << ' ' << qd << endl;

    double **    qqd = &qd;
    // !!! **qqd = &qd;
    // qqd == &qd
    // *qqd == *&qd == qd == &d
    // **qqd == **&qd == *qd == *&d == d
    // !!! qqd = &&d;
    cout << qqd << ' ' << &qd << ' ' << &pd << ' ' << *qqd << ' ' << **qqd << endl;
    *pd = 3.45;
    cout << qqd << ' ' << &qd << ' ' << &pd << ' ' << *qqd << ' ' << **qqd << endl;
    **qqd = 3.15;
    cout << d << ' ' << *pd << ' ' << *qd << ' ' << &d << ' ' << pd << ' ' << qd << ' ' << *qqd << ' ' << **qqd << endl;
    pd = qd;
    // !!! &*pd = qd; // !!! &d = qd; 
    pd = &*qd; // <-> pd = qd; <-> pd == &d;
}

void printArrayWithPointers(int a[], int n) {
    cout << sizeof(a) << ' ' << sizeof(a[0]) << endl; // !!!
    for(int i = 0; i < n; i++)
        cout << "a[" << i << "]: " << &a[i] << ' ' << a[i] << endl;
}

void testPointersAndArrays() {
    const int MAX = 10;
    int a[MAX];
    for(int i = 0; i < MAX; i++)
        a[i] = i + 1;
    cout << a << ' ' << &a[0] << endl;
    printArrayWithPointers(a, MAX);
    int* p = a;
    cout << p << ' ' << *p << endl;
    *p = 15;
    printArrayWithPointers(a, MAX);
    *a = 20;
    printArrayWithPointers(a, MAX);
    p = &a[1];
    *p = 30;
    printArrayWithPointers(a, MAX);
    // !!! a = &a[1];
    p = a;
    p = 4 + p;
    cout << a << ' ' << p << endl;
    cout << *a << ' ' << *p << endl;
    *p = 40; // <-> *(a + 4) <-> *(4 + a) <-> a[4]
    printArrayWithPointers(a, MAX);
    cout << sizeof(int) << endl;
    cout << sizeof(5) << endl;
    cout << sizeof(a[1]) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(p) << endl;
    cout << sizeof(*p) << endl;
    cout << sizeof(a) << endl;
    cout << sizeof(a) / sizeof(a[0]) << endl; // !!!
    cout << sizeof(long) << endl;
    long address = (long)p;
    cout << p << ' ' << address << endl;
    cout << (long)(p + 2) << ' ' << address + 2 * sizeof(int) << endl;
    /*
    !!!!!!
    address = 98437598432;
    p = (int*)address;
    cout << *p << endl;
    !!!!!!
    */
    cout << *p-- << endl; // *p-- <-> *(p--)
    cout << *p << endl;
    cout << *--p << endl;
    cout << *p << endl;
    (*(a+4))--;
    printArrayWithPointers(a, MAX);
    cout << 7[a] << endl; // <-> a[7]
}

void testPointersAndStrings() {
    char s[] = "Hello, world!";
    char* p = s;
    cout << p << endl;
    while (*p)
        cout << *p++;
    cout << endl;
    cout << s << endl;
    cout << p << endl;
    p = s;
    while (*p)
        cout << p++ << endl;

    int a[] = { 1, 2, 3, 4, 5, 0 };
    int* q = a;
    cout << a << endl;
    cout << q << endl;
    while (*q)
        cout << q++ << endl;

    int len = 0;
    p = s;
    // !!!while (*s++)
    while (*p++)
        // p е len+1 стъпки от началото на s
        len++;
    cout << len << endl;

    // !!! p = "Hello, world!";
}

void testPointersConsts() {
    int x = 10;
    int const MAX = x;
    // !!! int * const p;
    // !!! p = &x;
    int * const p = &x;
    int * const q = p;
    cout << *p << endl;
    *p = 20;
    // !!! p = q;
    cout << *p << endl;

    int const * r;
    r = p;
    cout << *r << endl;
    int y = 15;
    r = &y;
    cout << *r << endl;
    // !!! *r = 30;

    // !!! int *s = r; *s = 30;

    /*
    int *s = (int*)r;
    *s = 30;
    cout << y << endl;
    */

   // !!! int* pMAX = &MAX;
   int const *pMAX = &MAX;
   cout << *pMAX << endl;
}

void testVoidPointers() {
    int x = 2;
    double y = 1.23;
    char c;
    cout << "коя променлива да избера?";
    cin >> c;
    int *p = &x;
    double *q = &y;
    void* r;
    if (c == 'x') {
    // !!! q = &x;
       p = &x; 
       r = &x;
    }
    if (c == 'y') {
    // !!! p = &y;
       q = &y;
       r = &y;
    }
    /*
    if (c == 'x')
        cout << p << endl;
    if (c == 'y')
        cout << q << endl;
    */
    cout << r << endl;
    r = p;
    r = q;
    r = &r;
    // !!! p = r;
    // !!! q = r;
    cout << r << ' ' << &r << endl;
    // !!! cout << *r << endl;
}

void testReferences() {
    int x = 3, *p = &x, &q = x, a[] = { 1, 2, 3 };
    q += 5;
    cout << x << endl;
    *p += 13;
    cout << q << endl;
    p = a + 1;
    cout << *p << endl; // <-> *(a+1) <-> a[1]
    int &r = p[1]; // <-> a[2]
    r += 5;
    cout << a[2] << endl; // <-> *(p+1) <-> *(a+2)
    // !!! int &s;
    const int& s = a[1];
    // !!! s++;
    int y = s;
    cout << y << ' ' << a[1] << ' ' << s << endl;
    // !!! int& z = s;
    int& z = (int&)s; // !!!
    z++;
    cout << y << ' ' << a[1] << ' ' << s << endl;
}

int main() {
    // testUndefinedPointer();
    // testPointers();
    // testPointersAndArrays();
    // testPointersAndStrings();
    // testPointersConsts();
    // testVoidPointers();
    testReferences();
}
