#include <dht_nonblocking.h>
#include <LiquidCrystal.h>

#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 12, 11, 10, 9);


void setup( )
{
  Serial.begin( 9600);
  lcd.begin(16, 2);
  lcd.print("Welcome");
}


static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if( millis( ) - measurement_timestamp > 6000ul )
  {
    if( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      
      return( true );
    }
  }

  return( false );
}

  
void loop( )
{
  float temperature;
  float humidity;
  
  if( measure_environment( &temperature, &humidity ) == true )
  {
    lcd.clear();
    lcd.print("Temprature and ");
    lcd.setCursor(0, 1);
    lcd.print("Humidity Monitor");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print( "T = " );
    lcd.print( temperature, 1 );
    lcd.print( " deg. C" );
    lcd.setCursor(0, 1);
    lcd.print( "H = " );
    lcd.print( humidity, 1 );
    lcd.print( "%" );
  }
}
