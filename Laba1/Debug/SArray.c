#define _CRT_SECURE_NO_WARNINGS


#include "SArray.h"
#include "StringTool.h"


SArray* create(unsigned int n, EMode mode)
{
	SArray* tim = (SArray*)malloc(sizeof(SArray));
	if (tim == 0)
		return 0;
	tim->size = n;
	tim->mode= mode;
	n += (mode == mapping)?1:0;
	tim->data = (void**)malloc(sizeof(void*) * n);
	if (tim->data == 0)
	{
		free(tim);
		return 0;
	}
	memset(tim->data, 0, sizeof(void*) * n );
	return tim;
}
int set(SArray* ar, unsigned int pos, const void* data, unsigned int n)
{
	if (pos >= ar->size)
		return 0;
	if (ar->data[pos] != 0)
		free(ar->data[pos]);
	if (data != 0)
	{
		unsigned int size = sizeof(char) * n + 1;
		ar->data[pos] = (void*)malloc(size);
		if ((ar->data[pos]) != 0)
		{
			memset(ar->data[pos], 0, size);
			memcpy(ar->data[pos], data, size);
		}
		else
			return 0;
		}
	else
	{
		ar->data[pos] = 0;
	}
	return 1;
}

int set(SArray* ar, unsigned int pos,const char* str)
{
	unsigned int size = len(str) + 1;
	if (pos >= ar->size)
		return 0;
	if (ar->mode == 0)
	{
		set(ar, pos, (void*)str);
		return 1;
	}
	if (ar->data[pos] != 0)
	{
		free(ar->data[pos]);
	}
		if (str != 0)
	{
		ar->data[pos] = (char*)malloc(size);
		memset(ar->data[pos], 0, size);
		memcpy(ar->data[pos], str, size);
	}
	else
	{
		ar->data[pos] = 0;
	}
	return 1;
}


int set(SArray* ar, unsigned int pos, void* str)
{
	if ((ar->mode == mapping) && (pos > ar->size))
	{
		printf("Error: out of range!");
		return 0;
	}
	//=======================================
	if ((ar->mode != mapping) && (pos >= ar->size))
	{
		printf("Error: out of range!");
		return 0;
	}
	//=======================================

	ar->data[pos] = str;
	return 1;
}



int fillData(SArray* ar, unsigned int n)
{
	
	unsigned int j = 0;
	char str[256];
	while ((getchar()) != '\n');
	for (unsigned int i = 0; i < n; i++)
	{
		printf("String: ");
		gets_s(str);
		set(ar, i, str);
	}
	return 1;
}


void* get(SArray* ar, unsigned int pos)
{
	if (ar == 0)
		return 0;
	if (pos >= ar->size)
		return 0;
	if (ar->mode == mapping)
	{
		/*
		процедура отображения функции на функции(конвейер) требует жесткого соответсвия типов возвращаемых значений функцией и параметров функции
		в данном случае мы делаем конвейер преобразующий строку в число поэтому первая функция задана как pfstr2str, а вторая PFstr2int 
		по этой причине в функции mapfoo делается жесткое преобразование типов в типы функции
		*/
		mapfoo(0, (PFstr2str)ar->data[pos], (PFstr2int)ar->data[ar->size]);
		return mapfoo;
	}
	return ar->data[pos];
}

void clear(SArray* ar)
{
	if (ar == 0)
		return;
	if (ar->data == 0)
		return;
	for (unsigned int i = 0; i < ar->size; i++)
	{
		if (ar->data[i] != 0)
		{
			if (ar->mode == deep)
				free(ar->data[i]);
			ar->data[i] = 0;
		}
	}
	free(ar->data);
	ar->data = 0;
	free(ar);
	ar = 0;
	return;
}


SArray* sum(SArray* A, SArray* B)
{
	
	SArray* res = create(A->size + B->size,A->mode);
	if (A->mode == low)
	{
		for (unsigned int i = 0; i < A->size; i++)
		{
			set(res, i, get(A, i));
		}
		for (unsigned int i = 0; i < B->size; i++)
		{
			set(res, i + A->size, get(B, i));
		}
	}
	else
	{
		/*
		
		так как по условию задачи у нас возможно 2 типа данных:
		строки и функции,то в случае если мы используем массивы
		с выделением памяти под данные,то эти данные могут быть только строками.
		Поэтому мы используем специализированный set(...) для строк.
		Если в данные в массиве являются void,то мы никаким обазом 
		не можем узнать размеры этих данных.

		*/
		for (unsigned int i = 0; i < A->size; i++)
		{
			set(res, i, (char*)get(A, i));
		}
		for (unsigned int i = 0; i < B->size; i++)
		{
			set(res, i + A->size, (char*)get(B, i));
		}
	}
	return res;
}



SArray* where(SArray* arr, PFstrstr2int fwe,const char* tempstr)
{
	if (arr->mode == 0)
		return 0;
	int temp = 0;
	char* str = 0;
	int k = 0;
	int* r = (int*)malloc(sizeof(int) * arr->size);
	if (r == 0)
		return 0;
	/*
	Создан временный массив- для хранения позиции выбранных обьектов, чтобы впоследствии создать массив содержащий только выбранные обьекты
	*/
	for (unsigned int i = 0; i < arr->size; i++)
	{
		str =(char*)get(arr, i);
		if (fwe(str, tempstr) != 0)
		{
			r[k] = i;
			k++;
		}
	}
	if (k == 0)
		return 0;
	SArray* res = create(k, deep);
	for (int i = 0; i < k; i++)
	{
		set(res, i, (char*)arr->data[r[i]]);
	}
	free(r);
	return res;
}




SArray* map(SArray* arr, PFstr2str foo)
{
	if (arr->mode == low)
		return 0;
	char* temp = 0;
	char* str = 0;
	SArray* res = create(arr->size, deep);
	if (res == 0)
		return 0;
	for (unsigned int i = 0; i < arr->size; i++)
	{
		str = (char*)get(arr, i);
		temp = foo(str);
		set(res, i, temp);
	}
	return res;
}

SArray* map(SArray* arr, PFstr2int foo)
{
	if (arr->mode == low)
	{
		SArray* res = create(arr->size, mapping);
		if (res == 0)
			return 0;
		for (unsigned int i = 0; i < arr->size; i++)
		{
			set(res, i, get(arr, i));
		}
		set(res, arr->size, foo);
		return res;
	}
	return 0;
}


int mapfoo(const char* str, PFstr2str foo, PFstr2int map)
{
	// при первом вызове сохраняем в переменную 
// указатели функций, так как переменные статики
// то при следующем вызове мы их вызовем без 
// передачи функций в параметрах  
	static PFstr2int fmap = 0;
	static PFstr2str ffoo = 0;
	if (str == 0) {
		if (map != 0)
			fmap = map;
		ffoo = foo;
		return 0;
	}
	char* temp = ffoo((char*)str);
	int i = fmap(temp);
	// нужно очислить выделенную память, по этому делаем такой огород
	free(temp);
	return i;
}



void print(SArray* arr)
{
	if (arr->mode == 0)
	{
		printf("SArray has not printable data \n");
		return;
	}
		for (unsigned int i = 0; i < arr->size; i++)
	{
		printf("\t %d: %s\n",i ,(char*)get(arr, i));
	}
}
