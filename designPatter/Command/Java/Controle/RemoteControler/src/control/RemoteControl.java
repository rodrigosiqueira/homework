package control;

/**
 * Temos toda a quantidade de comando necessárias salva nos atributos.
 * Repare que temos dois tipos de ações distintas, uma que lida com 
 * operações de ligar e outra com a de desligar.
 * */
public class RemoteControl 
{
	Command[] onCommands;
	Command[] offCommands;
	
	/**
	 * Repare que no construtor inicializamos todos os atributos como 
	 * objetos nulos.
	 * */
	public RemoteControl()
	{
		onCommands = new Command[7];
		offCommands = new Command[7];
		
		Command noCommand = new NoCommand();
		for(int i = 0; i < 7; i++)
		{
			onCommands[i] = noCommand;
			offCommands[i] = noCommand;
		}
	}
	
	public void setCommand(int slot, Command onCommand, Command offCommand)
	{
		this.onCommands[slot] = onCommand;
		this.offCommands[slot] = offCommand;
	}
	
	public void onButtonWasPushed(int slot)
	{
		onCommands[slot].execute();
	}
	
	public void offButtonWasPushed(int slot)
	{
		offCommands[slot].execute();
	}
}
