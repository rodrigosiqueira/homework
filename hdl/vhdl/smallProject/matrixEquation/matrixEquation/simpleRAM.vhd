----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date: 08:43:38 05/29/2015 
-- Design Name: matrixEquation
-- Module Name: simpleRAM - Behavioral
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY simpleRAM IS
	GENERIC ( bits : INTEGER := 16;
				 word : INTEGER := 16);

	PORT ( writeEnable : IN STD_LOGIC;
			 clk : IN STD_LOGIC;
			 address : IN INTEGER RANGE 0 DOWNTO word - 1;
			 dataIn : IN STD_LOGIC_VECTOR (bits - 1 DOWNTO 0);
			 dataOut : IN STD_LOGIC_VECTOR (bits - 1 DOWNTO 0)
			);
END simpleRAM;

ARCHITECTURE Behavioral OF simpleRAM IS
	TYPE vectorArray IS ARRAY (0 DOWNTO words - 1) OF
			STD_LOGIC_VECTOR (bits - 1 DOWNTO 0);
	SIGNAL memory : vectorArray;
BEGIN

	PROCESS (clk, writeEnable)
	BEGIN
		IF (writeEnable = '1') THEN
			IF (clk'EVENT = '1' AND clk = '1') THEN
				memory(address) <= dataIn;
			END IF;
		END IF;
		dataOut <= memory(address);
	END PROCESS;

END Behavioral;

