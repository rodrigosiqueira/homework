----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date:    00:13:00 06/01/2015 
-- Design Name: 
-- Module Name:    multiplyMatrix - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE work.dataTypes.ALL;


ENTITY multiplyMatrix IS
	PORT (input : IN STD_LOGIC_VECTOR(47 DOWNTO 0);
			mutiplyType : IN STD_LOGIC_VECTOR(1 DOWNTO 0);
			readInput : IN STD_LOGIC;
			clkMult : IN STD_LOGIC;
			resetMult : IN STD_LOGIC;
			startMultiply : IN STD_LOGIC;
			output : OUT STD_LOGIC_VECTOR(95 DOWNTO 0);
			readyMultiply : OUT STD_LOGIC);
END multiplyMatrix;

ARCHITECTURE Behavioral OF multiplyMatrix IS

	SIGNAL a00 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL a01 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL a02 : STD_LOGIC_VECTOR(15 DOWNTO 0);

	SIGNAL b00 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL b01 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL b02 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	
	SIGNAL inputOne : STD_LOGIC_VECTOR (143 DOWNTO 0);
	SIGNAL inputTwo : STD_LOGIC_VECTOR (95 DOWNTO 0);
	
	SIGNAL tempResult : STD_LOGIC_VECTOR(15 DOWNTO 0);

	SIGNAL startOperation : STD_LOGIC;
	SIGNAL readyOperation : STD_LOGIC;

	TYPE state IS (waiting, mul00, mul01, mul10, mul11, mul20, mul21, final);
	SIGNAL mul3x3and3x2 : state;
	
	TYPE state2x3and3x2 IS (waiting, mul00, mul01, mul10, mul11);
	SIGNAL mul2x3and3x2 : state2x3and3x2;
	
	TYPE stateRead IS (lineA1, lineA2, lineA3, lineB1, lineB2);
	SIGNAL control : stateRead;

BEGIN

