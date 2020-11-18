int
main(){
	unsigned int i;
	OS_PowerOnDriverInitial();
	DRV_Printf("====================================\r\n", 0);
	DRV_Printf("ADP-WT58F2C9 LED demo program\r\n", 0);
	DRV_Printf("====================================\r\n", 0);
	DRV_Printf("LED testing ...\r\n", 0);GPIO_PTB_DIR = 0x0000;
	//for GPIO Output Mode (0)
	GPIO_PTB_CFG = 0xffff;//for open drain
	//GPIO_PTB_PADIN= 0x0000;//for Digital Output
	for(i=0; i<1; i++){
	GPIO_PTB_GPIO = 0x7fff;//從16號燈開始亮
	delay1(100000);
	GPIO_PTB_GPIO = 0x3fff;//15號燈亮
	delay1(100000);
	GPIO_PTB_GPIO = 0x1fff;//14號燈亮
	delay1(100000);
	GPIO_PTB_GPIO = 0x8fff;//三顆燈開始往另一邊跑
	delay1(100000);
	GPIO_PTB_GPIO = 0xc7ff;
	delay1(100000);
	GPIO_PTB_GPIO = 0xe3ff;
	delay1(100000);
	GPIO_PTB_GPIO = 0xf1ff;
	delay1(100000);
	GPIO_PTB_GPIO = 0xf8ff;
	delay1(100000);
	GPIO_PTB_GPIO = 0xfc7f;
	delay1(100000);
	GPIO_PTB_GPIO = 0xfe3f;
	delay1(100000);
	GPIO_PTB_GPIO = 0xff1f;
	delay1(100000);
	GPIO_PTB_GPIO = 0xff8f;
}
