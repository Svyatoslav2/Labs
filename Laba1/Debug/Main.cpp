#define _CRT_SECURE_NO_WARNINGS

#include "SArray.h"
#include "StringTool.h"
#include "Test.h"
#include "Function.h"
char fooName[][9] = { "sum","minus","mult","max","min","triangle","Unknown" };
tresult fooArray[] = { summ,minus,mult,max,min,triangle };







int concat();
int where();
int mmap();
int mmap1();
int mMapFunc();
int concatFunc();
int mMapStr();


int testString()

{
	while ((getchar()) != '\n');
	char ch = 0;
	int s = 0;
	while (ch != 'x') {
		printf("=========================================================\n");
		printf("Manual Test String Menu \n\n");

		printf("Choose operation:  \n");
		printf("1 - Concationation function \n");
		printf("2 - Test \"Map\" Function\n");
		printf("3 - Test \"Where\" Function\n");
		printf("x - Exit to previous menu\n");
		s = scanf("%c", &ch);
		switch (ch)
		{
		case '1': concat(); break;
		case '2': mMapStr(); break;
		case '3': where(); break;
		}
	}
	return 0;
}


int testFunction()
{
	while ((getchar()) != '\n');
	int s = 0;
	char ch = 0;
	while (ch != 'x') {
		printf("=========================================================\n");
		printf("Manual Function Test Menu \n\n");

		printf("Choose operation:  \n");
		printf("1 - Concationation function \n");
		printf("2 - Test \"Map\" Function\n");
		printf("x - Exit to previous menu\n");
		s = scanf("%c", &ch);
		switch (ch)
		{
		case '1': concatFunc(); break;
		case '2': mMapFunc(); break;
		}
	}
	while ((getchar()) != '\n');
	return 0;
}

void autotest() {
	int failedTest = 0;
	failedTest += testSArrayChar();
	failedTest += testSArrayCharV();
	failedTest += testConcat();
	failedTest += testMap();
	failedTest += testWhere();
	failedTest += testConcatFunc();
	failedTest += testMapFunc();
	printf("\n============== TEST DONE ============\n");
	if (failedTest == 0)
		printf("\nAll test PASSED!\n");
	else
	    printf("\nFAILED %d test(s)!\n", failedTest);

	while ((getchar()) != '\n');

}

void manualtest() {
	while ((getchar()) != '\n');
	int s = 0;
	char ch = 0;
	while (ch != 'x') {
		printf("=========================================================\n");
		printf("Manual Test Menu \n\n");
		printf("Choose operation:  \n");
		printf("1 - Test String mode  \n");
		printf("2 - Test Function mode  \n");
		printf("x - Exit to previous menu\n");
		s = scanf("%c", &ch);
		switch (ch) {
		case '1': testString(); break;
		case '2': testFunction(); break;
		}
	}
	while ((getchar()) != '\n');
}

void mainMenu()
{
	printf("SArray demonstration\n");
	char ch = 0;
	int s = 0;
	while (ch != 'x') {
		printf("=========================================================\n");
		printf("Main Menu \n\n");

		printf("Choose operation:  \n");
		printf("1 - Auto test  \n");
		printf("2 - Manual test  \n");
		printf("x - Exit \n");
		s = scanf("%c", &ch);
		switch (ch) {
		case '1': autotest(); break;
		case '2': manualtest(); break;
		}
	}
}


tresult getfoo()
{
	printf("Choose function(0-5): \n");
	for (int i = 0; i < 6; i++)
		printf("\t%d - %s \n", i, fooName[i]);
	int t=0,s;
	s=scanf("%d", &t);
	if ((t >= 0) && (t < 6))
		return fooArray[t];
	printf("Function dont exist");
	return 0;
}

char* getfooName(tresult foo)
{

	for (int i = 0; i < 6; i++)
	{
		if (foo == fooArray[i])
			return fooName[i];
	}
	return fooName[6];
}

