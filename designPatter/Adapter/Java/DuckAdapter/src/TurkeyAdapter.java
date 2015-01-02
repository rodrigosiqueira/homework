
public class TurkeyAdapter implements Duck 
{
	Turkey turkey;
	
	public TurkeyAdapter(Turkey tur)
	{
		this.turkey = tur;
	}
	
	public void quack()
	{
		this.turkey.gobble();
	}
	
	public void fly()
	{
		this.turkey.fly();
	}
}
