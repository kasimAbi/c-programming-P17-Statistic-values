#include "header.h"
// main
int main()
{
	// initialisierungen/ Deklarationen
	int wahl = 0, anzahl = 0, index = 0;
	char eingabe[GROESSE];
	Statistikwerte meine_werte;

	// w�hlen
	while (wahl != 3)
	{
		// alles auf 0 setzen
		wahl = 0;
		anzahl = 0;
		index = 0;
		cout << "womit moechten sie arbeiten?\n (1) integer- werten.\n (2) float- werten.\n (3) programm beenden.\n" << endl;
		cin >> eingabe;
		// pr�ft ob zahl integer ist.
		wahl = pruefen_gueltig_integer(eingabe);
		// wenn wahl 1
		if (wahl == 1)
		{
			// wandelt in zahl um.
			wahl = pruefen_ob_zahl(eingabe);
		}
		else
		{
			wahl = 0;
		}
		// 1 ist f�r pluszahl und 2 f�r minuszahl. das sind die werte die von pr�efen_ob_zahl zur�ck gegeben werden.
		if (wahl == 1 || wahl == 2)
		{
			// 0 oder 2 weil entweder ungueltige zahl oder - zahl
			while (anzahl == 0 || anzahl == 2)
			{
				cout << "mit wie vielen werten moechten sie arbeiten?\n" << endl;
				cin >> eingabe;
				// l�scht kommandozeile.
				system("cls");
				anzahl = pruefen_gueltig_integer(eingabe);
				// weil pr�fen_g�ltig_integer nur eine 1 f�r positive werte gibt muss gepr�ft werden ob die zahl eine 1 ist.
				if (anzahl == 1)
				{
					// wandelt zahl um.
					anzahl = pruefen_ob_zahl(eingabe);
					// integer
					if (wahl == 1)
					{
						// setzt es dementsprechend gro�
						meine_werte.integer_werte = (int*)malloc(anzahl * sizeof(int));
						if (meine_werte.integer_werte == NULL)
						{
							// fehlermeldung
							cout << "speicher konnte nciht gesetzt werden.\n" << endl;
							return 0;
						}
					}
					else
					{
						// float werte
						meine_werte.float_werte = (float*)malloc(anzahl * sizeof(float));
						if (meine_werte.float_werte == NULL)
						{
							// fehlermeldung
							cout << "speicher konnte nciht gesetzt werden.\n" << endl;
							return 0;
						}
					}
					// funktionsaufrufe.
					eingeben(meine_werte.integer_werte, meine_werte.float_werte, wahl, anzahl);
					get_statistikwerte(meine_werte, meine_werte.integer_werte, meine_werte.float_werte, wahl, anzahl);
					ausgeben(meine_werte, meine_werte.integer_werte, meine_werte.float_werte, wahl, anzahl);
				}
			}
		}
		// programm beenden.
		if (wahl == 3)
		{
			cout << "programm wird beendet.\n" << endl;
		}
	}
	return 0;
}