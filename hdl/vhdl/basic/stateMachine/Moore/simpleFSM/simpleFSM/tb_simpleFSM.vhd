--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   17:38:35 05/17/2015
-- Design Name:   
-- Module Name:   /home/rodrigo/Documents/Code/homework/hdl/vhdl/basic/stateMachine/Moore/simpleFSM/simpleFSM/tb_simpleFSM.vhd
-- Project Name:  simpleFSM
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: simpleFSM
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY tb_simpleFSM IS
END tb_simpleFSM;
 
ARCHITECTURE behavior OF tb_simpleFSM IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT simpleFSM
    PORT(
         a : IN  BIT;
         b : IN  BIT;
         d : IN  BIT;
         clk : IN  BIT;
         rst : IN  BIT;
         x : OUT  BIT
        );
    END COMPONENT;
    

   --Inputs
   signal a : std_logic := '0';
   signal b : std_logic := '0';
   signal d : std_logic := '0';
   signal clk : std_logic := '0';
   signal rst : std_logic := '0';

 	--Outputs
   signal x : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: simpleFSM PORT MAP (
          a => a,
          b => b,
          d => d,
          clk => clk,
          rst => rst,
          x => x
        );
		  
	clk <= not clk after 5 ns;

	d <=	'0' after 45 ns, 
			'1' after 145 ns,
			'1' after 245 ns,
			'0' after 345 ns,
			'0' after 445 ns,
			'0' after 545 ns,
			'1' after 645 ns;
END;
