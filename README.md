# 42_CPP_Modules

Репозиторий с упражнениями по C++ Modules в 42.

Сейчас в репозитории есть:

- `Module 00` — основы C++, классы, `static`
- `Module 01` — память, ссылки, указатели, файловые потоки
- `Module 02` — Orthodox Canonical Form, fixed-point numbers, перегрузка операторов

## Структура

```text
00/
├── cpp_module_00.pdf
├── ex00/  megaphone
├── ex01/  phonebook
└── ex02/  account

01/
├── en.subject-01.pdf
├── eval.txt
├── ex00/  BraiiiiiiinnnzzzZ
├── ex01/  Moar brainz!
├── ex02/  HI THIS IS BRAIN
├── ex03/  Unnecessary violence
├── ex04/  Sed is for losers
├── ex05/  Harl 2.0
└── ex06/  Harl filter

02/
├── en.subject.pdf
├── ex00/  My First Class in Orthodox Canonical Form
├── ex01/  Towards a more useful fixed-point number class
├── ex02/  Now we're talking
└── ex03/  BSP
```

## Общие правила

- компиляция через `c++`
- флаги: `-Wall -Wextra -Werror -std=c++98`
- нельзя использовать `printf`, `malloc`, `free`
- нельзя использовать `using namespace std;`
- нужно писать в стиле C++, а не в стиле C
- каждый exercise собирается отдельно через свой `Makefile`

## Сборка

```bash
cd <module>/ex<exercise>
make
```

Примеры:

```bash
cd 00/ex00
make
./megaphone "hello world"
```

```bash
cd 00/ex01
make
./phonebook
```

```bash
cd 00/ex02
make
./account
```

```bash
cd 01/ex04
make
./replace <filename> <s1> <s2>
```

```bash
cd 01/ex06
make
./harlFilter WARNING
```

```bash
cd 02/ex03
make
./bsp
```

## Module 00

### ex00 — Megaphone

Простая программа для знакомства с:

- `main(int argc, char **argv)`
- `std::cout`
- обработкой аргументов командной строки
- компиляцией C++-проекта через `Makefile`

### ex01 — PhoneBook

Первое упражнение на классы:

- класс `PhoneBook`
- класс `Contact`
- массив из 8 контактов
- команды `ADD`, `SEARCH`, `EXIT`
- форматированный вывод через `iomanip`

### ex02 — Account

Упражнение на:

- реализацию методов класса по готовому `header`
- `static` поля и методы
- конструктор и деструктор
- сравнение поведения программы с готовым логом

## Module 01

### ex00 — BraiiiiiiinnnzzzZ

Знакомство с выделением объектов на stack и heap:

- класс `Zombie`
- функции `newZombie` и `randomChump`
- конструктор, деструктор и метод `announce`

### ex01 — Moar brainz!

Упражнение на динамические массивы объектов:

- функция `zombieHorde`
- выделение массива через `new[]`
- освобождение памяти через `delete[]`

### ex02 — HI THIS IS BRAIN

Короткое упражнение на разницу между:

- переменной
- указателем
- ссылкой
- адресом и значением

### ex03 — Unnecessary violence

Упражнение на композицию классов и ссылки:

- классы `Weapon`, `HumanA`, `HumanB`
- хранение оружия по ссылке и по указателю
- изменение общего объекта `Weapon`

### ex04 — Sed is for losers

Работа с файлами и строками:

- чтение файла через `std::ifstream`
- запись результата через `std::ofstream`
- замена всех вхождений строки без `std::string::replace`

### ex05 — Harl 2.0

Упражнение на указатели на методы:

- класс `Harl`
- уровни `DEBUG`, `INFO`, `WARNING`, `ERROR`
- диспетчеризация вызовов без цепочки `if/else`

### ex06 — Harl filter

Расширение `Harl`:

- фильтрация сообщений по уровню
- использование `switch`
- обработка неизвестного уровня

## Module 02

### ex00 — My First Class in Orthodox Canonical Form

Первое упражнение на Orthodox Canonical Form:

- default constructor
- copy constructor
- copy assignment operator
- destructor
- хранение fixed-point value

### ex01 — Towards a more useful fixed-point number class

Расширение класса `Fixed`:

- конструкторы из `int` и `float`
- преобразование в `int` и `float`
- перегрузка `operator<<`
- округление через `roundf`

### ex02 — Now we're talking

Упражнение на перегрузку операторов:

- операторы сравнения
- арифметические операторы
- pre/post increment и decrement
- статические методы `min` и `max`

### ex03 — BSP

Практика с fixed-point числами в геометрии:

- класс `Point`
- неизменяемые координаты
- проверка, находится ли точка внутри треугольника
- работа с площадями и ориентацией точек

## Полезные файлы

- subject Module 00: [00/cpp_module_00.pdf](./00/cpp_module_00.pdf)
- subject Module 01: [01/en.subject-01.pdf](./01/en.subject-01.pdf)
- subject Module 02: [02/en.subject.pdf](./02/en.subject.pdf)
- лог для `00/ex02`: [00/ex02/19920104_091532.log](./00/ex02/19920104_091532.log)
- заметки для проверки Module 01: [01/eval.txt](./01/eval.txt)

## Заметка

`00/ex02` в subject помечен как не обязательный для прохождения модуля, но полезен для понимания:

- `static`
- конструкторов/деструкторов
- состояния объекта и состояния класса
