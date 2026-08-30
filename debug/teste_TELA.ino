#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// Mapeamento dos pinos que definimos no seu projeto
#define TFT_CS   15
#define TFT_DC   4
#define TFT_RST  27

// Inicializa a tela usando o barramento VSPI de hardware (velocidade máxima)
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);
  Serial.println("Inicializando o display...");

  // Liga a tela
  tft.begin();
  
  // Gira a tela para o modo paisagem (tente valores de 0 a 3 se ficar de ponta cabeça)
  tft.setRotation(1); 
  
  // Pinta o fundo de preto
  tft.fillScreen(ILI9341_BLACK);

  // Configura a primeira linha de texto (Estilo neon)
  tft.setCursor(30, 80);
  tft.setTextColor(ILI9341_CYAN); 
  tft.setTextSize(3);
  tft.println("Hello World!");

  // Configura a segunda linha de texto
  tft.setCursor(30, 120);
  tft.setTextColor(ILI9341_YELLOW);
  tft.setTextSize(2);
  tft.println("VSPI funcionando!");
  
  Serial.println("Texto enviado para a tela!");
}

void loop() {
  // Para um Hello World estático, não precisamos de nada no loop
}
