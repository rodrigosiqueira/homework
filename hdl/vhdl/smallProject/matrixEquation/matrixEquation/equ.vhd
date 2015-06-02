----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date: 17:12:09 05/31/2015 
-- Design Name: Rodrigo
-- Module Name: equ - Behavioral 
-- Project Name: Matrix Equation
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE work.dataTypes.ALL;

ENTITY equ IS
	PORT (input : IN STD_LOGIC_VECTOR (47 DOWNTO 0); -- Input for read 240 bits
			operation : IN STD_LOGIC_VECTOR (2 DOWNTO 0); -- 3 bits
			outputEQU : OUT STD_LOGIC_VECTOR (95 DOWNTO 0);
			readInput : IN STD_LOGIC;
			clkEQU : IN STD_LOGIC;
			startEQU : IN STD_LOGIC;
			resetEQU : IN STD_LOGIC;
			readyEQU : OUT STD_LOGIC); -- 96 bits
END equ;

ARCHITECTURE Behavioral OF equ IS

	SIGNAL inputOne : STD_LOGIC_VECTOR (63 DOWNTO 0);
	SIGNAL inputTwo : STD_LOGIC_VECTOR (63 DOWNTO 0);
	
	SIGNAL a00 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL a01 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL a10 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL a11 : STD_LOGIC_VECTOR(15 DOWNTO 0);

	SIGNAL b00 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL b01 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL b10 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL b11 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	
	SIGNAL sum00 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL sum01 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL sum10 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL sum11 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	
	SIGNAL sumReady : STD_LOGIC;
	SIGNAL sumStart : STD_LOGIC;
	
	SIGNAL multiplyType : STD_LOGIC_VECTOR(1 DOWNTO 0);
	SIGNAL multiplyStart : STD_LOGIC;
	SIGNAL multiplyReady : STD_LOGIC;
	SIGNAL multiplyResult: STD_LOGIC_VECTOR (95 DOWNTO 0);

	----------------------------
	-- EQU states
	----------------------------
	TYPE equState IS (waiting, mult3x2, mult2x3, mult2x2, sum, inverse);
	SIGNAL equControl : equState := waiting;

	----------------------------
	-- Read states
	----------------------------
	TYPE stateRead IS (firstCopy, secondCopy, thirdCopy);
	SIGNAL control : stateRead;

