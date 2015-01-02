package elements;

public class Light 
{
	String location;
	
	public Light(String location)
	{
		this.location = location;
	}
	
	public void on()
	{
		System.out.println(location + ": A luz foi ligada");
	}
	
	public void off()
	{
		System.out.println(location + ": A luz foi desligada");
	}
}
