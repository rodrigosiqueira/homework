----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date: 00:39:48 05/28/2015 
-- Design Name: 
-- Module Name: TopMultiplier - Behavioral 
-- Project Name: matrixEquation
-- Description: 
--
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE IEEE.STD_LOGIC_signed.ALL;
USE IEEE.STD_LOGIC_arith.ALL;

ENTITY TopMultiplier IS
    PORT ( reset : IN STD_LOGIC;
           clk : IN STD_LOGIC;
           aPort : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
           bPort : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
           startPort : IN STD_LOGIC;
           outputPort : OUT STD_LOGIC_VECTOR (15 DOWNTO 0);
           readyPort : OUT STD_LOGIC);
END TopMultiplier;

ARCHITECTURE Behavioral OF TopMultiplier is

	COMPONENT multiplier
	  PORT (
		 clk : IN STD_LOGIC;
		 a : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		 b : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
		 p : OUT STD_LOGIC_VECTOR(31 DOWNTO 0)
	  );
	END COMPONENT;

	SIGNAL auxiliar: STD_LOGIC_VECTOR (31 DOWNTO 0) := (others=>'0');
	SIGNAL aSignal: STD_LOGIC_VECTOR (15 DOWNTO 0) := (others=>'0');
	SIGNAL bSignal: STD_LOGIC_VECTOR (15 DOWNTO 0) := (others=>'0');

	TYPE states IS (waiting, operation, result);
	SIGNAL current : states := waiting;

BEGIN

	myMultiplier : multiplier PORT MAP ( clk => clk,
													 a => aSignal,
													 b => bSignal,
													 p => auxiliar);

	PROCESS (clk)
	BEGIN
		IF rising_edge (clk) THEN
			IF reset = '1' THEN
				current <= waiting;
				outputPort <= (OTHERS => '0');
				aSignal <= (OTHERS => '0');
				bSignal <= (OTHERS => '0');
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
						outputPort <= auxiliar(23 downto 8);					
						current <= waiting;
				END CASE;
			END IF;
		END IF;
	END PROCESS;

END Behavioral;
