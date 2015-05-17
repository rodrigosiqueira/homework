----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date:    11:09:24 05/17/2015 
-- Design Name: ShiftRegister
-- Module Name:    shiftRegister - Behavioral 
-- Project Name: Study
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

ENTITY shiftRegister IS
	GENERIC (n : INTEGER := 4);
	PORT (d, clk, rst: IN STD_LOGIC;
			q: OUT STD_LOGIC);
END shiftRegister;

ARCHITECTURE Behavioral OF shiftRegister IS
	SIGNAL internal : STD_LOGIC_VECTOR(n - 1 DOWNTO 0);
BEGIN
	PROCESS(clk, rst)
	BEGIN
		IF rst='1' THEN
			internal <= (OTHERS => '0');
		ELSIF (clk'EVENT AND clk = '1') THEN
			internal <= d & internal(internal'LEFT DOWNTO 1);
		END IF;
	END PROCESS;
	q <= internal(0);
END Behavioral;
