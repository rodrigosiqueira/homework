
-- VHDL Instantiation Created from source file TopMultiplier.vhd -- 10:56:28 05/28/2015
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT TopMultiplier
	PORT(
		reset : IN std_logic;
		clk : IN std_logic;
		aPort : IN std_logic_vector(15 downto 0);
		bPort : IN std_logic_vector(15 downto 0);
		startPort : IN std_logic;          
		outputPort : OUT std_logic_vector(15 downto 0);
		readyPort : OUT std_logic
		);
	END COMPONENT;

	Inst_TopMultiplier: TopMultiplier PORT MAP(
		reset => ,
		clk => ,
		aPort => ,
		bPort => ,
		startPort => ,
		outputPort => ,
		readyPort => 
	);


