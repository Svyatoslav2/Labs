#include "SArray.h"
#include "StringTool.h"
#include "Function.h"
tresult fooArr[] = { summ,minus,mult,max,min,triangle };

int testSArrayChar()
{
	/*Проверка основных функций по созданию и работой с структурой*/
	int res = 0;
	SArray* test;
	int failedTest = 0;
	unsigned int size = 5;
	unsigned int mode = 1;
	const char* str1 = "Hi";
	const char* str2 = "Hello";
	const char* str3 = "Bye";
	char str4[] = "Goodbye";

	test = create(size, deep);
	res = (test == 0 ? 0 : 1);
	printf("============================================================\n");
	printf("Test Block: Test Array as String\n");
	printf("Test1.create SArray: %s \n", (res == 0 ? "failed" : "passed"));
	if (res == 0)
		return 0;

	set(test, 0, str1);
	set(test, 1, str2);
	set(test, 2, str3);
	set(test, 3, str4);
	printf("Test2.CheckData: \n");

	res = strCmp((char*)get(test, 0), str1);
	printf("\t SArray[0]: %s \n", (res == 0 ? "failed" : "passed"));
	if (res == 0) failedTest++;
	res = strCmp((char*)get(test, 1), str2);
	printf("\t SArray[1]: %s \n", (res == 0 ? "failed" : "passed"));
	if (res == 0) failedTest++;
	res = strCmp((char*)get(test, 2), str3);
	printf("\t SArray[2]: %s \n", (res == 0 ? "failed" : "passed"));
	if (res == 0) failedTest++;
	res = strCmp((char*)get(test, 3), str4);
	printf("\t SArray[3]: %s \n", (res == 0 ? "failed" : "passed"));
	if (res == 0) failedTest++;
	res = (get(test, 5) == 0) ? 1 : 0;
	printf("\t SArray[4]: %s \n", (res == 0 ? "failed" : "passed"));
	if (res == 0) failedTest++;

	const char* str5 = "12345";
	set(test, 2, str5);
	res = strCmp((char*)get(test, 2), str5);
	printf("Test3.ChangeValue SArray[2]: %s \n", (res == 0 ? "failed" : "passed"));
	if (res == 0) failedTest++;

	set(test, 2, str5);
	res = strCmp((char*)get(test, 2), str3);
	printf("Test3.ChangeValue SArray[2]: %s \n", (res != 0 ? "failed" : "passed"));
	if (res != 0) failedTest++;
	printf("------------------------------------------------------------\n");
	if (failedTest == 0)
		printf("String test passed\n");
	else
		printf("Failed %d tests\n", failedTest);

	clear(test);

	return failedTest;
}


int testSArrayCharV()
{
	int res = 0;
	SArray* test = 0;
	unsigned int size = 5;
	unsigned int mode = 0;
	int failedTest = 0;
	const char* str1 = "Hi";
	char str2[] = "Hello";
	const char* str3 = "Bye";
	char str4[] = "Goodbye";
	void* pv = 0;
	test = create(size, low);
	res = (test == 0 ? 0 : 1);

	printf("============================================================\n");
	printf("Test Block: Test Array as \"void *\"\n");
	printf("Test1.create SArray: %s \n", ((res == 0) ? "failed" : "passed"));
	if (res == 0) failedTest++;

	set(test, 0, (void*)str1);
	set(test, 1, (void*)str2);
	set(test, 2, (void*)str3);
	set(test, 3, (void*)str4);
	printf("Test2.CheckData: \n");
	pv = get(test, 0);
	res = (pv == (void*)str1) ? 1 : 0;
	printf("\t SArray[0]: %s \n", (res == 0 ? "failed" : "passed"));
	if (res == 0) failedTest++;
	pv = get(test, 1);
	res = (pv == (void*)str2) ? 1 : 0;
	printf("\t SArray[1]: %s \n", (res == 0 ? "failed" : "passed"));
	if (res == 0) failedTest++;
	pv = get(test, 2);
	res = (pv == (void*)str3) ? 1 : 0;
	printf("\t SArray[2]: %s \n", (res == 0 ? "failed" : "passed"));
	if (res == 0) failedTest++;
	pv = get(test, 3);
	res = (pv == (void*)str4) ? 1 : 0;
	printf("\t SArray[3]: %s \n", (res == 0 ? "failed" : "passed"));
	if (res == 0) failedTest++;
	res = (get(test, 5) == 0) ? 1 : 0;
	printf("\t SArray[4]: %s \n", (res == 0 ? "failed" : "passed"));
	if (res == 0) failedTest++;

	const char* str5 = "12345";
	set(test, 2, str5);
	pv = get(test, 2);
	res = (pv == (void*)str5) ? 1 : 0;
	printf("Test3.ChangeValue SArray[2]: %s \n", (res == 0 ? "failed" : "passed"));
	if (res == 0) failedTest++;
	clear(test);
	printf("------------------------------------------------------------\n");
	if (failedTest == 0)
		printf("String test passed\n");
	else
		printf("Failed %d tests\n", failedTest);
	return failedTest;
}


