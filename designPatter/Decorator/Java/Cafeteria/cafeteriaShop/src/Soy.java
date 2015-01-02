
public class Soy extends CodimentDecorator 
{
	public Soy(Beverage bev)
	{
		this.setBeverage(bev);
	}
	
	public String getDescription()
	{
		return this.getBeverage().getDescription() + ", com Soy";
	}
	
	public double cost()
	{
		return this.getBeverage().cost() + 1.7;
	}
}
