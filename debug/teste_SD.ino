#include <SPI.h>
#include <SD.h>


int SCL_SD = 14;
int MISO_SD = 26;
int MOSI_SD = 13;
int CS_SD = 15;
SPIClass hspi(HSPI);

void setup() {
  hspi.begin(SCL_SD, MISO_SD, MOSI_SD, CS_SD);
  
  // Inicia o SD dizendo para usar a nossa rodovia customizada
  if (!SD.begin(15, hspi)) {
    Serial.println("Falha no SD!");
    return;
  }
}
