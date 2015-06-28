
-- VHDL Instantiation Created from source file lineColumnOperation.vhd -- 16:55:32 06/02/2015
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT lineColumnOperation
	PORT(
		elementA1 : IN std_logic_vector(15 downto 0);
		elementA2 : IN std_logic_vector(15 downto 0);
		elementA3 : IN std_logic_vector(15 downto 0);
		elementB1 : IN std_logic_vector(15 downto 0);
		elementB2 : IN std_logic_vector(15 downto 0);
		elementB3 : IN std_logic_vector(15 downto 0);
		startPort : IN std_logic;
		resetPort : IN std_logic;
		numOperation : IN std_logic;
		clk : IN std_logic;          
		resultPort : OUT std_logic_vector(15 downto 0);
		readyPort : OUT std_logic
		);
	END COMPONENT;

	Inst_lineColumnOperation: lineColumnOperation PORT MAP(
		elementA1 => ,
		elementA2 => ,
		elementA3 => ,
		elementB1 => ,
		elementB2 => ,
		elementB3 => ,
		startPort => ,
		resetPort => ,
		numOperation => ,
		clk => ,
		resultPort => ,
		readyPort => 
	);


