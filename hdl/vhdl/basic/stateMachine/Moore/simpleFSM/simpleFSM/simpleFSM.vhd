----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date:    16:22:16 05/17/2015 
-- Design Name: Rodrigo
-- Module Name:    simpleFSM - Behavioral 
-- Project Name: Study
--
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY simpleFSM IS
	PORT (a, b, d, clk, rst: IN BIT;
			x: OUT BIT);
END simpleFSM;

ARCHITECTURE Behavioral OF simpleFSM IS
	TYPE state IS (stateA, stateB);
	SIGNAL pr_state, nx_state: state;
	SIGNAL temp: BIT;
BEGIN
--- LOWER
	PROCESS(clk, rst)
	BEGIN
		IF (rst = '1') THEN
			pr_state <= stateA;
		ELSIF (clk'EVENT AND clk = '1') THEN
			x <= temp;
			pr_state <= nx_state;
		END IF;
	END PROCESS;

--- UPPER
	PROCESS(a, b, d, pr_state)
	BEGIN
		CASE pr_state IS
			WHEN stateA =>
				temp <= a;
				IF (d = '1') THEN
					nx_state <= stateB;
				ELSE
					nx_state <= stateA;
				END IF;
			WHEN stateB =>
				temp <= b;
				IF (d = '1') THEN
					nx_state <= stateA;
				ELSE
					nx_state <= stateB;
				END IF;
		END CASE;
	END PROCESS;
END Behavioral;
