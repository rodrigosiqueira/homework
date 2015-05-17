----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    18:22:44 05/16/2015 
-- Design Name: 
-- Module Name:    mux1 - Behavioral 
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

ENTITY mux1 IS
	PORT (a, b, c, d, s0, s1 : IN STD_LOGIC;
			y : OUT STD_LOGIC);
END mux1;

ARCHITECTURE Behavioral OF mux1 IS
BEGIN
	y <=	(a AND NOT s1 AND NOT s0) OR
			(b AND NOT s1 AND s0) OR
			(c AND s1 AND NOT s0) OR
			(d AND s1 AND s0);
END Behavioral;

