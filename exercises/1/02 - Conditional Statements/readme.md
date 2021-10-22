# Ex02 - Conditionals

## const type qualifer

Adding const during a variable declaration specifies that it should be constant and prevents people from changing it

- const variables must be initialized

```c++
const pi = 3.14; // GOOD
const pi2; // ERROR: Does not compile
```
- It's easier to reason about const variables (you don't need to worry about someone else changing the data)
- One popular approach to programming is making all data constant
- By default, make variables constant https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#con1-by-default-make-objects-immutable

## Definition: Integral Type

Any type that models a whole number (e.g. int, unsigned, long int, etc ...) + bool + different versions of char

Full list here: https://en.cppreference.com/w/cpp/types/is_integral

## Conditional Statements

### if

```c++
if (statement)
{
    // This will execute iff statement is true
}
else if (other_statement)
{
    // This will execute iff statement is false and other_statement is true
}
else
{
    // This will execute iff both statement and other_statement are false
}
```

- else if must follow an if or an else if
- else must be the last thing in the chain

- You can nest ifs

```c++
if (statement1)
{
    // This will execute if statement1 is true
    if (statement2)
    {
        // This will execute if both statement1 and statement2 are true
    }
}
```

- In C++17 you can initilize variables in the condition to limit their scope

```c++
if (bool condition = get_value(); condition)
{
    std::cout << condition; // OK, condition is in scope
}
else if (bool another = get_another_value(); another)
{
    std::cout << condition << another; // OK, both are in scope. Condition was passed on from the if
}
else
{
    std::cout << condition << another; // OK, both are in scope. Condition was passed on from the if, another from the else if
}
std::cout << condition; // ERROR, condition is out of scope
std::cout << another; // ERROR, another is out of scope

```

- You can use early returns in functions instead of else

```c++
int f1(bool cond)
{
    if (cond)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

// is equivalent to

int f2(bool cond)
{
    if (cond)
    {
        return 1;
    }

    return 2;
}
```

### ternary conditional operator

- The only ternary (3 operands) operator
- Checks is the first operand is true or false and depending on the result evaluates and returns either the second (if the first is true) or the third (if the first is false)

```c++
condition ? value_if_true : value_if_false;

// e.g.

a < b ? a : b; // min(a, b)
```

- Avoid nesting ternary operators
```c++
a == b ? "equal" : a < b ? "lesser" : "greater"; // BAD, Hard to read, should probably be an if or a switch 
```

### switch

Transfer control to one of many statements depending on a condition

```c++
switch (integral_type_condition)
{
    case constant_expression_1:
        // Execution will start here if integral_type_condition == constant_expression_1
    case constant_expression_2:
        // Execution will start here if integral_type_condition == constant_expression_2
    default:
        // Execution will start here if none of the above constant_expressions are equal to the condition
}
```

Adding ```break``` in a statement will prevent the following cases from executing

```c++
switch (integral_type_condition)
{
    case constant_expression_1:
        // Execution will start here if integral_type_condition == constant_expression_1
        break; // Execution will stop here
    case constant_expression_2:
        // Execution will start here if integral_type_condition == constant_expression_2
        break; // Execution will stop here
    default:
        // Execution will start here if none of the above constant_expressions are equal to the condition
        // No need to break here
}
```

You can group cases

```c++
switch (integral_type_condition)
{
    case constant_expression_1:
    case constant_expression_2:
        // Execution will start here if integral_type_condition is equal to either constant_expresison 1 or 2
        break; // Execution will stop here
    default:
        // Execution will start here if none of the above constant_expressions are equal to the condition
        // No need to break here
}
```

- Always break after non-emmpty / non-default cases https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es78-always-end-a-non-empty-case-with-a-break

- Prefer switch to if when possible https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es70-prefer-a-switch-statement-to-an-if-statement-when-there-is-a-choice

- Use default to handle non-common cases https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#es79-use-default-to-handle-common-cases-only

- In C++17 you can initilize variables in the condition to limit their scope

```c++
switch (int condition = get_value(); condition)
{
    // ...
    // condition is visible only here
}
```

## Problems

### 01

Given the radius of a circle, calculate its perimeter

### 02

Given the coordinates of 2 chess figures, check if they can take eachother

- 2 rooks
- 2 bishops
- 2 queens
- 2 horses

### 03

Check if given point in a 2D plane is a bove the line with equation 4x+y=24

### 04

Given a number, output if it is positive, negative or zero.

### 05

Rewrite the old min function using an if statement.

### 06

Given the coordinates of a point in a 2D plane and also the coordinates of circle as well as its radius. Output "inside" / "outside" / "on" depending on the position of the point relative to the circle

### 07

Given a number between 1 and 7, output the name of the corresponding day of the week.

### 08

Given a day, month and year, check if it is a valid year.

### 09

[](?raw=true)

![Figure 1-1](https://i.imgur.com/uCAD40m.jpg "Figure 1-1")