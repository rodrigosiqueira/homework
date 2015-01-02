package codigo;

public class ChicagoStyleCheesePizza extends Pizza
{
	public ChicagoStyleCheesePizza()
	{
		name  = "Pizza de queijo no estilo de Chicago - Muito queijo";
		dough = "Massa grossa";
		sauce = "Molho de tomate";
		
		topping.add("Queijo extra de muzzarella");
	}
	
	public void cut()
	{
		System.out.println("Corte a pizza em formatos quadrados");
	}
}
