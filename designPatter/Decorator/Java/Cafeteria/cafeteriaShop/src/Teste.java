
public class Teste 
{
	public static void main(String[] args) 
	{
		Beverage expresso = new Expresso();
		System.out.println(expresso.getDescription());
		System.out.println(expresso.cost());
		
		Beverage milk = new Milk(expresso);
		System.out.println(milk.getDescription());
		System.out.println(milk.cost());
		
		Beverage mocha = new Mocha(milk);
		System.out.println(mocha.getDescription());
		System.out.println(mocha.cost());
		
	}
}
