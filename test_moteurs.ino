// Broches du L298N
#define borneENA        10      // On associe la borne "ENA" du L298N à la pin 10 de l'Arduino (PWM possible sur cette broche)
#define borneIN1        9
#define borneIN2        8

// Constantes du programme
#define d 20       //délai en ms avant changement de vitesse
#define vitesseMin 60       // rapport cylique min du signal PWM, faire tourner le moteur au min de sa vitesse
#define vitesseMax 255      // rapport cylique max du signal PWM

const char avant   = 'V';            // Défini une constante pour la "marche avant" (peu importe la valeur)
const char arriere = 'R';            // Défini une constante pour la "marche arrière" (peu importe la valeur)

// Variables du programme
int v;                    //vitesse de rotation du moteur entre 0 et 255


/////////////////////////////////////////////////////////////////////////////SET UP///////////////////////////////////////////////////////////////////////////
void setup() {
  // Configuration des pins de l'Arduino en "sortie
  pinMode(borneENA, OUTPUT);
  pinMode(borneIN1, OUTPUT);
  pinMode(borneIN2, OUTPUT);
}


///////////////////////////////////////////////////////////////////////////FONCTIONS//////////////////////////////////////////////////////////////////////////
// sensRotationA() - définit le sens de rotation du moteur
void sensRotationA(char a) {
  if(a == avant) {
    digitalWrite(borneIN1, HIGH);                 // Entrée IN1 au niveau haut    
  }
  else if(a == arriere) {
    digitalWrite(borneIN1, LOW);                  // Entrée IN1 au niveau bas
  }
}

// changeVitesseA() - change la vitesse de rotation du moteur - valeur doit être comprise entre 0 et 255
void changeVitesseA(int v) {
  analogWrite(borneENA, v);
}


//////////////////////////////////////////////////////////////////////////////////LOOP///////////////////////////////////////////////////////////////////////
void loop() {

  //MARCHE AVANT
  sensRotationA(avant);

  // 0 à vitesse maximale (signal PWM a un rapport cyclique = 255)
  for(v=vitesseMin ; v<vitesseMax ; v++) {
    changeVitesseA(v);            // Met à jour la vitesse du moteur, en modifiant le rapport cyclique du signal PWM envoyé
    delay(d);                // ... et on rajoute un petit délai pour que tout n'aille pas trop vite !
  }

  // vitesse max à 0
  for(v=vitesseMax ; v>vitesseMin ; v--) {
    changeVitesseA(v);            // Met à jour la vitesse du moteur, en modifiant le rapport cyclique du signal PWM envoyé
    delay(d);                // ... et on rajoute un petit délai pour que tout n'aille pas trop vite !
  }

  // Pause
  changeVitesseA(0);
  delay(1000);
  
  //MARCHE ARRIÈRE
  sensRotationA(arriere);

  // 0 à vitesse maximale (signal PWM a un rapport cyclique = 255)
  for(v=vitesseMin ; v<vitesseMax ; v++) {
    changeVitesseA(v);            // Met à jour la vitesse du moteur, en modifiant le rapport cyclique du signal PWM envoyé
    delay(d);                // ... et on rajoute un petit délai pour que tout n'aille pas trop vite !
  }

  // vitesse max à 0
  for(v=vitesseMax ; v>vitesseMin ; v--) {
    changeVitesseA(v);            // Met à jour la vitesse du moteur, en modifiant le rapport cyclique du signal PWM envoyé
    delay(d);                // ... et on rajoute un petit délai pour que tout n'aille pas trop vite !
  }
   
  //PAUSE
  changeVitesseA(0);
  delay(1000);
}