int concatFunc()
{
	SArray* funcname = create(3, low);
	set(funcname,0,summ);
	set(funcname, 1, minus);
	set(funcname, 2,mult);
	SArray* funcnum = create(3, low);
	set(funcnum, 0, max);
	set(funcnum, 1, min);
	set(funcnum, 2, triangle);
	SArray* result = create(6, low);
	result = sum(funcname, funcnum);
	int res=0;
	for (unsigned int i = 0; i < result->size; i++)
	{
		tresult foo = (tresult)get(result, i);
		printf("\t %d: %s \n",i,getfooName(foo));
	}
	int a=0, b=0,s=0;
	printf("Input a: ");
	s=scanf("%d", &a);
	printf("Input b: ");
	s=scanf("%d", &b);
	for (unsigned int i = 0; i < result->size; i++)
	{
		tresult foo = (tresult)get(result, i);
		res = foo(a, b);
		printf("\t  %s(%d,%d)=%d \n", getfooName(foo),a,b,res);
	}
	return 0;
}


int mMapFunc()
{
	SArray* func = create(3, low);
	set(func, 0, rev);
	set(func, 1, caps);
	set(func, 2, etoT);
	SArray* changedfunc = map(func, lenVolve);
	if (changedfunc == 0)
	{
		printf("Error : map function crashed \n");
		return 0;
	}
	PFstr2int foo = 0;
	for (unsigned int i = 0; i < changedfunc->size; i++)
	{
		foo = (PFstr2int)get(changedfunc, i);
		int res;
		res = foo("Test succed");
		printf("%u \n", res);
	}
	clear(changedfunc);
	clear(func);
	return 1;
}

int mMapStr()
{
	while ((getchar()) != '\n');
	unsigned int k = 0, s = 0;
	char ch = 0;
	printf("Input count of strings:");
	s = scanf("%u", &k);
	SArray* test3 = create(k, deep);
	SArray* res = 0;
	fillData(test3, k);
	printf("Choose function: \n");
	printf("1 - caps \n");
	printf("2 - reverse \n");
	printf("3 - etoT \n");
	s = scanf("%c", &ch);
	switch (ch)
	{
	case '1':
		res = map(test3, caps);
		printf("Modified SArray:\n");
		print(res);
		clear(res);
		break;
	case '2':
		res = map(test3, rev);
		printf("Modified SArray:\n");
		print(res);
		clear(res);
		break;
	case '3':
		res = map(test3, etoT);
		printf("Modified SArray:\n");
		print(res);
		clear(res);
		break;
	default:printf("wrong choice\n");

	}
	clear(test3);
	while ((getchar()) != '\n');
	return 1;
}



int where()
{
	char ch = 0;
	int s = 0;
	printf("Input count of strings:");
	unsigned int l;
	s = scanf("%u", &l);
	SArray* test4 = create(l, deep);
	fillData(test4, l);
	printf("Choose function: \n");
	printf("1 - serchStr \n");
	printf("2 - notEmptyStr \n");
	s = scanf("%c", &ch);
	switch (ch)
	{
	case '1':
	{
		char str[256];
		printf("Input string :");
		s = scanf("%s", str);
		SArray* res = where(test4, searchStr, str);
		printf("Filtered SArray:\n");
		print(res);
		clear(res);
		break;
	}
	case '2':
	{
		SArray* res = where(test4, notEmptyStr, "Bye");
		printf("Filtered SArray:\n");
		print(res);
		clear(res);
		break;
	}
	default: printf("Wrong choise"); break;
	}
	clear(test4);
	while ((getchar()) != '\n');
	return 1;
}

int concat()
{
	while ((getchar()) != '\n');
	unsigned int n = 0, m = 0, s = 0;
	printf("Input count of strings 1:");
	s = scanf("%u", &n);
	SArray* test1 = create(n, deep);
	fillData(test1, n);
	printf("Input count of strings 2:");
	s = scanf("%u", &m);
	SArray* test2 = create(m, deep);
	fillData(test2, m);
	SArray* res = create(m + n, deep);
	res = sum(test1, test2);
	printf("\nConcatenated SArray: \n");
	print(res);

	clear(test1);
	clear(test2);
	clear(res);
	while ((getchar()) != '\n');
	return 1;
}


int main()
{
	mainMenu();
	return 0;
}
