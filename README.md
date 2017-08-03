# ULTRASONİK MESAFE(HC-SR04) SENSÖRÜ İLE MESAFEYE GÖRE RGB LED YAKMA

Arduino'ya giriş için basit bir proje. Bu projede ultrasonik mesafe sensörü(HCSR-04) kullanarak mesafeye göre RGB led yakacağız.

### MALZEME LİSTESİ
* HC-SR04 Ultrasonik Mesafe Sensörü
* Dişi-Erkek Jumper Kablo
* Erkek-Erkek Jumper Kablo
* Arduino Uno
*	Mini boy Breadboard
* RGB Led x4 ( Daha güçlü ışık vermesi için 4 adet kullandım, bu sizin isteğinize bağlı bir şey)

Öncelikle `HC-SR04'ten` birazcık bahsedelim:

![HCSR-04 PİC.](http://www.dhresource.com/260x260s/f2-albu-g5-M00-80-CD-rBVaI1kB-4qALHT6AAGXek7jOq4367.jpg/ivolador-ultrasonic-module-hc-sr04-distance.jpg)

Yukarıdaki Ultrasonik  Mesafe Sensörü(HC-SR04) `2-400 cm` arasında ölçüm yapar. 

Trig pininden ve Echo pininden gelen değerler arasındaki süreyi hesaplayarak bize doğru sonucu ulaştırır.

Toplamda 4 bacağı bulunur, bunlar:

```js
Vcc: 5 Volt yük ile beslenir.
Trig: Bu pinden çıkan sinyal ultrasonik bir dalga yayılmasını sağlar ve echo pinini aktifleştirir.
Echo: Trig pininden çıkan ultrasonik dalgayı alır.
Gnd: Topraklamadır, Arduino’da Gnd pinine bağlanır.
```

### DEVRE ŞEMASI

> Tasarım kısmı malzeme listesi ve yapım aşaması için link




