----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 14:56:09 04/07/2015 
-- Design Name: Rodrigo Siqueira de Melo
-- Module Name: nand_study - Behavioral 
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

ENTITY nand_study IS
	PORT (keyA, keyB : IN STD_LOGIC;
			ledOut : OUT STD_LOGIC);
END nand_study;

ARCHITECTURE Behavioral OF nand_study IS
BEGIN
	ledOut <= keyA NAND keyB;
END Behavioral;

