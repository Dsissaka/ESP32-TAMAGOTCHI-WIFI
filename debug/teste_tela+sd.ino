#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <XPT2046_Touchscreen.h>

// Pinos exclusivos da Tela
#define TFT_CS   5
#define TFT_DC   4
#define TFT_RST  33

// Pino exclusivo do Touch (O MISO, MOSI e SCK são os mesmos da tela)
#define TOUCH_CS 27

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);
XPT2046_Touchscreen ts(TOUCH_CS);

#define TS_MINX 300
#define TS_MAXX 3800
#define TS_MINY 300
#define TS_MAXY 3800

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando o teste do Barramento VSPI...");

  //Inicia o Touch
  ts.begin();
  ts.setRotation(1); // Rotação 1 = Paisagem (Deitado)

  //Inicia a Tela
  tft.begin();
  tft.setRotation(1); // Rotação 1 = Paisagem (Deitado)
  
  //Pinta o fundo e escreve as instruções
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_YELLOW);
  tft.setTextSize(2);
  tft.setCursor(10, 10);
  tft.println("Teste Touch + Tela VSPI!");
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(1);
  tft.setCursor(10, 35);
  tft.println("Toque e arraste para desenhar...");
}

void loop() {
  if (ts.touched()) {
    TS_Point p = ts.getPoint();

    // Mapeia os valores brutos (ex: 300 a 3800) para os pixels reais da tela (320x240)
    // O eixo X tem 320 pixels e o eixo Y tem 240 pixels (no modo paisagem)
    int pixel_X = map(p.x, TS_MINX, TS_MAXX, 0, 320);
    int pixel_Y = map(p.y, TS_MINY, TS_MAXY, 0, 240);

    // Desenha um círculo preenchido no local do toque (Raio 3, Cor Ciano)
    tft.fillCircle(pixel_X, pixel_Y, 3, ILI9341_CYAN);

    // Manda as coordenadas para o Serial Monitor para debug
    Serial.print("Toque -> X bruto: "); Serial.print(p.x);
    Serial.print(" | Y bruto: "); Serial.print(p.y);
    Serial.print("  ==>  Pixel X: "); Serial.print(pixel_X);
    Serial.print(" | Pixel Y: "); Serial.println(pixel_Y);
  }
}
