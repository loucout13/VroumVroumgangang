# VroumVroumgangang
Je suis dans ma Bugatti, t'es dans ta jalousie.

## Description du projet
Le projet "VroumVroumgangang" consiste en la création d'une voiture télécommandée équipée d'une caméra. 

L'objectif est de pouvoir contrôler la voiture via une interface web, et plus tard, de la piloter à l'aide d'une manette. 
La voiture sera dotée de plusieurs fonctions de déplacement et d'une caméra pour visualiser son environnement.

## Comment VroumVroum

### Fonctionnement du système avec le WEB
Le fichier `test_web2.ino` permet de lancer un serveur hébergé sur l'ESP32, qui sert à contrôler la voiture. Cependant, pour que l'ESP32 puisse se connecter à un réseau et fonctionner correctement, il doit être connecté à un partage de connexion (hotspot Wi-Fi). 

L'interface web associée au serveur comprend quatre boutons permettant de diriger la voiture :
- **Gauche**
- **Droite**
- **Avant**
- **Arrière**

Cette interface servira pour les tests de la voiture tant que la manette de contrôle ne sera pas disponible. Les utilisateurs pourront se connecter en créeant un réseau pour l'ESP32 et piloter la voiture via leur navigateur.

### Objectif avec deux ESP32 (voiture et manette)
- Verifier que ESP NOW ets plus performant que que le WIFI pour notre utilisation
- Créer la mannette avec deux joystick (un pour avancer/reculer et l'autre gacuhe droite. Peut etre les bloquer dans des rails pour seuement les faires bouger verticalement et horizontalement)

