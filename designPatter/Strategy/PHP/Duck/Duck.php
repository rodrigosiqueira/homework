<?php
include_once 'FlyBehavior.php';
include_once 'QuackBehavior.php';

abstract class Duck
{
	private  $flyBehavior;
	private  $quackBehavior;

	abstract function display();

	function performQuack()
	{
		$this->quackBehavior->quack();
	}

	function performFly()
	{
		$this->flyBehavior->fly();
	}

	function setFlyBehavior(FlyBehavior $fl)
	{
		$this->flyBehavior = $fl;
	}

	function setQuackBehavior(QuackBehavior $qc)
	{
		$this->quackBehavior = $qc;
	}
}

?>
