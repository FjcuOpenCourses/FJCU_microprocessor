//***********************BLT******************************************
//動作：使用硬體串列埠1連接藍牙，令手機與電腦進行傳輸
//      使用藍牙模組，D2(RX)-->P30(TXD1)，D3(TX)-->P30(RXD1)
//      開啟串列監控視窗，令手機與電腦進行傳輸字串
//********************************************************************

void setup()
{
  Serial.begin(38400); // 設定硬體UART2
  Serial.println("Enter APP Transmission:"); // 硬體UART2送字串到電腦顯示
  Serial1.begin(38400); // 設定硬體UART1, 即藍牙HC-05傳輸速率
}

void loop()
{
   if (Serial1.available()) // 檢查硬體UART1是否輸入字元，即手機是否有經藍牙輸入字元
    Serial.write(Serial1.read()); // 讀取硬體UART1的字元，經硬體UART2送到電腦顯示
  
  if (Serial.available()) // 檢查硬體UART2是否輸入字元，即電腦是否有輸入字元
    Serial1.write(Serial.read()); // 讀取硬體UART2的字元，由硬體UART1經藍牙送到手機顯示
}
