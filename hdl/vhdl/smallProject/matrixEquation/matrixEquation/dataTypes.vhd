----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo Siqueira de Melo
-- 
-- Create Date: 14:03:32 05/27/2015 
-- Design Name: 
-- Module Name: dataTypes - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

PACKAGE dataTypes IS	
	-- Multiplier
	COMPONENT TopMultiplier
		PORT ( reset : IN STD_LOGIC;
				 clk : IN STD_LOGIC;
				 aPort : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
				 bPort : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
				 startPort : IN STD_LOGIC;
				 outputPort : OUT STD_LOGIC_VECTOR (15 DOWNTO 0);
				 readyPort : OUT STD_LOGIC);
	END COMPONENT;

	-- Adder
	COMPONENT TopAdd
		 PORT ( resetPort : in  STD_LOGIC;
				  clkPort : in  STD_LOGIC;
				  startPort : in  STD_LOGIC;
				  aPort : in  STD_LOGIC_VECTOR (15 downto 0); -- Input A
				  bPort : in  STD_LOGIC_VECTOR (15 downto 0); -- Input B
				  outputPort : out  STD_LOGIC_VECTOR (15 downto 0);
				  readyPort : out  STD_LOGIC);
	END COMPONENT;
	
	-- Line column operator
	COMPONENT lineColumnOperation
		PORT ( lineElement1 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
				 lineElement2 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
				 lineElement3 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
				 columnElement1 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
				 columnElement2 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
				 columnElement3 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
				 startPort : IN STD_LOGIC;
				 resetPort : IN STD_LOGIC;
				 clk : IN STD_LOGIC;
				 resultPort : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
				 readyPort : OUT STD_LOGIC);
	END COMPONENT;
	
	-- ROM MATRIX
	COMPONENT romMatrix
		PORT ( address : IN STD_LOGIC_VECTOR (3 DOWNTO 0);
				 data : OUT STD_LOGIC_VECTOR (15 DOWNTO 0));
	END COMPONENT;
	
	-- SIMPLE RAM MEMORY
	COMPONENT simpleRAM
		GENERIC ( bits : INTEGER := 16;
				 word : INTEGER := 16);

		PORT ( writeEnable : IN STD_LOGIC;
				 clk : IN STD_LOGIC;
				 address : IN INTEGER RANGE 0 DOWNTO word - 1;
				 dataIn : IN STD_LOGIC_VECTOR (bits - 1 DOWNTO 0);
				 dataOut : IN STD_LOGIC_VECTOR (bits - 1 DOWNTO 0)
				);
	END COMPONENT;
	
	-- MATRIX 2 X 2 ADDITION
	COMPONENT matrix2by2Addition
		PORT ( element00A : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
			 element01A : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
			 element10A : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
			 element11A : IN STD_LOGIC_VECTOR (15 DOWNTO 0);

			 element00B : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
			 element01B : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
			 element10B : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
			 element11B : IN STD_LOGIC_VECTOR (15 DOWNTO 0);

			 clk : IN STD_LOGIC;
			 reset : IN STD_LOGIC;
			 start : IN STD_LOGIC;
			 ready : OUT STD_LOGIC;

			 result00 : OUT STD_LOGIC_VECTOR (15 DOWNTO 0);
			 result01 : OUT STD_LOGIC_VECTOR (15 DOWNTO 0);
			 result10 : OUT STD_LOGIC_VECTOR (15 DOWNTO 0);
			 result11 : OUT STD_LOGIC_VECTOR (15 DOWNTO 0));
	END COMPONENT;
END dataTypes;
