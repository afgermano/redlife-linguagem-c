#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
/* ===== STRUCTS ===== */
 
typedef struct {
    char nome[100];
    char tipo_sanguineo[5];
    char bolsa_vinculada[20];
} Paciente;

Paciente p;

typedef struct {
    char nome[100];
    char tipo_sanguineo[5];
} Doador;
 
typedef struct {
    char data[11]; 
    char horario[6];
    char local_sala[50];
    char observacoes[300];
} ATransfusao;

typedef struct {
    char data[11]; 
    char horario[6];
    char local_sala[50];
    char observacoes[300];
} AColeta;

void cadastrar_usuario();
void cadastrar_doador();
void cadastrar_paciente_menu();
void cadastrar_bolsa();
void registro_triagem();
void agendar_transfusao();
void agendar_coleta();
void exibir_paciente_menu();
 
/* ===== FUNÇÕES ===== */

/* ===== 0 - MENU (funções) ===== */
void exibir_menu (){
	system("cls");
	printf("1- Cadastro de usuario\n");
	printf("2- Cadastro de doador\n");
	printf("3- Cadastro de paciente\n");
	printf("4- Cadastro de bolsa\n");
	printf("5- Registro de triagem\n");
	printf("6- Agendamento de transfusao\n");
	printf("7- Agendamento de coleta\n");
	printf("8- exibir paciente\n");
	printf("0- Sair\n");
}

void menu(){
	int opcao_escolhida;

	do {
		exibir_menu();
		printf("Selecione uma das opcoes: ");
		scanf("%d", &opcao_escolhida);

		switch (opcao_escolhida) {
	        case 1: cadastrar_usuario();       break;
	        case 2: cadastrar_doador();        break;
	        case 3: cadastrar_paciente_menu(); break;
	        case 4: cadastrar_bolsa();         break;
	        case 5: registro_triagem();        break;
	        case 6: agendar_transfusao();      break;
	        case 7: agendar_coleta();          break;
	        case 8: exibir_paciente_menu();      break;
	        case 0: system("cls"); printf("Programa encerrado...\n");     break;
	        default: printf("Opcao invalida!\n");
	    }
	} while (opcao_escolhida != 0);
}

// Parte Fernando - Cadastro de doador
void cadastrar_doador(){
	// ...
}


// Parte Adriel - Cadastro de bolsas de sangue, usuario e triagem
void cadastrar_usuario(){
	// ...
}

void cadastrar_bolsa (){
	
}
 
void registro_triagem (){
	
}

// Parte Felipe - Cadastro de paciente
void cadastrar_paciente(Paciente *p) {
    printf("\n--- Dados do Paciente ---\n");
 
    printf("Nome do paciente: ");
    scanf(" %[^\n]", p->nome);
 
    printf("Tipo sanguíneo (ex: A+, O-): ");
    scanf(" %s", p->tipo_sanguineo);
 
    printf("Código da bolsa vinculada: ");
    scanf(" %s", p->bolsa_vinculada);
}
void exibir_paciente(Paciente *p) {

    printf("\n=========================================\n");
    printf("          DADOS DO PACIENTE\n");
    printf("=========================================\n");

    printf("Nome do paciente : %s\n", p->nome);
    printf("Tipo sanguineo   : %s\n", p->tipo_sanguineo);
    printf("Bolsa vinculada  : %s\n", p->bolsa_vinculada);

    printf("=========================================\n\n");
    system("pause");
}

void cadastrar_paciente_menu() {

    cadastrar_paciente(&p);
}

void exibir_paciente_menu(){
	
	exibir_paciente(&p);
}

//Parte Bia - Agendamento de transfusão e coleta de sangue
/* ===== 6-7 - AGENDAMENTOS  ===== */
void cadastrar_agendamento_transfusao(ATransfusao *at) {	
	printf("=========================================\n");
    printf("  6 -  SISTEMA DE AGENDAMENTO - TRANSFUSÃO\n");
    printf("=========================================\n");
 
 	printf("\n--- Dados do agendamento \n ---\n");
 	
    printf("Data (DD/MM/AAAA): ");
    scanf(" %s", at->data);
 
    printf("Horário (HH:MM): ");
    scanf(" %s", at->horario);
 
    printf("Local/Sala: ");
    scanf(" %[^\n]", at->local_sala);
 
    printf("Observações (pressione Enter para pular): ");
    scanf(" %[^\n]", at->observacoes);
}

