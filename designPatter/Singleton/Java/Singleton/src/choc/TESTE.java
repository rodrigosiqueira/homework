package choc;

public class TESTE 
{
	public static void main(String[] args)
	{
		ChocolateBoiler choc1, choc2;
		choc1 = ChocolateBoiler.getInstance();
		choc2 = ChocolateBoiler.getInstance();
		choc1.boil();
		if(!choc1.getBoiled())
		{
			System.out.println("Borbulhou");
		}
		choc2.fill();
		if(!choc2.getEmpty())
		{
			System.out.println("Encheu");
		}		
	}
}
