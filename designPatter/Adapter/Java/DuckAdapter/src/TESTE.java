
public class TESTE 
{
	public static void main(String[] args)
	{
		MallardDuck duck = new MallardDuck();
		
		WildTurkey turkey = new WildTurkey();
		TurkeyAdapter xpto = new TurkeyAdapter(turkey);
		
		System.out.println("O peru...");
		turkey.gobble();
		turkey.fly();
		
		System.out.println("O pato...");
		testDuck(duck);
		
		System.out.println("O Adaptador...");
		testDuck(xpto);
		
	}
	
	public static void testDuck(Duck dk)
	{
		dk.quack();
		dk.fly();
	}
}
