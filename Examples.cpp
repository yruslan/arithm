#include "Examples.h"
#include "color.h"

extern int maxNum;
extern CRng rng1;

void Example::printNumYellow(int num)
{
	textcolor(CN_NORMAL, CN_BRIGHT | CN_YELLOW);
	printf("%d", num);
	textcolor();
}

void Example::printNumRed(int num)
{
	textcolor(CN_NORMAL, CN_BRIGHT | CN_RED);
	printf("%d", num);
	textcolor();
}

class ExamplePlus0 : public Example
{
public:
	int a;
	int b;
	int answerEntered;

	ExamplePlus0()
	{
		answerEntered = 0;
		while (true)
		{
			a = rng1.GetUniformInterval(1, maxNum);
			b = rng1.GetUniformInterval(1, maxNum);
			if (a + b <= maxNum)
				break;
		}
	}

	void printTask() override
	{
		printf("%d + %d = ?\n", a, b);
	}

	void printAnswer() override
	{
		printf("%d + %d neni ", a, b);
		printNumRed(answerEntered);
		printf(", %d + %d = ", a, b);
		printNumYellow(a + b);
		printf("\n");
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return a + b == answerEntered;
	}
};

class ExampleMinus0 : public Example
{
public:
	int a;
	int b;
	int answerEntered;

	ExampleMinus0()
	{
		answerEntered = 0;
		while (true)
		{
			a = rng1.GetUniformInterval(1, maxNum);
			b = rng1.GetUniformInterval(1, maxNum);
			if (a - b >= 0)
				break;
		}
	}

	void printTask() override
	{
		printf("%d - %d = ?\n", a, b);
	}

	void printAnswer() override
	{
		printf("%d - %d neni ", a, b);
		printNumRed(answerEntered);
		printf(", %d - %d = ", a, b);
		printNumYellow(a - b);
		printf("\n");
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return a - b == answerEntered;
	}
};

class ExamplePlus1 : public Example
{
public:
	int b;
	int c;
	int answerEntered;

	ExamplePlus1()
	{
		answerEntered = 0;
		while (true)
		{
			b = rng1.GetUniformInterval(1, maxNum);
			c = rng1.GetUniformInterval(1, maxNum);
			if (c - b >= 0)
				break;
		}
	}

	void printTask() override
	{
		printf("? + %d = %d\n", b, c);
	}

	void printAnswer() override
	{
		printNumRed(answerEntered);
		printf(" + %d neni %d, ", b, c);
		printNumYellow(c - b);
		printf(" + %d = %d\n", b, c);
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return c - b == answerEntered;
	}
};

class ExamplePlus2 : public Example
{
public:
	int a;
	int c;
	int answerEntered;

	ExamplePlus2()
	{
		answerEntered = 0;
		while (true)
		{
			a = rng1.GetUniformInterval(1, maxNum);
			c = rng1.GetUniformInterval(1, maxNum);
			if (c - a >= 0)
				break;
		}
	}

	void printTask() override
	{
		printf("%d + ? = %d\n", a, c);
	}

	void printAnswer() override
	{
		printf("%d + ", a);
		printNumRed(answerEntered);
		printf(" neni %d, %d + ", c, a);
		printNumYellow(c - a);
		printf(" = %d\n", c);
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return c - a == answerEntered;
	}
};


class ExampleMinus1 : public Example
{
public:
	int b;
	int c;
	int answerEntered;

	ExampleMinus1()
	{
		answerEntered = 0;
		while (true)
		{
			b = rng1.GetUniformInterval(1, maxNum);
			c = rng1.GetUniformInterval(1, maxNum);
			if (c + b <= maxNum)
				break;
		}
	}

	void printTask() override
	{
		printf("? - %d = %d\n", b, c);
	}

	void printAnswer() override
	{
		printNumRed(answerEntered);
		printf(" - %d neni %d, ", b, c);
		printNumYellow(b + c);
		printf(" - %d = %d\n", b, c);
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return b + c == answerEntered;
	}
};

