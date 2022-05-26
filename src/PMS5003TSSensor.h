

#ifndef PMS5003TSSensor_h
#define PMS5003TSSensor_h
#include <Arduino.h>
#include <HardwareSerial.h>

#define PM_Buffer_LEN 39
#define PM_START_CHAR1 0x42
#define PM_START_CHAR2 0x4d
#define FRAME_LENGTH_H 1
#define FRAME_LENGTH_L 2
#define PM_DATA1_H 3    // PM1.0 concentration
#define PM_DATA1_L 4
#define PM_DATA2_H 5    // PM2.5 concentration
#define PM_DATA2_L 6
#define PM_DATA3_H 7    // PM10 concentration
#define PM_DATA3_L 8
#define PM_DATA4_H 9
#define PM_DATA4_L 10
#define PM_DATA5_H 11
#define PM_DATA5_L 12
#define PM_DATA6_H 13
#define PM_DATA6_L 14
#define PM_DATA7_H 15   // Particles beyond 0.3 um in 0.1L of air
#define PM_DATA7_L 16
#define PM_DATA8_H 17   // Particles beyond 0.5 um in 0.1L of air
#define PM_DATA8_L 18
#define PM_DATA9_H 19   // Particles beyond 1.0 um in 0.1L of air
#define PM_DATA9_L 20
#define PM_DATA10_H 21  // Particles beyond 2.5 um in 0.1L of air
#define PM_DATA10_L 22
#define PM_DATA11_H 23  // Particles beyond 5.0 um in 0.1L of air
#define PM_DATA11_L 24
#define PM_DATA12_H 25  // Particles beyond 10 um in 0.1L of air
#define PM_DATA12_L 26
#define PM_DATA13_H 27  // Formaldehyde Concentration
#define PM_DATA13_L 28
#define PM_DATA14_H 29  // Temperature
#define PM_DATA14_L 30
#define PM_DATA15_H 31  // Humidity
#define PM_DATA15_L 32
#define PM_DATA16_H 33  // Reserved
#define PM_DATA16_L 34
#define PM_DATA17_H 35  // Firmware version
#define PM_DATA17_L 36  // Error code

class PMS5003TSSensor
{
private:
    Stream* _serial;
    unsigned char pmBuffer[PM_Buffer_LEN];
    uint16_t cPM1_0=0;
    uint16_t cPM2_5=0;
    uint16_t cPM10_0=0;
    uint16_t numPartBeyond0_3=0;
    uint16_t numPartBeyond0_5=0;
    uint16_t numPartBeyond1_0=0;
    uint16_t numPartBeyond2_5=0;
    uint16_t numPartBeyond5_0=0;
    uint16_t numPartBeyond10_0=0;
    uint16_t formaldehyde=0;
    int16_t temperature=0;
    uint16_t humidity=0;
    bool checkData();

public:
    HKA5_PMSensor(Stream &serial);
    void begin();
    uint16_t getConcentrationPM1_0();
    uint16_t getConcentrationPM2_5();
    uint16_t getConcentrationPM10_0();
    uint16_t getNumberPariticlesBeyond0_3();
    uint16_t getNumberPariticlesBeyond0_5();
    uint16_t getNumberPariticlesBeyond1_0();
    uint16_t getNumberPariticlesBeyond2_5();
    uint16_t getNumberPariticlesBeyond5_0();
    uint16_t getNumberPariticlesBeyond10_0();
    float getFormaldehyde();
    float getTemperature();
    float getHumidity();
    bool readData();
};
#endif
