#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <vector>
#include <math.h>
#ifdef WIN32
#include <locale.h>
#endif
#include "rng.h"
#include <memory>
#include "Examples.h"
#include "color.h"

const char *g_szCurClass = "parallel2014";

//#define _RUN_ANALISYS

//#ifndef UINT
typedef unsigned int UINT;
//#endif

using namespace std;

#ifdef WIN32
#define _WIN32_WINNT    0x0500
#include <windows.h>
#include <winnt.h>
#include <winbase.h>
#endif 

CRng rng1;

int goal = 20;
int penalty = 3;
int maxNum = 250;

struct Expression
{
	Expression(int a_, int b_, int err_, char op_)
		: a(a_)
		, b(b_)
		, err(err_)
		, op(op_)
	{}
	void print()
	{
		if (op=='+')
		{
			printf("%d + %d neni %d, %d + %d = %d\n", a, b, err, a, b, a+b);
		}
		if (op == '-')
		{
			printf("%d - %d neni %d, %d + %d = %d\n", a, b, err, a, b, a - b);
		}
	}
	int a;
	int b;
	int err;
	char op;
};

//std::vector<Expression> errorList;
std::vector<shared_ptr<Example> > errorList;

void generateExample(int &a, int &b, bool isPlus)
{
	while (true)
	{
		a = rng1.GetUniformInterval(1, maxNum);
		b = rng1.GetUniformInterval(1, maxNum);

		if (isPlus)
		{
			if (a + b <= maxNum)
				return;
		}
		else
		{
			if (a - b > 0)
				return;
		}
	}
}

bool askExample(int num, int numOk, int cntErr, int toGo)
{
	auto example = GenerateExample();
	printf("Priklad #%d (%d spravnich), %d chyb. Zustalo %d prikladu.\n", num, numOk, cntErr, toGo);
	example->printTask();

	int c = -1;
	while (c<0 || c>maxNum)
	{
		scanf("%d", &c);
		if (c == -999)
		{
			throw 1;
		}
		if (c<0 || c>maxNum)
		{
			printf("Skus jeste jednou!\n");
			char ch;
			scanf("%c", &ch);
		}
	}
	bool isValid = example->checkAnswer(c);
	if (isValid)
	{
		textcolor(CN_NORMAL, CN_GREEN | CN_BRIGHT);

		int r = rng1.GetUniformInterval(0, 10);
		switch (r)
		{
		case 0:
			printf("Ano!\n");
			break;
		case 1:
			printf("Jo!\n");
			break;
		case 2:
			printf("Presne tak!\n");
			break;
		case 3:
			printf("Jiste!\n");
			break;
		case 4:
			printf("Prima!\n");
			break;
		case 5:
			printf("Super!\n");
			break;
		case 6:
			printf("Hesky!\n");
			break;
		case 7:
			printf("Vyborne!\n");
			break;
		case 8:
			printf("Jsi sikula!\n");
			break;
		case 9:
			printf("To je vono!\n");
			break;
		case 10:
			printf("Dobre!\n");
			break;
		}		

		textcolor();		
	} else
	{
		printf("Ne! ");
		example->printAnswer();
		errorList.push_back(example);
	}

	return isValid;

	
	/*
	int r = rng1.GetUniformInterval(0, 100);
	bool sign = r < 70 ? true : false;



	
int a = 0, b = 0;
	generateExample(a, b, sign);

	printf("Priklad #%d (%d spravnich), %d chyb. Zustalo %d prikladu.\n", num, numOk, cntErr, toGo);

	if (sign)
		printf("%d + %d = ", a, b);
	else
		printf("%d - %d = ", a, b);

	int c = 0;
	scanf("%d", &c);

	bool isValid = false;

	if (sign)
	{
		isValid = a + b == c;
		if (!isValid)
		{
			printf("Ne! Spravna odpoved = %d\n", a + b);
			errorList.push_back(Expression(a, b, c, '+'));
		}
	}
	else
	{
		isValid = a - b == c;
		if (!isValid)
		{
			printf("Ne! Spravna odpoved = %d\n", a-b);
			errorList.push_back(Expression(a, b, c, '-'));
		}
	}
	if (isValid)
		printf("Ano!\n");

	return isValid;	
	*/
}

int main (int argc, char **argv)
{
	char szCode[255];
	//strncpy(szCode,argv[1],200);
	//strcat(szCode, g_szCurClass);
	//strcpy(szCode, g_szCurClass);

	
	//rng1.Seed(szCode, strlen(szCode));
	rng1.Seed();

	int cntOk = 0;
	int cntErr = 0;
	int cnt = 0;
	int toGo = goal;

	try
	{
		while (toGo > 0)
		{
			cnt++;
			if (askExample(cnt, cntOk, cntErr, toGo))
			{
				cntOk++;
				toGo--;
			}
			else
			{
				cntErr++;
				toGo += penalty;
				if (toGo > goal)
					toGo = goal;
			}
		}
	}
	catch (...)
	{
		
	}

	if (errorList.size()>0)
	{
		textcolor(CN_NORMAL, CN_GREEN | CN_BRIGHT);
		printf("Jsi mel nekolik chyb!\n");
		textcolor();
		for (auto &k : errorList)
		{
			k->printAnswer();
		}
	}

	if (toGo == 0)
	{
		if (errorList.size() == 0)
		{
			textcolor(CN_NORMAL, CN_GREEN | CN_BRIGHT);
			printf("Dobri!!! Muzes hrat!\n");
			textcolor();
		}
		else
		{
			textcolor(CN_NORMAL, CN_YELLOW | CN_BRIGHT);
			printf("Dobri!!! Muzes hrat!\n");
			textcolor();
		}
	}		
	else
	{
		textcolor(CN_NORMAL, CN_RED | CN_BRIGHT);
		printf("Musis opakovat jeste jednou!\n");
		textcolor();
	}
	char s[255];
	scanf("%s", s);
	
    return 0;
}
