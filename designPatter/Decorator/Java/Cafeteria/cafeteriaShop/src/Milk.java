
public class Milk extends CodimentDecorator 
{
	public Milk(Beverage bev)
	{
		this.setBeverage(bev);
	}
	
	public String getDescription()
	{
		return this.getBeverage().getDescription() + ", com leite incluso ";
	}
	
	public double cost()
	{
		return this.getBeverage().cost() + 0.50;
	}
}
