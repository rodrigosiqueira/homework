import java.util.ArrayList;


public class WeatherData implements Subject 
{
	private ArrayList<Observer> observers;
	private float humidity, temperature, pressure;
	
	public WeatherData()
	{
		this.observers = new ArrayList();
	}
	
	public void setMeasurement(float tmp, float hum, float pres)
	{
		this.temperature = tmp;
		this.humidity = hum;
		this.pressure = pres;
		this.notifyObserver();
	}
	
	public void registerObserver(Observer obs) 
	{
		observers.add(obs);
	}
	
	public void removeObserver(Observer obs) 
	{
		int i = observers.indexOf(obs);
		if(i > 0)
			observers.remove(i);
	}
	
	public void notifyObserver()
	{
		Observer obs;
		for(int i = 0; i < observers.size(); i++)
		{
			obs = (Observer)observers.get(i);
			obs.update(temperature, humidity, pressure);
		}
	}
	
	public float getTemperature()
	{
		return this.temperature;
	}
	
	public float getHumidity()
	{
		return this.humidity;
	}
	
	public float getPressure()
	{
		return this.pressure;
	}
	
}
