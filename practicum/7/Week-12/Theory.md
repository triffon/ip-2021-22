# Рекурсия

Рекурсията е метод за решаване на даден проблем чрез решението на по-малка/проста версия на проблема.   

Например редицата на Фибоначи се дефинира като *Fib(n) = Fib(n - 1) + Fib(n - 2)*

В програмирането рекурсията е директно или индиректно извикване на дадена функция в собственото ѝ тяло. 

```c++
//намиране на N-тия елемент от редицата на Фибоначи
int fib(int n) {
    if(n == 0 || n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2); //рекурсивни извиквания
}
```
## Дъно

За да може рекурсивна фунцкия да приключи, тя трябва да има условие, при което не извиква самата себе си, а връща готов резултат. Това условие наричаме дъно.

```c++
int factorial(int n) {
    if(n == 0) //дъно
        return 1;
    
    return n * factorial(n - 1);
}

void print(int n) {
    if(n == 0){
        std::cout << std::endl;
        return;
    }
    
    std::cout << n << ' ';

    print(n - 1);
} 
```
Ако няма дъно, функцията изпада в *безкрайна рекурсия*

```c++
int sum(int n)  {
    return n + sum(n - 1);
}
```
## Типове рекурсия

- Според това къде в тялото се случва рекурсивното извикване (head, tail recursion)
- Според това колко пъти се извиква (linear, tree recursion)
- Според това как се извиква (директно, индиректно)

### Tail recursion

Ако последното нещо, което правим, е да викнем функцията:

```c++
void print(int n) {
    if(n == 0)
        return;
    
    std::cout << n << ' ';
    print(n - 1);
}

int main() {
    print(5); //5 4 3 2 1
    return 0;
}
```
### Head recursion

Ако викаме функцията преди всички останали действия
```c++
void print(int n) {
    if(n == 0)
        return;

    print(n - 1);
    std::cout << n << ' ';
}

int main() {
    print(5); //1 2 3 4 5
    return 0;
}
```
### Linear recursion
Горните два примера са линейна рекурсия, защото правим само едно рекурсивно извикване.

### Tree recursion
Ако правим повече от едно извикване, както в примера с Фибоначи

### Direct recursion
Ако викаме самата функция в себе си

### Indirect recursion
Ако викаме друга функция, която в себе си вика първата

```c++
void anotherPrint(int n);
void print(int n) {
    if(n == 0)
        return;

    anotherPrint(n - 1);
    std::cout << n;
}

void anotherPrint(int n){
    if(n == 0)
        return;

    anotherPrint(n - 1);
    std::cout << ' ';
}
```

## Wrappers

Понякога се налага да подаваме много параметри на рекурсивната функция и не е удобно да я използваме. За това използваме *"опаковки"*.

```c++
void printArrRec(int arr[], int size, int i) {
    if(i == size)
        return;

    std::cout << arr[i] << ' ';
    printArrRec(arr, size, i + 1);
 }

//Wrapper
 void printArr(int arr[], int size){
     printArrRec(arr, size, 0);
 }
```

