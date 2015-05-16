----------------------------------------------------------------------------------
-- Company: 
-- Engineer: Rodrigo Siqueira de Melo
-- 
-- Create Date:    07:39:45 05/12/2015 
-- Design Name: 
-- Module Name:    stateAandStateB - Behavioral 
-- Project Name: StateA and StateB
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
--------------------------------------------------
ENTITY stateAandStateB IS
	PORT(a, b, d, clk, rst : IN STD_LOGIC;
			x: OUT STD_LOGIC);
END stateAandStateB;
--------------------------------------------------
ARCHITECTURE Behavioral OF stateAandStateB IS
	TYPE state IS (stateA, stateB);
	SIGNAL pr_state, nx_state: state;
	SIGNAL temp: STD_LOGIC;
BEGIN
------------ Lower section: ----------------------
PROCESS(rst, clk)
BEGIN
	IF (rst='1') THEN
		pr_state <= stateA;
	ELSIF (clk'EVENT AND clk = '1') THEN
		x <= temp;
		pr_state <= nx_state;
	END IF;
end PROCESS;
------------ Upper section: ----------------------
PROCESS (a, b, d, pr_state)
BEGIN
	CASE pr_state IS
		WHEN stateA =>
			temp <= a;
			IF(d = '1') THEN nx_state <= stateB;
			ELSE nx_state <= stateA;
			END IF;
		WHEN stateB =>
			temp <= b;
			IF(d = '1') THEN nx_state <= stateA;
			ELSE nx_state <= stateB;
			END IF;
		END CASE;
END PROCESS;
END Behavioral;
