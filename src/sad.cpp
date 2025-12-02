#include <Arduino.h>
#include <DHT.h>

// DHT11 設定
#define DHTPIN 19       // DHT11 信號腳接在 GPIO19
#define DHTTYPE DHT11   // 感測器類型為 DHT11

// 建立 DHT 物件
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // 初始化序列埠
  Serial.begin(9600);
  Serial.println();
  Serial.println("DHT11 溫溼度感測器測試");
  Serial.println("------------------------");
  
  // 初始化 DHT 感測器
  dht.begin();
}

void loop() {
  // 讀取濕度 (相對濕度百分比)
  float humidity = dht.readHumidity();
  
  // 讀取溫度 (攝氏)
  float temperature = dht.readTemperature();
  
  // 檢查讀取是否失敗
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("無法讀取 DHT11 感測器資料！");
  } else {
    // 顯示溫度
    Serial.print("溫度: ");
    Serial.print(temperature);
    Serial.print(" °C\t");
    
    // 顯示濕度
    Serial.print("濕度: ");
    Serial.print(humidity);
    Serial.println(" %");
  }
  
  // 每 3 秒偵測一次
  delay(3000);
}