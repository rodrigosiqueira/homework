package control;
import elements.Stereo;

public class StereoOffCommand implements Command 
{
	Stereo stereo;
	
	public StereoOffCommand(Stereo st)
	{
		this.stereo = st;
	}
	
	public void execute()
	{
		stereo.off();
	}
}
