<?php
include_once 'FlyBehavior.php';

class NoFlyWay implements FlyBehavior
{
	function fly()
	{
		echo "Eu não posso voar!!! Que Triste =(";
	}
}

?>
