#pragma once
//��������� ����� ������
int len(const char*);
//���� ������ � �������� ����������,���������� 0 ���� �� �������
int searchStr(char* str,const char* tempstr);
//���� �� ������� ������,tempstr ������������,���������� 0 ���� �� �������
int notEmptyStr(char* str,const char* tempstr);
//������� ����� ������ �� ������ ���������� � ����������,��������� ��� ����� � ������� �������
char* caps(char* str);
//������� ����� ������ �� ������ ���������� � ����������,������������ ������
char* rev(char* str);
//������� ����� ������ �� ������ ���������� � ����������,������ ����� e �� T
char* etoT(char* str);
//��������� �����
int strCmp(const char* str1, const char* str2);
int lenVolve(const char* str);
