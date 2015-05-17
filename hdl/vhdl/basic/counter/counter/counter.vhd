----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date:    10:56:49 05/17/2015 
-- Design Name: counter
-- Module Name:    counter - Behavioral 
-- Project Name: Study
-- Target Devices: Spartan 6
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

ENTITY counter IS
	PORT (clk : IN STD_LOGIC;
			digit : OUT INTEGER RANGE 0 TO 9);
END counter;

ARCHITECTURE counter OF counter IS
BEGIN
	count: PROCESS (clk)
		VARIABLE temp : INTEGER RANGE 0 TO 9;
	BEGIN
		IF (clk'EVENT AND clk='1') THEN
			temp := temp + 1;
			IF (temp = 10) THEN
				temp := 0;
			END IF;
		END IF;
		digit <= temp;
	END PROCESS count;
END counter;

