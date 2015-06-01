----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo Siqueira de Melo
-- 
-- Create Date: 13:52:43 05/27/2015 
-- Design Name: Matrix Multiplication
-- Module Name: lineColumnOperation - Behavioral 
-- Project Name: Matrix equation 
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE work.dataTypes.ALL;

ENTITY lineColumnOperation IS
	PORT (lineElement1 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
			lineElement2 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
			lineElement3 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
			columnElement1 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
			columnElement2 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
			columnElement3 : IN STD_LOGIC_VECTOR(15 DOWNTO 0);
			startPort : IN STD_LOGIC;
			resetPort : IN STD_LOGIC;
			clk : IN STD_LOGIC;
			resultPort : OUT STD_LOGIC_VECTOR(15 DOWNTO 0);
			readyPort : OUT STD_LOGIC);
END lineColumnOperation;

ARCHITECTURE Behavioral OF lineColumnOperation IS

	TYPE state IS (waiting, twoMultiplication, multiplicationSum, finalSum);
	SIGNAL presentState : state;

	SIGNAL elementLine1 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL elementColumn1 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL resultMultOne : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL readyMultiplyOne : STD_LOGIC;
	SIGNAL startMultiplyOne : STD_LOGIC;

	SIGNAL elementLine2 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL elementColumn2 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL resultMultTwo : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL readyMultiplyTwo : STD_LOGIC;
	SIGNAL startMultiplyTwo : STD_LOGIC;
	
	SIGNAL sumA : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL sumB : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL resultSum : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL startAdd : STD_LOGIC;
	SIGNAL readyAdd : STD_LOGIC;

BEGIN

	-- Component instance
	multiplierOne : TopMultiplier PORT MAP (	reset => resetPort,
															clk => clk,
															aPort => elementLine1,
															bPort => elementColumn1,
															startPort => startMultiplyOne,
															outputPort => resultMultOne,
															readyPort => readyMultiplyOne
														);

	multiplierTwo : TopMultiplier PORT MAP (	reset => resetPort,
															clk => clk,
															aPort => elementLine2,
															bPort => elementColumn2,
															startPort => startMultiplyTwo,
															outputPort => resultMultTwo,
															readyPort => readyMultiplyTwo
														);

	adder : TopAdd PORT MAP (	resetPort => resetPort,
											clkPort => clk,
											startPort => startAdd,
											aPort => sumA,
											bPort => sumB,
											outputPort => resultSum,
											readyPort => readyAdd
										);


-------------------- STATE MACHINE -----------------------------
	PROCESS(clk, resetPort) 
	BEGIN
		IF rising_edge(clk) THEN
			IF resetPort = '1' THEN
				presentState <= waiting;
				readyPort <= '0';
				resultPort <= (OTHERS => '0');
			ELSE
				CASE presentState IS
					WHEN waiting =>
						readyPort <= '0';
						IF startPort = '1' THEN
							-- Operation signals
							startMultiplyOne <= '1';
							startMultiplyTwo <= '1';
							startAdd <= '0';
							-- Input
							elementLine1 <= lineElement1;
							elementLine2 <= lineElement2;
							elementColumn1 <= columnElement1;
							elementColumn2 <= columnElement2;
							-- Next state
							presentState <= twoMultiplication;
						END IF;

					WHEN twoMultiplication =>
						startMultiplyOne <= '0';
						startMultiplyTwo <= '0';
						-- In the case of end multiplication
						IF readyMultiplyOne = '1' AND readyMultiplyTwo = '1' THEN
							-- Operation signals
							startMultiplyOne <= '1';
							startAdd <= '1';
							-- Input
							sumA <= resultMultOne;
							sumB <= resultMultTwo;
							elementLine1 <= lineElement3;
							elementColumn1 <= columnElement3;
							-- Next state
							presentState <= multiplicationSum;
						ELSE
							presentState <= twoMultiplication;
						END IF;

					WHEN multiplicationSum =>
						startMultiplyOne <= '0';
						startAdd <= '0';
						IF readyMultiplyOne = '1' AND readyAdd = '1' THEN
							-- Operations signals
							startAdd <= '1';
							-- Input
							sumA <= resultSum;
							sumB <= resultMultOne;
							-- Next state
							presentState <= finalSum;
						ELSE
							presentState <= multiplicationSum;
						END IF;

					WHEN finalSum =>
						startAdd <= '0';
						IF readyAdd = '1' THEN
							-- Operations signal
							readyPort <= '1';
							-- Output
							resultPort <= resultSum;
							--Next state
							presentState <= waiting;
						ELSE
							presentState <= finalSum;
						END IF;
				END CASE;
			END IF;
		END IF;
	END PROCESS stateMachine;

END Behavioral;
