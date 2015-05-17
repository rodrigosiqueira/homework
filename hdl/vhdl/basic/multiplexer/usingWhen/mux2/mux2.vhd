----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:44:33 05/16/2015 
-- Design Name: 
-- Module Name:    mux2 - Behavioral 
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

ENTITY mux2 IS
	PORT (a, b, c, d: IN STD_LOGIC;
			sel: IN STD_LOGIC_VECTOR (1 DOWNTO 0);
			y: OUT STD_LOGIC);
END mux2;

ARCHITECTURE Behavioral OF mux2 IS
BEGIN
	y <= 	a WHEN sel="00" ELSE
			b WHEN sel="01" ELSE
			c WHEN sel="10" ELSE
			d;
END Behavioral;