int testConcat()
{
	/*Проверка конкатенации*/
	int failedTest = 0;
	char array1[][12] = { "one","two","three" };
	char array2[][12] = { "four","five" };
	char res[][12] = { "one","two","three","four","five" };
	SArray* arr1, * arr2, * result;
	arr1 = create(3, deep);
	arr2 = create(2, deep);
	for (int i = 0; i < 3; i++)
		set(arr1, i, array1[i]);

	for (int i = 0; i < 2; i++)
		set(arr2, i, array2[i]);

	result = sum(arr1, arr2);
	printf("============================================================\n");
	printf("Test concatination:\n");
	int j = 0;
	for (int i = 0; i < 5; i++)
	{
		j = strCmp((char*)get(result, i), res[i]);
		printf("\t Test.Check value[%d]: %s \n", i, (j == 0 ? "failed" : "passed"));
		if (j == 0) failedTest++;
	}
	printf("------------------------------------------------------------\n");
	if (failedTest == 0)
		printf("String test passed\n");
	else
		printf("Failed %d tests\n", failedTest);
	return failedTest;
}


int testMap()
{
	/*Проверка map*/
	int failedTest = 0;
	char array1[][12] = { "one","two","three" };
	char array2[][12] = { "ONE","TWO","THREE" };
	SArray* arr1, * arr2;
	arr1 = create(3, deep);
	arr2 = create(3, deep);
	for (int i = 0; i < 3; i++)
		set(arr1, i, array1[i]);
	arr2 = map(arr1, caps);
	printf("============================================================\n");
	printf("Test Map:\n");
	int j = 0;
	for (int i = 0; i < 3; i++)
	{
		j = strCmp((char*)get(arr2, i), array2[i]);
		printf("\t Test.Check value[%d]: %s \n", i, (j == 0 ? "failed" : "passed"));
		if (j == 0) failedTest++;
	}
	printf("------------------------------------------------------------\n");
	if (failedTest == 0)
		printf("String test passed\n");
	else
		printf("Failed %d tests\n", failedTest);
	return failedTest;
}




int testWhere()
{
	/*Проверка where*/
	int failedTest = 0;
	char array1[][12] = { "one dog","one kid","three" };
	char array2[][12] = { "one dog","one kid" };
	SArray* arr1, * arr2;
	arr1 = create(3, deep);
	for (int i = 0; i < 3; i++)
		set(arr1, i, array1[i]);
	printf("============================================================\n");
	printf("Test Where:\n");
	int j = 0;
	arr2 = where(arr1, searchStr, "one");
	for (int i = 0; i < 2; i++)
	{
		j = strCmp((char*)get(arr2, i), array2[i]);
		printf("\t Test.Check found value[%d]: %s \n", i, (j == 0 ? "failed" : "passed"));
		if (j == 0) failedTest++;
	}
	clear(arr2);
	arr2 = where(arr1, searchStr, "ones");
	j = 0;
	for (int i = 0; i < 2; i++)
	{
		j = strCmp((char*)get(arr2, i), array2[i]);
		printf("\t Test.Check not found value[%d]: %s \n", i, (j != 0 ? "failed" : "passed"));
		if (j != 0) failedTest++;
	}
	printf("------------------------------------------------------------\n");
	if (failedTest == 0)
		printf("String test passed\n");
	else
		printf("Failed %d tests\n", failedTest);
	return failedTest;
}



int testConcatFunc()
{
	printf("============================================================\n");
	printf("Test Function Concatnation:\n");
	int failedTest = 0;
	SArray* funcname = create(4, low);
	if (funcname == 0)
		return 1;
	for (unsigned int i = 0;i < funcname->size; i++)
	{
		set(funcname, i, fooArr[i]);
	}
	SArray* funcnum = create(2, low);
	if (funcnum == 0)
		return 1;
	for (unsigned int i = 0; i < funcnum->size; i++)
	{
		set(funcnum, i, fooArr[i + 4]);
	}
	SArray* result = sum(funcname, funcnum);
	for (unsigned  int i = 0; i < result->size; i++)
	{
		tresult foo = (tresult)get(result, i);
		if (foo != fooArr[i])
			failedTest++;
	}

	if (failedTest == 0)
		printf("Function Concatnation test passed\n");
	else
		printf("Failed %d tests\n", failedTest);
	return failedTest;
}



int testMapFunc()
{
	printf("============================================================\n");
	printf("Test Map Concatnation:\n");
	int failedTest = 0;
	SArray* func = create(2, low);
	set(func, 0, rev);
	set(func, 1, caps);
	SArray* changedfunc = map(func, lenVolve);
	char teststr[] = "Hello world";
	PFstr2int foo = 0;
	for (unsigned  int i = 0; i < changedfunc->size; i++)
	{
		foo = (PFstr2int)get(changedfunc, i);
		if (foo(teststr)!=3)
		{
			failedTest++;
		}
	}
	if (failedTest == 0)
		printf("Map Concatnation test passed\n");
	else
		printf("Failed %d tests\n", failedTest);
	return failedTest;
}