class ExampleMinus2 : public Example
{
public:
	int a;
	int c;
	int answerEntered;

	ExampleMinus2()
	{
		answerEntered = 0;
		while (true)
		{
			a = rng1.GetUniformInterval(1, maxNum);
			c = rng1.GetUniformInterval(1, maxNum);
			if (a - c >= 0)
				break;
		}
	}

	void printTask() override
	{
		printf("%d - ? = %d\n", a, c);
	}

	void printAnswer() override
	{
		printf("%d - ", a);
		printNumRed(answerEntered);
		printf(" neni %d, %d - ", c, a);
		printNumYellow(a - c);
		printf(" = %d\n", c);
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return a - c == answerEntered;
	}
};

class ExamplePlus11 : public Example
{
public:
	int a;
	int b;
	int c;
	int d;
	int answerEntered;

	ExamplePlus11()
	{
		answerEntered = 0;
		while (true)
		{
			a = rng1.GetUniformInterval(1, maxNum);
			b = rng1.GetUniformInterval(1, maxNum);
			c = rng1.GetUniformInterval(1, maxNum);
			if (a + b + c <= maxNum)
				break;
		}
	}

	void printTask() override
	{
		printf("%d + %d + %d = ?\n", a, b, c);
	}

	void printAnswer() override
	{
		printf("%d + %d + %d  neni ", a, b, c);
		printNumRed(answerEntered);
		printf(", %d + %d + %d = ", a, b, c);
		printNumYellow(a + b + c);
		printf("\n");
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return a + b + c == answerEntered;
	}
};

class ExampleMinus11 : public Example
{
public:
	int a;
	int b;
	int c;
	int d;
	int answerEntered;

	ExampleMinus11()
	{
		answerEntered = 0;
		while (true)
		{
			a = rng1.GetUniformInterval(1, maxNum);
			b = rng1.GetUniformInterval(1, maxNum);
			c = rng1.GetUniformInterval(1, maxNum);
			if (a - b - c >= 0)
				break;
		}
	}

	void printTask() override
	{
		printf("%d - %d - %d = ?\n", a, b, c);
	}

	void printAnswer() override
	{
		printf("%d - %d - %d  neni ", a, b, c);
		printNumRed(answerEntered);
		printf(", %d - %d - %d = ", a, b, c);
		printNumYellow(a - b - c);
		printf("\n");
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return a - b - c == answerEntered;
	}
};

class ExamplePlusMinus1 : public Example
{
public:
	int a;
	int b;
	int c;
	int d;
	int answerEntered;

	ExamplePlusMinus1()
	{
		answerEntered = 0;
		while (true)
		{
			a = rng1.GetUniformInterval(1, maxNum);
			b = rng1.GetUniformInterval(1, maxNum);
			c = rng1.GetUniformInterval(1, maxNum);
			if (a - (b + c) >= 0)
				break;
		}
	}

	void printTask() override
	{
		printf("%d - (%d + %d) = ?\n", a, b, c);
	}

	void printAnswer() override
	{
		printf("%d - (%d + %d)  neni ", a, b, c);
		printNumRed(answerEntered);
		printf(", %d - (%d + %d) = ", a, b, c);
		printNumYellow(a - (b + c));
		printf("\n");
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return a - (b + c) == answerEntered;
	}
};

class ExampleComparison1 : public Example
{
public:
	int a;
	int answerEntered;

	ExampleComparison1()
	{
		answerEntered = 0;
		while (true)
		{
			a = rng1.GetUniformInterval(1, maxNum);
			break;
		}
	}

	void printTask() override
	{
		printf("%d = a, a = ?\n", a);
	}

	void printAnswer() override
	{
		printf("%d = a, a nepatri ", a);
		printNumRed(answerEntered);
		printf(", spravna odpoved: ");
		printNumYellow(a);
		printf("\n");
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return a == ans;
	}
};

