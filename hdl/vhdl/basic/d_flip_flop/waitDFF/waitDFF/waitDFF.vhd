----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date:    11:22:49 05/17/2015 
-- Design Name: Wait DD Flip flop
-- Module Name:    waitDFF - Behavioral 
-- Project Name: Study
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY waitDFF IS
	PORT (d, clk, rst: IN STD_LOGIC;
			q: OUT STD_LOGIC);
END waitDFF;

ARCHITECTURE Behavioral OF waitDFF IS
BEGIN
	PROCESS
	BEGIN
		WAIT ON rst, clk;
		IF rst='1' THEN
			q <= '0';
		ELSIF clk'EVENT AND clk='1' THEN
			q <= d;
		END IF;
	END PROCESS;
END Behavioral;
