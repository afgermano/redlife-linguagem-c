#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h> // correção do bug da acentuação
#define N 3

 
/* ===== STRUCTS ===== */
 
typedef struct {
    char nome[100];
    char tipo_sanguineo[5];
    char bolsa_vinculada[20];
} Paciente;


typedef struct {
	//Dados pessoais doador
    char nome[100];
    char cpf[100];
    char rg[100];
    char sexo[2];
    char dn[100];
    char cel[100];
    char email[100];
    char cep[100];
    char cidade[50];
    char logradouro[100];
    char numero_bairro[50];
    
    //Criterios do doador
    int idade;
    int peso;
    int saude;
    int bebida;
    int hrs_sono;
    int gravidez;
    
    //sangue do daodor
    char tipo_sanguineo[5];
    char ultima_doacao[100];
    char ndoacao[100];
    int hepatite;
    int hiv_aids;
    int chagas;
    int drogas;
    char medicamentos[100];
    char alergias[100];
    char obs[100];
    
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

/*===== Variaveis Glocais ===== */

int op;
Paciente p[3];
Doador d;
ATransfusao at[3];

//-------------
void exibir_agenda_menu();
void cadastrar_usuario();
void cadastrar_doador();
void cadastrar_paciente();
void cadastrar_bolsa();
void registro_triagem();
void agendar_transfusao();
void agendar_coleta();
void exibir_paciente();

 
/* ===== FUNÇÕES ===== */

/* ===== 0 - MENU (funções) ===== */
void exibir_menu (){
	system("cls");
	printf("_--------------------------_\n");
	printf("      SISTEMA REDLIFE       \n");
	printf("_--------------------------_\n");
	printf("1- Cadastro de usuario\n");
	printf("2- Cadastro de doador\n");
	printf("3- Cadastro de paciente\n");
	printf("4- Cadastro de bolsa\n");
	printf("5- Registro de triagem\n");
	printf("6- Agendamento de transfusao\n");
	printf("7- Agendamento de coleta\n");
	printf("8- exibir paciente\n");
	printf("9- exibir agendamentos\n");
	printf("0- Sair\n");
	printf("---------------------------\n");
}

void menu(){
	int opcao_escolhida;

	do {
		exibir_menu();
		printf("Selecione uma das opcoes: ");
		scanf("%d", &opcao_escolhida);

		switch (opcao_escolhida) {
	        case 1: cadastrar_usuario();       			break;
	        case 2: cadastrar_doador();       			break;
	        case 3: cadastrar_paciente();      			break;
	        case 4: cadastrar_bolsa();         			break;
	        case 5: registro_triagem();        			break;
	        case 6: agendar_transfusao();      			break;
	        case 7: agendar_coleta();          			break;
	        case 8: exibir_paciente();         			break;
	        case 9: exibir_agenda_menu();    			break;
	        case 0: system("cls"); printf("Programa encerrado...\n");     break;
	        default: printf("Opcao invalida!\n");
	    }
	} while (opcao_escolhida != 0);
}

// Parte Fernando - Cadastro de doador
void cadastrar_doador(){
	// criterios
	memset(&d, 0, sizeof(d));
	int opcao;
	int op;
	
	printf(" ------------------------------\n");
	printf("-      CADASTRO DE DOADOR      -\n");
	printf(" ------------------------------\n");
	
	do{
		printf("Criterios de elegiblidade -----\n");
		printf("[%s]1 - Tem entre 18 a 69 anos\n", d.idade ?"x":" ");
		printf("[%s]2 - Peso minimo entre 50kg\n", d.peso ?"x":" ");
		printf("[%s]3 - Estado de saude bom\n", d.saude ?"x":" ");
		printf("[%s]4 - Dormiu pelos menos 6horas na noite antorior\n", d.hrs_sono ?"x":" ");
		printf("[%s]5 - Não consumiu bebida alcoolica nas ultimas 12h\n", d.bebida ?"x":" ");
		printf("[%s]6 - Não esta gestando ou amamentando\n", d.gravidez ?"x":" ");
		
		printf("Digite o Numero(0 para avancar):");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1: d.idade = !d.idade; break;
			case 2: d.peso = !d.peso; break;
			case 3: d.saude = !d.saude; break;
			case 4: d.hrs_sono = !d.hrs_sono; break;
			case 5: d.bebida = !d.bebida; break;
			case 6: d.gravidez = !d.gravidez; break;
		}
		
	}while(opcao != 0);
	
	 // Verifica se é apto ← faltava isso
    if(!(d.idade && d.peso && d.saude && d.hrs_sono && d.bebida && d.gravidez)){
        printf("\nDoador NAO apto. Cadastro cancelado.\n");
        system("pause");
        return;
    }
	
	//dados pessoais
	printf("Dados pessoais -----\n");
	printf("Nome completo:");
	scanf(" %[^\n]", d.nome);
	printf("CPF:");
	scanf(" %[^\n]", d.cpf);
	printf("RG:");
	scanf(" %[^\n]", d.rg);
	printf("Sexo(M/F):");
	scanf(" %[^\n]", d.sexo);
	printf("Data de nascimento:");
	scanf(" %[^\n]", d.dn);
	
	//dados contatos
	printf("Dados de contato -----\n");
	printf("Celular:");
	scanf(" %[^\n]", d.cel);
	printf("Email:");
	scanf(" %[^\n]",d.email);
	printf("CEP:");
	scanf(" %[^\n]", d.cep);
	printf("Cidade:");
	scanf(" %[^\n]", d.cidade);
	printf("Ruas:");
	scanf(" %[^\n]", d.logradouro);
	printf("Numero:");
	scanf(" %[^\n]", d.numero_bairro);
	
	//Historico de saude
	printf("Historico de saude -----\n");
	do{
		printf("[%s]Diagnostico de hepatite B ou C\n", d.hepatite ?"x":" ");
		printf("[%s]HIV/AIDS \n", d.hiv_aids ?"x":" ");
		printf("[%s]Doenças de chagas\n", d.chagas ?"x":" ");
		printf("[%s]Uso de drogas ingetaveis\n", d.drogas ?"x":" ");
		
		printf("Digite um numero(1 ate 4 e 0 para avancar):");
		scanf("%d", &op);
		
		switch(op){
			case 1: d.hepatite = !d.hepatite;    break;
			case 2: d.hiv_aids = !d.hiv_aids;    break;
			case 3: d.chagas = !d.chagas;    break;
			case 4: d.drogas = !d.drogas;    break;
		}
		
	}while(op != 0);
	
	if(d.hepatite || d.hiv_aids || d.chagas || d.drogas){
	    printf("\nDoador INAPTO por historico de saude. Cadastro cancelado.\n");
	    system("pause");
	    return;
	}
	
	printf("--------------------------\n");
	printf("Tipo sanguineo:");
	scanf(" %[^\n]", d.tipo_sanguineo);
	printf("Ultima doaçao:");
	scanf(" %[^\n]", d.ultima_doacao);
	printf("Numero de doaçoes:");
	scanf(" %[^\n]", d.ndoacao);
	printf("Medicamentos em uso:");
	scanf(" %[^\n]", d.medicamentos);
	printf("Alergias conhecidas:");
	scanf(" %[^\n]", d.alergias);
	printf("Observacao:");
	scanf(" %[^\n]", d.obs);
}


