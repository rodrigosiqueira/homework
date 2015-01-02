/*Comentários: É interessante observar que esta classe ao herdar de Beverage
 * e sobreescreve o método getDescription para deixa-lo abstrato. Isto faz com 
 * que as classes filhas sejam obrigadas a implementa-lo, isto é necessário pois 
 * o método em questão precisará sofrer especificações nas subclasses. 
 * 
 * Conclusão: Defina na classe base todos os metódos que precisarão ser
 * "decorados" e na classe decorador faça com que estes fiquem abstrato.
 * Isti força que as subclasses sejam obrigados a implementar o método. 
 * */

public abstract class CodimentDecorator extends Beverage 
{
	private Beverage beverage;
	
	public abstract String getDescription();
	
	public void setBeverage(Beverage bv)
	{
		this.beverage = bv;
	}
	
	public Beverage getBeverage()
	{
		return this.beverage;
	}
}
