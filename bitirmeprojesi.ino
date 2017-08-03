int kirmiziPin = 5; // RGB'nin kırmızı led bacağı için pin tanımlıyoruz

int yesilPin = 10; // RGB'nin yeşil led bacağı için pin tanımlıyoruz

int maviPin = 11; // RGB'nin mavi led bacağı için pin tanımlıyoruz

int gIndex = 0; //Yeşil renk için başlangıç değerini 0 olarak belirtiyoruz
int bIndex = 0; //Mavi renk için başlangıç değerini 0 olarak belirtiyoruz
int rIndex = 0; //Kırmızı renk için başlangıç değerini 0 olarak belirtiyoruz


#define trigPin 9 // Ultrasonik mesafe sensörünün trig bacağı için pin tanımlıyoruz

#define echoPin 8 // Ultrasonik mesafe sensörünün echo bacağı için pin tanımlıyoruz

void setup()

{
  Serial.begin (9600); // Seri haberleşme hızını ayarlıyoruz
  //ultrasonik sensör üzerindeki trig pin sinyali gönderir, echo pin ise sinyali alır.
  //Yani Trig pin veri gönderdiği için output, Echo pin veri aldığı için inputtur. Aşağıda bunları belirliyoruz.
  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  pinMode(kirmiziPin, OUTPUT); //Kırmızı bacağın bağlı olduğu pini output olarak ayarlıyoruz.

  pinMode(yesilPin, OUTPUT); //Yeşil bacağın bağlı olduğu pini output olarak ayarlıyoruz.

  pinMode(maviPin, OUTPUT); //Mavi bacağın bağlı olduğu pini output olarak ayarlıyoruz.

}

void loop()

{
  long sure, distance; // Süreyi ve mesafeyi tanımlıyoruz
  digitalWrite(trigPin, LOW);  // Sensör kapatıldı
  delayMicroseconds(2); // 2 ms beklenildi
  digitalWrite(trigPin, HIGH); // Sensöre dalga üretmesi için komut gönderildi
  delayMicroseconds(10); // 10 ms beklenildi
  digitalWrite(trigPin, LOW); // Yeni dalgaların üretilmemesi için tekrar kapatıldı.
  sure = pulseIn(echoPin, HIGH); // Süreyi hesaplıyoruz
  distance = (sure / 2) / 29.1; // Ölçülen süre ile uzaklığı hesaplıyoruz

  //int rIndex, gIndex, bIndex;

  if (distance >= 0 && distance < 50) //eğer mesafe 0-50 cm arasında ise,
  {
    gIndex = 0; //Yeşil rengi 0 yap yani söndür
    bIndex = 0; // Aynı şekilde mabi rengide 0 yap
    //gIndex ve bIndex'i sıfırlayarak yeşil ve mavi rengi söndürüyor,sadece kırmızı rengi yakıyoruz.
    for (rIndex; rIndex <= 255; rIndex++)// Kırmızı renk değerini bir bir arttırarak ışık yanarken fade efekti veriyoruz.
    {
      changeColour(rIndex, gIndex, bIndex);
      delay(3); //3 ms bekliyoruz, bu sayıyı arttırırsanız daha yavaş bir şekilde yanacaktır
    }
  }
  if (distance >= 50 && distance < 100) // eğer mesage 50-100 cm arasında ise,
  {
    rIndex = 0; // kırmızı rengi 0 yap
    bIndex = 0; // mavi rengi 0 yap
    for (gIndex; gIndex <= 255; gIndex++) // Yeşil renk değerini bir bir arttırarak ışık yanarken fade efekti veriyoruz.
    {
      changeColour(rIndex, gIndex, bIndex);
      delay(3); //3 ms bekliyoruz, bu sayıyı arttırırssanız daha yavaş bir şekilde yanacaktır.
    }

  }
  if (distance >= 100 && distance < 150) // eğer mesafe 100-150 cm arasında ise,
  {
    rIndex = 0; // Kırmızı rengi 0 yap
    gIndex = 0; // Yeşil rengi 0 yap
    for (bIndex ; bIndex <= 255; bIndex++) // Mavi renk değerini bir bir arttır
    {
      changeColour(rIndex, gIndex, bIndex);
      delay(3);
    }

  }
  else // eğer yukarıdaki koşulların hiçbirini karşılamıyorsa,
  {
    rIndex = 0; //kırmızıyı sıfır yap
    gIndex = 0; // yeşili sıfır yap
    bIndex = 0; //maviyi sıfır yap
    //yani mesafe<0 ve mesafe>150 olursa hiçbir renk yanmayacak.
    changeColour(rIndex, gIndex, bIndex);
  }


}

void changeColour(int kirmizi, int yesil, int mavi) //renk değişimleri için renkleri tanımlıyoruz

{

  kirmizi = 255 - kirmizi; //ölçülen kırmızı değerden yeni bir kırmızı elde edilerek sürekli kırmızı yanmasını sağlar, tek seferlik çalışmaz

  yesil = 255 - yesil; //ölçülen yesil  değerden yeni bir yeşil elde edilerek sürekli yeşişl yanmasını sağlar, tek seferlik çalışmaz

  mavi = 255 - mavi; //ölçülen mavi değerden yeni bir mavi elde edilerek sürekli mavi yanmasını sağlar, tek seferlik çalışmaz

  analogWrite(kirmiziPin, kirmizi); //kirmiziPin'de kırmızı rengin yandığını belirtiyoruz

  analogWrite(yesilPin, yesil); //yesilPin'de yeşil rengin yandığını belirtiyoruz

  analogWrite(maviPin, mavi); //maviPin'de mavi rengin yandığını belirtiyoruz


}


