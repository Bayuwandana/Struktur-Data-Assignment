#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED

#define Nil NULL
typedef bool boolean;

typedef int infotypeanak;
typedef int infotypeinduk;

typedef struct elemen_list_induk *address;
typedef struct elemen_list_anak *address_anak;

/* ===== STRUCT ANAK ===== */
struct elemen_list_anak{
    infotypeanak info;
    address_anak next;
    address_anak prev;
};

struct listanak{
    address_anak first;
    address_anak last;
};

/* ===== STRUCT INDUK ===== */
struct elemen_list_induk{
    infotypeinduk info;
    listanak lanak;
    address next;
    address prev;
};

struct listinduk{
    address first;
    address last;
};

/* ===== PROTOTYPE ===== */
boolean ListEmpty(listinduk L);
boolean ListEmptyAnak(listanak L);

void CreateList(listinduk &L);
void CreateListAnak(listanak &L);

address alokasi(infotypeinduk x);
address_anak alokasiAnak(infotypeanak x);

void dealokasi(address P);
void dealokasiAnak(address_anak P);

void insertFirst(listinduk &L, address P);
void insertAfter(listinduk &L, address P, address Prec);
void insertLast(listinduk &L, address P);

void insertLastAnak(listanak &L, address_anak P);

void delFirst(listinduk &L, address &P);
void delLast(listinduk &L, address &P);

void printInfo(listinduk L);

#endif

