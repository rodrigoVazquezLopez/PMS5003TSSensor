#include "PMS5003TSSensor.h"
#include <Arduino.h>
#include <HardwareSerial.h>

PMS5003TSSensor::PMS5003TSSensor(Stream &serial)
{
    _serial = &serial;
}

void PMS5003TSSensor::begin()
{
    //_serial->begin(9600);
    _serial->setTimeout(1500);
}

bool PMS5003TSSensor::readData()
{
    if(_serial->available() > 0)
    {
        while(!_serial->find(PM_START_CHAR1))
        {
            if(_serial->read() == -1)
                return false;
        }
        _serial->readBytes(pmBuffer,PM_Buffer_LEN);
        if(pmBuffer[0] == PM_START_CHAR2)
        {
            if(checkData())
            {
                cPM1_0 = ((pmBuffer[PM_DATA1_H] << 8) + pmBuffer[PM_DATA1_L]);
                cPM2_5 = ((pmBuffer[PM_DATA2_H] << 8) + pmBuffer[PM_DATA2_L]);
                cPM10_0 = ((pmBuffer[PM_DATA3_H] << 8) + pmBuffer[PM_DATA3_L]);
                numPartBeyond0_3 = ((pmBuffer[PM_DATA7_H] << 8) + pmBuffer[PM_DATA7_L]);
                numPartBeyond0_5 = ((pmBuffer[PM_DATA8_H] << 8) + pmBuffer[PM_DATA8_L]);
                numPartBeyond1_0 = ((pmBuffer[PM_DATA9_H] << 8) + pmBuffer[PM_DATA9_L]);
                numPartBeyond2_5 = ((pmBuffer[PM_DATA10_H] << 8) + pmBuffer[PM_DATA10_L]);
                numPartBeyond5_0 = ((pmBuffer[PM_DATA11_L] << 8) + pmBuffer[PM_DATA11_L]);
                numPartBeyond10_0 = ((pmBuffer[PM_DATA12_H] << 8) + pmBuffer[PM_DATA12_L]);
                formaldehyde = ((pmBuffer[PM_DATA13_H] << 8) + pmBuffer[PM_DATA13_L]);
                temperature = ((pmBuffer[PM_DATA14_H] << 8) + pmBuffer[PM_DATA14_L]);
                humidity = ((pmBuffer[PM_DATA12_H] << 8) + pmBuffer[PM_DATA12_L]);
                return true;
            }
        }
    }
    return false;
}

bool PMS5003TSSensor::checkData()
{
    int checkSum = PM_START_CHAR1;

    for(int i=0; i<(PM_Buffer_LEN-2); i++){
        checkSum = checkSum + pmBuffer[i];
    }
    //checkSum = checkSum + PM_START_CHAR1;

    if(checkSum == ((pmBuffer[PM_Buffer_LEN-2] << 8) + pmBuffer[PM_Buffer_LEN-1]))  //check the serial data
        return true;
    else
        return false;
}

uint16_t PMS5003TSSensor::getConcentrationPM1_0()
{
    return cPM1_0;
}

uint16_t PMS5003TSSensor::getConcentrationPM2_5()
{
    return cPM2_5;
}

uint16_t PMS5003TSSensor::getConcentrationPM10_0()
{
    return cPM10_0;
}

uint16_t PMS5003TSSensor::getNumberPariticlesBeyond0_3()
{
    return numPartAbove0_3;
}

uint16_t PMS5003TSSensor::getNumberPariticlesBeyond0_5()
{
    return numPartAbove0_5;
}

uint16_t PMS5003TSSensor::getNumberPariticlesBeyond1_0()
{
    return numPartAbove1_0;
}

uint16_t PMS5003TSSensor::getNumberPariticlesBeyond2_5()
{
    return numPartAbove2_5;
}

uint16_t PMS5003TSSensor::getNumberPariticlesBeyond5_0()
{
    return numPartAbove5_0;
}

uint16_t PMS5003TSSensor::getNumberPariticlesBeyond10_0()
{
    return numPartAbove10_0;
}

float PMS5003TSSensor::getFormaldehyde()
{
    return formaldehyde/1000;
}

float PMS5003TSSensor::getTemperature()
{
    return temperature/10;
}

float PMS5003TSSensor::getHumidity()
{
    return humidity/10;
}
