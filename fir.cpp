#include <systemc.h>
#include "fir.h"

//FIR main thread
void fir::fir_main(void)
{
	sc_int<16> taps[5];


	//Resetowanie wyjscia
	outp.write(0);
	wait(); //czeka na sygnal zegara

	while (true) {

		for (int i = 4; i > 0; i--) {
			taps[i] = taps[i - 1];
			
		}

		//odczytywanie wartosci z portu in
		taps[0] = inp.read();

		//deklaracja tymczasowej zmiennej do przechowywania wartosci
		sc_int<16> val;

		for (int i = 0; i < 5; i++) {
			//val += coef[i] * taps[i];
			val +=2 * taps[i];
		}

		outp.write(val);
		wait(); //czeka na zegar

	}

}
