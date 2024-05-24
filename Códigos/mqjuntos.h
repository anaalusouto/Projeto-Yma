int pin_buzzer = 8;

// Definições dos pinos ligados aos sensores
int pin_mq2_d0 = 7;
int pin_mq4_d0 = 6; // Assumindo que o MQ4 está no pino digital 6

int nivel_sensor_mq2 = 75;
int nivel_sensor_mq4 = 50; // Valor do nível do sensor MQ4 (ajuste conforme necessário)

void setup()
{
  // Define os pinos de leitura dos sensores como entrada
  pinMode(pin_mq2_d0, INPUT);
  pinMode(pin_mq4_d0, INPUT);
  // Define o pino do buzzer como saída
  pinMode(pin_buzzer, OUTPUT);

  // Inicializa a serial
  Serial.begin(9600);
}

void loop()
{
  // Le os dados dos pinos digitais D0 dos sensores
  int valor_analogico_mq2 = analogRead(pin_mq2_d0);
  int valor_analogico_mq4 = analogRead(pin_mq4_d0);
  
  // Mostra os dados no serial monitor
  Serial.print("MQ2 - D0: ");
  Serial.print(valor_analogico_mq2);
  Serial.print(" | MQ4 - D0: ");
  Serial.println(valor_analogico_mq4);
  
  // Verifica se algum dos sensores detectou gás/fumaça
  if (valor_analogico_mq2 == HIGH || valor_analogico_mq4 == HIGH)
  {
    // Ativa o buzzer se algum dos sensores detectar gás/fumaça
    analogWrite(pin_buzzer, HIGH);
  }
  else
  {
    // Desliga o buzzer se nenhum dos sensores detectar gás/fumaça
    analogWrite(pin_buzzer, LOW);
  }

  delay(10);
}