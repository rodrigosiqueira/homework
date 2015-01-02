package control;
import elements.Light;

public class LightOffCommand implements Command 
{
	Light light;
	
	public LightOffCommand(Light lg)
	{
		this.light = lg; 
	}
	
	public void execute()
	{
		light.off();
	}
}
