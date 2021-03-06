# Поразрядные и логические операции
## Задание
Написать программу, которая получает случайное целое типа int, выводит его двоичное представление на экран,
выполняет преобразование в соответствии с вариантом,
затем выводит на экран двоичное представление результата преобразования.

Программу необходимо реализовать в двух вариантах:
1. На языке С.
2. На ассемблере для x86-64.

В обоих случаях в качестве целевой платформы необходимо использовать ОС Linux, в
качестве ассемблера для x86-64 использовать NASM, а компилировать программу на С с
помощью gcc.

После написания программ на C и на ассемблере необходимо выполнить
дизассемблирование программы на С и сравнить получившийся код с ассемблерным кодом,
который был написан для решения задачи вручную.

Отчет должен содержать:
- правильно оформленную титульную страницу;
- задание;
- блок-схему алгоритма преобразования для программы на С;
- текст программы на С с комментариями;
- текст программы на ассемблере NASM с комментариями;
- дизассемблерный листинг существенных частей программы на С с добавленными комментариями или пояснениями;
- краткий анализ по результатам сравнения программы на ассемблере и дизассемблированной программы на С;
- скриншоты прогонов программ на различных исходных данных.

## Вариант #11
Назовем характеристикой байта количество единичных битов. Упорядочить байты числа по возрастанию их характеристик.

## Пример
0xDEADBEEF -> 0xEFDEBEAD

## Output
```
11011110 10101101 10111110 11101111
11101111 11011110 10111110 10101101
```
