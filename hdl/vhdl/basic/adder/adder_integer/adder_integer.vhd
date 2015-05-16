----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 22:56:52 04/15/2015 
-- Design Name: Rodrigo
-- Module Name: adder_integer - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_ARITH.ALL;

ENTITY adder_integer IS
	PORT (a, b : IN SIGNED (3 DOWNTO 0);
			sum : OUT INTEGER RANGE -16 TO 15);
END adder_integer;

ARCHITECTURE Behavioral OF adder_integer IS
BEGIN

	sum <= CONV_INTEGER(a + b);

END Behavioral;
