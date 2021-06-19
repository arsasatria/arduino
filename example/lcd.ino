#include <Wire.h> //Tambahkan Library Wire sebagai penghubung ke LCD
#include <LiquidCrystal_I2C.h> // Tambahkan library LiquidCrystal I2C

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init(); // Inisialisasi
}

void loop(){
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("TEST LCD I2C");
  lcd.setCursor(0,1);
  lcd.print("https://arsa.me");
}
