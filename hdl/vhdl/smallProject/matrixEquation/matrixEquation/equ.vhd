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
	PORT (inputOne : IN STD_LOGIC_VECTOR (143 DOWNTO 0); -- 144 bits
			inputTwo : IN STD_LOGIC_VECTOR (95 DOWNTO 0); -- 96 bits
			operation : IN STD_LOGIC_VECTOR (2 DOWNTO 0); -- 3 bits
			outputEQU : OUT STD_LOGIC_VECTOR (95 DOWNTO 0);
			clkEQU : IN STD_LOGIC;
			resetEQU : IN STD_LOGIC;
			readyEQU : OUT STD_LOGIC
			); -- 96 bits
END equ;

ARCHITECTURE Behavioral OF equ IS

	-- ========== MATRIX SIGNALS ===========
	
	SIGNAL line00 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL line01 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL line02 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL line10 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL line11 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL line12 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL line20 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL line21 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL line22 : STD_LOGIC_VECTOR (15 DOWNTO 0);

	SIGNAL column00 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL column01 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL column10 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL column11 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL column20 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL column21 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	
	SIGNAL sumA00 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL sumA01 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL sumA10 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL sumA11 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL sumB00 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL sumB01 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL sumB10 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL sumB11 : STD_LOGIC_VECTOR (15 DOWNTO 0);

	SIGNAL sumResult00 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL sumResult01 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL sumResult10 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL sumResult11 : STD_LOGIC_VECTOR(15 DOWNTO 0);

	SIGNAL result00 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL result01 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL result10 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL result11 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL result20 : STD_LOGIC_VECTOR(15 DOWNTO 0);
	SIGNAL result21 : STD_LOGIC_VECTOR(15 DOWNTO 0);

	-- Control signals
	SIGNAL start1 : STD_LOGIC;
	SIGNAL ready1 : STD_LOGIC;
	
	SIGNAL start2 : STD_LOGIC;
	SIGNAL ready2 : STD_LOGIC;
	
	SIGNAL start3 : STD_LOGIC;
	SIGNAL ready3 : STD_LOGIC;

	SIGNAL start4 : STD_LOGIC;
	SIGNAL ready4 : STD_LOGIC;
	
	SIGNAL start5 : STD_LOGIC;
	SIGNAL ready5 : STD_LOGIC;

	SIGNAL start6 : STD_LOGIC;
	SIGNAL ready6 : STD_LOGIC;
	
	SIGNAL startSum : STD_LOGIC;
	SIGNAL readySum : STD_LOGIC;
	
	-- State
	TYPE state IS (waiting, mult3x2, mult2x3, mult2x2, sum, inverse);
	SIGNAL currentState : state;
