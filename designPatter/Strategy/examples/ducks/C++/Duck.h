#ifndef DUCK_H
#define DUCK_H

class FlyBehavior;
class QuackBehavior;

class Duck
{
	public:
		Duck();
		void swin();
		virtual void display() = 0;
		void performQuack();
		void performFly();
		void setFlyBehavior(FlyBehavior*);
		void setQuackBehavior(QuackBehavior*);
	private:
		FlyBehavior *flyBehavior;
		QuackBehavior *quackBehavior;
};

#endif
