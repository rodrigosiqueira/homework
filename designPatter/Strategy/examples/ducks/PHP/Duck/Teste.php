<?php
include_once 'MallardDuck.php';
include_once 'FlyBehavior.php';
include_once 'QuackBehavior.php';
include_once 'Duck.php';

$teste = new MallardDuck();
$teste->display();
$teste->performFly();
$teste->performQuack();

?>
