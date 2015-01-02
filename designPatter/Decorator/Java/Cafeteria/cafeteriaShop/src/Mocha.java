
public class Mocha extends CodimentDecorator 
{
	public Mocha(Beverage bev)
	{
		this.setBeverage(bev);
	}
	
	public String getDescription()
	{
		return this.getBeverage().getDescription() + ", com Mocha";
	}
	
	public double cost()
	{
		return this.getBeverage().cost() + 0.7;
	}
}
