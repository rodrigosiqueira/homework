--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   15:52:58 06/02/2015
-- Design Name:   
-- Module Name:   /home/rodrigo/Documents/Code/homework/hdl/vhdl/smallProject/matrixEquation/matrixEquation/matrixAddition_TestBench.vhd
-- Project Name:  matrixEquation
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: matrix2by2Addition
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
 
ENTITY matrixAddition_TestBench IS
END matrixAddition_TestBench;
 
ARCHITECTURE behavior OF matrixAddition_TestBench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT matrix2by2Addition
    PORT(
         element00A : IN  std_logic_vector(15 downto 0);
         element01A : IN  std_logic_vector(15 downto 0);
         element10A : IN  std_logic_vector(15 downto 0);
         element11A : IN  std_logic_vector(15 downto 0);
         element00B : IN  std_logic_vector(15 downto 0);
         element01B : IN  std_logic_vector(15 downto 0);
         element10B : IN  std_logic_vector(15 downto 0);
         element11B : IN  std_logic_vector(15 downto 0);
         clk : IN  std_logic;
         reset : IN  std_logic;
         start : IN  std_logic;
         ready : OUT  std_logic;
         result00 : OUT  std_logic_vector(15 downto 0);
         result01 : OUT  std_logic_vector(15 downto 0);
         result10 : OUT  std_logic_vector(15 downto 0);
         result11 : OUT  std_logic_vector(15 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal element00A : std_logic_vector(15 downto 0) := (others => '0');
   signal element01A : std_logic_vector(15 downto 0) := (others => '0');
   signal element10A : std_logic_vector(15 downto 0) := (others => '0');
   signal element11A : std_logic_vector(15 downto 0) := (others => '0');
   signal element00B : std_logic_vector(15 downto 0) := (others => '0');
   signal element01B : std_logic_vector(15 downto 0) := (others => '0');
   signal element10B : std_logic_vector(15 downto 0) := (others => '0');
   signal element11B : std_logic_vector(15 downto 0) := (others => '0');
   signal clk : std_logic := '0';
   signal reset : std_logic := '0';
   signal start : std_logic := '0';

 	--Outputs
   signal ready : std_logic;
   signal result00 : std_logic_vector(15 downto 0);
   signal result01 : std_logic_vector(15 downto 0);
   signal result10 : std_logic_vector(15 downto 0);
   signal result11 : std_logic_vector(15 downto 0);

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: matrix2by2Addition PORT MAP (
          element00A => element00A,
          element01A => element01A,
          element10A => element10A,
          element11A => element11A,
          element00B => element00B,
          element01B => element01B,
          element10B => element10B,
          element11B => element11B,
          clk => clk,
          reset => reset,
          start => start,
          ready => ready,
          result00 => result00,
          result01 => result01,
          result10 => result10,
          result11 => result11
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