class ExampleComparison2 : public Example
{
public:
	int b;
	int r;
	int answerEntered;

	ExampleComparison2()
	{
		r = rng1.GetUniformInterval(0, 1);
		answerEntered = 0;
		while (true)
		{
			b = rng1.GetUniformInterval(1, maxNum);
			if (b>3)
				break;
		}
	}

	void printTask() override
	{
		
		if (r == 0)
		{
			printf("%d > a, a = ?\n", b);
		}
		else
		{
			printf("a < %d, a = ?\n", b);
		}
		
	}

	void printAnswer() override
	{
		if (r == 0)
		{
			printf("%d > a, a nepatri ", b);
			printNumRed(answerEntered);
			printf(", spravna odpoved: ");
			printNumYellow(b-2);
			printf("\n");
		}
		else
		{
			printf("a < %d, a nepatri ", b);
			printNumRed(answerEntered);
			printf(", spravna odpoved: ");
			printNumYellow(b - 2);
			printf("\n");
		}
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return b > ans;
	}
};

class ExampleComparison3 : public Example
{
public:
	int a;
	int r;
	int answerEntered;

	ExampleComparison3()
	{
		r = rng1.GetUniformInterval(0, 1);
		answerEntered = 0;
		while (true)
		{
			a = rng1.GetUniformInterval(1, maxNum);
			if (a<maxNum-4)
				break;
		}
	}

	void printTask() override
	{
		if (r == 0)
		{
			printf("%d < b, b = ?\n", a);
		}
		else
		{
			printf("b > %d, b = ?\n", a);			
		}
	}

	void printAnswer() override
	{
		if (r == 0)
		{
			printf("%d < b, b nepatri ", a);
			printNumRed(answerEntered);
			printf(", spravna odpoved: ");
			printNumYellow(a + 3);
			printf("\n");
		}
		else
		{
			printf("b > %d, b nepatri ", a);
			printNumRed(answerEntered);
			printf(", spravna odpoved: ");
			printNumYellow(a + 3);
			printf("\n");
		}
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return a < ans;
	}
};

class ExampleComparison4 : public Example
{
public:
	int a;
	int b;
	int r;
	int answerEntered;

	ExampleComparison4()
	{
		r = rng1.GetUniformInterval(0, 1);
		answerEntered = 0;
		while (true)
		{
			a = rng1.GetUniformInterval(1, maxNum);
			b = rng1.GetUniformInterval(1, maxNum);
			if (b - a > 5)
				break;
		}
	}

	void printTask() override
	{
		if (r == 0)
		{
			printf("%d < f < %d, f = ?\n", a, b);
		}
		else
		{
			printf("%d > f > %d, f = ?\n", b, a);
		}
	}

	void printAnswer() override
	{
		if (r == 0)
		{
			printf("%d < f < %d, f nepatri ", a, b);
			printNumRed(answerEntered);
			printf(", spravna odpoved: ");
			printNumYellow(a + (b - a) / 2);
			printf("\n");
		}
		else
		{
			printf("%d > f > %d, f nepatri ", b, a);
			printNumRed(answerEntered);
			printf(", spravna odpoved: ");
			printNumYellow(a + (b - a) / 2);
			printf("\n");
		}
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return a < ans && ans < b;
	}
};


class ExampleComparison5 : public Example
{
public:
	int b;
	int r;
	int answerEntered;

	ExampleComparison5()
	{
		r = rng1.GetUniformInterval(0, 1);
		answerEntered = 0;
		while (true)
		{
			b = rng1.GetUniformInterval(1, maxNum);
			if (b > 3)
				break;
		}
	}

	void printTask() override
	{
		if (r == 0)
		{
			printf("c < %d, c = ?\n", b);
		}
		else
		{
			printf("%d > c, c = ?\n", b);
		}
	}