BEGIN

	matrixSum : matrix2by2Addition PORT MAP(element00A => a00,
														 element01A => a01,
														 element10A => a10,
														 element11A => a11,
														 element00B => b00,
														 element01B => b01,
														 element10B => b10,
														 element11B => b11,
														 clk => clkEQU,
														 reset => resetEQU,
														 start => sumStart,
														 ready => sumReady,
														 result00 => sum00,
														 result01 => sum01,
														 result10 => sum10,
														 result11 => sum11);

	multMatrix : multiplyMatrix PORT MAP( input => input,
													  mutiplyType => multiplyType,
													  readInput => readInput,
													  clkMult => clkEQU,
													  resetMult => resetEQU,
													  startMultiply => multiplyStart,
													  output => multiplyResult,
													  readyMultiply => multiplyReady);

	-------------------------------------------
	-- READ INPUT
	-------------------------------------------
	-- TODO: Try to put it on sum state machine
	PROCESS(clkEQU, readInput)
	BEGIN
		IF rising_edge(clkEQU) AND readInput = '1' THEN
			IF resetEQU = '1' THEN
				control <= firstCopy;
				inputOne <= (OTHERS => '0');
			ELSE
				CASE control IS
					WHEN firstCopy =>
						inputOne(63 DOWNTO 16) <= input;
						control <= secondCopy;
					WHEN secondCopy =>
						inputOne(15 DOWNTO 0) <= input(47 DOWNTO 32);
						inputTwo(63 DOWNTO 32) <= input(31 DOWNTO 0);
						--inputTwo
						control <= thirdCopy;
					WHEN thirdCopy =>
						inputTwo(31 DOWNTO 0) <= input(47 DOWNTO 16);
				END CASE;
			END IF;
		END IF;
	END PROCESS;
	
	-------------------------------------------
	-- EQU STATE MACHINE
	-------------------------------------------
	PROCESS (clkEQU, readInput)
	-- TODO: Put here the input copy.
	BEGIN
		IF rising_edge(clkEQU) AND readInput = '0' THEN
			IF resetEQU = '1' THEN
				readyEQU <= '0';
				outputEQU <= (OTHERS => '0');
			ELSE
				CASE equControl IS
					WHEN waiting =>
						readyEQU <= '0';
						IF startEQU = '1' THEN
							-- MULTIPLY 3x3 AND 3x2
							IF operation = "000" THEN
								multiplyStart <= '1';
								multiplyType <= "00";
								equControl <= mult3x2;
							-- MULTIPLY 2x3 AND 3x2
							ELSIF operation = "001" THEN
								multiplyStart <= '1';
								multiplyType <= "01";
								equControl <= mult2x3;
							-- MULTIPLY 3x2 AND 2x2
							ELSIF operation = "010" THEN
								multiplyStart <= '1';
								multiplyType <= "10";
								equControl <= mult2x2;
							-- SUM
							ELSIF operation = "011" THEN
								-- State control
								equControl <= sum;
								-- Signals
								sumStart <= '1';
								-- Data path
								a00 <= inputOne(63 DOWNTO 48);
								a01 <= inputOne(47 DOWNTO 32);
								a10 <= inputOne(31 DOWNTO 16);
								a11 <= inputOne(15 DOWNTO 0);
								--inputOne 
								b00 <= inputTwo(63 DOWNTO 48);
								b01 <= inputTwo(47 DOWNTO 32);
								b10 <= inputTwo(31 DOWNTO 16);
								b11 <= inputTwo(15 DOWNTO 0);
							-- INVERSE
							ELSIF operation = "100" THEN
								equControl <= inverse;
							END IF;
						END IF;
					-------------------
					-- Multiply: 3x2 by 2x3
					-------------------
					WHEN mult3x2 =>
						readyEQU <= '0';
						multiplyStart <= '0';
						IF multiplyReady = '1' THEN
							-- Change state
							equControl <= waiting;
							-- Signals
							readyEQU <= '1';
							-- Data path
							 outputEQU <= multiplyResult;
						END IF;

					-------------------
					-- Multiply: 2x3 by 3x2
					-------------------
					WHEN mult2x3 =>
						readyEQU <= '0';
						multiplyStart <= '0';
						IF multiplyReady = '1' THEN
							-- Change state
							equControl <= waiting;
							-- Signals
							readyEQU <= '1';
							-- Data path
							outputEQU <= multiplyResult;
						END IF;
					-------------------
					-- Multiply: 3x2 by 2x2
					-------------------
					WHEN mult2x2 =>
						readyEQU <= '0';
						multiplyStart <= '0';
						IF multiplyReady = '1' THEN
							-- Change state
							equControl <= waiting;
							-- Signals
							readyEQU <= '1';
							-- Data path
							outputEQU <= multiplyResult;
						END IF;
					-------------------
					-- Sum: 2x2 by 2x2
					-------------------
					WHEN sum =>
						readyEQU <= '0';
						sumStart <= '0';
						IF sumReady = '1' THEN
							-- Change state
							equControl <= waiting;
							-- Signals
							readyEQU <= '1';
							-- Data path
							outputEQU(95 DOWNTO 80) <= sum00;
							outputEQU(79 DOWNTO 64) <= sum01;
							outputEQU(63 DOWNTO 48) <= sum10;
							outputEQU(47 DOWNTO 32) <= sum11;
							outputEQU(31 DOWNTO 0) <= (OTHERS => '0');
						END IF;
					-------------------
					-- Inverse
					-------------------
					WHEN inverse =>
						readyEQU <= '0';
				END CASE;
			END IF;
		END IF;
	END PROCESS;
	
END Behavioral;

