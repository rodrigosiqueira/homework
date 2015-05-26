----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date:    10:22:33 05/26/2015 
-- Design Name: AKU
-- Module Name:  alu - Behavioral 
-- Project Name: ALU
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY alu IS
	PORT (a, b : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
			cin : IN STD_LOGIC;
			sel : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
			y : OUT STD_LOGIC_VECTOR (7 DOWNTO 0));
END alu;

ARCHITECTURE Behavioral OF alu IS
	-- ARITHMETIC UNIT
	COMPONENT arith_unit IS
		PORT (a, b : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
				cin : IN STD_LOGIC;
				sel : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
				x : OUT STD_LOGIC_VECTOR (7 DOWNTO 0));
	END COMPONENT;
	-- LOGIC UNIT
	COMPONENT logic_unit IS
		PORT (a, b : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
				sel : IN STD_LOGIC_VECTOR (2 DOWNTO 0);
				x : OUT STD_LOGIC_VECTOR (7 DOWNTO 0));
	END COMPONENT;
	-- MUX
	COMPONENT mux IS
		PORT (a, b : IN STD_LOGIC_VECTOR (7 DOWNTO 0);
				sel : IN STD_LOGIC;
				x : OUT STD_LOGIC_VECTOR (7 DOWNTO 0));
	END COMPONENT;
	-- CONNECT UNITS
	SIGNAL x1, x2 : STD_LOGIC_VECTOR (7 DOWNTO 0);
BEGIN
	U1 : arith_unit PORT MAP (a, b, cin, sel(2 DOWNTO 0), x1);
	U2 : logic_unit PORT MAP (a, b, sel(2 DOWNTO 0), x2);
	U3 : mux PORT MAP (x1, x2, sel(3), y);
END Behavioral;
