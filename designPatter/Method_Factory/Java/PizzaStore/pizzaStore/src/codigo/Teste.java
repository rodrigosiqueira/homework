package codigo;

public class Teste 
{
	public static void main(String[] args) 
	{
		PizzaStore nystore = new NYPizzaStore();
		PizzaStore chstore = new ChicagoPizzaStore();
		
		nystore.orderPizza("cheese");
		System.out.println("------------------------------");
		chstore.orderPizza("cheese");
	}
}
