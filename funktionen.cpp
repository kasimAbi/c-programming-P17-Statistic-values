#include "header.h"

// zum eingeben von den werten
void eingeben(int* int_werte, float* float_werte, int wahl, int anzahl)
{
	char eingabe[GROESSE];
	int index = 0, ok = 0;
	// solange was eingeben bis man halt die anzahl- variable erreicht hat
	for (index = 0; index < anzahl; index++)
	{
		cout << "geben sie ihre " << index + 1 << ".te zahl ein:" << endl;
		// wahl ist: entweder integer oder float
		if (wahl == 1)
		{
			cin >> eingabe;
			// löscht kommandozeile
			system("cls");
			// prüft ob der wert ein integer ist
			ok = pruefen_gueltig_integer(eingabe);
			// -1 ist minuszahl und 1 ist pluszahl darum != 0.
			if (ok != 0)
			{
				// wenn ja wandelt zahl in integer wert um
				int_werte[index] = pruefen_ob_zahl(eingabe);
			}
			else
			{
				// fehlermeldung
				index--;
				cout << "wiederholen sie ihre eingabe." << endl;
			}
		}
		else
		{
			cin >> eingabe;
			system("cls");
			// prüft ob float
			ok = pruefen_gueltig(eingabe);
			// 1 ist pluswert und 2 ist minuswert
			if (ok == 1 || ok == 2)
			{
				// wandelt zahl in float wert um
				float_werte[index] = pruefen_komma_zahl(eingabe);
			}
			else
			{
				// fehlermeldung
				index--;
				cout << "wiederholen sie ihre eingabe.\n\n" << endl;
			}
		}
	}
}

// die entsprechenden werte berechnen
void get_statistikwerte(struct Statistikwerte &statistikwerte, int *integer_werte, float *float_werte, int wahl, int anzahl)
{
	// initialisierungen/ deklarationen
	int index = 0, index2 = 0;
	// integer werten wahl = 1
	if (wahl == 1)
	{
		// Minimum berechnen
		// erste wert speichern
		statistikwerte.mimumumwert_float = integer_werte[0];
		// alle werte durchgehen. wenn eins kleiner ist dann 0 setzen
		for (int index = 1; index < anzahl; index++)
		{
			if (statistikwerte.mimumumwert_float > integer_werte[index])
			{
				statistikwerte.mimumumwert_float = integer_werte[index];
			}
		}

		// Maximum berechnen
		// das gleiche nur andersrum.
		statistikwerte.maximumwert_float = integer_werte[0];
		for (int index = 1; index < anzahl; index++)
		{
			if (statistikwerte.maximumwert_float < integer_werte[index])
			{
				statistikwerte.maximumwert_float = integer_werte[index];
			}
		}

		// Mittelwert berechnen
		statistikwerte.mittelwert_float = 0.0;
		// alle werte zsm addieren und dann durch die anzahl teilen
		for (int index = 0; index < anzahl; index++)
		{
			statistikwerte.mittelwert_float += integer_werte[index];
		}

		statistikwerte.mittelwert_float /= (float)anzahl;

		// Streuung berechen
		statistikwerte.streuung_float = 0.0;
		for (int index = 0; index < anzahl; index++)
		{
			// wurde vorgegeben also diese formel. s = (E(wert - mittelwert)²) / anzahl - 1.
			statistikwerte.streuung_float += pow(integer_werte[index] - statistikwerte.mittelwert_float, 2);
		}
		statistikwerte.streuung_float /= (float)anzahl - 1.0;

		// Standardabweichung berechnen
		// wurzel aus streuung. wurde vorgegeben.
		statistikwerte.standartabweichung_float = sqrt(statistikwerte.streuung_float);

		//-------------------------------------------------------------------------------------------------------------------------//
		// Häufigkeiten ermitteln
		int *schon_gehabt;
		int ueberspringe = 0;
		
		// schon_gehabt array größe wie die werte größe stellen also anzahl
		schon_gehabt = (int*)malloc(anzahl * sizeof(int));
		for (index = 0; index < anzahl; index++)
		{
			ueberspringe = 0;
			if (index != 0)
			{
				for (index2 = 0; index2 < anzahl; index2++)
				{
					// wenn die zahl schonmal vorkam
					if (integer_werte[index] == schon_gehabt[index2])
					{
						ueberspringe = 1;
					}
				}
			}
			if (ueberspringe != 1)
			{
				// wenn die zahl nicht vorkam
				for (index2 = 0; index2 < anzahl; index2++)
				{
					if (integer_werte[index] == integer_werte[index2])
					{
						// zählt die werte hoch also die anzahl wie oft die zahl vorkam und setzt schon_gehabt für diese zahl damit sie nciht
						// erneut untersucht wird.
						schon_gehabt[index] = integer_werte[index];
						statistikwerte.modalwerte_float[index]++;
					}
				}
			}
		}
		// größte zahl für die anzahl der meist vorkommenden zahlen speichern. wie bei maximumwert ausrechnen
		statistikwerte.groesste_zahl = statistikwerte.modalwerte_float[0];
		for (index = 0; index < anzahl; index++)
		{
			if (statistikwerte.groesste_zahl < statistikwerte.modalwerte_float[index])
			{
				statistikwerte.groesste_zahl = statistikwerte.modalwerte_float[index];
			}
		}

		
		//___________________________________________________________________________________________________________________________
	}
	// float werte
	if (wahl == 2)
	{
		// Minimum berechnen
		statistikwerte.mimumumwert_float = float_werte[0];
		for (index = 1; index < anzahl; index++)
		{
			if (statistikwerte.mimumumwert_float > float_werte[index])
			{
				statistikwerte.mimumumwert_float = float_werte[index];
			}
		}

		// Maximum berechnen
		statistikwerte.maximumwert_float = float_werte[0];
		for (int index = 1; index < anzahl; index++)
		{
			if (statistikwerte.maximumwert_float < float_werte[index])
			{
				statistikwerte.maximumwert_float = float_werte[index];
			}
		}

		// Mittelwert berechnen
		statistikwerte.mittelwert_float = 0.0;
		for (index = 0; index < anzahl; index++)
		{
			statistikwerte.mittelwert_float += float_werte[index];
		}

		statistikwerte.mittelwert_float /= (float)anzahl;

		// Streuung berechen
		statistikwerte.streuung_float = 0.0;
		for (index = 0; index < anzahl; index++)
		{
			statistikwerte.streuung_float += pow(float_werte[index] - statistikwerte.mittelwert_float, 2);
		}
		statistikwerte.streuung_float /= (float)anzahl - 1.0;

		// Standardabweichung berechnen
		statistikwerte.standartabweichung_float = sqrt(statistikwerte.streuung_float);
		//___________________________________________________________________________________________________________________________
		// Häufigkeiten ermitteln
		// genauso wir oben modalwert ausrechnen nur für float werte
		float *schon_gehabt_float;
		schon_gehabt_float = (float*)malloc(anzahl * sizeof(float));
		int ueberspringe = 0;
		for (index = 0; index < anzahl; index++)
		{
			ueberspringe = 0;
			if (index != 0)
			{
				for (index2 = 0; index2 < anzahl; index2++)
				{
					if (float_werte[index] == schon_gehabt_float[index2])
					{
						ueberspringe = 1;
					}
				}
			}
			if (ueberspringe != 1)
			{
				for (index2 = 0; index2 < anzahl; index2++)
				{
					if (float_werte[index] == float_werte[index2])
					{
						schon_gehabt_float[index] = float_werte[index];
						statistikwerte.modalwerte_float[index]++;
					}
				}
			}
		}
		statistikwerte.groesste_zahl = statistikwerte.modalwerte_float[0];
		for (index = 0; index < anzahl; index++)
		{
			if (statistikwerte.groesste_zahl < statistikwerte.modalwerte_float[index])
			{
				statistikwerte.groesste_zahl = statistikwerte.modalwerte_float[index];
			}
		}
	}
	// spannweite: max.wert - min.wert. wurde vorgegeben
	statistikwerte.spannweite_float = fabs(statistikwerte.maximumwert_float - statistikwerte.mimumumwert_float);
}


