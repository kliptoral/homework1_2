#include <stdio.h>
#include <conio.h>
void main()
{
	int girilen_sayi;					// istenilen sayý  (4 haneli olacak)
	int binlik;							// istenilen basamak sayýsý; binlik, yüzlük, onluk ve birlik sayýsý
	int yuzluk;
	int onluk;
	int birlik;
	char cevap;
	cevap = 'e';
	while (cevap == 'e')				// sayý çözümlendikten sonra kullanýcýya devam etmek isteyip istemediði sorulsun...
	{
		printf ("Cozumlenecek sayi = "); 
		scanf ("%d", &girilen_sayi);		// klavyeden girilen çözümlenecek sayýyý, girilen_sayi deðiþkenine aktarmak için kullanýlýr..
		printf ("\n");
		if (girilen_sayi >= 1000 && girilen_sayi <= 9999) // istenilen sayý 4 haneli olacaðýndan if koþulunu kullandým...
		{
			binlik = girilen_sayi / 1000;		// verilen 4 haneli sayýnýn içindeki binlik sayýsýný bulmak için sayýmýzý 1000'e bölmemiz yeterlidir.. 
			yuzluk = ((girilen_sayi) - (binlik * 1000)) / 100; // yüzlük sayýsýný bulmamýz için binlik kýsmý yok etmek gerek. bunun en pratik yolu ise; girilen sayý - (1000*binlik sayýsý)
			onluk = ((girilen_sayi) - (binlik * 1000) - (yuzluk * 100)) / 10; // onluk sayýsýný bulmamýz için az once binlik kýsmýný yok ettiðimiz sayýnýn þimdide yüzlük kýsmýný yok etmemiz gerekir..   
			birlik = ((girilen_sayi) - (binlik * 1000) - (yuzluk * 100) - (onluk * 10)); // birlik sayýsýný bulmamýz için ise bi önceki yüzlük kýsmýný da yok ettigimiz sayýnýn onluk kýsmýný da yok ederek birlik kýsmýný elde etmiþ oluruz...
			printf ("Girilen Sayi = %d.\n", girilen_sayi);	// istenilen þekilde listelemiþ oluruz...
			printf ("\n%d tane binlik sayi\n", binlik);
			printf ("\n%d tane yuzluk sayi\n", yuzluk);
			printf ("\n%d tane onluk sayi\n", onluk);
			printf ("\n%d tane birlik sayi vardir...\n", birlik);
		}
		else				// 1000-9999 arasýnda olmayacaðýndan 4 haneli rakam olamaz ve hata uyarýsý verilsin
		{
			printf ("Yanlis Deger Girdiniz Lutfen 4 basamakli bir sayi giriniz...\n");
		}
		printf("\nDevam etmek istiyormusunuz (e'ye bas):"); // e harfi girildiðinde (cevap == 'e') koþulu doðru olacaðýndan döngüdeki iþlemler yeniden çalýþacak...
		cevap = getche();									// girilecek karakteri (e) ekranda gösterir...
		printf ("\n");
	}
	getch();							// programýmýz çalýþtýrýlýp ekran cýktýsý görüntülendikten sonra hicbir tusa basýlmaksýzýn okunan karakteri deðiþkeni aktarýr ve çýktýyý görüntüde tutar. bu fonksiyon için de gerekli olan "conio.h" header dosyasýný da baþta eklemiþ oldum..
}