// Parte Adriel - Cadastro de bolsas de sangue, usuario e triagem
void cadastrar_usuario(){
	// ...
}

void cadastrar_bolsa (){
	
}

// Parte Felipe - Cadastro de paciente
void cadastrar_paciente() {
    char cont;
    int i = 0;

    do {

        printf("\n--- Dados do %dº Paciente ---\n", i + 1);

        printf("Nome do paciente: ");
        scanf(" %[^\n]", p[i].nome);

        printf("Tipo sanguíneo (ex: A+, O-): ");
        scanf(" %s", p[i].tipo_sanguineo);

        printf("Código da bolsa vinculada: ");
        scanf(" %s", p[i].bolsa_vinculada);

        printf("Deseja continuar? (s/n): ");
        scanf(" %c", &cont);

        i++;
	} while ((cont == 'S' || cont == 's') && i < N);
}
    
void exibir_paciente() {
	
    int i;

    printf("\n=========================================\n");
    printf("          DADOS DOS PACIENTES\n");
    printf("=========================================\n");

    for(i = 0; i < N; i++){
    	
        printf("Paciente %d\n", i + 1);
		printf("Nome do paciente : %s\n", p[i].nome);
		printf("Tipo sanguineo   : %s\n", p[i].tipo_sanguineo);
		printf("Bolsa vinculada  : %s\n", p[i].bolsa_vinculada);
		printf("-----------------------------------------\n");
    }

    system("pause");
}
void exibir_agenda_menu(){
	system("cls");
	for(int i=0;i<N;i++){
		
   	 	printf("\n=========================================\n");
   	 	printf("      Agenda do %d Paciente \n", i+1);
   	 	printf("=========================================\n");
   	 	printf("Paciente       : %s\n", p[i].nome);
   	 	printf("Tipo sanguíneo : %s\n", p[i].tipo_sanguineo);
   	 	printf("Bolsa vinculada: %s\n", p[i].bolsa_vinculada);
   	 	printf("-----------------------------------------\n");
   	 	printf("Data           : %s\n", at[i].data);
   	 	printf("Horário        : %s\n", at[i].horario);
   	 	printf("Local/Sala     : %s\n", at[i].local_sala);
   	 	printf("Observações    : %s\n", at[i].observacoes);
   	 	printf("=========================================\n");
	}
	system("pause");
}


