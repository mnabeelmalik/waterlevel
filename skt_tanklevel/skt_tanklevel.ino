#define tank1level1 6
#define tank1level2 7
#define tank2level1 8
#define tank2level2 9
#define selection1 10
#define selection2 11
#define out1 2
#define out2 3
#define pump 4
#define ind_power A0
#define ind_tank1 A1
#define ind_tank2 A2
bool chk_tank1 = false, chk_tank2 = false, chk_tank1full = false, chk_tank2full = false;
void setup()
{
  for (int i = 6; i < 12; i++)
  {
    pinMode(i, INPUT_PULLUP);
  }

  pinMode(out1, OUTPUT);
  pinMode(out2, OUTPUT);
  pinMode(pump, OUTPUT);
  pinMode(ind_power, OUTPUT);
  pinMode(ind_tank1, OUTPUT);
  pinMode(ind_tank2, OUTPUT);
  digitalWrite(pump, HIGH);
  digitalWrite(out1, HIGH);
  digitalWrite(out2, HIGH);
  digitalWrite(ind_power, HIGH);
}

void loop()
{
  if (digitalRead(selection1) == LOW) // autocontrol
  {
    if ((digitalRead(tank1level2) == LOW) && (digitalRead(tank1level1) == LOW) && (chk_tank1full == false))
    {
      chk_tank1full = true;
      digitalWrite(out1, HIGH);
      digitalWrite(ind_tank1, LOW);
    }
    else if ((digitalRead(tank1level1) == HIGH) && (digitalRead(tank1level2) == HIGH) && (chk_tank1 == false))
    {
      digitalWrite(pump, LOW);
      digitalWrite(out1, LOW);
      digitalWrite(ind_tank1, HIGH);
      chk_tank1full = false;

    }
    else if ((digitalRead(tank2level2) == LOW) && (digitalRead(tank2level1) == LOW) && (chk_tank2full == false))
    {
      chk_tank2full = true;
      chk_tank1 = false;
      digitalWrite(out2, HIGH);
      digitalWrite(ind_tank2, LOW);
      digitalWrite(pump, HIGH);
    }
    else if ((digitalRead(tank2level1) == HIGH) && (digitalRead(tank2level2) == HIGH) && (digitalRead(tank1level2) == LOW) )
    {
      digitalWrite(pump, LOW);
      digitalWrite(out2, LOW);
      digitalWrite(ind_tank2, HIGH);
      chk_tank2full = false;
      chk_tank1 = true;
    }
    else if ((chk_tank1full == true) && (chk_tank2full == true))
    {
      digitalWrite(pump, HIGH);
    }

  }
  else if (digitalRead(selection2) == LOW) //manual
  {
    digitalWrite(pump, LOW);
    digitalWrite(out1, HIGH);
    digitalWrite(out2, HIGH);
  }
  else
  {
    chk_tank1full = false;
    digitalWrite(ind_tank1, LOW);
    digitalWrite(ind_tank2, LOW);
    digitalWrite(pump, HIGH);
    digitalWrite(out1, HIGH);
    digitalWrite(out2, HIGH);
  }




}
