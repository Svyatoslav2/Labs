#pragma once
//вычисляет длину строки
int len(const char*);
//ищет строку с заданной подстрокой,возвращает 0 если не найдена
int searchStr(char* str,const char* tempstr);
//ищет не нулевые строки,tempstr игнорируется,возвращает 0 если не найдена
int notEmptyStr(char* str,const char* tempstr);
//Создает новую строку на основе полученной в параметрах,переводит все буквы в верхний регистр
char* caps(char* str);
//Создает новую строку на основе полученной в параметрах,раворачивает строку
char* rev(char* str);
//Создает новую строку на основе полученной в параметрах,меняет букву e на T
char* etoT(char* str);
//Сравнение строк
int strCmp(const char* str1, const char* str2);
int lenVolve(const char* str);