void exibir_agendamento_transfusao(Paciente *p, ATransfusao *at) {
    printf("\n=========================================\n");
    printf("       RESUMO DO AGENDAMENTO DE TRANSFUSÃO \n");
    printf("=========================================\n");
    printf("Paciente       : %s\n", p->nome);
    printf("Tipo sanguíneo : %s\n", p->tipo_sanguineo);
    printf("Bolsa vinculada: %s\n", p->bolsa_vinculada);
    printf("-----------------------------------------\n");
    printf("Data           : %s\n", at->data);
    printf("Horário        : %s\n", at->horario);
    printf("Local/Sala     : %s\n", at->local_sala);
    printf("Observações    : %s\n", at->observacoes);
    printf("=========================================\n");
    printf("Agendamento realizado com sucesso!\n\n");
}

int confirmar_agendamento_transfusao() {
    char opcao;
    printf("\nDeseja agendar a transfusão? (s/n): ");
    scanf(" %c", &opcao);
    return (opcao == 's' || opcao == 'S');
}

void agendar_transfusao() {
    Paciente paciente;
    ATransfusao agendamento;

    cadastrar_paciente(&paciente);
    cadastrar_agendamento_transfusao(&agendamento);

    if (confirmar_agendamento_transfusao()) {
    	system("cls");
        exibir_agendamento_transfusao(&paciente, &agendamento);
    } else {
    	system("cls");
        printf("\nAgendamento cancelado.\n\n");
    }
}

// adicionar uma lógica que só possibilita a função ser feita após a aprovação da triagem
void cadastrar_doador_coleta(Doador *d) {
    printf("\n--- Dados do Doador ---\n");
 
    printf("Nome do doador: ");
    scanf(" %[^\n]", d->nome);
 
    printf("Tipo sanguíneo (ex: A+, O-): ");
    scanf(" %s", d->tipo_sanguineo);
}

void cadastrar_agendamento_coleta(AColeta *ac) {
	printf("=========================================\n");
    printf("  7 -  SISTEMA DE AGENDAMENTO - DOAÇÃO\n");
    printf("=========================================\n");
 
 	printf("\n--- Dados do agendamento \n ---\n");
 	
    printf("Data (DD/MM/AAAA): ");
    scanf(" %s", ac->data);
 
    printf("Horario (HH:MM): ");
    scanf(" %s", ac->horario);
 
    printf("Local/Sala: ");
    scanf(" %[^\n]", ac->local_sala);
 
    printf("Observacoes: ");
    scanf(" %[^\n]", ac->observacoes);
}

void exibir_agendamento_coleta(Doador *d, AColeta *ac) {
    printf("\n=========================================\n");
    printf("       RESUMO DO AGENDAMENTO DE Doador \n");
    printf("=========================================\n");
 	// Adicionar os dados do doador
    printf("Doador         : %s\n", d->nome);
    printf("Tipo sanguineo : %s\n", d->tipo_sanguineo);
    printf("-----------------------------------------\n");
    printf("Data           : %s\n", ac->data);
    printf("Horário        : %s\n", ac->horario);
    printf("Local/Sala     : %s\n", ac->local_sala);
    printf("Observações    : %s\n", ac->observacoes);
    printf("=========================================\n");
    printf("Agendamento realizado com sucesso!\n\n");
}

int confirmar_agendamento_coleta() {
    char opcao;
    printf("\nDeseja confirmar o agendamento? (s/n): ");
    scanf(" %c", &opcao);
    return (opcao == 's' || opcao == 'S');
}

void agendar_coleta() {
    Doador doador;
    AColeta agendamento;

    cadastrar_doador_coleta(&doador);
    cadastrar_agendamento_coleta(&agendamento);

    if (confirmar_agendamento_coleta()) {
    	system("cls");
        exibir_agendamento_coleta(&doador, &agendamento);
    } else {
    	system("cls");
        printf("\nAgendamento cancelado.\n\n");
    }
}

 
int main() {
	menu();
    return 0;
}
