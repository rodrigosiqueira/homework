package choc;

public class ChocolateBoiler 
{
	private boolean empty;
	private boolean boiled;
	public static ChocolateBoiler unique;
	
	private ChocolateBoiler()
	{
		empty = true;
		boiled = false;
	}
	
	public void fill()
	{
		if(isEmpty())
		{
			empty = false;
			boiled = false;
		}
	}
	
	public void drain()
	{
		if(!isEmpty() && isBoiled())
		{
			empty = true;
		}
	}
	
	public void boil()
	{
		if(!isEmpty() && !isBoiled())
			boiled = true;
	}
	
	public boolean isEmpty()
	{
		return empty;
	}
	
	public boolean isBoiled()
	{
		return boiled;
	}
	
	public boolean getEmpty()
	{
		return this.empty;
	}
	
	public boolean getBoiled()
	{
		return this.boiled;
	}
	
	public static ChocolateBoiler getInstance()
	{
		if(unique == null)
			unique = new ChocolateBoiler();
		return unique;
	}
}
