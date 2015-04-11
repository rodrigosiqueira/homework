----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    15:39:57 04/07/2015 
-- Design Name: Rodrigo Siqueira de Melo
-- Module Name: d_flip_flop - Behavioral 
-- Project Name: Homework 
-- Target Devices: Atlys
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
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

ENTITY d_flip_flop IS
	PORT(	d, clock, reset : IN STD_LOGIC;
			Q: OUT STD_LOGIC);
END d_flip_flop;

ARCHITECTURE Behavioral OF d_flip_flop IS
BEGIN
	PROCESS (reset, clock)
	BEGIN
		IF (reset = '1') THEN
			Q <= '0';
		ELSIF (clock'EVENT AND clock = '1') THEN
			Q <= d;
		END IF;
	END PROCESS;
END Behavioral;
