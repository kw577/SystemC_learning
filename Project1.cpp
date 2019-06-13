#include <systemc.h>

/////////////////////////////////
//PRZYKLAD - ten plik nie jest uzywany w projekcie
/////////////////////////////////

//deklaracja modulu and2
SC_MODULE(and2) {
	sc_in< sc_uint<1> >		a; //wejscie unsigned int (wektor z 1na wartoscia)
	sc_in< sc_uint<1> >		b; //wejscie
	sc_out< sc_uint<1> >	f; //wyjscie 
	sc_in<bool>		clk; //zegar

	//deklaracja funkcji
	void func() {

		f.write(a.read() & b.read());

	}


	//konstruktor
	SC_CTOR(and2) {

		//jeden z 3 typow watkow w systemC - wykonywalny 1 raz
		SC_METHOD(func);

		//dziala na sygnal zegara - rising edge
		sensitive << clk.pos();

		//dziala na sygnal zegara - falling edge
		//sensitive << clk.pos();

	}


}