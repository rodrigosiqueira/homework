----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date: 23:35:22 05/28/2015 
-- Design Name: 
-- Module Name: romMatrix - Behavioral 
-- Project Name: matrixEquation 
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_UNSIGNED.ALL;

ENTITY romMatrix IS
	PORT (address : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
			data : OUT STD_LOGIC_VECTOR (15 DOWNTO 0));
END romMatrix;

ARCHITECTURE Behavioral OF romMatrix IS
	-- B'
	CONSTANT data0 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	CONSTANT data1 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	CONSTANT data2 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	CONSTANT data3 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	CONSTANT data4 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	CONSTANT data5 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	
	-- B
	CONSTANT data6 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	CONSTANT data7 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	CONSTANT data8 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	CONSTANT data9 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	CONSTANT data10 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	CONSTANT data11 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	
	-- C
	CONSTANT data12 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	CONSTANT data13 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	CONSTANT data14 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	CONSTANT data15 : STD_LOGIC_VECTOR (15 DOWNTO 0) := "0001";
	
	TYPE romArray IS ARRAY (NATURAL RANGE <>) OF STD_LOGIC_VECTOR(15 DOWNTO 0);
	CONSTANT matrixROM : romArray :=
		(data0, data1, data2, data3, data4, data5, data6, data7, data8, data9,
		 data10, data11, data12, data13, data14, data15);
BEGIN

	PROCESS (address)
		VARIABLE position : INTEGER;
	BEGIN
		position := conv_integer(address);
		data <= matrixROM(position);
	END PROCESS;

END Behavioral;
