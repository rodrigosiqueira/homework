----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date:    16:11:29 05/17/2015 
-- Design Name: String detector
-- Module Name:    stringDetector - Behavioral 
-- Project Name: Study
--
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY stringDetector IS
	PORT (d, clk, rst: IN BIT;
			q: OUT BIT);
END stringDetector;

ARCHITECTURE Behavioral OF stringDetector IS
	TYPE state IS (zero, one, two, three);
	SIGNAL pr_state, nx_state : state;
BEGIN
--- LOWER
	PROCESS (clk, rst)
	BEGIN
		IF (rst = '1') THEN
			pr_state <= zero;
		ELSIF (clk'EVENT AND clk = '1') THEN
			pr_state <= nx_state;
		END IF;
	END PROCESS;
--- UPPER
	PROCESS (d, pr_state)
	BEGIN
		CASE pr_state IS
			WHEN zero =>
				q <= '0';
				IF (d = '1') THEN
					nx_state <= one;
				ELSE
					nx_state <= zero;
				END IF;
			WHEN one =>
				q <= '0';
				IF (d = '1') THEN
					nx_state <= two;
				ELSE
					nx_state <= zero;
				END IF;
			WHEN two =>
				q <= '0';
				IF (d = '1') THEN
					nx_state <= three;
				ELSE
					nx_state <= zero;
				END IF;
			WHEN three =>
				q <= '1';
				IF (d = '0') THEN 
					nx_state <= zero;
				ELSE
					nx_state <= three;
				END IF;
		END CASE;
	END PROCESS;

END Behavioral;
