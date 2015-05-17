----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:05:07 05/16/2015 
-- Design Name: 
-- Module Name:    encoderWhen - Behavioral 
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

ENTITY encoderWhen IS
	PORT (x : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
			y : OUT STD_LOGIC_VECTOR (2 DOWNTO 0));
END encoderWhen;

ARCHITECTURE encoder1 OF encoderWhen IS
BEGIN

	WITH x SELECT
		y <=  "000" WHEN "00000001",
				"001" WHEN "00000010",
				"010" WHEN "00000100",
				"011" WHEN "00001000",
				"100" WHEN "00010000",
				"101" WHEN "00100000",
				"110" WHEN "01000000",
				"111" WHEN "10000000",
				"ZZZ" WHEN OTHERS;
END encoder1;
