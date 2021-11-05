## Functions

- Reuse code
- Give a name to a piece of code
- That's all for now, wait for upcoming exercises

### Syntax

```c++
/*
<return type> <name>(<type_of_arg_1> <name_of_arg_1>, <type_of_arg_2> <name_of_arg_2>, ...)
{
    <body>;
    return <result>;
}
*/

// e.g.

int add(int a, int b) // 2 arguments
{
    return a + b;
}

int meaning_of_life() // 0 arguments
{
    return 42;
}
```

### Declaration

Declare functions before you use them

```c++
int add(int a, int b) { return a + b; }

int main()
{
    int a{add(10, 20)}; // GOOD
    int b{bad_add(10, 20)}; // BAD, bad_add has not been declared yet
}

int bad_add(int am int b) { return a + b; }

```

You can declare a function before you define it (FORWARD DECLARATION)

```c++
int this_works();

int main()
{
    int a{this_works();} // GOOD, this_works has been declared before main

    return 0;
}

int this_works() { return 42; } // but the definition is here

// This is not super important now but a VERY powerful tool when we start to separate our code

```

You cannot define a function (in this fashion) inside another function

```c++
int main()
{
    int error() { return 0; } // ERROR: Does not compile
    return 0;
}
```

There are different ways to position the brackers

```c++
int simple() { return 42; } // GOOD for small functions
int more_complex() { int x; std::cin >> x; return x; } // BAD, multiple statements on the same line

int same_line() {
    int x;
    std::cin >> x;
    return x;
} // GOOD

int new_line()
{
    int x;
    std::cin >> x;
    return x;
} // also GOOD but don't mix the last 2, be consistent
```

Functions follow the same naming conventions as variables.

```c++
int a(int x, int y) { return x + y; } // BAD, what does 'a' mean?
int add(int x, int y) { return x + y; } // GOOD
```

### Usage

```c++
// <name>(<argument1>, <argument2>, ...)

// e.g.

int a{add(10, 20)}; // you can pass literals

int arg1{10};
int arg2{20};
int b{add(arg1, arg2)}; // or variables

int c(add(5, 5), add(10, 10)); // or results of other functions to def
```

### Scope

The arguments passed to a function are COPIES (see pass-by-value pass-by-reference in a later exercise)

```c++
int increment(int a)
{
    return a++;
}

int main()
{
    int a{10}; // this a is not the a in increment
    int b = increment(a); // b is now 11, but a is still 10
    return 0;
}
```

```c++
int another_function()
{
    int in_another_function{};

    return 322;
}

int scope_check(int argument)
{
    int same_scope{};
    {
        int deeper_scope{};
        std::cout << deeper_scope; // GOOD
    }

    std::cout << argument; // GOOD
    std::cout << same_scope; // GOOD
    std::cout << deeper_scope; // ERROR: does not compile
    std::cout << in_another_function; // ERROR: does not compile

    return 0;
}
```

### Alternative declaration syntax - trailing return

```c++
auto name(args) -> return_type

auto add(int, int) -> int
```

- Actually looks like a mathematical function declaration
- Can use some trick with types and templates (next semester)
- You can ommit the return type and leave it for the compiler to deduce (we will AVOID doing that this semester)
- Creates nicer identation

#### NB: The most important thing is to bee stylistically consistent, do NOT mix regular declarations with trailing return types