# solarmax-motorized-tuning
Motorized tuning system for Solarmax III 90 double stack telescope

# Système de réglage motorisé pour Solarmax III 90 Double Stack

## Présentation

Ce projet propose un **système de motorisation des réglages** pour une lunette solaire Solarmax III 90 en configuration double stack.

L’objectif est de permettre un réglage **précis, reproductible et confortable** des bagues d’accord, sans manipulation directe sur l’instrument.
Le système est entièrement conçu dans une logique **DIY / open hardware**, avec :

* Électronique basée sur Arduino
* PCB personnalisés
* Pièces mécaniques imprimables en 3D
* Câblage modulaire

Il est particulièrement adapté aux astrophotographes et observateurs solaires souhaitant automatiser leur réglage sans modification permanente de l’instrument.

---

## Fonctionnalités principales

* Commande à distance via télécommande infrarouge
* 4 moteurs indépendants
* Réglage fin et répétable
* Câblage modulaire RJ12
* Boîtier compact
* Pièces 100% imprimables en 3D
* Composants économiques et faciles à trouver

---

## Architecture du système

### Vue d’ensemble

Le système se compose de trois sous-ensembles principaux :

1. Électronique de contrôle
2. Cartes adaptatrices moteurs
3. Ensemble mécanique

---

## Électronique

### Carte principale

Carte conçue avec **KiCad** et fabriquée chez **JLCPCB**.

#### Fonctions

* Support Arduino Nano
* Pilotage de 4 moteurs pas-à-pas
* Réception infrarouge
* Distribution alimentation
* Connectique RJ12 pour moteurs

#### Caractéristiques

* PCB double couche
* Composants traversants (facilité d’assemblage)
* Conception compacte

---

### Composants principaux

| Composant        | Rôle                   |
| ---------------- | ---------------------- |
| Arduino Nano     | Contrôleur principal   |
| 4 × ULN2003AN    | Drivers moteurs        |
| 4 × 28BYJ-48 5V  | Moteurs pas-à-pas      |
| Récepteur IR     | Interface télécommande |
| Régulateur 5V    | 9v vers 5v LM7805      |
| Connecteurs RJ12 | Liaison moteurs        |
| JST-XH5          | Connexion côté moteur  |

---

### Cartes adaptatrices RJ12 → JST-XH5

Quatre petites cartes dédiées permettent :

* Conversion RJ12 vers connecteur moteur standard
* Déport des connexions près des moteurs
* Maintenance facilitée

Elles sont volontairement simples pour un assemblage rapide.

---

## Partie mécanique

### Conception

Toutes les pièces mécaniques ont été conçues avec **FreeCAD** et optimisées pour l’impression 3D FDM.

### Éléments fournis

* Boîtier électronique
* Supports moteurs
* Interfaces de fixation sur la lunette (brides)
* Systèmes de maintien des câbles (optionnel)

### Objectifs de conception

* Montage sans modification irréversible de la lunette
* Démontage rapide
* Rigidité suffisante pour réglages fins
* Impression sans supports complexes

---

### Paramètres d’impression recommandés

| Paramètre         | Valeur conseillée |
| ----------------- | ----------------- |
| Technologie       | FDM               |
| Buse              | 0.4 mm            |
| Hauteur de couche | 0.2 mm            |
| Remplissage       | 20–30%            |
| Matériau          | PETG recommandé   |

#### Remarques

* PETG pour stabilité thermique
* ABS possible en environnement chaud
* PLA déconseillé en plein soleil

---

## Firmware

Le firmware est conçu pour un **Arduino Nano**.

### Fonctions

* Décodage télécommande infrarouge
* Sélection individuelle des moteurs
* Contrôle pas-à-pas
* Gestion du sens de rotation
* Réglage fin des déplacements

### Dépendances typiques

* IRremote (ou équivalent)
* Librairies stepper Arduino ou implémentation custom

Voir le dossier `/firmware` pour :

* Code source
* Mapping télécommande
* Instructions de compilation

---

## Câblage

### Principe

Chaque moteur est relié via :

Carte principale → RJ12 → Câble → Carte adaptatrice → JST-XH5 → Moteur

### Avantages

* Modularité
* Remplacement rapide
* Longueur de câble adaptable
* Installation propre

---

## Alimentation

### Spécifications

* Tension : 9V DC (pile)
* Courant recommandé : ≥ 2A



---

## Assemblage

### 1. Assemblage électronique

1. Souder les connecteurs sur la carte principale
2. Installer les ULN2003AN
3. Ajouter les headers Arduino
4. Flasher le firmware
5. Tester le récepteur IR
6. Tester chaque moteur individuellement

---

### 2. Cartes adaptatrices

1. Souder RJ12 et JST-XH5
2. Vérifier continuité
3. Identifier chaque moteur

---

### 3. Assemblage mécanique

1. Imprimer toutes les pièces STL
2. Monter les moteurs dans leurs supports
3. Installer les supports sur la lunette
4. Monter l’électronique dans le boîtier
5. Installer le câblage

---

## Calibration

Procédure recommandée :

1. Test à vide (sans charge mécanique)
2. Vérification sens de rotation
3. Correction firmware si nécessaire
4. Installation sur la lunette
5. Définition position neutre
6. Tests de réglage fin

---

## Utilisation

1. Mettre sous tension
2. Pointer la télécommande vers le récepteur
3. Sélectionner le moteur
4. Ajuster le réglage

Le mapping des touches est documenté dans le firmware.

---

## Structure du dépôt

```
/hardware
  /kicad-main-board
  /adapter-pcbs

/mechanical
  /freecad
  /stl

/firmware

/docs
  photos
  schémas
  câblage
```

---

## Fabrication

### PCB

* Compatible JLCPCB standard
* 2 couches
* Fichiers Gerber fournis

---

### Impression 3D

Testé sur imprimantes FDM standard.
Aucune contrainte particulière.

---

## Améliorations possibles

* Contrôle Bluetooth ou WiFi
* Intégration ASCOM / INDI
* Écran OLED
* Positions mémorisées
* Drivers silencieux (TMC)
* Version autonome sur batterie
* Capteurs de position

---


## Licence

Licence MIT (modifiable selon votre choix).

---