BEGIN

	multBlock1 : lineColumnOperation PORT MAP (lineElement1 => line00,
															 lineElement2 => line01,
															 lineElement3 => line02,
															 columnElement1 => column00,
															 columnElement2 => column10,
															 columnElement3 => column20,
															 startPort => start1,
															 resetPort => resetEQU,
															 clk => clkEQU,
															 resultPort => result00,
															 readyPort => ready1);
																 
	multBlock2 : lineColumnOperation PORT MAP (lineElement1 => line00,
															 lineElement2 => line01,
															 lineElement3 => line02,
															 columnElement1 => column01,
															 columnElement2 => column11,
															 columnElement3 => column21,
															 startPort => start2,
															 resetPort => resetEQU,
															 clk => clkEQU,
															 resultPort => result01,
															 readyPort => ready2);
															 
	multBlock3 : lineColumnOperation PORT MAP (lineElement1 => line10,
															 lineElement2 => line11,
															 lineElement3 => line12,
															 columnElement1 => column00,
															 columnElement2 => column10,
															 columnElement3 => column20,
															 startPort => start3,
															 resetPort => resetEQU,
															 clk => clkEQU,
															 resultPort => result10,
															 readyPort => ready3);

	multBlock4 : lineColumnOperation PORT MAP (lineElement1 => line10,
															 lineElement2 => line11,
															 lineElement3 => line12,
															 columnElement1 => column01,
															 columnElement2 => column11,
															 columnElement3 => column21,
															 startPort => start4,
															 resetPort => resetEQU,
															 clk => clkEQU,
															 resultPort => result11,
															 readyPort => ready4);
															 
	multBlock5 : lineColumnOperation PORT MAP (lineElement1 => line20,
															 lineElement2 => line21,
															 lineElement3 => line22,
															 columnElement1 => column00,
															 columnElement2 => column10,
															 columnElement3 => column20,
															 startPort => start5,
															 resetPort => resetEQU,
															 clk => clkEQU,
															 resultPort => result20,
															 readyPort => ready5);

	multBlock6 : lineColumnOperation PORT MAP (lineElement1 => line20,
															 lineElement2 => line21,
															 lineElement3 => line22,
															 columnElement1 => column01,
															 columnElement2 => column11,
															 columnElement3 => column21,
															 startPort => start6,
															 resetPort => resetEQU,
															 clk => clkEQU,
															 resultPort => result21,
															 readyPort => ready6);

	adderMatrix : matrix2by2Addition PORT MAP(element00A => sumA00,
															element01A => sumA01,
															element10A => sumA10,
															element11A => sumA11,
															element00B => sumB00,
															element01B => sumB01,
															element10B => sumB10,
															element11B => sumB11,
															clk => clkEQU,
															reset => resetEQU,
															start => startSum,
															ready => readySum,
															result00 => sumResult00,
															result01 => sumResult01,
															result10 => sumResult10,
															result11 => sumResult11);

	PROCESS (clkEQU)
	BEGIN
		IF rising_edge(clkEQU) THEN
			IF resetEQU = '1' THEN
				readyEQU <= '0';
				outputEQU <= (OTHERS => '0');
			ELSE
				CASE currentState IS
					WHEN waiting =>
						IF operation = "000" THEN
							-- Change state
							currentState <= mult3x2;
							-- Start lineColumnOperations: 6
							start1 <= '1';
							start2 <= '1';
							start3 <= '1';
							start4 <= '1';
							start5 <= '1';
							start6 <= '1';
							-- Data path
							line00 <= inputOne(143 DOWNTO 128);
							line01 <= inputOne(127 DOWNTO 112);
							line02 <= inputOne(111 DOWNTO 96);
							line10 <= inputOne(95 DOWNTO 80);
							line11 <= inputOne(79 DOWNTO 64);
							line12 <= inputOne(63 DOWNTO 48);
							line20 <= inputOne(47 DOWNTO 32);
							line21 <= inputOne(31 DOWNTO 16);
							line22 <= inputOne(15 DOWNTO 0);
							column00 <= inputTwo(95 DOWNTO 80);
							column01 <= inputTwo(79 DOWNTO 64);
							column10 <= inputTwo(63 DOWNTO 48);
							column11 <= inputTwo(47 DOWNTO 32);
							column20 <= inputTwo(31 DOWNTO 16);
							column21 <= inputTwo(15 DOWNTO 0);
						ELSIF operation = "001" THEN
							-- Change state
							currentState <= mult2x3;
							-- Start lineColumnOperation: only 4
							start1 <= '1';
							start2 <= '1';
							start3 <= '1';
							start4 <= '1';
							-- Data path
							line00 <= inputOne(143 DOWNTO 128);
							line01 <= inputOne(127 DOWNTO 112);
							line02 <= inputOne(111 DOWNTO 96);
							line10 <= inputOne(95 DOWNTO 80);
							line11 <= inputOne(79 DOWNTO 64);
							line12 <= inputOne(63 DOWNTO 48);
							column00 <= inputTwo(95 DOWNTO 80);
							column01 <= inputTwo(79 DOWNTO 64);
							column10 <= inputTwo(63 DOWNTO 48);
							column11 <= inputTwo(47 DOWNTO 32);
							column20 <= inputTwo(31 DOWNTO 16);
							column21 <= inputTwo(15 DOWNTO 0);
						ELSIF operation = "010" THEN
							-- Change state
							currentState <= mult2x2;
							-- Start lineColumnOperation: only 4
							start1 <= '1';
							start2 <= '1';
							start3 <= '1';
							start4 <= '1';
							-- Data path
							line00 <= inputOne(143 DOWNTO 128);
							line01 <= inputOne(127 DOWNTO 112);
							line02 <= inputOne(111 DOWNTO 96);
							line10 <= inputOne(95 DOWNTO 80);
							line11 <= inputOne(79 DOWNTO 64);
							line12 <= inputOne(63 DOWNTO 48);
							column00 <= inputTwo(95 DOWNTO 80);
							column01 <= inputTwo(79 DOWNTO 64);
							column10 <= inputTwo(63 DOWNTO 48);
							column11 <= inputTwo(47 DOWNTO 32);
						ELSIF operation = "011" THEN
							-- Change state
							currentState <= sum;
							-- Start lineColumnOperation: only 4
							startSum <= '1';
							-- Data path
							sumA00 <= inputOne(143 DOWNTO 128);
							sumA01 <= inputOne(127 DOWNTO 112);
							sumA10 <= inputOne(111 DOWNTO 96);
							sumA11 <= inputOne(95 DOWNTO 80);
							sumB00 <= inputTwo(95 DOWNTO 80);
							sumB01 <= inputTwo(79 DOWNTO 64);
							sumB10 <= inputTwo(63 DOWNTO 48);
							sumB11 <= inputTwo(47 DOWNTO 32);
						ELSIF operation = "100" THEN
							-- Change State
							currentState <= inverse;
						ELSE
							-- Change state
							currentState <= waiting;
						END IF;

					-- Multiplication between 3x3 and 3x2
					WHEN mult3x2 =>
						start1 <= '0';
						start2 <= '0';
						start3 <= '0';
						start4 <= '0';
						start5 <= '0';
						start6 <= '0';
						IF ready1 = '1' AND ready2 = '1' AND ready3 = '1' AND 
							ready4 = '1' AND ready5 = '1' AND ready6 = '1' THEN
							readyEQU <= '1';
							-- TODO: SAVE THE RESULT IN A BUFFER
							currentState <= waiting;
						END IF;
						
					-- Multiplication between 2x3 and 3x2
					WHEN mult2x3 =>
						IF ready1 = '1' AND ready2 = '1' AND ready3 = '1' AND ready4 = '1' THEN
							readyEQU <= '1';
							outputEQU(95 DOWNTO 80) <= "0000000000000000";
							outputEQU(79 DOWNTO 64) <= "0000000000000000";
							outputEQU(63 DOWNTO 48) <= result00;
							outputEQU(47 DOWNTO 32) <= result01;
							outputEQU(31 DOWNTO 16) <= result10;
							outputEQU(15 DOWNTO 0) <= result11;
							currentState <= waiting;
						END IF;
					
					-- Multiplication between 3x2 and 2x2
					WHEN mult2x2 =>
						IF ready1 = '1' AND ready2 = '1' AND ready3 = '1' AND ready4 = '1' THEN
							readyEQU <= '1';
							outputEQU(95 DOWNTO 80) <= result00;
							outputEQU(79 DOWNTO 64) <= result01;
							outputEQU(63 DOWNTO 48) <= result10;
							outputEQU(47 DOWNTO 32) <= result11;
							outputEQU(31 DOWNTO 16) <= result20;
							outputEQU(15 DOWNTO 0) <= result21;
							currentState <= waiting;
						END IF;

					-- Sum of two matrix 2x2.
					WHEN sum =>
						IF readySum = '1' THEN
							readyEQU <= '1';
							outputEQU(95 DOWNTO 80) <= sumResult00;
							outputEQU(79 DOWNTO 64) <= sumResult01;
							outputEQU(63 DOWNTO 48) <= sumResult10;
							outputEQU(47 DOWNTO 32) <= sumResult11;
							outputEQU(31 DOWNTO 0)<= (OTHERS => '0');
							currentState <= waiting;
						END IF;

					-- Inverse the matrix 2x2.
					WHEN inverse =>
						currentState <= waiting;
				END CASE;
			END IF;
		END IF;
			
	END PROCESS;
END Behavioral;

