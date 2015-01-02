
public class BorderDecorator extends Decorador 
{
	public BorderDecorator(VisualComponent w)
	{
		super(w);
	}
	
	public void draw()
	{
		super.draw();
		System.out.print(" ,agora estou com BORDA!!!");
	}
}
