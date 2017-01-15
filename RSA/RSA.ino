// RSA_kriptiranje i dekriptiranje



int timer() {
    
    int mili=millis();
    return mili;
}

//Kriptiranje
int encrypt(int text, int n, int e){
  
   int sifrat=1;
   for(int i=0; i<e; i++){
    sifrat=sifrat*text%n;
    sifrat=sifrat % n;
  }
  return sifrat;
}

//Dekriptiranje
int decrypt(int sifrat, int n, int d){
  int desifrat=1;
  for(int i=0; i<d;i++){
    desifrat=desifrat*sifrat%n;
    desifrat=desifrat%n;
  }
  return desifrat;
}


//Odaberite dva velika prirodna broja
int p=17;
int q=23;

int s;

void setup() {
  
Serial.begin(9600);

int pocetak= timer();

int n=p*q;
int FIn=(p-1)*(q-1);

//Odaberite "e" prirodni broj manji od FIn
int e=35;

//Računamo "d"
int d=1;
do{
  s=(d*e)%FIn;
  d++;
}while(s!=1);
d=d-1;

String rijec = "Dorian i Goran kriptografija";

Serial.println("");
Serial.print("Izvorni tekst: ");
Serial.println(rijec);

//Ispis ključeva
Serial.print("Javni kljuc: {");
Serial.print(e);
Serial.print(",");
Serial.print(n);
Serial.print("}");

Serial.println("");
Serial.print("Tajni kljuc: {");
Serial.print(d);
Serial.print(",");
Serial.print(n);
Serial.println("}");

int duljinaR=rijec.length();

String sifra="";

//Kriptiranje
Serial.print("Kriptirani tekst: ");



for (int i=0; i<duljinaR;i++){
  char c = encrypt (rijec[i],n,e);
  sifra=sifra+c;
}


Serial.println(sifra);

String dsifra="";

//Dekriptiranje
int duljinaS=sifra.length();
Serial.print("Dekriptirani tekst: ");
for (int i=0; i<duljinaS; i++){
  char c = decrypt (sifra[i],n,d);
  dsifra=dsifra+c;
}
Serial.println(dsifra);

int kraj= timer();
int trajanje= kraj-pocetak;
Serial.print("Proteklo vrijeme: ");
Serial.print(trajanje);
Serial.println(" ms");
}
void loop() {
  
}
