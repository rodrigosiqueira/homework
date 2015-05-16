----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 21:39:28 04/15/2015 
-- Design Name: Rodrigo
-- Module Name: adder - Behavioral 
-- Project Name: Adder 
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
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use ieee.std_logic_arith.ALL;

entity adder is
	port (a, b : in signed (3 downto 0);
			sum : out signed (3 downto 0));
end adder;

architecture Behavioral of adder is
begin
	sum <= a + b;
end Behavioral;

