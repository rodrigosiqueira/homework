# Duck

> Attention: This example was extracted from the book "head first".

----
# Problem description

> Imagine a situation which you have to describe the behaviour of any kind of
ducks, for a new game. After you study the project you noticed two different
behaviour on ducks:

* Fly behavior: Each species of duck have their own fly behavior, it means that
  part of your code change for each kind of duck.
* Quack behaviour: Every duck can have their style of quack.

> After you find those differences, you can define your "composition" as an
abstract class named "Duck". Secondly, you can create two "compositor"
interface named "FlyBehavior" and "QuackBehavior". Finally, you can have each
species of duck, extend from Duck and implements their own fly and quack
behavior. See the picture below, for get an overview of the example.

<<<< picture >>>>

----
# About code

> In this folder, you can find the implementation of this example in: C++, C,
python, PHP, and Ruby. However, before you read the code take a deeply look on
the class diagram above, because the implementation follows the code described
on the image.


