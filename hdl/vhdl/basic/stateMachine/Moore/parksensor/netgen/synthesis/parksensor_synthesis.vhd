--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____
--  /   /\/   /
-- /___/  \  /    Vendor: Xilinx
-- \   \   \/     Version: P.20131013
--  \   \         Application: netgen
--  /   /         Filename: parksensor_synthesis.vhd
-- /___/   /\     Timestamp: Tue May 12 22:37:59 2015
-- \   \  /  \ 
--  \___\/\___\
--             
-- Command	: -intstyle ise -ar Structure -tm parksensor -w -dir netgen/synthesis -ofmt vhdl -sim parksensor.ngc parksensor_synthesis.vhd 
-- Device	: xc6slx45-3-csg324
-- Input file	: parksensor.ngc
-- Output file	: /home/rodrigo/Documents/Code/homework/hdl/vhdl/basic/stateMachine/Moore/parksensor/netgen/synthesis/parksensor_synthesis.vhd
-- # of Entities	: 1
-- Design Name	: parksensor
-- Xilinx	: /opt/ISE/14.7/ISE_DS/ISE/
--             
-- Purpose:    
--     This VHDL netlist is a verification model and uses simulation 
--     primitives which may not represent the true implementation of the 
--     device, however the netlist is functionally correct and should not 
--     be modified. This file cannot be synthesized and should only be used 
--     with supported simulation tools.
--             
-- Reference:  
--     Command Line Tools User Guide, Chapter 23
--     Synthesis and Simulation Design Guide, Chapter 6
--             
--------------------------------------------------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
use UNISIM.VPKG.ALL;

entity parksensor is
  port (
    sensor_1 : in STD_LOGIC := 'X'; 
    sensor_2 : in STD_LOGIC := 'X'; 
    clk : in STD_LOGIC := 'X'; 
    rst : in STD_LOGIC := 'X'; 
    vacancy : out STD_LOGIC_VECTOR ( 3 downto 0 ) 
  );
end parksensor;

architecture Structure of parksensor is
  signal vacancy_1_OBUF_0 : STD_LOGIC; 
  signal vacancy_0_OBUF_1 : STD_LOGIC; 
begin
  XST_VCC : VCC
    port map (
      P => vacancy_0_OBUF_1
    );
  XST_GND : GND
    port map (
      G => vacancy_1_OBUF_0
    );
  vacancy_3_OBUF : OBUF
    port map (
      I => vacancy_1_OBUF_0,
      O => vacancy(3)
    );
  vacancy_2_OBUF : OBUF
    port map (
      I => vacancy_1_OBUF_0,
      O => vacancy(2)
    );
  vacancy_1_OBUF : OBUF
    port map (
      I => vacancy_1_OBUF_0,
      O => vacancy(1)
    );
  vacancy_0_OBUF : OBUF
    port map (
      I => vacancy_0_OBUF_1,
      O => vacancy(0)
    );

end Structure;

