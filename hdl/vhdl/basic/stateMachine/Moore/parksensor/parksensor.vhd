
LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.ALL;
USE ieee.std_logic_arith.ALL;

ENTITY parksensor IS
	PORT (sensor_1, sensor_2, clk, rst: IN STD_LOGIC;
			vacancy: OUT STD_LOGIC_VECTOR(3 DOWNTO 0));
END parksensor;

ARCHITECTURE Behavioral OF parksensor IS
	TYPE state IS (idle, startEnter, middleEnter, almostEnter, parked,
						startLeave, middleLeave, almostLeave, left);
	SIGNAL previousState, nextState: state;
	--SIGNAL countVacancy: SIGNED(3 DOWNTO 0) := "0011";
BEGIN
---------------- LOWER PART --------------------------------------------------
	PROCESS (rst, clk)
	BEGIN
		IF (rst = '1') THEN
			previousState <= idle;
		ELSIF (clk'EVENT AND clk = '1') THEN
			previousState <= nextState;
		END IF;
	END PROCESS;
-----------------UPPER PART --------------------------------------------------
	PROCESS (sensor_1, sensor_2, previousState)
	BEGIN
		CASE previousState IS
			WHEN idle =>
				vacancy <= "0001";
				-- Enter
				IF (sensor_1 = '1') THEN
					nextState <= startEnter;
				-- LEAVE
				ELSIF (sensor_2 = '1') THEN
					nextState <= startLeave;
				END IF;
			WHEN startEnter =>
				vacancy <= "0010";
				IF (sensor_2 = '1') THEN
					nextState <= middleEnter;
				ELSIF (sensor_1 = '0') THEN
					nextState <= idle;
				ELSIF (sensor_1 = '1') THEN
					nextState <= startEnter;
				END IF;
			WHEN middleEnter =>
				vacancy <= "0011";
				IF (sensor_2 = '0') THEN
					nextState <= startEnter;
				ELSIF (sensor_2 = '1') THEN
					nextState <= middleEnter;
				ELSIF (sensor_1 = '0') THEN
					nextState <= almostEnter;
				END IF;
			WHEN almostEnter =>
				vacancy <= "0100";
				IF (sensor_1 = '1') THEN
					nextState <= middleEnter;
				ELSIF (sensor_2 = '1') THEN
					nextState <= almostEnter;
				ELSIF (sensor_2 = '0') THEN
					nextState <= parked;
				END IF;
			WHEN parked =>
				vacancy <= "0101";
				--countVacancy <= count;
				nextState <= idle;
			WHEN startLeave =>
				vacancy <= "0110";
				IF (sensor_2 = '0') THEN
					nextState <= idle;
				ELSIF (sensor_1 = '1') THEN
					nextState <= middleLeave;
				END IF;
			WHEN middleLeave =>
				vacancy <= "0110";
				IF (sensor_1 = '0') THEN
					nextState <= startLeave;
				ELSIF (sensor_1 = '1') THEN
					nextState <= middleLeave;
				ELSIF (sensor_2 = '0') THEN
					nextState <= almostLeave;
				END IF;
			WHEN almostLeave =>
				vacancy <= "0111";
				IF (sensor_2 = '1') THEN
					nextState <= middleLeave;
				ELSIF (sensor_1 = '0') THEN
					nextState <= left;
				END IF;
			WHEN left =>
				vacancy <= "1000";
				--vacancy <= "1010";
				nextState <= idle;
		END CASE;
	END PROCESS;
END Behavioral;

