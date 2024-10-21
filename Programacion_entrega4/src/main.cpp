/*#include <WiFi.h>
#include <HTTPClient.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>
#include <PubSubClient.h>  // Incluir la librería para MQTT

LiquidCrystal_I2C lcd(0x27, 16, 2);
HTTPClient http;
Servo servo;

// Datos para la conexión wifi
#define ssid "Wokwi-GUEST"
#define password ""

//Url a la api donde subiremos el uuid
#define apiUrl "https://6532f899-586a-454e-ab9e-1f89e78767e5-00-6ynbn5jm5uy1.picard.replit.dev:3001/register"

// Cluster URL y puerto para MQTT
const char* mqttServer = "283af90fa0c7478691a829d1e7a78995.s1.eu.hivemq.cloud";
const int mqttPort = 8883;

// Pines a utilizar
#define pirPin 2
#define buzzerPin 4
#define btnPin 14
#define ledAllowed 17
#define ledDenied 16
#define servoPin 15

// Pin para el botón que simula la lectura del RFID
#define rfidButtonPin 26

boolean pirState = false;

#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>  // Cliente seguro para conexiones TLS

// Datos de conexión WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Datos de conexión MQTT
const char* mqtt_server = "283af90fa0c7478691a829d1e7a78995.s1.eu.hivemq.cloud";  // URL del broker
const int mqtt_port = 8883;  // Puerto TLS para MQTT
const char* mqtt_user = "tu_usuario_mqtt";  // Tu usuario MQTT
const char* mqtt_password = "tu_contraseña_mqtt";  // Tu contraseña MQTT

WiFiClientSecure espClient;  // Cliente seguro para MQTT con TLS
PubSubClient client(espClient);

void setup_wifi() {
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("WiFi Conectado");
  Serial.print("Direccion IP asignada: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Intentar reconectar a MQTT
  while (!client.connected()) {
    Serial.print("Intentando conectar al broker MQTT...");
    
    // Conectarse al broker MQTT con usuario y contraseña
    if (client.connect("ESP32Client", mqtt_user, mqtt_password)) {
      Serial.println("Conectado al broker MQTT");
      
      // Suscribirse a un tópico si es necesario
      // client.subscribe("tu_topico");
    } else {
      Serial.print("Error de conexión MQTT: ");
      Serial.println(client.state());  // Imprimir el código de error
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();

  // Configurar el cliente MQTT
  client.setServer(mqtt_server, mqtt_port);

  // Verificar si TLS es válido (puedes desactivarlo si tu broker no usa certificados)
  espClient.setInsecure();  // Si no tienes certificados para validar, desactiva la verificación del certificado
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Aquí irían las demás funciones del loop
}


#include <WiFi.h>
#include <PubSubClient.h>
#include <WiFiClientSecure.h>  // Cliente seguro para conexiones TLS

// Datos de conexión WiFi
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Datos de conexión MQTT
const char* mqtt_server = "283af90fa0c7478691a829d1e7a78995.s1.eu.hivemq.cloud";  // URL del broker
const int mqtt_port = 8883;  // Puerto TLS para MQTT
const char* mqtt_user = "tu_usuario_mqtt";  // Tu usuario MQTT
const char* mqtt_password = "tu_contraseña_mqtt";  // Tu contraseña MQTT

WiFiClientSecure espClient;  // Cliente seguro para MQTT con TLS
PubSubClient client(espClient);

void setup_wifi() {
  Serial.print("Conectando a ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("WiFi Conectado");
  Serial.print("Direccion IP asignada: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Intentar reconectar a MQTT
  while (!client.connected()) {
    Serial.print("Intentando conectar al broker MQTT...");
    
    // Conectarse al broker MQTT con usuario y contraseña
    if (client.connect("ESP32Client", mqtt_user, mqtt_password)) {
      Serial.println("Conectado al broker MQTT");
      
      // Suscribirse a un tópico si es necesario
      // client.subscribe("tu_topico");
    } else {
      Serial.print("Error de conexión MQTT: ");
      Serial.println(client.state());  // Imprimir el código de error
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();

  // Configurar el cliente MQTT
  client.setServer(mqtt_server, mqtt_port);

  // Verificar si TLS es válido
  espClient.setInsecure();  // Si no tienes certificados para validar, desactiva la verificación del certificado
  
  Serial.println("Conectando al broker MQTT...");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Aquí irían las demás funciones del loop
}
_________________________________________
// 'bat 0', 25x20px
// 'batería', 25x20px
// 'batería', 25x20px
// 'batería', 25x20px

// Declaración de las imágenes
const unsigned char epd_bitmap_bat_0 [] = {
    0x3f, 0xff, 0xff, 0x00, 0x20, 0x00, 0x00, 0x80, 0x20, 0x00, 0x00, 0x80, 0x20, 0x00, 0x00, 0x80,
    0xe0, 0x00, 0x00, 0x80, 0xa0, 0x00, 0x00, 0x80, 0xa0, 0x00, 0x00, 0x80, 0xa0, 0x00, 0x00, 0x80,
    0xa0, 0x00, 0x00, 0x80, 0xe0, 0x00, 0x00, 0x80, 0x60, 0x00, 0x00, 0x80, 0x20, 0x00, 0x00, 0x80,
    0x20, 0x00, 0x00, 0x80, 0x3f, 0xff, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char epd_bitmap_sin_se_al [] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x80, 0x00, 0x10, 0xc0, 0x00, 0x29, 0x40, 0x03, 
    0xe6, 0x40, 0x0e, 0xa6, 0x40, 0x1e, 0xa9, 0x40, 0x27, 0xf0, 0xc0, 0x24, 0x9f, 0x00, 0x24, 0x92, 
    0x00, 0x3f, 0xfe, 0x00, 0x2c, 0x92, 0x00, 0x24, 0x92, 0x00, 0x27, 0xf4, 0x00, 0x1c, 0xbc, 0x00, 
    0x0e, 0xb8, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00
};

// Tu código principal
#include <Wire.h>                  
#include <Adafruit_GFX.h>          
#include <Adafruit_SSD1306.h>       

#define ANCHO 128                   
#define ALTO 64                      

#define OLED_RESET 4                 
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET); 

int pinBateria = 36;
int nivelBajo = 3102;
int nivelAlto = 4095;

unsigned long previousMillis = 0;
const long interval = 4000; // Intervalo de tiempo en milisegundos

bool bat;

void setup() {
    Serial.begin(9600);
    Wire.begin();                        
    oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); 

    oled.clearDisplay();                  
}

void loop() {
    int lectura = analogRead(pinBateria);
    int porcentaje_bateria = map(lectura, nivelBajo, nivelAlto, 0, 100);
    porcentaje_bateria = constrain(porcentaje_bateria, 0, 100); 

    unsigned long currentMillis = millis();
    oled.clearDisplay();
    if (currentMillis - previousMillis >= interval) {
        previousMillis = currentMillis;
        bat = true;
    }

    if (porcentaje_bateria > 20) {
        if (bat) {
            oled.setTextSize(1);
            oled.setTextColor(WHITE);
            oled.setCursor(106, 6);
            oled.print(porcentaje_bateria);
        }

        // Muestra el % de bateria y otras imágenes
        oled.setTextColor(WHITE);
        oled.setTextSize(1);
        oled.setCursor(4, 23);
        oled.print("Bienvenido ID_1");

        oled.setCursor(30, 55);
        oled.print("Abierto");

        oled.setCursor(0, 45);
        oled.print("Acceso programado");

        oled.setCursor(14, 3);
        oled.print("Acceso Rfid:");

        oled.setCursor(0, 13);
        oled.print("Acerca el lector");

        oled.setTextSize(2);
        oled.setCursor(110, 42);
        oled.print("5");

        oled.setTextSize(1);
        oled.setCursor(16, 35);
        oled.print("Acceso wifi");

        // Dibujar contorno y las imágenes
        oled.drawLine(100, 0, 128, 0, WHITE);
        oled.drawLine(100, 0, 0, 0, WHITE);
        oled.drawLine(100, 63, 0, 63, WHITE);
        oled.drawLine(101, 0, 101, 63, WHITE);
        oled.drawLine(100, 32, 0, 32, WHITE);
        oled.drawLine(100, 63, 128, 63, WHITE);
        oled.drawBitmap(102, 3, epd_bitmap_bat_0, 25, 20, WHITE);
        oled.drawBitmap(107, 20, epd_bitmap_sin_se_al, 20, 20, WHITE);

    } else {
        // Muestra que la batería es baja
        oled.setTextSize(1);
        oled.setTextColor(WHITE);
        oled.setCursor(106, 6);
        oled.print(porcentaje_bateria);

        oled.drawBitmap(107, 20, epd_bitmap_sin_se_al, 20, 20, WHITE);
        oled.drawBitmap(102, 3, epd_bitmap_bat_0, 25, 20, WHITE);
        oled.setTextSize(1);
        oled.setCursor(25, 25);
        oled.print("Bateria baja");
    }
    oled.display();
    Serial.println(lectura);
    delay(2000);
}
*/


