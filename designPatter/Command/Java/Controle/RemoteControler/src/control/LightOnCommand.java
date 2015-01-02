package control;
import elements.Light;

public class LightOnCommand implements Command 
{
	Light light;
	
	public LightOnCommand(Light lg)
	{
		this.light = lg;
	}
	
	public void execute()
	{
		light.on();
	}
}
