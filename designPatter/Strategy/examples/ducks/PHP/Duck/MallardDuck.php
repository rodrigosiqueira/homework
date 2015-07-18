<?php
include_once 'Duck.php';
include_once 'FlyWithWings.php';
include_once 'Quack.php';

class MallardDuck extends Duck
{
	function __construct()
	{
		$this->setQuackBehavior(new Quack());
		$this->setFlyBehavior(new FlyWithWings());
	}

	function display()
	{
		echo "Eu sou o pato MALLARD!!! <br>";
	}

}

?>
