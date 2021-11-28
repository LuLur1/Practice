/* 20210728 할 일
 * 와이파이 연구
 */

#include <MQUnifiedsensor.h>
#include "MQ131.h"
#include <pm2008_i2c.h>
#include <C403_Steam_Air_MICS-4514_NO2.h>

#define Board ("Arduino UNO")
#define MQ9_Pin A0
#define Type ("MQ-9")
#define Voltage_Resolution 5
#define ADC_Bit_Resolution 10
#define RatioMQ9CleanAir 9.6

#define RZERO 206.85

MQUnifiedsensor MQ9(Board, Voltage_Resolution, ADC_Bit_Resolution, MQ9_Pin, Type);
MQ131 sensor(2, A1, LOW_CONCENTRATION, 10000);
SteamMICS4514 mics4514(3, A3, A2);
PM2008_I2C pm2008_i2c;

void setup() {
  Serial.begin(9600);

  /* MQ9 Code */
  MQ9.setRegressionMethod(1);
  MQ9.init();

  Serial.print("MQ-9 Sensors Calibrating please wait.");
  float calcR0 = 0;
  for(int i = 1; i<=10; i ++)
  {
    MQ9.update();
    calcR0 += MQ9.calibrate(RatioMQ9CleanAir);
    Serial.print(".");
  }
  MQ9.setR0(calcR0/10);
  Serial.print("  DONE! \n");
  
  if(isinf(calcR0)) {Serial.print("Warning: Conection issue founded, R0 is infite (Open circuit detected) please check your wiring and supply \n"); while(1);}
  if(calcR0 == 0){Serial.print("Warning: Conection issue founded, R0 is zero (Analog pin with short circuit to ground) please check your wiring and supply \n"); while(1);}

  /* MQ131 Code */
  /*
  Serial.print("MQ 131 Calibration in progress... \n");   
  sensor.calibrate();
  Serial.print("MQ 131 Calibration done! \n");
  Serial.print("R0 = ");                
  Serial.print(sensor.getR0());
  Serial.print(" Ohms \n");           
  Serial.print("Time to heat = ");
  Serial.print(sensor.getTimeToRead());
  Serial.print(" s \n");
  Serial.print("Sampling... \n");
  sensor.begin();
  */
  

  /* PM 2008 Code */
  pm2008_i2c.begin();
  pm2008_i2c.command();
  delay(1000);

  /* Mics-4514 Code */
  mics4514.begin();

  /* Result Print */
  Serial.print("|       CO       |    PM 10   |    PM 2.5   |      NO2      |      O3      | \n");  
}

void loop() {  
  /* MQ9 Code */
  MQ9.update();
  MQ9.setA(599.65); MQ9.setB(-2.244);
  float CO = MQ9.readSensor();

  /* PM2008 Code */
  uint8_t ret = pm2008_i2c.read();

  /* Mics-4514 Code */
  float no2 = analogRead(A3) / 409.2;
  float Rs_no2 = 22000 / ((5 / no2) - 1);
  float ppmNO2 = (.000008 * Rs_no2 - .0194);

  /* Result Print */
  Serial.print("|    "); Serial.print(CO); Serial.print(" ppm");
  
  if (ret == 0) {
    Serial.print("    |    "); Serial.print(pm2008_i2c.number_of_10_um); Serial.print(" ug");
    Serial.print("    |    "); Serial.print(pm2008_i2c.number_of_2p5_um); Serial.print(" ug");
  }
  
  Serial.print("    |    "); Serial.print(ppmNO2); Serial.print(" ppm");

  Serial.print("    |    "); Serial.print(sensor.getO3(PPM)); Serial.print(" ppm");
  
  /*
  Serial.print("    |    "); Serial.print(sensor.getO3(PPB)); Serial.print(" ppb");
  Serial.print("    |    "); Serial.print(sensor.getO3(MG_M3)); Serial.print(" mg/m3");
  Serial.print("    |    "); Serial.print(sensor.getO3(UG_M3)); Serial.print(" ug/m3");
  */
  
  Serial.print("    | \n");
  delay(1000);
}
