
public class ScrollDecorator extends Decorador 
{
	public ScrollDecorator(VisualComponent w)
	{
		super(w);
	}
	
	public void draw()
	{
		super.draw();
		System.out.print(" ,agora estou scroll!!");
	}
}
