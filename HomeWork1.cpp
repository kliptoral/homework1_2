#include <stdio.h>
#include <conio.h>
void main ()
{
	int parola = 1234;       //kullanýcý kimliðini (hesap_no ile þifre) önceden belirledim
	int hesap_no = 666666;
	int gon_hesap_no;		 // para gönderilecek hesap numarasýný belirlemedim. kullanýcý rastgele hesap numarasýný kendisi girebilir.
	int islem_no;			 
	int yatirilan_miktar;
	int cekilen_miktar;
	int gon_miktar;
	int bakiye = 1000;		// kullanýcýnýn hesabýndaki baþlangýç parasý
	char cevap = 'e';		
	while (cevap == 'e')	// sistemde devam etmek isteyip istemediði kullanýcýya sorulsun. aksi taktirde (e dýþýnda herhangi bir tusa basýldýgýnda) program bitsin
	{
		printf ("Lutfen hesap numaranizi giriniz...: ");
		scanf ("%d", &hesap_no);
		printf ("\n");
		printf ("Lutfen sifrenizi giriniz...: ");
		scanf ("%d", &parola);
		printf ("\n");
		if(hesap_no == 666666 && parola == 1234)  // hesap_no ve þifre önceden belirlenmiþ bir þekilde girilerek sisteme giriþ yapýlsýn
		{											// aksi takdirde hata uyarýsý verip yeniden denenebilsin.
			while (cevap == 'e')					//sistemde baþka iþlem için devam etmek isteyip istemediði kullanýcýya sorulsan
			{
				printf (" # SAYIN FATIH AYGUN #\n");		// kullanýcý sisteme giriþ yaptýktan sonra yapacaðý iþlem için menü oluþturdum
				printf ("\n# SISTEME HOSGELDINIZ #\n");
				printf ("\n=======================\n");
				printf ("\n1. Bakiye Ogrenme\n");
				printf ("\n2. Para Yatirma\n");
				printf ("\n3. Para Cekme\n");
				printf ("\n4. Para Gonderme\n");
				printf ("\n5. Cikis\n");
				printf ("\nLutfen yapmak istediginiz islemi seciniz (1/2/3/4/5):"); // kullanýcý istediði iþlemi yapabilmek için iþlem numarasýný girmelidir.
				scanf ("%d", &islem_no);
				printf ("\n");
				switch(islem_no)		// iþlemin numarasýný girerek iþlemini yapmasý için switch-case yapýsýný kullandým
				{
					case 1:									// hesaptaki para miktarýný gösterme 
						printf ("Bakiyeniz %d TL", bakiye);  // ilk case yapýsý sadece hesabýndaki para miktarýný gösterir
						break;
					case 2:									// para yatýrma iþlemi
						printf ("Yatirilacak Miktar...: "); // kullanýcý yatýrýlacak miktarý belirledikten sonra para kullanýcýnýn hesabýndaki baþlangýç parasýna eklenir ve toplam bakiye gösterilir
						scanf ("%d",&yatirilan_miktar); 
						bakiye += yatirilan_miktar;
						printf ("\nPara yatirma isleminiz basariyla gerceklestirilmistir...\n");
						printf ("\nHesabinizdaki toplam bakiye %d TL", bakiye);
						break;
					case 3:									// para cekme islemi
						printf ("Cekilecek Miktar...: ");	// cekilecek para miktarýný kullanýcý girsin
						scanf("%d",&cekilen_miktar); 
						if (bakiye >= cekilen_miktar)		// cekilecek para hesaptaki paradan az yada hesaptaki para kadar olmalý. aksi takdirde hata uyarýsý versin
						{									// bunun için de if-else koþulu kullandým
							printf("\nCekilen Para Miktari: %d TL\n", cekilen_miktar);
							bakiye = (bakiye) - (cekilen_miktar);
							printf("\nHesabinizda %d TL kalmistir.",bakiye); 
						}
						else
						{									// eðer çekilecek para, hesaptaki paradan fazla ise hata uyarýsý "yetersiz bakiye" versin.. 
							printf ("\nHesabinizdaki toplam bakiye: %d TL\n", bakiye);
							printf ("\nCekilen para miktari: %d TL\n", cekilen_miktar);
							printf ("\nYetersiz Bakiye...");
						}
						break;
					case 4:
						printf ("Gonderilecek hesap numarasini giriniz...: "); // kullanýcý rasgele belirlediði hesap numarasýný girerek para gonderme iþlemini yapar..
						scanf ("%d", &gon_hesap_no);
						printf ("\nGondermek istediginiz tutari seciniz...: ");
						scanf ("%d", &gon_miktar);
						if (bakiye >= gon_miktar)								// 3. iþlemdeki gibi gondereceði para miktarý, hesabýndaki para miktarýndan fazla olmamalý
						{														// aksi takdirde hata uyarýsý versin. kullanýcý tekrar hesabýndaki para miktarý kadar yada daha az miktar gondermesi için iþlem tekrar kullanýcýya sorulsun.
							bakiye = (bakiye) - (gon_miktar);
							printf ("\nhesabinizda %d TL kalmistir.", bakiye);
						}
						else
						{
							printf ("\nHesabinizdaki toplam bakiye: %d TL\n", bakiye);
							printf ("\nGondermek istediginiz tutar: %d TL\n", gon_miktar);
							printf ("\nYetesiz Bakiye...");
						}
						break;
					case 5:
						printf ("Sistemden Cikmak Uzeresiniz...");				// cýkmak için
						break;
					default:													// iþlem numarasý farklý girildiðinde (1,2,3,4 dýþýnda)
						printf ("Yanlis secim yaptiniz. Lutfen tekrar deneyiniz...");
						break;
				}
				printf("\n\nIsleme devam etmek istiyor musunuz? (e): "); // menüden çýkmak/çýkmamak için
				cevap = getche();										// girilecek "e" karakterini ekranda gosterir
				printf("\n\n");
			}
		}
		else
		{
			printf ("Hesap numarasini ya da parolayi yanlis girdiniz.Lutfen tekrar deneyiniz...", hesap_no, parola);
		}
		printf("\n\nSistemde devam etmek istiyor musunuz? (e): ");	// sistemden çýkmak/çýkmamak için
		cevap = getche();											// girilecek "e" karakterini ekranda gosterir
		printf("\n\n");
	}
	getch();	// programýmýz çalýþtýrýlýp ekran cýktýsý görüntülendikten sonra hicbir tusa basýlmaksýzýn okunan karakteri deðiþkeni aktarýr ve çýktýyý görüntüde tutar. bu fonksiyon için de gerekli olan "conio.h" header dosyasýný da baþta eklemiþ oldum..
}