#pragma once

#ifndef header_h
#define header_h


using namespace std;	// bibliotheken
#include<iostream>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

#define GROESSE 20		// größe definieren

struct Statistikwerte	// struktur
{
	// Definitionen
	float mimumumwert_float;
	float maximumwert_float;
	float mittelwert_float;
	float streuung_float;
	// damit die entsprechenden stellen auch gezählt werden
	int modalwerte_float[GROESSE] = { 0 };
	float spannweite_float;
	float standartabweichung_float;
	int groesste_zahl;		// für modalwert
	int *integer_werte;
	float *float_werte;
};

// Funktionsdeklarationen
int pruefen_ob_zahl(char[GROESSE]);
int pruefen_gueltig(char[GROESSE]);
int pruefen_gueltig_integer(char[GROESSE]);
float pruefen_komma_zahl(char[GROESSE]);

void eingeben(int*, float*, int, int);
void ausgeben(struct Statistikwerte &statistikwerte,int*, float*, int, int);
void get_statistikwerte(struct Statistikwerte &statistikwerte,int*, float*, int, int);

#endif