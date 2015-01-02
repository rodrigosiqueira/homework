package codigo;

import java.util.ArrayList;

public abstract class Pizza 
{
	protected String name, dough, sauce;
	protected ArrayList<String> topping = new ArrayList();
	
	public void prepare()
	{
		System.out.println("Preparando" + name);
		System.out.println("Amassando a Massa...");
		System.out.println("Adicionando o tempero...");
		System.out.println("Adicionando o topo: ");
		for(int i = 0; i < topping.size(); i++)
			System.out.println("   " + topping.get(i));
	}
	
	public void bake()
	{
		System.out.println("Assar por 25 minutos a 350");
	}
	
	public void cut()
	{
		System.out.println("Corte a pizza em pedaços diagonais");
	}
	
	public void box()
	{
		System.out.println("Coloque a pizza em uma caixa oficial da PizzaStore");
	}
	
	public String getName()
	{
		return name;
	}
}
