

#ifndef PMS5003TSSensor_h
#define PMS5003TSSensor_h
#include <Arduino.h>
#include <HardwareSerial.h>

#define PM_Buffer_LEN 39
#define PM_START_CHAR1 0x42
#define PM_START_CHAR2 0x4d
#define FRAME_LENGTH_H 1
#define FRAME_LENGTH_L 2
#define PM_DATA1_H 3
#define PM_DATA1_L 4
#define PM_DATA2_H 5
#define PM_DATA2_L 6
#define PM_DATA3_H 7
#define PM_DATA3_L 8
#define PM_DATA4_H 9
#define PM_DATA4_L 10
#define PM_DATA5_H 11
#define PM_DATA5_L 12
#define PM_DATA6_H 13
#define PM_DATA6_L 14
#define PM_DATA7_H 15
#define PM_DATA7_L 16
#define PM_DATA8_H 17
#define PM_DATA8_L 18
#define PM_DATA9_H 19
#define PM_DATA9_L 20
#define PM_DATA10_H 21
#define PM_DATA10_L 22
#define PM_DATA11_H 23
#define PM_DATA11_L 24
#define PM_DATA12_H 25
#define PM_DATA12_L 26
#define PM_DATA13_H 27
#define PM_DATA13_L 28
#define PM_DATA14_H 29
#define PM_DATA14_L 30
#define PM_DATA15_H 31
#define PM_DATA15_L 32
#define PM_DATA16_H 33
#define PM_DATA16_L 34
#define PM_DATA17_H 35
#define PM_DATA17_L 36

class PMS5003TSSensor
{
private:
    Stream* _serial;
    unsigned char pmBuffer[PM_Buffer_LEN];
    uint16_t cPM1_0=0;
    uint16_t cPM2_5=0;
    uint16_t cPM10_0=0;
    uint16_t numPartAbove0_3=0;
    uint16_t numPartAbove0_5=0;
    uint16_t numPartAbove1_0=0;
    uint16_t numPartAbove2_5=0;
    uint16_t numPartAbove5_0=0;
    uint16_t numPartAbove10_0=0;
    bool checkData();

public:
    HKA5_PMSensor(Stream &serial);
    void begin();
    uint16_t getConcentrationPM1_0();
    uint16_t getConcentrationPM2_5();
    uint16_t getConcentrationPM10_0();
    uint16_t getNumberPariticlesAbove0_3();
    uint16_t getNumberPariticlesAbove0_5();
    uint16_t getNumberPariticlesAbove1_0();
    uint16_t getNumberPariticlesAbove2_5();
    uint16_t getNumberPariticlesAbove5_0();
    uint16_t getNumberPariticlesAbove10_0();
    bool readData();
};
#endif
