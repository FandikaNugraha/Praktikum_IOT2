const int buttonPin = 4;   // Pin D2 terhubung ke push button
const int ledPin = 5;      // Pin D1 terhubung ke LED

// Variabel untuk melacak status sistem
int ledState = LOW;        // Status LED saat ini (ON/HIGH atau OFF/LOW)
int lastButtonState = LOW; // Menyimpan status pembacaan tombol sebelumnya

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Membaca status tombol saat ini
  int currentButtonState = digitalRead(buttonPin);

  // Logika deteksi tombol ditekan (transisi dari LOW ke HIGH)
  // dan menggunakan delay singkat untuk debounce (mengatasi pantulan mekanis tombol)
  if (currentButtonState == HIGH && lastButtonState == LOW) {
    // Delay untuk debounce (mengatasi pantulan sinyal mekanis tombol fisik)
    delay(50); 

    // Toggle status LED (membalikkan status dari ON ke OFF, atau sebaliknya)
    if (ledState == LOW) {
      ledState = HIGH;
      Serial.println("Tombol dilepas -> LED Menyala (ON)");
    } else {
      ledState = LOW;
      Serial.println("Tombol dilepas -> LED Mati (OFF)");
    }

    // Terapkan perubahan status ke fisik LED
    digitalWrite(ledPin, ledState);
  }

  // Simpan status tombol saat ini sebagai status terakhir untuk perulangan berikutnya
  lastButtonState = currentButtonState;
}
