
public abstract class Beverage 
{
	private String description = "Nenhuma descrição conhecida";
	
	public String getDescription()
	{
		return this.description;
	}
	
	public abstract double cost();
	
	public void setDescription(String ds)
	{
		this.description = ds;
	}
}
