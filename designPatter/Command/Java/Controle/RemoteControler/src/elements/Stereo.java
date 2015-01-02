package elements;

public class Stereo 
{
	String location;
	
	public Stereo(String location)
	{
		this.location = location;
	}
	
	public void on()
	{
		System.out.println(location + ": o som foi LIGADO");
	}
	
	public void off()
	{
		System.out.println(location + ": o som foi DESLIGADO");
	}
	
	public void setCD()
	{
		System.out.println(location + ": o CD foi acionado");
	}
	
	public void setDVD()
	{
		System.out.println(location + ": o DVD foi acionadado");
	}
	
	public void setRadio()
	{
		System.out.println(location + ": o Radio foi ajustado");
	}
	
	public void setVolume(int vol)
	{
		System.out.println(location + ": O volume foi ajustado para " + vol);
	}
}
