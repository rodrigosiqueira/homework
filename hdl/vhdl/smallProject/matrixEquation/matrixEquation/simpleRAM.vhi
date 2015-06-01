
-- VHDL Instantiation Created from source file simpleRAM.vhd -- 11:33:30 05/31/2015
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT simpleRAM
	PORT(
		writeEnable : IN std_logic;
		clk : IN std_logic;
		address : IN std_logic_vector(3 downto 0);
		dataIn : IN std_logic_vector(15 downto 0);
		dataOut : IN std_logic_vector(15 downto 0);       
		);
	END COMPONENT;

	Inst_simpleRAM: simpleRAM PORT MAP(
		writeEnable => ,
		clk => ,
		address => ,
		dataIn => ,
		dataOut => 
	);


