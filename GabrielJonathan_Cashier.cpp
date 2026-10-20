#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	char Kode [12][9] = {
	"BRG001" , "BRG002" , "BRG003" , "BRG004" , "BRG005" , "BRG006" , "BRG007" , "BRG008" , "BRG009" , "BRG010"
	};
	
	char NamaBarang [12][30] = {
	"Keyboard Mechanical RGB" , "Mouse Wireless" , "Mousepad XL" , "Headset Gaming" , "Webcam Full HD 1080P" ,
	"Monitor 24 inch IPS" , "Flashdisk 64 GB" , "SSD 512 GB" , "USB Hub 4 Port" , "Speaker Bluetooth"
	};
	
	char Kategori [12][15] = {
	"Keyboard" , "Mouse" , "Aksesoris", "Audio" , "Kamera", "Monitor" , "Penyimpanan" , "Penyimpanan" ,
	"Aksesoris" , "Audio"
	};
	
	int Harga [12] = {
		450000, 150000, 85000, 375000, 320000, 1850000, 95000, 650000, 75000, 280000
	};
	
	int Stok [12] = {
		15, 25, 30, 12, 10, 8, 40, 18, 20, 14
	};
	
	
	int keranjang [12] = {0};
	
	int No;
	int Banyak_barang;
	
	
	
	
	
	
	void Checkout (){
		int Bayar;
		int total_semua = 0;
		
		time_t waktu = time(NULL);
		
		for (int i = 0; i < 10; i++){
			total_semua += keranjang[i] * Harga[i];
		}
		
		if (total_semua == 0){                                  
			system ("cls");
			printf ("\n\nKeranjang masih kosong!\n\n");
			return;
		}
		
		printf ("==================== STRUK BELANJA ====================\n");
		printf ("Tanggal : %s", ctime(&waktu));
		printf ("-------------------------------------------------------\n");
		
		for (int i = 0; i < 10; i++){
			if (keranjang[i] != 0){
				int Total_sementara = keranjang[i] * Harga[i];
				printf ("%-25s %5d x %-9d %-9d\n", NamaBarang[i], keranjang[i], Harga[i], Total_sementara);
			}		
		}
		
		
		
		printf ("-------------------------------------------------------\n");
		printf ("%39s", "Total : Rp ");
		printf ("%d\n", total_semua);
		
		do {
			printf ("%39s", "Bayar : Rp");
			scanf (" %d", &Bayar);
			if (Bayar < total_semua){
				printf ("Silahkan masukan uang! Uang anda kurang.");
			}
		} while (Bayar < total_semua);
		
		int kembali = Bayar - total_semua;
		printf ("%39s", "Kembalian : Rp ");
		printf ("%d\n", kembali);
		
		for (int i = 0; i < 10; i++){
			keranjang [i] = 0;
		}
		
		printf ("=======================================================\n");
		printf ("Terimakasih sudah berbelanja!\n");
		
	}
	
	
	
	
	
	void Removecart(){
		printf ("Manakah barang yang ingin di remove? Input [1 - 10]: ");
		scanf ("%d", &No);
		
		if (No < 1 || No > 10 || keranjang[No -1] == 0){
			system ("cls");
			printf ("\n\nInput tidak valid!   Masukan Input yang benar!\n\n");
			return;
		} 
		
		No -= 1;
		
		Stok [No] += keranjang[No];
		printf ("Anda sudah meremove barang %s sebanyak %d", NamaBarang[No], keranjang[No]);
		
		keranjang [No] = 0;
		
		
			
	}




void Editcart(){
	int Banyak_barang_baru;
	int total = 0;
	int selisih;
	
	printf ("Manakah barang yang ingin diubah? Input [1-10]: ");
	scanf ("%d", &No);
	
	if (No < 1 || No > 10 || keranjang[No -1] == 0){
		system ("cls");
		printf ("\n\nInput tidak valid!   Masukan Input yang benar!\n\n");
		return;
	} 
	
	printf ("Masukan jumlah baru yang diinginkan : ");
	scanf (" %d", &Banyak_barang_baru);
	
	selisih = Banyak_barang_baru - keranjang[No - 1];
	
	No -= 1;
	
	if (Banyak_barang_baru <= 0 || selisih > Stok[No]) {
		system ("cls");
		printf ("\n\nJumlah tidak valid atau stok tidak cukup!\n\n");
		return;
	} 
	
	
	Stok [No] -= selisih;
	keranjang [No] = Banyak_barang_baru;
	
	printf ("Jumlah %s berhasil diubah menjadi %d!\n\n", NamaBarang[No], Banyak_barang_baru);
	
}






