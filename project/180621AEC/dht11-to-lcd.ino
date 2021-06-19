  /*
  
  ========== PETUNJUK PEMASANGAN KOMPONEN ==========
  I. Alat & Bahan
      1. DHT 11 (dengan modul)
      2. LCD 16x2 (dengan modul)
      3. Arduino Uno
      4. Kabel Jumper
    
  II. Koneksi
      A. Koneksi LCD
          1. GND (LCD) -> GND (Arduino Board)
          2. VCC (LCD) -> 5v (Arduino Board)
          3. SDA (LCD) -> Analog A4 (Arduino Board)
          4. SCL (LCD) -> Analog A5 (Arduino Board)
      B. Koneksi DHT 11
          1. + (DHT 11) -> 5v (Arduino Board)
          2. Out (DHT 11) -> Digital pin 2 (Arduino Board)
          3. - (DHT 11) -> GND (Arduino Board)
  ==================================================
  
  */

  #include <Wire.h>
  #include <LiquidCrystal_I2C.h>
  #include <DHT.h> // Library DHT
  #define DHTPIN 2 // Masukkan output DHT ke digital pin 2
  #define DHTTYPE DHT11 // Tipe sensor DHT11
  DHT dht(DHTPIN, DHTTYPE); // Set sensor + koneksi pin
 
  float humi, temp;// Deklarasi variabel 
  LiquidCrystal_I2C lcd(0x27, 16, 2);

  void setup() {
    lcd.init(); // Inisialisasi
    lcd.backlight(); // Menyalakan Backlight LCD

    lcd.setCursor(0,0);
    lcd.print("DHT 11");

    lcd.setCursor(0,1);
    lcd.print("Memindai");
    delay(700);
    lcd.setCursor(8,1);
    lcd.print(".");
    delay(700);
    lcd.setCursor(9,1);
    lcd.print(".");
    delay(700);
    lcd.setCursor(10,1);
    lcd.print(".");
    delay(800);
    lcd.setCursor(11,1);
    lcd.print(".");
    delay(900);
    lcd.setCursor(12,1);
    lcd.print(".");
    delay(1000);
    lcd.clear();
  }
  
  void loop(){
    delay(1000);
    lcd.backlight();

    

    humi = dht.readHumidity();//baca kelembaban
    temp = dht.readTemperature();//baca suhu
    if (!isnan(humi) || !isnan(temp)) { 
      //jika ada hasilnya
      delay(100);
      lcd.setCursor(0,1);
      lcd.print("Suhu: ");
      lcd.setCursor(6,1);
      lcd.print(temp);
      lcd.setCursor(11,1);
      lcd.print("c");
      
      lcd.setCursor(0,0);
      lcd.print("Humi: ");
      lcd.setCursor(6,0);
      lcd.print(humi);
      delay(1000);
    }else if(isnan(humi) || isnan(temp)){
      //jika tidak ada hasil
      
    }
  }