//Parte Bia - Agendamento de transfusão e coleta de sangue
/* ===== 6-7 - AGENDAMENTOS  ===== */
void cadastrar_agendamento_transfusao() {	
	switch (op){
		case 1:
   		 	printf("=========================================\n");
   	 		printf("  6 -  SISTEMA DE AGENDAMENTO - TRANSFUSÃO\n");
   		 	printf("=========================================\n");
 
   		 	printf("\n--- Dados do agendamento \n ---\n");
 	
   		 	printf("Data (DD/MM/AAAA): ");
   		 	scanf(" %s", at[0].data);
 
   	 		printf("Horário (HH:MM): ");
   		 	scanf(" %s", at[0].horario);
 
   		 	printf("Local/Sala: ");
   		 	scanf(" %[^\n]", at[0].local_sala);
 
   		 	printf("Observações (pressione Enter para pular): ");
   	 		scanf(" %[^\n]", at[0].observacoes);
   	 	break;
   	 	case 2:
   	 		printf("=========================================\n");
   	 		printf("  6 -  SISTEMA DE AGENDAMENTO - TRANSFUSÃO\n");
   	 		printf("=========================================\n");
 
   	 		printf("\n--- Dados do agendamento \n ---\n");
 	
   	 		printf("Data (DD/MM/AAAA): ");
   	 		scanf(" %s", at[1].data);
 		
   	 		printf("Horário (HH:MM): ");
   	 		scanf(" %s", at[1].horario);
 
   	 		printf("Local/Sala: ");
   	 		scanf(" %[^\n]", at[1].local_sala);
 
   	 		printf("Observações (pressione Enter para pular): ");
   	 		scanf(" %[^\n]", at[1].observacoes);
   	 	break;
   	 	case 3:
   	 		printf("=========================================\n");
   	 		printf("  6 -  SISTEMA DE AGENDAMENTO - TRANSFUSÃO\n");
   	 		printf("=========================================\n");
 
   	 		printf("\n--- Dados do agendamento \n ---\n");
 	
   	 		printf("Data (DD/MM/AAAA): ");
   	 		scanf(" %s", at[2].data);
	 
	   	 	printf("Horário (HH:MM): ");
   	 		scanf(" %s", at[2].horario);
 
   	 		printf("Local/Sala: ");
   	 		scanf(" %[^\n]", at[2].local_sala);
 
   	 		printf("Observações (pressione Enter para pular): ");
   	 		scanf(" %[^\n]", at[2].observacoes);
   	 	break;
	}


}

