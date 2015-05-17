--------------------------------------------------------------------------------
-- Copyright (c) 1995-2013 Xilinx, Inc.  All rights reserved.
--------------------------------------------------------------------------------
--   ____  ____
--  /   /\/   /
-- /___/  \  /    Vendor: Xilinx
-- \   \   \/     Version: P.20131013
--  \   \         Application: netgen
--  /   /         Filename: simpleFSM_synthesis.vhd
-- /___/   /\     Timestamp: Sun May 17 17:03:21 2015
-- \   \  /  \ 
--  \___\/\___\
--             
-- Command	: -intstyle ise -ar Structure -tm simpleFSM -w -dir netgen/synthesis -ofmt vhdl -sim simpleFSM.ngc simpleFSM_synthesis.vhd 
-- Device	: xc6slx45-3-csg324
-- Input file	: simpleFSM.ngc
-- Output file	: /home/rodrigo/Documents/Code/homework/hdl/vhdl/basic/stateMachine/Moore/simpleFSM/simpleFSM/netgen/synthesis/simpleFSM_synthesis.vhd
-- # of Entities	: 1
-- Design Name	: simpleFSM
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

entity simpleFSM is
  port (
    a : in STD_LOGIC := 'X'; 
    b : in STD_LOGIC := 'X'; 
    d : in STD_LOGIC := 'X'; 
    clk : in STD_LOGIC := 'X'; 
    rst : in STD_LOGIC := 'X'; 
    x : out STD_LOGIC 
  );
end simpleFSM;

architecture Structure of simpleFSM is
  signal a_IBUF_0 : STD_LOGIC; 
  signal b_IBUF_1 : STD_LOGIC; 
  signal d_IBUF_2 : STD_LOGIC; 
  signal clk_BUFGP_3 : STD_LOGIC; 
  signal rst_IBUF_4 : STD_LOGIC; 
  signal temp : STD_LOGIC; 
  signal nx_state : STD_LOGIC; 
  signal pr_state_7 : STD_LOGIC; 
  signal x_OBUF_8 : STD_LOGIC; 
  signal rst_inv : STD_LOGIC; 
begin
  pr_state : FDC
    port map (
      C => clk_BUFGP_3,
      CLR => rst_IBUF_4,
      D => nx_state,
      Q => pr_state_7
    );
  x_2 : FDE
    port map (
      C => clk_BUFGP_3,
      CE => rst_inv,
      D => temp,
      Q => x_OBUF_8
    );
  Mmux_temp11 : LUT3
    generic map(
      INIT => X"CA"
    )
    port map (
      I0 => a_IBUF_0,
      I1 => b_IBUF_1,
      I2 => pr_state_7,
      O => temp
    );
  Mmux_nx_state11 : LUT2
    generic map(
      INIT => X"6"
    )
    port map (
      I0 => d_IBUF_2,
      I1 => pr_state_7,
      O => nx_state
    );
  a_IBUF : IBUF
    port map (
      I => a,
      O => a_IBUF_0
    );
  b_IBUF : IBUF
    port map (
      I => b,
      O => b_IBUF_1
    );
  d_IBUF : IBUF
    port map (
      I => d,
      O => d_IBUF_2
    );
  rst_IBUF : IBUF
    port map (
      I => rst,
      O => rst_IBUF_4
    );
  x_OBUF_9 : OBUF
    port map (
      I => x_OBUF_8,
      O => x
    );
  clk_BUFGP : BUFGP
    port map (
      I => clk,
      O => clk_BUFGP_3
    );
  rst_inv1_INV_0 : INV
    port map (
      I => rst_IBUF_4,
      O => rst_inv
    );

end Structure;

