// TemperatureConverter.cpp
class TemperatureConverter {
public:
  static double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32;
  }

  static double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
  }

  static double kelvinToCelsius(double kelvin) { return kelvin - 273.15; }

  static double celsiusToKelvin(double celsius) { return celsius + 273.15; }
};
