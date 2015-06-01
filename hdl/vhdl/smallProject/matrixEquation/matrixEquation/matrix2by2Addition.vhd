----------------------------------------------------------------------------------
-- Company: UnB
-- Engineer: Rodrigo
-- 
-- Create Date: 09:16:04 05/29/2015 
-- Design Name: Rodrigo
-- Module Name: matrix2by2Addition - Behavioral 
-- Project Name: matrixEquation 
----------------------------------------------------------------------------------
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE work.dataTypes.ALL;

ENTITY matrix2by2Addition IS
	PORT ( element00A : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
			 element01A : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
			 element10A : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
			 element11A : IN STD_LOGIC_VECTOR (15 DOWNTO 0);

			 element00B : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
			 element01B : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
			 element10B : IN STD_LOGIC_VECTOR (15 DOWNTO 0);
			 element11B : IN STD_LOGIC_VECTOR (15 DOWNTO 0);

			 clk : IN STD_LOGIC;
			 reset : IN STD_LOGIC;
			 start : IN STD_LOGIC;
			 ready : OUT STD_LOGIC;

			 result00 : OUT STD_LOGIC_VECTOR (15 DOWNTO 0);
			 result01 : OUT STD_LOGIC_VECTOR (15 DOWNTO 0);
			 result10 : OUT STD_LOGIC_VECTOR (15 DOWNTO 0);
			 result11 : OUT STD_LOGIC_VECTOR (15 DOWNTO 0)
			);
END matrix2by2Addition;

ARCHITECTURE Behavioral OF matrix2by2Addition IS
	SIGNAL a00 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL a01 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL a10 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL a11 : STD_LOGIC_VECTOR (15 DOWNTO 0);

	SIGNAL b00 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL b01 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL b10 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL b11 : STD_LOGIC_VECTOR (15 DOWNTO 0);

	SIGNAL final00 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL final01 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL final10 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	SIGNAL final11 : STD_LOGIC_VECTOR (15 DOWNTO 0);
	
	SIGNAL readyA : STD_LOGIC;
	SIGNAL readyB : STD_LOGIC;
	SIGNAL readyC : STD_LOGIC;
	SIGNAL readyD : STD_LOGIC;

	SIGNAL startA : STD_LOGIC;
	SIGNAL startB : STD_LOGIC;
	SIGNAL startC : STD_LOGIC;
	SIGNAL startD : STD_LOGIC;

	TYPE state IS (waiting, sumElements, final);
	SIGNAL presentState : state := waiting;

BEGIN
	-- ADDER COMPONENTS.
	sumA : TopAdd PORT MAP ( resetPort => reset,
									 clkPort => clk,
									 startPort => startA,
									 aPort => a00,
									 bPort => b00,
									 outputPort => final00,
									 readyPort => readyA);

	sumB : TopAdd PORT MAP ( resetPort => reset,
									 clkPort => clk,
									 startPort => startB,
									 aPort => a01,
									 bPort => b01,
									 outputPort => final01,
									 readyPort => readyB);

	sumC : TopAdd PORT MAP ( resetPort => reset,
									 clkPort => clk,
									 startPort => startC,
									 aPort => a10,
									 bPort => b10,
									 outputPort => final10,
									 readyPort => readyC);

	sumD : TopAdd PORT MAP ( resetPort => reset,
									 clkPort => clk,
									 startPort => startD,
									 aPort => a11,
									 bPort => b11,
									 outputPort => final11,
									 readyPort => readyD);

	PROCESS (clk)
	BEGIN
		IF rising_edge (clk) THEN
			IF (reset = '1') THEN
				presentState <= waiting;
				result00 <= (OTHERS => '1');
				result01 <= (OTHERS => '1');
				result10 <= (OTHERS => '1');
				result11 <= (OTHERS => '1');
				startA <= '0';
				startB <= '0';
				startC <= '0';
				startD <= '0';
			ELSE
				CASE presentState IS
					WHEN waiting =>
						ready <= '0';
						IF start = '1' THEN
							-- Start signal
							startA <= '1';
							startB <= '1';
							startC <= '1';
							startD <= '1';
							-- Data pah
							a00 <= element00A;
							a01 <= element01A;
							a10 <= element10A;
							a11 <= element11A;
							b00 <= element00B;
							b01 <= element01B;
							b10 <= element10B;
							b11 <= element11B;
							presentState <= sumElements;
						END IF;
					WHEN sumElements =>
						startA <= '0';
						startB <= '0';
						startC <= '0';
						startD <= '0';
						ready <= '0';
						IF (readyA = '1' AND readyB = '1' AND readyC = '1' AND readyD = '1') THEN
							result00 <= final00;
							result01 <= final01;
							result10 <= final10;
							result11 <= final11;
							presentState <= final;
						END IF;
					WHEN final =>
						ready <= '1';
						presentState <= waiting;
				END CASE;
			END IF;
		END IF;
	END PROCESS;
END Behavioral;
