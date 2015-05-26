----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date:    10:12:37 05/26/2015 
-- Design Name: Logic Unit
-- Module Name:    logic_unit - Behavioral 
-- Project Name: ALU
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY logic_unit IS
	PORT (a, b : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
			sel: IN STD_LOGIC_VECTOR (2 DOWNTO 0);
			x : OUT STD_LOGIC_VECTOR (7 DOWNTO 0));
END logic_unit;

ARCHITECTURE logic_unit OF logic_unit IS
BEGIN
	WITH sel SELECT
		x <=  NOT a WHEN "000",
				NOT b WHEN "001",
				a AND b WHEN "010",
				a OR b WHEN "011",
				a NAND b WHEN "100",
				a NOR b WHEN "101",
				a XOR b WHEN "110",
				NOT (a NOR b) WHEN OTHERS;
END logic_unit;
