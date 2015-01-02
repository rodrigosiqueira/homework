
public class CurrentConditionDisplay implements Observer, DisplayElement 
{	
	private float humidity, temperature, pressure;
	private Subject weatherData;
	
	public CurrentConditionDisplay(Subject w)
	{
		this.weatherData = w;
		weatherData.registerObserver(this);
	}
	
	public void update(float tmp, float hum, float pres)
	{
		this.temperature = tmp;
		this.humidity = hum;
		this.pressure = pres;
		display();
	}
	
	public void display()
	{
		System.out.println("Temperatura atual: " + this.temperature +
				"F graus e " + this.humidity + "% humidade");
	}
}
