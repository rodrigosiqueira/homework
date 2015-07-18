#include "MallardDuck.h"
#include "FlyWithWings.h"
#include "Quack.h"
#include <iostream>

using namespace std;

Mallard::Mallard()
{
	this->setFlyBehavior(new FlyWithWings());
	this->setQuackBehavior(new Quack());
}

void Mallard::display()
{
	cout << "Eu sou o Pato Mallard!!! ;)" << endl;
}