#include <Wire.h>                   // librería para bus I2C
#include <Adafruit_GFX.h>           // librería para pantallas gráficas
#include <Adafruit_SSD1306.h>       // librería para controlador SSD1306
#include <LiquidCrystal.h>           // librería para LCD

#define ANCHO 128                   // reemplaza ocurrencia de ANCHO por 128
#define ALTO 64                     // reemplaza ocurrencia de ALTO por 64
#define OLED_RESET 4                // necesario por la librería pero no usado
Adafruit_SSD1306 oled(ANCHO, ALTO, &Wire, OLED_RESET); // crea objeto

// Configuración del LCD
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // Asumiendo que el LCD está conectado a estos pines

// Pines de los LEDs verdes
const int ledVerde1 = 2;
const int ledVerde2 = 3;
const int ledVerde3 = 4;
const int ledVerde4 = 5;

int pinBateria = 36;
int nivelBajo = 3102;
int nivelAlto = 4095;
int botonVerde = 26;  // Pin donde está conectado el botón verde
int buzzer = 4;       // Pin donde está conectado el buzzer

unsigned long previousMillis = 0;
const long interval = 4000; // Intervalo de tiempo en milisegundos

void setup() {
  Serial.begin(9600);
  Wire.begin();                        // inicializa bus I2C
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C); // inicializa pantalla con direccion 0x3C
  oled.clearDisplay();                  // limpia pantalla

  pinMode(botonVerde, INPUT_PULLUP);    // Configura el botón verde como entrada

  // Inicializa el LCD
  lcd.begin(16, 2); // Configura el LCD de 16 columnas y 2 filas
  lcd.clear();

  // Configura los pines de los LEDs como salida
  pinMode(ledVerde1, OUTPUT);
  pinMode(ledVerde2, OUTPUT);
  pinMode(ledVerde3, OUTPUT);
  pinMode(ledVerde4, OUTPUT);
  
  // Configura el buzzer como salida
  pinMode(buzzer, OUTPUT);
}

