//***********************UART1****************************************
//動作：令串列監控視窗，顯示各種數值
//操作：開啟串列監控視窗，設定9600-bps
//********************************************************************
int num=65;
int i=1;

void setup() {                
	Serial.begin(9600); // 設定串列埠的鮑率為 9600 bps
}

// 此 loop 程序會一直重覆執行
void loop() {
	// 不同進制的顯示範例
	Serial.write(num); // 顯示字元(ASCII)
	Serial.print("\t"); // 加定位字元
	Serial.print(num); // 顯示十進制
	Serial.print("\t");
	Serial.print(num, BIN); // 顯示二進制
	Serial.print("\t");
	Serial.print(num, OCT); // 顯示八進制
	Serial.print("\t");
	Serial.println(num, HEX); // 顯示十六進制, 分行

	// 組合字串的顯示, 顯示結果為 i * i = i^2
	Serial.print(i);
	Serial.print("*");
	Serial.print(i);
	Serial.print("=");
	Serial.print(i*i);
	Serial.print("\n\n"); // 增加2行分行符號

	delay(500); // 延遲500ms
	num++; // num每次加1
	i++;
}
