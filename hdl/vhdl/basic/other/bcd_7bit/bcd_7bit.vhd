----------------------------------------
-- 8-bit Binary to BCD
-- By ProXcMOS
-- ProXcMOS@gmail.com
----------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity bcd_6bin is
	port( bin : in std_logic_vector(6 downto 0);
		  BCD : out std_logic_vector(7 downto 0));
end bcd_6bin;

architecture arch of bcd_6bin is

begin
 process(bin)
	variable i : NATURAL;
	variable bcd_temp : unsigned(7 downto 0);
	variable bint : std_logic_vector(6 downto 0);
	
	begin
		bint := bin;
		bcd_temp := (others => '0');
		for i in 0 to 6 loop  -- repeating 8 times.
			bcd_temp(7 downto 1) := bcd_temp(6 downto 0);  --shifting the bits.
			bcd_temp(0) := bint(6);
			bint(6 downto 1) := bint(5 downto 0);
			bint(0) :='0';

			if(i < 6 and bcd_temp(3 downto 0) > "0100") then --add 3 if bcd_temp digit is greater than 4.
			bcd_temp(3 downto 0) := bcd_temp(3 downto 0) + "0011";
			end if;

			if(i < 6 and bcd_temp(7 downto 4) > "0100") then --add 3 if bcd_temp digit is greater than 4.
			bcd_temp(7 downto 4) := bcd_temp(7 downto 4) + "0011";
			end if;

		end loop;
		BCD <= std_logic_vector(bcd_temp);
 end process;
end arch;

