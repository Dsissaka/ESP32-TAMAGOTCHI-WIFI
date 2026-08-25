// 1. Define que estamos usando o barramento paralelo de 8 bits
#define ESP32_PARALLEL

// 2. Define o driver da tela (Muitas telas OpenSmart antigas 
// rodam com a base do ILI9341 em modo paralelo, vale o teste)
#define ILI9341_DRIVER 

// 3. Declarando os Pinos de Controle (RS, CS, WR, RD, RST)
#define TFT_CS   17  // Chip Select
#define TFT_DC   4   // Data/Command (Também chamado de RS na tela)
#define TFT_RST  22  // Reset
#define TFT_WR   19  // Write
#define TFT_RD   5   // Read

// 4. Declarando o barramento de dados (D0 a D7)
// Usando pinos seguros que não atrapalham o boot do ESP32
#define TFT_D0   13
#define TFT_D1   16  // Evitamos o GPIO 12 aqui!
#define TFT_D2   14
#define TFT_D3   27
#define TFT_D4   26
#define TFT_D5   25
#define TFT_D6   33
#define TFT_D7   32

// 5. Fonte padrão
#define LOAD_GLCD
