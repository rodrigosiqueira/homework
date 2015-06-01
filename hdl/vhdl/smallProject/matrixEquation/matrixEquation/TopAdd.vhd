----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date: 23:45:21 05/27/2015
-- Module Name: TopAddSub - Behavioral 
-- Project Name: matrixEquation
-- Description: 
--		This file keeps the Add component
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_signed.ALL;
USE IEEE.STD_LOGIC_arith.ALL;

------------------------- ENTITY -------------------------------
ENTITY TopAdd is
    PORT ( resetPort : in  STD_LOGIC;
           clkPort : in  STD_LOGIC;
           startPort : in  STD_LOGIC;
           aPort : in  STD_LOGIC_VECTOR (15 downto 0); -- Input A
           bPort : in  STD_LOGIC_VECTOR (15 downto 0); -- Input B
           outputPort : out  STD_LOGIC_VECTOR (15 downto 0);
           readyPort : out  STD_LOGIC);
END TopAdd;

------------------------- ACHITECTURE --------------------------
ARCHITECTURE Behavioral OF TopAdd IS

	COMPONENT adder IS
	  PORT (
		 a : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		 b : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		 clk : IN STD_LOGIC;
		 ce : IN STD_LOGIC;
		 s : OUT STD_LOGIC_VECTOR(15 DOWNTO 0)
	  );
	END COMPONENT;

	SIGNAL auxiliar: STD_LOGIC_VECTOR (15 DOWNTO 0) := (others=>'0');
	SIGNAL aSignal: STD_LOGIC_VECTOR (15 DOWNTO 0) := (others=>'0');
	SIGNAL bSignal: STD_LOGIC_VECTOR (15 DOWNTO 0) := (others=>'0');
	SIGNAL operationSignal: STD_LOGIC := '1';

	TYPE state IS (waiting, operation, result);
	SIGNAL current: state := waiting;

BEGIN

myAdd : adder PORT MAP( 	clk => clkPort,
										ce => '1',
										a => aSignal,
										b => bSignal,
										s => auxiliar);

PROCESS(clkPort)
BEGIN
	IF rising_edge(clkPort) THEN
		IF resetPort='1' THEN
			current <= waiting;
			outputPort <= (others=>'0');
			aSignal <= (others=>'0');
			bSignal <= (others=>'0');
			readyPort <= '0';
		ELSE
			CASE current IS
				WHEN waiting =>
					readyPort <= '0';
					IF startPort = '1' THEN
						aSignal <= aPort;
						bSignal <= bPort;
						current <= operation;
					END IF;
				WHEN operation =>
					readyPort <= '0';
					current <= result;
				WHEN result =>
					readyPort <= '1';
					outputPort <= auxiliar;
					current <= waiting;
			END CASE;
		END IF;
	END IF;
END PROCESS;

END Behavioral;