void loop() {
  int lectura = analogRead(pinBateria);
  int porcentaje_bateria = map(lectura, nivelBajo, nivelAlto, 0, 100);

  porcentaje_bateria = constrain(porcentaje_bateria, 0, 100); // Limita la lectura de 100 a 0

  oled.clearDisplay();
  
  // Muestra el nivel de batería en el OLED
  oled.setTextSize(1);
  oled.setTextColor(WHITE);
  oled.setCursor(106, 6);
  oled.print(porcentaje_bateria);
  
  if (porcentaje_bateria > 20) {
    if (digitalRead(botonVerde) == LOW) {  // Si el botón está presionado
      oled.clearDisplay();
      oled.setTextSize(2);
      oled.setCursor(15, 30);
      oled.print("Acceso");
      oled.setCursor(15, 50);
      oled.print("Permitido");
      
      // Encender los LEDs verdes
      digitalWrite(ledVerde1, HIGH);
      digitalWrite(ledVerde2, HIGH);
      digitalWrite(ledVerde3, HIGH);
      digitalWrite(ledVerde4, HIGH);
      
      // Hacer sonar el buzzer
      digitalWrite(buzzer, HIGH);
      delay(500); // Suena durante 500 ms
      digitalWrite(buzzer, LOW);
      
      // Mostrar en el LCD
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Acceso Permitido");
    } else {
      // Apagar los LEDs verdes
      digitalWrite(ledVerde1, LOW);
      digitalWrite(ledVerde2, LOW);
      digitalWrite(ledVerde3, LOW);
      digitalWrite(ledVerde4, LOW);

      // Contenido de la pantalla normal
      oled.setTextSize(1);
      oled.setCursor(4, 23);
      oled.print("Bienvenido ID_1");
      oled.setCursor(30, 55);
      oled.print("Abierto");
      oled.setCursor(0, 45);
      oled.print("Acceso programado");
      oled.setCursor(14, 3);
      oled.print("Acceso Rfid:");
      oled.setCursor(0, 13);
      oled.print("Acerca el lector");
      oled.setTextSize(2);
      oled.setCursor(110, 42);
      oled.print("5");
      oled.setTextSize(1);
      oled.setCursor(16, 35);
      oled.print("Acceso wifi");
      
      // Mostrar en el LCD
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Acceso Denegado");
    }
    
  } else {
    // Muestra que la batería es baja
    oled.setTextSize(1);
    oled.setCursor(25, 25);
    oled.print("Bateria baja");
    
    // Apagar los LEDs verdes
    digitalWrite(ledVerde1, LOW);
    digitalWrite(ledVerde2, LOW);
    digitalWrite(ledVerde3, LOW);
    digitalWrite(ledVerde4, LOW);

    // Mostrar en el LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Bateria Baja");
  }

  oled.display();
  delay(2000);
}
