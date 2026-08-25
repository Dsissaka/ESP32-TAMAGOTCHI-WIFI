#include <TFT_eSPI.h> 
#include <SPI.h>

TFT_eSPI tft = TFT_eSPI(); 

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando a tela OpenSmart...");

  tft.begin();
  tft.setRotation(1); 
  tft.fillScreen(TFT_BLACK);

  // --- Hello World ---
  
  // Cor do texto (Branco) e cor de fundo do texto (Preto)
  tft.setTextColor(TFT_WHITE, TFT_BLACK); 
  // Tamanho da fonte (1 a 7)
  tft.setTextSize(3);
  // Escreve a mensagem nas coordenadas X=40 e Y=60
  tft.drawString("Hello World!", 40, 60);
  // Um charminho extra pro projeto do Baja/Tamagotchi
  tft.setTextSize(2);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.drawString("ESP32 + R61503", 40, 100);
}

void loop() {
}
