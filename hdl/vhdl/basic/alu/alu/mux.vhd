----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date:    10:18:15 05/26/2015 
-- Design Name: Mux
-- Module Name:    mux - Behavioral 
-- Project Name: ALU
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY mux IS
	PORT (a, b : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
			sel : IN STD_LOGIC;
			x : OUT STD_LOGIC_VECTOR (7 DOWNTO 0));
END mux;

ARCHITECTURE BehavioralMux OF mux IS
BEGIN
	WITH sel SELECT
		x <=  a WHEN '0',
				b WHEN OTHERS;

END BehavioralMux;