	void printAnswer() override
	{
		if (r == 0)
		{
			printf("c < %d, c nepatri ", b);
			printNumRed(answerEntered);
			printf(", spravna odpoved: ");
			printNumYellow(b-2);
			printf("\n");
		}
		else
		{
			printf("%d > c, c nepatri ", b);
			printNumRed(answerEntered);
			printf(", spravna odpoved: ");
			printNumYellow(b - 2);
			printf("\n");
		}
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return b > ans;
	}
};

class ExampleComparison6 : public Example
{
public:
	int a;
	int r;
	int answerEntered;

	ExampleComparison6()
	{
		r = rng1.GetUniformInterval(0, 1);
		answerEntered = 0;
		while (true)
		{
			a = rng1.GetUniformInterval(1, maxNum);
			if (a < maxNum - 4)
				break;
		}
	}

	void printTask() override
	{
		if (r == 0)
		{
			printf("d > %d, d = ?\n", a);
		}
		else
		{
			printf("%d < d, d = ?\n", a);
		}
	}

	void printAnswer() override
	{
		if (r == 0)
		{
			printf("d > %d, d nepatri ", a);
			printNumRed(answerEntered);
			printf(", spravna odpoved: ");
			printNumYellow(a + 3);
			printf("\n");
		}
		else
		{
			printf("%d < d, d nepatri ", a);
			printNumRed(answerEntered);
			printf(", spravna odpoved: ");
			printNumYellow(a + 3);
			printf("\n");
		}

		printf("d > %d, d nepatri %d, spravna odpoved: %d\n", a, answerEntered, a + 3);
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return a < ans;
	}
};


class ExampleMultiply : public Example
{
public:
	int a;
	int b;
	int answerEntered;

	ExampleMultiply()
	{
		a = rng1.GetUniformInterval(1, 10);
		b = rng1.GetUniformInterval(1, 10);
		answerEntered = 0;
	}

	void printTask() override
	{
		printf("%d * %d = ?\n", a, b);
	}

	void printAnswer() override
	{
		printf("%d * %d neni ", a, b);
		printNumRed(answerEntered);
		printf(", %d * %d = ", a, b);
		printNumYellow(a * b);
		printf("\n");
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return ans == a*b;
	}
};

class ExampleMultiplySum1 : public Example
{
public:
	int a;
	int b;
	int c;
	int answerEntered;

	ExampleMultiplySum1()
	{
		while (true)
		{
			a = rng1.GetUniformInterval(1, 10);
			b = rng1.GetUniformInterval(1, 10);
			c = rng1.GetUniformInterval(1, maxNum);

			if (a * b + c <= maxNum)
				break;
		}

		answerEntered = 0;
	}

	void printTask() override
	{
		printf("%d * %d + %d = ?\n", a, b, c);
	}

	void printAnswer() override
	{
		printf("%d * %d + %d neni ", a, b, c);
		printNumRed(answerEntered);
		printf(", %d * %d + %d = ", a, b, c);
		printNumYellow(a * b + c);
		printf("\n");
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return ans == a*b+c;
	}
};

class ExampleMultiplySum2 : public Example
{
public:
	int a;
	int b;
	int c;
	int answerEntered;

	ExampleMultiplySum2()
	{
		while (true)
		{
			a = rng1.GetUniformInterval(1, 10);
			b = rng1.GetUniformInterval(1, 10);
			c = rng1.GetUniformInterval(1, maxNum);

			if (a * b + c <= maxNum)
				break;
		}
	}

	void printTask() override
	{
		printf("%d + %d * %d = ?\n", c, a, b);
	}

	void printAnswer() override
	{
		printf("%d + %d * %d neni ", c, a, b);
		printNumRed(answerEntered);
		printf(", %d + %d * %d = ", c, a, b);
		printNumYellow(a * b + c);
		printf("\n");
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return ans == a*b + c;
	}
};