void Viewcart (){
	system ("cls");
	int kondisi = 0;
	int total = 0;
	
	printf ("%-3s %-25s %15s %13s %15s\n", "No", "Nama Barang", "Jumlah Barang", "Harga", "Subtotal");
	printf ("----------------------------------------------------------------------------\n");
	for (int i = 0; i < 10; i++){
		if (keranjang[i] > 0){
			printf ("%-3d %-25s %15d %13d %15d\n", i + 1, NamaBarang[i], keranjang[i], Harga[i], keranjang[i] * Harga[i]);
			
			total += keranjang[i] * Harga[i];
			kondisi = 1;
		}	
	}
	
	if (kondisi == 0){
			printf ("\n\nKeranjang masih kosong. \n\n");
			
	} else {
		printf ("----------------------------------------------------------------------------\n");
		printf ("Total = Rp %d\n\n\n", total);	
	}	
}






void Addtocart(){
	
	printf ("Silahkan memilih barang [Input 1 - 10]: ");
	scanf ("%d", &No);
	
	if (No < 1 || No > 10){
		system ("cls");
		printf ("\n\nInput tidak valid!   Masukan Input yang benar!\n\n");
		return;
	} 
	
	printf ("Silahkan memilih banyak barang yang akan dibeli: ");
	scanf ("%d",&Banyak_barang);
	
	No -= 1;
	
	if (Banyak_barang <= 0 || Banyak_barang > Stok[No]) {
		system ("cls");
		printf ("\n\nInput tidak valid!   Masukan Input yang benar!\n\n");
		return;
	} 
	
	keranjang [No] += Banyak_barang;
	Stok [No] -= Banyak_barang;
	
	printf ("\n%s sebanyak %d berhasil ditambahkan ke cart!\n\n", NamaBarang[No], Banyak_barang);
}






void listBarang(){
	system ("cls");
	
	
	printf ("%-3s %-8s %-25s %-12s %10s %7s\n", "No", "Kode", "Nama Barang", "Kategori", "Harga", "Stok");
	printf("-------------------------------------------------------------------------\n");
	
	for (int i = 0; i < 10; i++){
		printf ("%-3d %-8s %-25s %-12s %10d %6d\n", i + 1, Kode[i], NamaBarang[i], Kategori[i], Harga[i], Stok[i]);
	}
	
	printf ("\n\n");
	
}




void InterfaceMenuAwal(){
	
	printf ("===============================================\n");
	printf ("\t\tTRANSAKSI KASIR\n");
	printf ("===============================================\n");
	printf ("1. List Barang\t\t2. Add to Cart\n");
	printf ("3. Remove from Cart\t4. Edit Cart\n");
	printf ("5. View Cart\t\t6. Checkout\n");
	printf ("0. Keluar\n");
	printf ("------------------------------------------------\n");
	printf (">> Pilih Menu: ");
}







int main (){
	
	int menu;
	char nambahgak;
	char Ubahgak;
	char removegak;
	
	do {
		InterfaceMenuAwal();
		scanf ("%d", &menu);
		
		switch (menu){
			case 1:
				// listbarang
				
				listBarang();
				break;
			
			case 2:
				//add to cart
				
				do {
					listBarang();
					Addtocart();
					printf ("Tambah barang lagi gak? (y/n) :\n");
					scanf (" %c", &nambahgak);
					
				} while ( nambahgak == 'y' || nambahgak == 'Y' );
				
				system ("cls");
				break;
			
			case 3:
				//remove from cart
				
				do {
					Viewcart();
					Removecart();
					printf ("\n\nRemove barang lagi gak? (y/n) :\n");
					scanf (" %c", &removegak);
				} while (removegak == 'y' || removegak == 'Y');
				
				system ("cls");
				break;
			
			case 4:
				// edit cart
				
				do {
					Viewcart();
					Editcart();
					printf ("Mau ubah barang lagi gak? (y/n) :\n");
					scanf (" %c", &Ubahgak);
					
				} while ( Ubahgak == 'y' || Ubahgak == 'Y' );
				
				system ("cls");
				break;
			
			case 5:
				//View cart
				
				Viewcart();
				break;
			
			case 6:
				//Checkout
				
				Checkout();
				break;
				
			case 0:
				// Exit
				system ("cls");
				printf ("Terimakasih sudah berkunjung");
				break;
				
			default:
				system ("cls");
				printf ("\n\nInput tidak valid\n\n\n");
				
		}
	} 	while ( menu != 0);
	
	
	
	
	
	
	return 0;
}

