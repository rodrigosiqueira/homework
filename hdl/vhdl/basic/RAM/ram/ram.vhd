----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date:    13:52:21 05/17/2015 
-- Design Name: Rodrigo
-- Module Name: ram - Behavioral 
-- Project Name: Study 
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY ram IS
	GENERIC (bits : INTEGER := 8;
				words : INTEGER := 16);
	PORT (write_enable, clk : IN STD_LOGIC;
			address: IN INTEGER RANGE 0 TO words -1;
			data_input: IN STD_LOGIC_VECTOR (bits - 1 DOWNTO 0);
			data_output: OUT STD_LOGIC_VECTOR (bits - 1 DOWNTO 0));
END ram;

ARCHITECTURE ram OF ram IS
	TYPE vector_array IS ARRAY (0 DOWNTO words - 1) OF
		STD_LOGIC_VECTOR (bits - 1 DOWNTO 0);
	SIGNAL memory: vector_array;
BEGIN
	PROCESS(clk, write_enable)
	BEGIN
		IF (write_enable = '1') THEN
			IF (clk'EVENT AND clk = '1') THEN
				memory(address) <= data_input;
			END IF;
		END IF;
	END PROCESS;
	data_output <= memory(address);
END ram;