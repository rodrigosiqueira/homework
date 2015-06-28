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
		PORT ( elementA1 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
				 elementA2 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
				 elementA3 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
				 elementB1 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
				 elementB2 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
				 elementB3 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
				 startPort : IN STD_LOGIC;
				 resetPort : IN STD_LOGIC;
				 numOperation : IN STD_LOGIC;
				 clk : IN STD_LOGIC;
				 resultPort : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
				 readyPort : OUT STD_LOGIC);
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
	
	COMPONENT multiplyMatrix
		PORT (input : IN STD_LOGIC_VECTOR(47 DOWNTO 0);
				mutiplyType : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
				readInput : IN STD_LOGIC;
				clkMult : IN STD_LOGIC;
				resetMult : IN STD_LOGIC;
				startMultiply : IN STD_LOGIC;
				output : OUT STD_LOGIC_VECTOR(95 DOWNTO 0);
				readyMultiply : OUT STD_LOGIC);
	END COMPONENT;
END dataTypes;
