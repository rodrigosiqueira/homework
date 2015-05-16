----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 23:22:15 04/15/2015 
-- Design Name: Rodrigo
-- Module Name: genericDecoder - Behavioral 
-- Project Name: Generic Decoder
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
	PORT( enable : IN STD_LOGIC;
			sel : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
			output : OUT STD_LOGIC_VECTOR (7 DOWNTO 0));
END genericDecoder;

ARCHITECTURE Behavioral OF genericDecoder IS
BEGIN
	PROCESS(enable, sel)
		VARIABLE temp1 : STD_LOGIC_VECTOR(output'HIGH DOWNTO 0);
		VARIABLE temp2 : INTEGER RANGE 0 TO output'HIGH;
	BEGIN
		temp1 := (OTHERS => '1');
		temp2 := 0;
		IF (enable='1') THEN
			FOR i IN sel'RANGE LOOP
				IF (sel(i) = '1') THEN
					temp2 := 2 * temp2 + 1;
				ELSE
					temp2 := 2 * temp2;
				END IF;
			END LOOP;
			temp1(temp2) := '0';
		END IF;
		output <= temp1;
	END PROCESS;

END Behavioral;

