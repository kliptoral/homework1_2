#include <stdio.h>
#include <conio.h>
void main ()
{
	int parola = 1234;       //kullan�c� kimli�ini (hesap_no ile �ifre) �nceden belirledim
	int hesap_no = 666666;
	int gon_hesap_no;		 // para g�nderilecek hesap numaras�n� belirlemedim. kullan�c� rastgele hesap numaras�n� kendisi girebilir.
	int islem_no;			 
	int yatirilan_miktar;
	int cekilen_miktar;
	int gon_miktar;
	int bakiye = 1000;		// kullan�c�n�n hesab�ndaki ba�lang�� paras�
	char cevap = 'e';		
	while (cevap == 'e')	// sistemde devam etmek isteyip istemedi�i kullan�c�ya sorulsun. aksi taktirde (e d���nda herhangi bir tusa bas�ld�g�nda) program bitsin
	{
		printf ("Lutfen hesap numaranizi giriniz...: ");
		scanf ("%d", &hesap_no);
		printf ("\n");
		printf ("Lutfen sifrenizi giriniz...: ");
		scanf ("%d", &parola);
		printf ("\n");
		if(hesap_no == 666666 && parola == 1234)  // hesap_no ve �ifre �nceden belirlenmi� bir �ekilde girilerek sisteme giri� yap�ls�n
		{											// aksi takdirde hata uyar�s� verip yeniden denenebilsin.
			while (cevap == 'e')					//sistemde ba�ka i�lem i�in devam etmek isteyip istemedi�i kullan�c�ya sorulsan
			{
				printf (" # SAYIN FATIH AYGUN #\n");		// kullan�c� sisteme giri� yapt�ktan sonra yapaca�� i�lem i�in men� olu�turdum
				printf ("\n# SISTEME HOSGELDINIZ #\n");
				printf ("\n=======================\n");
				printf ("\n1. Bakiye Ogrenme\n");
				printf ("\n2. Para Yatirma\n");
				printf ("\n3. Para Cekme\n");
				printf ("\n4. Para Gonderme\n");
				printf ("\n5. Cikis\n");
				printf ("\nLutfen yapmak istediginiz islemi seciniz (1/2/3/4/5):"); // kullan�c� istedi�i i�lemi yapabilmek i�in i�lem numaras�n� girmelidir.
				scanf ("%d", &islem_no);
				printf ("\n");
				switch(islem_no)		// i�lemin numaras�n� girerek i�lemini yapmas� i�in switch-case yap�s�n� kulland�m
				{
					case 1:									// hesaptaki para miktar�n� g�sterme 
						printf ("Bakiyeniz %d TL", bakiye);  // ilk case yap�s� sadece hesab�ndaki para miktar�n� g�sterir
						break;
					case 2:									// para yat�rma i�lemi
						printf ("Yatirilacak Miktar...: "); // kullan�c� yat�r�lacak miktar� belirledikten sonra para kullan�c�n�n hesab�ndaki ba�lang�� paras�na eklenir ve toplam bakiye g�sterilir
						scanf ("%d",&yatirilan_miktar); 
						bakiye += yatirilan_miktar;
						printf ("\nPara yatirma isleminiz basariyla gerceklestirilmistir...\n");
						printf ("\nHesabinizdaki toplam bakiye %d TL", bakiye);
						break;
					case 3:									// para cekme islemi
						printf ("Cekilecek Miktar...: ");	// cekilecek para miktar�n� kullan�c� girsin
						scanf("%d",&cekilen_miktar); 
						if (bakiye >= cekilen_miktar)		// cekilecek para hesaptaki paradan az yada hesaptaki para kadar olmal�. aksi takdirde hata uyar�s� versin
						{									// bunun i�in de if-else ko�ulu kulland�m
							printf("\nCekilen Para Miktari: %d TL\n", cekilen_miktar);
							bakiye = (bakiye) - (cekilen_miktar);
							printf("\nHesabinizda %d TL kalmistir.",bakiye); 
						}
						else
						{									// e�er �ekilecek para, hesaptaki paradan fazla ise hata uyar�s� "yetersiz bakiye" versin.. 
							printf ("\nHesabinizdaki toplam bakiye: %d TL\n", bakiye);
							printf ("\nCekilen para miktari: %d TL\n", cekilen_miktar);
							printf ("\nYetersiz Bakiye...");
						}
						break;
					case 4:
						printf ("Gonderilecek hesap numarasini giriniz...: "); // kullan�c� rasgele belirledi�i hesap numaras�n� girerek para gonderme i�lemini yapar..
						scanf ("%d", &gon_hesap_no);
						printf ("\nGondermek istediginiz tutari seciniz...: ");
						scanf ("%d", &gon_miktar);
						if (bakiye >= gon_miktar)								// 3. i�lemdeki gibi gonderece�i para miktar�, hesab�ndaki para miktar�ndan fazla olmamal�
						{														// aksi takdirde hata uyar�s� versin. kullan�c� tekrar hesab�ndaki para miktar� kadar yada daha az miktar gondermesi i�in i�lem tekrar kullan�c�ya sorulsun.
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
						printf ("Sistemden Cikmak Uzeresiniz...");				// c�kmak i�in
						break;
					default:													// i�lem numaras� farkl� girildi�inde (1,2,3,4 d���nda)
						printf ("Yanlis secim yaptiniz. Lutfen tekrar deneyiniz...");
						break;
				}
				printf("\n\nIsleme devam etmek istiyor musunuz? (e): "); // men�den ��kmak/��kmamak i�in
				cevap = getche();										// girilecek "e" karakterini ekranda gosterir
				printf("\n\n");
			}
		}
		else
		{
			printf ("Hesap numarasini ya da parolayi yanlis girdiniz.Lutfen tekrar deneyiniz...", hesap_no, parola);
		}
		printf("\n\nSistemde devam etmek istiyor musunuz? (e): ");	// sistemden ��kmak/��kmamak i�in
		cevap = getche();											// girilecek "e" karakterini ekranda gosterir
		printf("\n\n");
	}
	getch();	// program�m�z �al��t�r�l�p ekran c�kt�s� g�r�nt�lendikten sonra hicbir tusa bas�lmaks�z�n okunan karakteri de�i�keni aktar�r ve ��kt�y� g�r�nt�de tutar. bu fonksiyon i�in de gerekli olan "conio.h" header dosyas�n� da ba�ta eklemi� oldum..
}