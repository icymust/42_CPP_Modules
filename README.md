# 42_CPP_Modules
**Module 00 Version: 11.2**

Репозиторий с упражнениями по C++ Modules в 42.

Сейчас в репозитории есть `Module 00`:

- `ex00` — `megaphone`
- `ex01` — `phonebook`
- `ex02` — `account`

## Структура

```text
00/
├── cpp_module_00.pdf
├── ex00/
│   ├── Makefile
│   └── megaphone.cpp
├── ex01/
│   ├── Makefile
│   ├── main.cpp
│   ├── PhoneBook.cpp
│   └── PhoneBook.hpp
└── ex02/
    ├── Makefile
    ├── Account.cpp
    ├── Account.hpp
    ├── tests.cpp
    └── 19920104_091532.log
```

## Общие правила

- компиляция через `c++`
- флаги: `-Wall -Wextra -Werror -std=c++98`
- нельзя использовать `printf`, `malloc`, `free`
- нельзя использовать `using namespace std;`
- нужно писать в стиле C++, а не в стиле C

## Сборка

### ex00

```bash
cd 00/ex00
make
./megaphone
./megaphone "hello world"
```

### ex01

```bash
cd 00/ex01
make
./phonebook
```

### ex02

```bash
cd 00/ex02
make
./account
```

## Описание упражнений

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

## Полезные файлы

- subject модуля: [00/cpp_module_00.pdf](./00/cpp_module_00.pdf)
- лог для `ex02`: [00/ex02/19920104_091532.log](./00/ex02/19920104_091532.log)

## Заметка

`ex02` в subject помечен как не обязательный для прохождения модуля, но полезен для понимания:

- `static`
- конструкторов/деструкторов
- состояния объекта и состояния класса