class ExampleMultiplySub1 : public Example
{
public:
	int a;
	int b;
	int c;
	int answerEntered;

	ExampleMultiplySub1()
	{
		while (true)
		{
			a = rng1.GetUniformInterval(1, 10);
			b = rng1.GetUniformInterval(1, 10);
			c = rng1.GetUniformInterval(1, maxNum);

			if (a * b - c >= 0)
				break;
		}

		answerEntered = 0;
	}

	void printTask() override
	{
		printf("%d * %d - %d = ?\n", a, b, c);
	}

	void printAnswer() override
	{
		printf("%d * %d - %d neni ", a, b, c);
		printNumRed(answerEntered);
		printf(", %d * %d - %d = ", a, b, c);
		printNumYellow(a * b - c);
		printf("\n");
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return ans == a*b - c;
	}
};

class ExampleMultiplySub2 : public Example
{
public:
	int a;
	int b;
	int c;
	int answerEntered;

	ExampleMultiplySub2()
	{
		while (true)
		{
			a = rng1.GetUniformInterval(1, 10);
			b = rng1.GetUniformInterval(1, 10);
			c = rng1.GetUniformInterval(1, maxNum);

			if (c - a * b >= 0)
				break;
		}

		answerEntered = 0;
	}

	void printTask() override
	{
		printf("%d - %d * %d = ?\n", c, a, b);
	}

	void printAnswer() override
	{
		printf("%d - %d * %d neni ", c, a, b);
		printNumRed(answerEntered);
		printf(", %d - %d * %d = ", c, a, b);
		printNumYellow(c - a * b);
		printf("\n");
	}

	bool checkAnswer(int ans) override
	{
		answerEntered = ans;
		return ans == c - a*b;
	}
};

std::shared_ptr<Example> GenerateExample()
{
	int r = rng1.GetUniformInterval(0, 19);
	int r1 = rng1.GetUniformInterval(1, 6);
	std::shared_ptr<Example> example;
	switch (r)
	{
	case 0:
		example = std::make_shared<ExamplePlus0>();
		break;
	case 1:
		example = std::make_shared<ExamplePlus1>();
		break;
	case 2:
		example = std::make_shared<ExamplePlus2>();
		break;
	case 3:
		example = std::make_shared<ExampleMinus0>();
		break;
	case 4:
		example = std::make_shared<ExampleMinus1>();
		break;
	case 5:
		example = std::make_shared<ExampleMinus2>();
		break;
	case 6:
		example = std::make_shared<ExamplePlus0>();
		break;
	case 7:
		example = std::make_shared<ExampleMinus0>();
		break;
	case 8:
		example = std::make_shared<ExamplePlus11>();
		break;
	case 9:
		example = std::make_shared<ExampleMinus11>();
		break;
	case 10:
		example = std::make_shared<ExamplePlusMinus1>();
		break;
	case 11:
	case 12:
		switch (r1)
		{
		case 1:
			example = std::make_shared<ExampleComparison1>();
			break;
		case 2:
			example = std::make_shared<ExampleComparison2>();
			break;
		case 3:
			example = std::make_shared<ExampleComparison3>();
			break;
		case 4:
			example = std::make_shared<ExampleComparison4>();
			break;
		case 5:
			example = std::make_shared<ExampleComparison5>();
			break;
		case 6:
			example = std::make_shared<ExampleComparison6>();
			break;
		}
		break;
	case 13:
	case 14:
	case 15:
		example = std::make_shared<ExampleMultiply>();
		break;
	case 16:
		example = std::make_shared<ExampleMultiplySum1>();
		break;
	case 17:
		example = std::make_shared<ExampleMultiplySum2>();
		break;
	case 18:
		example = std::make_shared<ExampleMultiplySub1>();
		break;
	case 19:
		example = std::make_shared<ExampleMultiplySub2>();
		break;
	}

	return example;
}

