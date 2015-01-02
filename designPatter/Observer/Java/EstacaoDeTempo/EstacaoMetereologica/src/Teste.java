
public class Teste 
{
	public static void main(String[] args)
	{
		WeatherData weather = new WeatherData();
		CurrentConditionDisplay c = new CurrentConditionDisplay(weather);
		
		weather.setMeasurement(23, 234, 34);
		weather.setMeasurement(45, 345, 54);
	}
}
