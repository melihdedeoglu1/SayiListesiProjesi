# SayiListesiProjesi
Bu proje, bir metin dosyasından okunan sayıları bağlı listeler yapısında saklayarak çeşitli manipülasyon işlemlerini gerçekleştiren bir C++ konsol uygulamasıdır.


# Sayı İşlemleri Projesi
Bu proje, bir metin dosyasından okunan sayıları bağlı listeler yapısında saklayarak çeşitli manipülasyon işlemlerini gerçekleştiren bir C++ konsol uygulamasıdır. Her bir sayı, basamaklarına ayrılarak bir bağlı liste (Sayi sınıfı içinde Basamak nesneleri) olarak temsil edilir. Bu sayılar da genel bir bağlı liste (SayilarListesi sınıfı içinde Dugum nesneleri) içinde tutulur.
# Proje Yapısı
Proje aşağıdaki temel sınıflardan oluşmaktadır:

Basamak: Bir sayının tek bir basamağını ve bir sonraki basamağa olan bağlantıyı tutar.

Sayi: Bir sayıyı, basamaklarından oluşan bir bağlı liste olarak temsil eder. Sayıyı basamaklarına ayırma, ters çevirme, gösterme gibi metotları içerir.

Dugum: SayilarListesi içinde her bir Sayi nesnesini ve bir sonraki Dugum'a olan bağlantıyı tutar.

SayilarListesi: Sayi nesnelerinden oluşan ana bağlı listedir. Listeye sayı ekleme, listeyi gösterme, tek basamakları başa alma, sayıları ters çevirme ve en büyük sayıyı çıkarma gibi işlemleri yönetir.

Proje dosyaları aşağıdaki gibi organize edilmiştir:.

├── include/        # Başlık (.hpp) dosyaları
│   ├── Basamak.hpp
│   ├── Dugum.hpp
│   ├── Sayi.hpp
│   └── SayilarListesi.hpp
├── lib/            # Derlenmiş nesne (.o) dosyaları
├── src/            # Kaynak (.cpp) dosyaları
│   ├── Basamak.cpp
│   ├── Dugum.cpp
│   ├── main.cpp
│   ├── Sayi.cpp
│   └── SayilarListesi.cpp
├── bin/            # Makefile çalıştırıldıktan sonra oluşan Çalıştırılabilir dosya
│   └── main.exe
├── Makefile        # Derleme talimatları
└── Sayilar.txt     # İşlenecek sayıları içeren metin dosyası

# Kullanım 
Eğer dosyaları manuel olarak indirdiyseniz, bir klasöre çıkarın ve o klasörde çalışın. DerlemeProje dosyalarını derlemek için proje kök dizinindeyken aşağıdaki komutu CMD (Komut İstemi) veya PowerShell üzerinden çalıştırın:mingw32-make

Bu komut, Makefile dosyasındaki derleme hedefini çalıştırarak gerekli .o dosyalarını ./lib/ klasörüne ve çalıştırılabilir main.exe dosyasını ./bin/ klasörüne oluşturacaktır.Alternatif olarak, sadece derleme yapmak için:mingw32-make derleme

Proje derlendikten sonra, çalıştırılabilir dosyayı komut satırı üzerinden çalıştırmak için Makefile içindeki calistirma hedefini kullanabilirsiniz:mingw32-make calistirma
Bu komut, ./bin/main.exe dosyasını çalıştıracaktır.Program başladığında, Sayilar.txt dosyasındaki sayıları okuyacak ve işleyecektir. Ardından kullanıcıya aşağıdaki gibi bir menü sunulacaktır:

############    ******* ******* *******
# 0xSayıAdresi #    * Adr1 * * Adr2 * * Adr3 *
#----------#    ******* ******* *******
#      Sayı  #    * Bs1  * * Bs2  * * Bs3  *
############    ******* ******* *******

1.Tek basamaklari Basa Al
2.Basamaklari Tersle
3.En Buyuk Cikar
4.cikis

İstediğiniz işlemi seçmek için ilgili numarayı girip Enter tuşuna basın.
Önemli: Programın doğru çalışabilmesi için proje kök dizininde Sayilar.txt adında bir dosya bulunmalı ve bu dosya içinde işlenecek sayılar (boşluk veya satırlarla ayrılmış) yer almalıdır.
