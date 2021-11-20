# Кратка теория - Цикли

> Нека отбележим, че `i-=3` е еквивалентно на `i = i-3` като това правило важи за всички аритметични операции.

## For цикъл

1. Първата дума, която често ще използваме от тук нататък е **итерация**, която означава едно завъртане на цикъла.

```C++
for(int i = 0; i < 25;i++){
    //1          2      3
}
```
   1. **i** се нарича итератор и тук указваме началната стойност на **i**, тя ще брои колко пъти се е завъртял(итерирал) цикъла.
   2. Нашия цикъл, ще се върти(итерира) докато това условие стане изпълнено.
   3. Указваме как да променяме стойноста на итератора при всяко завъртане на цикъла (може да бъде i+=2, i--, i-=3 и тн)
   4. Кодът, които се намира между "{ }" се нарича тяло на цикъла и той е нещото което се изпълнява при всяко завъртане на цикъла. 

## While цикъл

```C++
//Синтаксис
while(<условие>){
    <тяло>;
}
```
- <условие> е булев израз, в който участва променлива, която участва и в тялото на цикъла
- <тяло> е последователност от оператори, където задължително променяме променливата, която използваме в <условието>, за да не изпаднем в ситуация на безкраен цикъл.

### Как работи while?

- При всяка итерация на цикъла се проверява дали <условие>-то е изпълнено.
- Ако условието НЕ е изпълнено, <тяло>-то СПИРА да се изпълнява и цикъла приключва.
- Ако условието Е изпълнено, <тяло>-то се изпълнява още веднъж и се променя стойността на променливата, използвана в <условие>-то

## Do...While цикъл

```C++
// Синтаксис
do{
    <тяло>;
}while(<условие>);  // забележете че за разлика от другите цикли тук имаме **;** след (<условие>)
```
- <условие> е булев израз, в който участва променлива, която участва и в тялото на цикъла
- <тяло> е последователност от оператори, където задължително променяме променливата, която използваме в <условието>, за да не изпаднем в ситуация на безкраен цикъл.

### Как работи do...while?

- Влиза в цикъла и изпълянва тялото
- В тялото променяваме променливата, която използваме в <условие>, за да избегнем безкраен цикъл.
- След като приключи изпълнението на тялото, проверяваме дали е изпълнено <условие>-то.
- Ако условието НЕ е изпълнено, <тяло>-то не се изпълнява повече и изпълнението на цикъла приключва.
- Ако условието Е изпълнено, тялото се изпълнява още веднъж (още една итерация)

> Тук е важно да отбележим разликата между While и Do...While: 
> При **while** първо се прави проверкатана <условие>-то, и ако тя е изпълнена тогава се изпълнява <тяло>-то.
> При **do-while** се изпълнява първо тялото и накрая се прави проверката.
> **ТЯЛОТО НА DO...WHILE ВИНАГИ СЕ ИЗПЪЛНЯВА ПОНЕ ВЕДНЪЖ** 

## Кога използваме различните видове цикли?

- For цикъла е удобен, когато очакваме точен брой на итерациите които ще прави нашия цикъл, например искаме да изведем числата от 0 до n
- While - докато нещо е изпълнено прави <тяло>
- Do-While - цикъла е много подходящ за операции, при които искаме да се изпълни тялото поне веднъж и после да се прави проверката (например валидация на входа)

## Ключови думи - Break и Continue

1. **Break** - прекратява моментално изпълнението на цикъла.
      - След него нищо не се изпълнява
      - Работи еднакво за всички видове цикли
      - **Спомнете си switch** 
2. **Continue** - прекратява текущата итерация и започва нова без да се изпълнява кода по-долу за **текущата** итерация.
      - Работи еднакво за всички видове цикли


# Префиксен и постфиксен оператор

## Префиксен

- `++i` (`--i`), променливата увеличава стойноста си с 1 и после се изпълнява операцията, в която учасва променливата с префиксния оператор.
```C++
int i = 1;
cout << ++i; //Ще изведе 2
```

## Постфиксен
- `i++` (`i--`), първо се изпълнява операцията, в която учасва променливата с постфиксния оператор и чак след като тя приключи се увеличава стойноста ѝ с 1.
```C++
int i = 1;
cout << i++; //Ще изведе 1
cout << i; //Ще изведе 2
```