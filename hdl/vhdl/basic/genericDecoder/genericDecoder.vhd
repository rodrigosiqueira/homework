----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:11:40 05/14/2015 
-- Design Name: 
-- Module Name:    genericDecoder - Behavioral 
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

ENTITY genericDecoder IS
	PORT ( enable : IN STD_LOGIC;
			 sel : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
			 x : OUT STD_LOGIC_VECTOR (7 DOWNTO 0));
END genericDecoder;

ARCHITECTURE Behavioral OF genericDecoder IS
BEGIN
	PROCESS (enable, sel)
		VARIABLE temp1 : STD_LOGIC_VECTOR (x'HIGH DOWNTO 0);
		VARIABLE temp2 : INTEGER RANGE 0 TO x'HIGH;
		BEGIN
			temp1 := (OTHERS => '1');
			temp2 := 0;
			IF (enable = '1') THEN
				-- Select range
				FOR i IN sel'RANGE LOOP
					-- Bin to integer conversion
					IF (sel(i) = '1') THEN
						temp2 := 2 * temp2 + 1;
					ELSE
						temp2 := 2 * temp2;
					END IF;
				END LOOP;
				temp1(temp2) := '0';
			END IF;
			x <= temp1;
	END PROCESS;
END Behavioral;
