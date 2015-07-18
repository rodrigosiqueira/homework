#include <iostream>
#include "Duck.h"
#include "FlyBehavior.h"
#include "QuackBehavior.h"

using namespace std;

Duck::Duck()
{}

void Duck::swin()
{
	cout << "Eu estou nadando!!!! " << endl;
}

void Duck::performQuack()
{
	this->quackBehavior->quack();
}

void Duck::performFly()
{
	this->flyBehavior->fly();
}

void Duck::setFlyBehavior(FlyBehavior *fl)
{
	this->flyBehavior = fl;
}

void Duck::setQuackBehavior(QuackBehavior *qc)
{
	this->quackBehavior = qc;
}
