#ifndef EXAMPLES_H_INCLUDED
#define EXAMPLES_H_INCLUDED
#include <memory>
#include "rng.h"

class Example
{
public:
	virtual ~Example() {};

	void printNumYellow(int num);
	void printNumRed(int num);
	virtual void printTask() = 0;
	virtual void printAnswer() = 0;
	virtual bool checkAnswer(int ans) = 0;
};

std::shared_ptr<Example> GenerateExample();

#endif // EXAMPLES_H_INCLUDED