void ausgeben(Statistikwerte &statistikwerte, int* integer_werte, float* float_werte, int wahl, int anzahl)
{
	// initialisierungen für modalwert.
	int index = 0;
	// alles ausgeben
	cout << endl << "Minimalwert: " << statistikwerte.mimumumwert_float << endl;
	cout << "Maximalwert: " << statistikwerte.maximumwert_float << endl;
	cout << "Mittelwert:  " << statistikwerte.mittelwert_float << endl;
	cout << "Streuung:    " << statistikwerte.streuung_float << endl;
	cout << "Standardabweichung: " << statistikwerte.standartabweichung_float << endl;
	if (statistikwerte.modalwerte_float == NULL)
	{
		// wenn modalwert nciht vorhanden ist.
		cout << "Modalwert:   Nicht vorhanden" << endl;
	}
	else
	{
		// ansonsten geht er alle zahlen durch bis ein modalwert gefunden wurde
		for (index = 0; index < anzahl; index++)
		{
			// in modalwerte_float sind keine werte drin gespeichert sondern die anzahl der werte wie oft sie vorkamen.
			if (statistikwerte.modalwerte_float[index] == statistikwerte.groesste_zahl)
			{
				// für integer.
				if (wahl == 1)
				{	
					cout << "ihr Modalwert lautet: " << integer_werte[index] << endl;
					// index = anzahl setzen damit er nur ein modalwert ausgibt.
					index = anzahl;
				}
				// für float.
				if (wahl == 2)
				{
					cout << "ihr Modalwert lautet: " << float_werte[index] << endl;
					// index = anzahl setzen damit er nur ein modalwert ausgibt.
					index = anzahl;
				}
			}
		}
	}
	// gibt spannweite aus.
	cout << "Spannweite:  " << statistikwerte.spannweite_float << endl << endl;
}