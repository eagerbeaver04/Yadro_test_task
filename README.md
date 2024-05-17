# Computer Club Management Program

## Описание
Этот проект представляет собой программу для управления компьютерным клубом. Программа считывает входные данные из текстового файла, обрабатывает события в течение рабочего дня клуба, подсчитывает выручку и выводит все произошедшие события, а также итоговые данные занятости и выручки по каждому столу в консоль.

## Структура проекта

В этом разделе описывается структура проекта, включая список файлов и их назначение:

- `Message.h`: Заголовочный файл, реализующий класс Message для удобного соединения строковых данных.
- `Time.h`: Заголовочный файл, реализующий структуру Time для работы со временем.
- `Event.h`: Заголовочный файл, реализующий структуру Event для представления событий в клубе.
- `Table.h`: Заголовочный файл, реализующий структуру Table для представления столов в клубе.
- `Computer_club.h`: Заголовочный файл, реализующий класс Computer_club, который управляет клубом.
- `Computer_club.cpp`: Файл с исходным кодом, содержащий реализацию методов класса Computer_club.
- `Parser.h`: Заголовочный файл, реализующий класс Parser для парсинга входных данных.
- `Parser.cpp`: Файл с исходным кодом, содержащий реализацию методов класса Parser.
- `Reader.h`: Заголовочный файл, реализующий класс Reader для чтения данных из файла.
- `Reader.cpp`: Файл с исходным кодом, содержащий реализацию методов класса Reader.
- `main.cpp`: Главный файл с исходным кодом, содержащий точку входа в программу.
- `test.txt`: Текстовый файл с примером входных данных для тестирования программы.
- `README.md`: Содержит описание проекта, инструкции по использованию и другую информацию.


## Формат входных данных
Входные данные представляют собой текстовый файл, содержащий:

1. Количество столов в виде целого положительного числа.
2. Время начала и окончания работы клуба, разделенные пробелом.
3. Стоимость часа в клубе в виде целого положительного числа.
4. Список входящих событий, разделенных переносом строки.

Пример входного файла (`test.txt`):
## Требования
Для сборки и запуска проекта необходим компилятор C++ (gcc или clang) на Linux, MinGW/Cygwin на Windows.

## Клонирование репозитория
Чтобы получить копию этого проекта на вашем компьютере, выполните следующие шаги:

1. Откройте терминал (командную строку) на вашем компьютере.

2. Выберите или создайте директорию, в которой хотите разместить проект.

3. Введите следующую команду, чтобы склонировать репозиторий:

   ```sh
   git clone https://github.com/eagerbeaver04/Yadro_test_task.git
   ```

## Сборка и запуск
Для сборки и запуска проекта выполните следующие шаги:

1. Скомпилируйте проект:
    ```sh
    g++ Computer_club.cpp Parser.cpp Reader.cpp main.cpp -o computer_club
    ```

2. Запустите программу с указанием входного файла:
    ```sh
    ./computer_club test.txt
    ```

