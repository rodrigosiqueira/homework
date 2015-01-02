package control;
import elements.*;

public class TESTE 
{
	public static void main(String[] args)
	{
		RemoteControl remote = new RemoteControl();
		
		Light lt = new Light("Cozinha");
		Stereo st = new Stereo("Quarto");
		
		LightOnCommand lightOnCommand = new LightOnCommand(lt);
		LightOffCommand lightOffCommand = new LightOffCommand(lt);
		
		StereoOnWithCDCommand stereoOnWithCDCommand = new StereoOnWithCDCommand(st);
		StereoOffCommand stereoOffCommand = new StereoOffCommand(st);
		
		remote.setCommand(0, lightOnCommand, lightOffCommand);
		remote.setCommand(1, stereoOnWithCDCommand, stereoOffCommand);
		
		System.out.println("Começando a brincar com o controle...");
		
		remote.onButtonWasPushed(0);
		remote.onButtonWasPushed(1);
		
		System.out.println("Desligando...");
		
		remote.offButtonWasPushed(0);
		remote.offButtonWasPushed(1);
		
	}
}
