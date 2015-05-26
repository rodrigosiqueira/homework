----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date:    08:35:01 05/26/2015 
-- Design Name: arithmetic unit
-- Module Name:    arith_unit - Behavioral 
-- Project Name: ALU
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY arith_unit IS
	PORT (a, b : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
			sel : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
			cin : IN STD_LOGIC;
			x: OUT STD_LOGIC_VECTOR (7 DOWNTO 0));
END arith_unit;

ARCHITECTURE arith OF arith_unit IS
	SIGNAL arith, logic : STD_LOGIC_VECTOR(7 DOWNTO 0);
BEGIN
	WITH sel SELECT
		x <=  a WHEN "000",
				a + 1 WHEN "001",
				a - 1 WHEN "010",
				b WHEN "011",
				b + 1 WHEN "100",
				b - 1 WHEN "101",
				a + b WHEN "110",
				a + b + cin  WHEN OTHERS;
END arith;
