# Structures de données en C

Ce dépôt contient les implémentations des **principales structures de données** en **langage C**.  
Chaque structure est organisée dans son propre dossier, avec des fichiers séparés pour le code source (`.c`), les en-têtes (`.h`) et un fichier `main.c` pour les tests.

---

## 📁 Structure du projet

```bash
├── doubly_linked_list
│   ├── doubly_linked_list
│   ├── doubly_linked_list.c
│   ├── doubly_linked_list.h
│   └── main.c
├── linked_list
│   ├── linked_list.c
│   ├── linked_list.h
│   ├── main.c
│   └── test
├── queue
│   ├── main.c
│   ├── queue
│   ├── queue.c
│   └── queue.h
└── stack
    ├── main.c
    ├── stack
    ├── stack.c
    └── stack.h

5 directories, 16 files


## ⚙️ Compilation et exécution

Chaque module peut être compilé séparément avec `gcc` :

cd linked_list
gcc main.c linked_list.c -o linked_list
./linked_list
