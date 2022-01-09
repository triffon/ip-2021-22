# Assignments

## Task 1
Напишете функция, която по въведени N и M, въвежда N*M цели числа и ги попълва в динамично заделен двумерен масив. Напишете и функция, която го принтира.

## Task 2
Напишете функция, която по даден едномерен масив с 16 елемента, въвежда елементите му в динамично заделена матрица 4 Х 4. 

## Task 3
Напишете функция като горната, която попълва матрицата по колони.

## Task 4
Напишете функция, която по даден двумерен масив, връща едномерен масив от елементите му в нарастващ ред.

## Task 5
Напишете функция, която по въведено изречение, запазва думите от него в двумерен масив.

## Task 6*
Напишете функция, която по дадено число N, въвежда N изречения и ги запазва в масив. След това създайте нов масив, в който да запазите всички уникални думи от изреченията. (т.е. нещо като речник, ако някоя дума вече е записана, не я добавяте)
- За улеснение приемаме че уникалните думи могад да са най-много 1024 на брой.


# Additional Tasks

## Task 7
Напишете функция, която приема като аргумент масив и позиция от масива и изтрива елемента на тази позиция.

## Task 8
Дадени са два масива – A и B, съответно с рaзмери N и M. Множество наричаме съвкупност от уникални стойности. Множествата на двата масива съвпадат ли?

## Task 9
Да се напише функция, която приема като аргумент квадратна матрица nxn (4 <= n <= 36) и връща сборът на всички нечетни елементи.

## Task 10
Да се напише функция, която приема като аргумент квадратна матрица nxn (4 <= n <= 36) и да връща произведението на всички елементи, в чийто запис се съдържа цифрата 1 и са под вторичния диагонал(без него).

## Task 11
Да се напише функция, която приема като аргумент квадратна матрица nxn (4 <= n <= 36) и извежда на екрана редът и колоната, чийто сбор от елементи е най-голям.

## Task 12
Да се напише функция, която приема като аргумент квадратна матрица nxn (3 <= n <= 32) и връща броят на всички елементи, които са прости числа и са над главния диагонал(с него).

## Task 13
Да се напише функция, която приема като аргумент число k и матрица nxm (1 < n <= 32, 1 < m <= 64) и да се изтрива от нея k-тия стълб.

## Task 14**
Създайте опростена система за бърз анализ на текст. Нека системата ни поддържа няколко метода, които работят с подадено изречение и текст. Текста има максимална дължина от 2048 символа, а изречението с произволна дължина която се въвежда от използващия програмата, максимално 2048...Дума наричаме последователност от символи. Думите са отделени с интервали. Методите са следните:
  - [тип] countConsecutiveWords([параметри]) - намира максималния брой последователни думи от изречението, които се срещат в текста
  - [тип] findSameWordsPercent([параметри]) - връща процента на думите от изречението, които се срещат изобщо в текста. 
  - [тип] createWordsHistogram([параметри]) - връща броя на срещания на всяка дума в текста.