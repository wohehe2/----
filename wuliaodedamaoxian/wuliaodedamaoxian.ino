#include <IRremote.h>
#include <Adafruit_NeoPixel.h>
#include <U8glib.h>//关于oled屏幕引用函数的声明
#define PIN 6
#define RECV_PIN 10
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);      //说明oled型号
#define ziti1 u8g.setFont(u8g_font_7x13)    //给这个字体取个新的名字



//遥控器按键编码定义
#define n1 0x1FEF807    //增加+
#define n2 0x1FE708F   //减少-
#define n3 0x1FED827      //数字0
#define n4 0x1FE807F      //数字1
#define n5 0x1FE40BF      //数字2
#define n6 0x1FEC03F      //数字3
#define n7 0x1FE20DF      //数字4
#define n8 0x1FEA05F      //数字5
#define n9 0x1FE609F      //数字6
#define n10 0x1FEE01F      //数字7
#define n11 0x1FE10EF      //数字8
#define n12 0x1FE906F      //数字9

Adafruit_NeoPixel strip = Adafruit_NeoPixel(6, PIN, NEO_GRB + NEO_KHZ800);

IRrecv irrecv(RECV_PIN);
decode_results results;

#define val_max 255
#define val_min 0

int pos = 8, color = 100;

uint32_t color_n[9] =
{
  strip.Color(255, 0, 0),
  strip.Color(248, 141, 30),
  strip.Color(255, 255, 0),
  strip.Color(0, 255, 0),
  strip.Color(0, 127, 255),
  strip.Color(0, 0, 255),
  strip.Color(139, 0, 255),
  strip.Color(255, 255, 255),
  strip.Color(0, 0, 0)
};
uint32_t color_m[9][3] =
{
  {0, 255, 255},
  {255, 0, 0},
  {248, 141, 30},
  {255, 255, 0},
  {0, 255, 0},
  {0, 127, 255},
  {0, 0, 255},
  {139, 0, 255},
  {255, 255, 255}
};

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  irrecv.enableIRIn(); // Start the receiver
  for (int i = 0; i < 9; i++)
  {
    colorSetall(color_n[i]);
    delay(300);
  }
}

void maoxian1()
 {u8g.firstPage();           
      do {
          ziti1;
          u8g.setPrintPos(10, 40);
          u8g.print("kiss th wall");
         }while( u8g.nextPage() );
  
  }

void maoxian2()
{u8g.firstPage();          
      do {
          ziti1;
          u8g.setPrintPos(10, 40);
          u8g.print("Carpet bombing");
         }while( u8g.nextPage() );
  }


void maoxian3()
{u8g.firstPage();          
      do {
          ziti1;
          u8g.setPrintPos(10, 40);
          u8g.print("comfess one's love");
         }while( u8g.nextPage() );
  }


void maoxian4()
{u8g.firstPage();          
      do {
          ziti1;
          u8g.setPrintPos(10, 40);
          u8g.print("run for 2 minutes");
         }while( u8g.nextPage() );
  }

void maoxian5()
{u8g.firstPage();          
      do {
          ziti1;
          u8g.setPrintPos(10, 40);
          u8g.print("nothing");
         }while( u8g.nextPage() );
  }


  void maoxian6()
  {u8g.firstPage();          
      do {
          ziti1;
          u8g.setPrintPos(10, 40);
          u8g.print("nothing");
         }while( u8g.nextPage() );
  }



  void maoxian7()
  {u8g.firstPage();          
      do {
          ziti1;
          u8g.setPrintPos(10, 40);
          u8g.print("nothing");
         }while( u8g.nextPage() );
  }


  void maoxian8()
  {u8g.firstPage();         
      do {
          ziti1;
          u8g.setPrintPos(10, 40);
          u8g.print("recite a poem");
         }while( u8g.nextPage() );
  }

  void maoxian9()
  {u8g.firstPage();          
      do {
          ziti1;
          u8g.setPrintPos(10, 40);
          u8g.print("nothing");
         }while( u8g.nextPage() );
  }


  void maoxian10()
  {u8g.firstPage();          
      do {
          ziti1;
          u8g.setPrintPos(10, 40);
          u8g.print("dance");
         }while( u8g.nextPage() );
  }

  void maoxian11()
  {u8g.firstPage();          
      do {
          ziti1;
          u8g.setPrintPos(10, 40);
          u8g.print("sing a song");
         }while( u8g.nextPage() );
  }




void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
    switch (results.value)
    {
      case n1:
        color += 50;
        maoxian1();
        if (color > 250)
          color = 250;
        break;
      case n2:
        color -= 50;
        maoxian2();
        if (color < 0)
          color = 0;
        break;
      case n3:
        color = 100;
        pos = 0;
        maoxian3();
        break;
      case n4:
        pos = 1;
        color = 100;
        maoxian4();
        break;
      case n5:
        pos = 2;
        color = 100;
        maoxian5();
        break;
      case n6:
        pos = 3;
        color = 100;
        maoxian6();
        break;
      case n7:
        pos = 4;
        color = 100;
        maoxian7();
        break;
      case n8:
        pos = 5;
        color = 100;
        maoxian8();
        break;
      case n9:
        pos = 6;
        color = 100;
        maoxian9();
        break;
      case n10:
        pos = 7;
        color = 100;
        maoxian10();
        break;
      case n11:
        pos = 8;
        color = 100;
        maoxian11();
        break;
      default:
        break;
    }
    irrecv.resume(); // Receive the next value
    colorSetall(strip.Color(map(color, val_min, val_max, 0, color_m[pos][0]),
                            map(color, val_min, val_max, 0, color_m[pos][1]),
                            map(color, val_min, val_max, 0, color_m[pos][2])));
  }
}

void colorSetall(uint32_t c) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
  }
  strip.show();
}

