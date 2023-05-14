int led_Vm_1 = 11;
int led_Am_1 = 12;
int led_Vd_1 = 13;
int led_Vm_2 = 9;
int led_Am_2 = 8;
int led_Vd_2 = 7;
int botao_1 = 1;
int botao_2 = 2;
bool estadoChave1 = false;
bool estadoChave2 = false;

void setup() {
pinMode(led_Vm_1, OUTPUT);
pinMode(led_Am_1, OUTPUT);
pinMode(led_Vd_1, OUTPUT);
pinMode(led_Vm_2, OUTPUT);
pinMode(led_Am_2, OUTPUT);
pinMode(led_Vd_2, OUTPUT);
pinMode(botao_1, INPUT);
pinMode(botao_2, INPUT);
}
void a()
{

digitalWrite(led_Vd_1, HIGH);
delay(3000);
digitalWrite(led_Vd_1, LOW);
for (int i = 0; i < 6; i++) {
digitalWrite(led_Am_1, HIGH);
delay(500);
digitalWrite(led_Am_1, LOW);
delay(500);
}
}

void b()
{
digitalWrite(led_Vm_1, HIGH);
digitalWrite(led_Vm_2, LOW);
digitalWrite(led_Vd_2, HIGH);
delay(2000);
digitalWrite(led_Vd_2, LOW);
for (int i = 0; i < 6; i++) {
digitalWrite(led_Am_2, HIGH);
delay(500);
digitalWrite(led_Am_2, LOW);
delay(500);
}
}
void c()
{
digitalWrite(led_Vm_1, LOW);
digitalWrite(led_Vm_2, HIGH);
digitalWrite(led_Vd_1, HIGH);

delay(10);
if (digitalRead(botao_1) == HIGH)
{
for (int j = 0; j < 6; j++)
{
digitalWrite(led_Am_1, HIGH);
delay(500);
digitalWrite(led_Am_1, LOW);
delay(500);
}
digitalWrite(led_Vd_1, HIGH);
delay(3000);
digitalWrite(led_Vd_1, LOW);
digitalWrite(led_Vm_1, LOW);
digitalWrite(led_Vd_2, HIGH);
b();
}
delay(3000);
digitalWrite(led_Vd_1, LOW);
a();
}

void loop()
{
if(digitalRead(botao_1) == HIGH || digitalRead(botao_2) == HIGH)
{
estadoChave1 = true;
estadoChave2 = true;
}

if (estadoChave1 == true || estadoChave2 == true)
{
digitalWrite(led_Vm_1, HIGH);
digitalWrite(led_Vm_2, HIGH);
delay(5000);
digitalWrite(led_Vm_1, LOW);
a();
b();
c();
}
else
{
digitalWrite(led_Vm_1, HIGH);
digitalWrite(led_Vm_2, HIGH);
delay(1000);
digitalWrite(led_Vm_1, LOW);
digitalWrite(led_Vm_2, LOW);
delay(1000);
}
}
