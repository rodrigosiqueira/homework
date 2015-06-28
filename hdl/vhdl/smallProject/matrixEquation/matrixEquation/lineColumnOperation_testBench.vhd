--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   15:55:06 06/02/2015
-- Design Name:   
-- Module Name:   /home/rodrigo/Documents/Code/homework/hdl/vhdl/smallProject/matrixEquation/matrixEquation/lineColumnOperation_testBench.vhd
-- Project Name:  matrixEquation
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: lineColumnOperation
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
 
ENTITY lineColumnOperation_testBench IS
END lineColumnOperation_testBench;
 
ARCHITECTURE behavior OF lineColumnOperation_testBench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT lineColumnOperation
    PORT(
         elementA1 : IN  std_logic_vector(15 downto 0);
         elementA2 : IN  std_logic_vector(15 downto 0);
         elementA3 : IN  std_logic_vector(15 downto 0);
         elementB1 : IN  std_logic_vector(15 downto 0);
         elementB2 : IN  std_logic_vector(15 downto 0);
         elementB3 : IN  std_logic_vector(15 downto 0);
         startPort : IN  std_logic;
         resetPort : IN  std_logic;
         numOperation : IN  std_logic;
         clk : IN  std_logic;
         resultPort : OUT  std_logic_vector(15 downto 0);
         readyPort : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal elementA1 : std_logic_vector(15 downto 0) := (others => '0');
   signal elementA2 : std_logic_vector(15 downto 0) := (others => '0');
   signal elementA3 : std_logic_vector(15 downto 0) := (others => '0');
   signal elementB1 : std_logic_vector(15 downto 0) := (others => '0');
   signal elementB2 : std_logic_vector(15 downto 0) := (others => '0');
   signal elementB3 : std_logic_vector(15 downto 0) := (others => '0');
   signal startPort : std_logic := '0';
   signal resetPort : std_logic := '0';
   signal numOperation : std_logic := '0';
   signal clk : std_logic := '0';

 	--Outputs
   signal resultPort : std_logic_vector(15 downto 0);
   signal readyPort : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: lineColumnOperation PORT MAP (
          elementA1 => elementA1,
          elementA2 => elementA2,
          elementA3 => elementA3,
          elementB1 => elementB1,
          elementB2 => elementB2,
          elementB3 => elementB3,
          startPort => startPort,
          resetPort => resetPort,
          numOperation => numOperation,
          clk => clk,
          resultPort => resultPort,
          readyPort => readyPort
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for clk_period*10;

      -- insert stimulus here 

      wait;
   end process;

END;
