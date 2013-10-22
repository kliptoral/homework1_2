#include <stdio.h>
#include <conio.h>
void main()
{
	int girilen_sayi;					// istenilen say�  (4 haneli olacak)
	int binlik;							// istenilen basamak say�s�; binlik, y�zl�k, onluk ve birlik say�s�
	int yuzluk;
	int onluk;
	int birlik;
	char cevap;
	cevap = 'e';
	while (cevap == 'e')				// say� ��z�mlendikten sonra kullan�c�ya devam etmek isteyip istemedi�i sorulsun...
	{
		printf ("Cozumlenecek sayi = "); 
		scanf ("%d", &girilen_sayi);		// klavyeden girilen ��z�mlenecek say�y�, girilen_sayi de�i�kenine aktarmak i�in kullan�l�r..
		printf ("\n");
		if (girilen_sayi >= 1000 && girilen_sayi <= 9999) // istenilen say� 4 haneli olaca��ndan if ko�ulunu kulland�m...
		{
			binlik = girilen_sayi / 1000;		// verilen 4 haneli say�n�n i�indeki binlik say�s�n� bulmak i�in say�m�z� 1000'e b�lmemiz yeterlidir.. 
			yuzluk = ((girilen_sayi) - (binlik * 1000)) / 100; // y�zl�k say�s�n� bulmam�z i�in binlik k�sm� yok etmek gerek. bunun en pratik yolu ise; girilen say� - (1000*binlik say�s�)
			onluk = ((girilen_sayi) - (binlik * 1000) - (yuzluk * 100)) / 10; // onluk say�s�n� bulmam�z i�in az once binlik k�sm�n� yok etti�imiz say�n�n �imdide y�zl�k k�sm�n� yok etmemiz gerekir..   
			birlik = ((girilen_sayi) - (binlik * 1000) - (yuzluk * 100) - (onluk * 10)); // birlik say�s�n� bulmam�z i�in ise bi �nceki y�zl�k k�sm�n� da yok ettigimiz say�n�n onluk k�sm�n� da yok ederek birlik k�sm�n� elde etmi� oluruz...
			printf ("Girilen Sayi = %d.\n", girilen_sayi);	// istenilen �ekilde listelemi� oluruz...
			printf ("\n%d tane binlik sayi\n", binlik);
			printf ("\n%d tane yuzluk sayi\n", yuzluk);
			printf ("\n%d tane onluk sayi\n", onluk);
			printf ("\n%d tane birlik sayi vardir...\n", birlik);
		}
		else				// 1000-9999 aras�nda olmayaca��ndan 4 haneli rakam olamaz ve hata uyar�s� verilsin
		{
			printf ("Yanlis Deger Girdiniz Lutfen 4 basamakli bir sayi giriniz...\n");
		}
		printf("\nDevam etmek istiyormusunuz (e'ye bas):"); // e harfi girildi�inde (cevap == 'e') ko�ulu do�ru olaca��ndan d�ng�deki i�lemler yeniden �al��acak...
		cevap = getche();									// girilecek karakteri (e) ekranda g�sterir...
		printf ("\n");
	}
	getch();							// program�m�z �al��t�r�l�p ekran c�kt�s� g�r�nt�lendikten sonra hicbir tusa bas�lmaks�z�n okunan karakteri de�i�keni aktar�r ve ��kt�y� g�r�nt�de tutar. bu fonksiyon i�in de gerekli olan "conio.h" header dosyas�n� da ba�ta eklemi� oldum..
}
