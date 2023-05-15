// Se ingresa:
//
// - Número de Cuenta
// - Saldo en Caja de Ahorro
// - Saldo en Cuenta Corriente
//
// Cargar una lista con estos datos.
//
// La carga de datos finaliza cuando el número de cuenta del cliente es cero.
//
// a) Generar una nueva lista con el número de cuenta de cada cliente y su
//   saldo unificado.
//
// b) Eliminar las cuentas de aquellos clientes con saldo negativo en la caja
//   de ahorro o en la cuenta corriente
//
// c) Ordenar la lista segun el número de cuenta de menor a mayor.
//
// d) Ingresar los datos de un nuevo cliente e insertarlo manteniendo el orden
// de la lista.

#include <stdio.h>
#include <stdlib.h>

// Registro de la cuenta de un cliente
typedef struct IRecord {
  int account;
  int savings;
  int balance;
  struct IRecord* next;
} Record;

// Registro con datos fusionados
typedef struct IMergedRecord {
  int account;
  int balance;
  struct IMergedRecord* next;
} MergedRecord;

void load(Record*);
void show(Record*);
MergedRecord* merge(Record*);

int main() {
  Record* list = malloc(sizeof(Record));

  load(list);

  if (list -> next == NULL) {
    printf("No hay datos para mostrar\n");
    return 0;
  }

  show(list);
  free(list);

  return 0;
}

void load(Record* head) {
  int account_number = 0;
  int savings_balance = 0;
  int current_balance = 0;

  printf("Ingrese Número de Cuenta: ");
  scanf("%d", &account_number);

  if (account_number == 0) {
    printf("Data entry finished\n");
    return;
  }

  printf("Ingrese Saldo en Caja de Ahorro: ");
  scanf("%d", &savings_balance);

  printf("Ingrese Saldo en Cuenta Corriente: ");
  scanf("%d", &current_balance);

  head -> account = account_number;
  head -> savings = savings_balance;
  head -> balance = current_balance;

  while(account_number != 0) {
    printf("Ingrese Número de Cuenta: ");
    scanf("%d", &account_number);

    if (account_number != 0) {
      printf("Ingrese Saldo en Caja de Ahorro: ");
      scanf("%d", &savings_balance);

      printf("Ingrese Saldo en Cuenta Corriente: ");
      scanf("%d", &current_balance);

      Record* record = malloc(sizeof(Record));

      record -> account = account_number;
      record -> savings = savings_balance;
      record -> balance = current_balance;

      head -> next = record;
      head = record;
    } else {
      printf("Data entry finished\n");
    }
  }
}

void show(Record* head) {
  printf("Account\tSavings\tBalance\n");

  while(head != NULL) {
    printf("%d\t%d\t%d\n", head -> account, head -> savings, head -> balance);
    head = head -> next;
  }
}

MergedRecord* merge(Record* head) {
  MergedRecord* merged = malloc(sizeof(MergedRecord));

  while(head != NULL) {
    record -> account = head -> account;
    record -> balance = head -> savings + head -> balance;

    merged -> next = record;
    merged = record;

    head = head -> next;
  }

  return merged;
}
