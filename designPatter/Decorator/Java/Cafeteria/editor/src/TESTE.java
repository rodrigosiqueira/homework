
public class TESTE 
{
	public static void main(String[] args) 
	{
		VisualComponent text = new TextView();
		text.draw();
		System.out.println("");
		VisualComponent scroll = new ScrollDecorator(text);
		scroll.draw();
		System.out.println("");
		VisualComponent border = new BorderDecorator(scroll);
		border.draw();
		System.out.println("");
	}
}
