--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   15:56:53 06/02/2015
-- Design Name:   
-- Module Name:   /home/rodrigo/Documents/Code/homework/hdl/vhdl/smallProject/matrixEquation/matrixEquation/topAdd_testBench.vhd
-- Project Name:  matrixEquation
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: TopAdd
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
 
ENTITY topAdd_testBench IS
END topAdd_testBench;
 
ARCHITECTURE behavior OF topAdd_testBench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT TopAdd
    PORT(
         resetPort : IN  std_logic;
         clkPort : IN  std_logic;
         startPort : IN  std_logic;
         aPort : IN  std_logic_vector(15 downto 0);
         bPort : IN  std_logic_vector(15 downto 0);
         outputPort : OUT  std_logic_vector(15 downto 0);
         readyPort : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal resetPort : std_logic := '0';
   signal clkPort : std_logic := '0';
   signal startPort : std_logic := '0';
   signal aPort : std_logic_vector(15 downto 0) := (others => '0');
   signal bPort : std_logic_vector(15 downto 0) := (others => '0');

 	--Outputs
   signal outputPort : std_logic_vector(15 downto 0);
   signal readyPort : std_logic;

   -- Clock period definitions
   constant clkPort_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: TopAdd PORT MAP (
          resetPort => resetPort,
          clkPort => clkPort,
          startPort => startPort,
          aPort => aPort,
          bPort => bPort,
          outputPort => outputPort,
          readyPort => readyPort
        );

   -- Clock process definitions
   clkPort_process :process
   begin
		clkPort <= '0';
		wait for clkPort_period/2;
		clkPort <= '1';
		wait for clkPort_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for clkPort_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
