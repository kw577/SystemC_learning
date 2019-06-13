#include "tb.h"

//funkcja wysylajaca dane do modulu fir
void tb::source() {

	//resetowanie wejsc i wyjsc
	inp.write(0);
	rst.write(1);
	wait(); //czeka do nastepnego cyklu zegara
	rst.write(0); //do resetu nalezy najpierw wyslac 1 potem 0 - dopiero wtedy sygnal reset jest zakonczony
	wait();

	sc_int<16> tmp;

	//wyslanie przykladowego sygnalow do modulu fir
	for (int i = 0; i < 64; i++)
	{
		//przyjete przykladowe wartosci do wyslania do modulu fir
		if (i > 23 && i < 29)
			tmp = 256;
		else
			tmp = 0;

		//zapis sygnalu do wyjscia - polaczonego sygnalem z wejsciem modulu fir o nazwie inp
		inp.write(tmp); 

		//czeka do kolejnego cyklu zegara
		wait();

	}


}


// funkjca pobierajaca wartosci zwrotne z modulu fir
void tb::sink() {

	sc_int<16> indata;

	//funckja source wysyla 64 sygnaly zatem funkcja sink powinna odebrac rowniez 64 sygnaly
	for (int i = 0; i < 64; i++) {

		//czyta odpowiedz od modulu fir
		indata = outp.read();
		wait();

		//zapisanie wynikow
		cout << i << " : \t" << indata.to_int << endl;


	}

	//zakonczenie symulacji i uruchomienie destruktorow modulow
	sc_stop();

}