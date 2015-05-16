----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:28:05 05/16/2015 
-- Design Name: 
-- Module Name:    parity_det - Behavioral 
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

ENTITY parity_det IS
	GENERIC (n : INTEGER := 7);
	PORT (input : IN BIT_VECTOR (n DOWNTO 0);
			output : OUT BIT);
END parity_det;

ARCHITECTURE Behavioral OF parity_det IS
BEGIN

	PROCESS (input)
		VARIABLE temp: BIT;
	BEGIN
		temp := '0';
		FOR i IN input'RANGE LOOP
			temp := temp XOR input(i);
		END LOOP;
		output <= temp;
	END PROCESS;
END Behavioral;
