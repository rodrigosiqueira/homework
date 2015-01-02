#include "MallardDuck.h"

int main()
{
	Mallard *d = new Mallard();
	d->display();
	d->performFly();
	d->performQuack();
	
	return 0;
}
