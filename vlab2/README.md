# Эксплуатация уязвимости
## Задание
1. Создать проект С в VS 2008
2. Реализовать две функции:
    - Функция vuln - содержит в себе уязвимость переполнения буфера на стеке. Выбрать один из вариантов для реализации:
        - void vuln (unsigned int arr_size, unsigned char \*arr)
        - void vuln (char\* arr);
    - Функция main - является точкой входа в программу и вызывает уязвимую функцию vuln с аргументами.
3. Сформировать аргументы для функции vuln таким образом чтобы в момент ее работы происходила эксплуатация уязвимости переполнения буфера на стеке и выполнялся следующий код (выбрать один вариант):
   - запускался калькулятор (calc.exe)
   - запускался командный интерпретатор (cmd.exe)
4. После эксплуатации уязвимости, исходная программа должна корректно завершаться.
## Дополнение
Configuration: Release, Optimization: Disabled, Buffer Security Check: No  
Выполнено 24.09.2021 14.36
