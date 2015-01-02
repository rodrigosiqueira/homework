
public abstract class Decorador extends VisualComponent 
{
	private VisualComponent widget;
	
	public Decorador(VisualComponent wid)
	{
		this.widget = wid;
	}
	
	public void draw()
	{
		this.widget.draw();
	}
}
