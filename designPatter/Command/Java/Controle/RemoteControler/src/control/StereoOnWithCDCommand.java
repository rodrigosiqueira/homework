package control;
import elements.Stereo;

public class StereoOnWithCDCommand implements Command 
{
	Stereo stereo;
	
	public StereoOnWithCDCommand(Stereo st)
	{
		this.stereo = st;
	}
	
	public void execute()
	{
		stereo.on();
		stereo.setCD();
		stereo.setVolume(20);
	}
}