void exibir_agendamento_transfusao() {
	system("cls");
	
	switch (op){
		case 1:
   		 	printf("\n=========================================\n");
   	 		printf("       RESUMO DO AGENDAMENTO DE TRANSFUSÃO \n");
   	 		printf("=========================================\n");
   		 	printf("Paciente       : %s\n", p[0].nome);
   		 	printf("Tipo sanguíneo : %s\n", p[0].tipo_sanguineo);
   	 		printf("Bolsa vinculada: %s\n", p[0].bolsa_vinculada);
   	 		printf("-----------------------------------------\n");
   		 	printf("Data           : %s\n", at[0].data);
   	 		printf("Horário        : %s\n", at[0].horario);
   	 		printf("Local/Sala     : %s\n", at[0].local_sala);
   	 		printf("Observações    : %s\n", at[0].observacoes);
   	 		printf("=========================================\n");
   	 		printf("Agendamento realizado com sucesso!\n\n");
   	 		system("pause");
   	 	break;
   	 	case 2:
   	 		printf("\n=========================================\n");
   	 		printf("       RESUMO DO AGENDAMENTO DE TRANSFUSÃO \n");
   	 		printf("=========================================\n");
   	 		printf("Paciente       : %s\n", p[1].nome);
   	 		printf("Tipo sanguíneo : %s\n", p[1].tipo_sanguineo);
   	 		printf("Bolsa vinculada: %s\n", p[1].bolsa_vinculada);
   	 		printf("-----------------------------------------\n");
   	 		printf("Data           : %s\n", at[1].data);
   	 		printf("Horário        : %s\n", at[1].horario);
   	 		printf("Local/Sala     : %s\n", at[1].local_sala);
   	 		printf("Observações    : %s\n", at[1].observacoes);
   	 		printf("=========================================\n");
   	 		printf("Agendamento realizado com sucesso!\n\n");
   	 		system("pause");
   	 	break;
   	 	case 3:
   	 		printf("\n=========================================\n");
   	 		printf("       RESUMO DO AGENDAMENTO DE TRANSFUSÃO \n");
   	 		printf("=========================================\n");
   	 		printf("Paciente       : %s\n", p[2].nome);
   	 		printf("Tipo sanguíneo : %s\n", p[2].tipo_sanguineo);
   	 		printf("Bolsa vinculada: %s\n", p[2].bolsa_vinculada);
   	 		printf("-----------------------------------------\n");
   	 		printf("Data           : %s\n", at[2].data);
   	 		printf("Horário        : %s\n", at[2].horario);
   	 		printf("Local/Sala     : %s\n", at[2].local_sala);
   	 		printf("Observações    : %s\n", at[2].observacoes);
   	 		printf("=========================================\n");
   	 		printf("Agendamento realizado com sucesso!\n\n");
   	 		system("pause");
   	 	break;
   	 	default:
   	 		printf("sem agendamento ou paciente\n");
   	 		system("pause");
   	 	break;
   	 	
	}
	

}

int confirmar_agendamento_transfusao() {
    char opcao;
    printf("\nDeseja agendar a transfusão? (s/n): ");
    scanf(" %c", &opcao);
    return (opcao == 's' || opcao == 'S');
}

void agendar_transfusao() {
	
    ATransfusao agendamento;
    
    printf("qual paciente tera o agendamento? \n");
    printf("Paciente 1: %s \n",p[0].nome);
    printf("Paciente 2: %s \n",p[1].nome);
    printf("Paciente 3: %s \n",p[2].nome);
    scanf("%d", &op);

    cadastrar_agendamento_transfusao();

    if (confirmar_agendamento_transfusao()) {
    	system("cls");
        exibir_agendamento_transfusao();
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
	setlocale(LC_ALL, "Portuguese_Brazil");
	menu();
    return 0;
}