operationMatrix :	lineColumnOperation PORT MAP( elementA1 => a00,
																elementA2 => a01,
																elementA3 => a02,
																elementB1 => b00,
																elementB2 => b01,
																elementB3 => b02,
																startPort => startOperation,
																resetPort => resetMult,
																clk => clkMult,
																resultPort => tempResult,
																readyPort => readyOperation);

	-- READ INPUT
	PROCESS(clkMult, readInput)
	BEGIN
		IF rising_edge(clkMult) AND readInput = '1' THEN
			IF resetMult = '1' THEN
				control <= lineA1;
				inputOne <= (OTHERS => '0');
			ELSE
				CASE control IS
					WHEN lineA1 =>
						inputOne(143 DOWNTO 96) <= input;
						control <= lineA2;
					WHEN lineA2 =>
						inputOne(95 DOWNTO 48) <= input;
						control <= lineA3;
					WHEN lineA3 =>
						inputOne(47 DOWNTO 0) <= input;
						control <= lineB1;
					WHEN lineB1 =>
						inputTwo(95 DOWNTO 48) <= input;
						control <= lineB2;
					WHEN lineB2 =>
						inputTwo(47 DOWNTO 0) <= input;
				END CASE;
			END IF;
		END IF;
	END PROCESS;

	-- MULTIPLICATION
	PROCESS(clkMult, readInput)
		-- BUFFER
		VARIABLE result00 : STD_LOGIC_VECTOR(15 DOWNTO 0);
		VARIABLE result01 : STD_LOGIC_VECTOR(15 DOWNTO 0);
		VARIABLE result10 : STD_LOGIC_VECTOR(15 DOWNTO 0);
		VARIABLE result11 : STD_LOGIC_VECTOR(15 DOWNTO 0);
		VARIABLE result20 : STD_LOGIC_VECTOR(15 DOWNTO 0);
		VARIABLE result21 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	BEGIN
		IF rising_edge(clkMult) AND readInput = '0' THEN
			IF resetMult = '1' THEN
				readyMultiply <= '0';
				output <= (OTHERS => '0');
			ELSE
				-- 3x3 and 3x2
				IF mutiplyType = "00" THEN
					CASE mul3x3and3x2 IS
						WHEN waiting =>
							readyMultiply <= '0';
							startOperation <= '0';
							IF startMultiply = '1' THEN
								-- Set state
								mul3x3and3x2 <= mul00;
								-- Set signals
								startOperation <= '1';
								-- Data path
									-- Line: First
								a00 <= inputOne(143 DOWNTO 128);
								a01 <= inputOne(127 DOWNTO 112);
								a02 <= inputOne(111 DOWNTO 96);
									-- Column: First
								b00 <= inputTwo(95 DOWNTO 80);
								b01 <= inputTwo(63 DOWNTO 48);
								b02 <= inputTwo(31 DOWNTO 16);
							END IF;
						WHEN mul00 =>
							readyMultiply <= '0';
							startOperation <= '0';
							IF readyOperation = '1' THEN
								-- Set state
								mul3x3and3x2 <= mul01;
								-- Output
								result00 := tempResult;
								-- Set signals
								startOperation <= '1';
								-- Data path
									-- Line: First
								a00 <= inputOne(143 DOWNTO 128);
								a01 <= inputOne(127 DOWNTO 112);
								a02 <= inputOne(111 DOWNTO 96);
									-- Column: Second
								b00 <= inputTwo(79 DOWNTO 64);
								b01 <= inputTwo(47 DOWNTO 32);
								b02 <= inputTwo(15 DOWNTO 0);
							END IF;
						WHEN mul01 =>
							readyMultiply <= '0';
							startOperation <= '0';
							IF readyOperation = '1' THEN
								-- Set state
								mul3x3and3x2 <= mul10;
								-- Output
								result01 := tempResult;
								-- Set signals
								startOperation <= '1';
								-- Data path
									-- Line: Second
								a00 <= inputOne(95 DOWNTO 80);
								a01 <= inputOne(79 DOWNTO 64);
								a02 <= inputOne(63 DOWNTO 48);
									-- Column: First
								b00 <= inputTwo(95 DOWNTO 80);
								b01 <= inputTwo(63 DOWNTO 48);
								b02 <= inputTwo(31 DOWNTO 16);
							END IF;
						WHEN mul10 =>
							readyMultiply <= '0';
							startOperation <= '0';
							IF readyOperation = '1' THEN
								-- Set state
								mul3x3and3x2 <= mul11;
								-- Output
								result10 := tempResult;
								-- Set signals
								startOperation <= '1';
								-- Data path
									-- Line: Second
								a00 <= inputOne(95 DOWNTO 80);
								a01 <= inputOne(79 DOWNTO 64);
								a02 <= inputOne(63 DOWNTO 48);
									-- Column: Second
								b00 <= inputTwo(79 DOWNTO 64);
								b01 <= inputTwo(47 DOWNTO 32);
								b02 <= inputTwo(15 DOWNTO 0);
							END IF;
						WHEN mul11 =>
							readyMultiply <= '0';
							startOperation <= '0';
							IF readyOperation = '1' THEN
								-- Set state
								mul3x3and3x2 <= mul20;
								-- Output
								result11 := tempResult;
								-- Set signals
								startOperation <= '1';
								-- Data path
									-- Line: Third
								a00 <= inputOne(47 DOWNTO 32);
								a01 <= inputOne(31 DOWNTO 16);
								a02 <= inputOne(15 DOWNTO 0);
									-- Column: First
								b00 <= inputTwo(95 DOWNTO 80);
								b01 <= inputTwo(63 DOWNTO 48);
								b02 <= inputTwo(31 DOWNTO 16);
							END IF;
						WHEN mul20 =>
							readyMultiply <= '0';
							startOperation <= '0';
							IF readyOperation = '1' THEN
								-- Set state
								mul3x3and3x2 <= mul21;
								-- Output
								result20 := tempResult;
								-- Set signals
								startOperation <= '1';
								-- Data path
									-- Line: Third
								a00 <= inputOne(47 DOWNTO 32);
								a01 <= inputOne(31 DOWNTO 16);
								a02 <= inputOne(15 DOWNTO 0);
									-- Column: Second
								b00 <= inputTwo(79 DOWNTO 64);
								b01 <= inputTwo(47 DOWNTO 32);
								b02 <= inputTwo(15 DOWNTO 0);
							END IF;
						WHEN mul21 =>
							readyMultiply <= '0';
							IF readyOperation = '1' THEN
								-- Set state
								mul3x3and3x2 <= final;
								-- Output
								result21 := tempResult;
								-- Set signals
								startOperation <= '0';
							END IF;
						WHEN final =>
							-- Set state
							mul3x3and3x2 <= waiting;
							-- Set signals
							readyMultiply <= '1';
							-- Output
							output(95 DOWNTO 80) <= result00;
							output(79 DOWNTO 64) <= result01;
							output(63 DOWNTO 48) <= result10;
							output(47 DOWNTO 32) <= result11;
							output(31 DOWNTO 16) <= result20;
							output(15 DOWNTO 0) <= result21;
					END CASE;
				-- 2x3 and 3x2
				ELSIF mutiplyType = "01" THEN
					CASE mul2x3and3x2 IS
						WHEN waiting =>
							readyMultiply <= '0';
							startOperation <= '0';
							IF startMultiply = '1' THEN
								-- Set state
								mul2x3and3x2 <= mul00;
								-- Set signals
								startOperation <= '1';
								-- Data path
									-- Line: First
								a00 <= inputOne(143 DOWNTO 128);
								a01 <= inputOne(127 DOWNTO 112);
								a02 <= inputOne(111 DOWNTO 96);
									-- Column: First
								b00 <= inputTwo(95 DOWNTO 80);
								b01 <= inputTwo(63 DOWNTO 48);
								b02 <= inputTwo(31 DOWNTO 16);
							END IF;
						WHEN mul00 =>
							readyMultiply <= '0';
							startOperation <= '0';
							IF readyOperation = '1' THEN
								-- Set state
								mul2x3and3x2 <= mul01;
								-- Output
								result00 := tempResult;
								-- Set signals
								startOperation <= '1';
								-- Data path
									-- Line: First
								a00 <= inputOne(143 DOWNTO 128);
								a01 <= inputOne(127 DOWNTO 112);
								a02 <= inputOne(111 DOWNTO 96);
									-- Column: Second
								b00 <= inputTwo(79 DOWNTO 64);
								b01 <= inputTwo(47 DOWNTO 32);
								b02 <= inputTwo(15 DOWNTO 0);
							END IF;
						WHEN mul01 =>
							readyMultiply <= '0';
							startOperation <= '0';
							IF readyOperation = '1' THEN
								-- Set state
								mul2x3and3x2 <= mul10;
								-- Output
								result01 := tempResult;
								-- Set signals
								startOperation <= '1';
								-- Data path
									-- Line: Second
								a00 <= inputOne(95 DOWNTO 80);
								a01 <= inputOne(79 DOWNTO 64);
								a02 <= inputOne(63 DOWNTO 48);
									-- Column: First
								b00 <= inputTwo(95 DOWNTO 80);
								b01 <= inputTwo(63 DOWNTO 48);
								b02 <= inputTwo(31 DOWNTO 16);
							END IF;
						WHEN mul10 =>
							readyMultiply <= '0';
							startOperation <= '0';
							IF readyOperation = '1' THEN
								-- Set state
								mul2x3and3x2 <= mul11;
								-- Output
								result10 := tempResult;
								-- Set signals
								startOperation <= '1';
								-- Data path
									-- Line: Second
								a00 <= inputOne(95 DOWNTO 80);
								a01 <= inputOne(79 DOWNTO 64);
								a02 <= inputOne(63 DOWNTO 48);
									-- Column: Second
								b00 <= inputTwo(79 DOWNTO 64);
								b01 <= inputTwo(47 DOWNTO 32);
								b02 <= inputTwo(15 DOWNTO 0);
							END IF;
						WHEN mul11 =>
							readyMultiply <= '0';
							startOperation <= '0';
							IF readyOperation = '1' THEN
								-- Set state
								mul2x3and3x2 <= waiting;
								-- Output
								result11 := tempResult;
								-- Set signals
								readyMultiply <= '1';
								-- Set output
								output(95 DOWNTO 80) <= result00;
								output(79 DOWNTO 64) <= result01;
								output(63 DOWNTO 48) <= result10;
								output(47 DOWNTO 32) <= result11;
								output(31 DOWNTO 16) <= (OTHERS => '0');
							END IF;
					END CASE;
				-- 3x2 and 2x2
				ELSIF mutiplyType = "10" THEN
				ELSE
				END IF;
			END IF;
		END IF;
	END PROCESS;

END Behavioral;
