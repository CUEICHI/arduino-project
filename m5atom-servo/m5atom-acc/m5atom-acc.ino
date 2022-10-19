#include "M5Atom.h"
#define SIG_MAX (4096)

extern const unsigned char AtomImageData[375 + 2];

uint8_t DisBuff[2 + 5 * 5 * 3];
int16_t adX,adY,adZ;

void setBuffP(uint8_t posData, uint8_t Rdata, uint8_t Gdata, uint8_t Bdata)
{
    DisBuff[2 + posData * 3 + 0] = Rdata;
    DisBuff[2 + posData * 3 + 1] = Gdata;
    DisBuff[2 + posData * 3 + 2] = Bdata;
}
void setBuff(uint8_t Rdata, uint8_t Gdata, uint8_t Bdata)
{
    for (uint8_t i = 0; i < 25; i++)
        setBuffP(i, Rdata, Gdata, Bdata);
}
void shftBuff()
{
    for (uint8_t i = 24; i > 0; i--)
    {
        for (uint8_t j = 0; j < 3; j++)
            DisBuff[2 + i * 3 + j] = DisBuff[2 + (i-1) * 3 + j];
    }
}

void setup()
{
    DisBuff[0] = 0x05;
    DisBuff[1] = 0x05;
    M5.begin(false, true, true);
    delay(10);
    M5.IMU.Init();
    setBuff(0x20, 0x20, 0x20);
    M5.dis.displaybuff(DisBuff);
}

void loop()
{
    M5.update();
    if (M5.Btn.read()==0)
    {
        M5.IMU.getAccelAdc(&adX, &adY, &adZ);
        int r = min(max((int)map(adX,-SIG_MAX,SIG_MAX,0,255),0),255);
        int g = min(max((int)map(adY,-SIG_MAX,SIG_MAX,0,255),0),255);
        int b = min(max((int)map(adZ,-SIG_MAX,SIG_MAX,0,255),0),255);
        shftBuff();
        setBuffP(0,r,g,b);
        M5.dis.displaybuff(DisBuff);
    }
    delay(20);
}
