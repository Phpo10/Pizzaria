#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

int total, quantidade;

int pizza(){
	
	//Vetor para o sabor de pizza
	char saboresPizza[3][20] = { "Mussarela", "Calabresa", "Carne" };
	char tamanhoPizza[3][20] = { "Pequena", "Média", "Família" };
	
	//Sistema do case 1 para pizzas
	
	int pizzat, pizzas, sabor=0, sabores;
	
	//Pedido de pizza
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("Carregando o cardápio de pizzas...\n");
	printf("-----------------------------------------------------------------------------------------------\n");
	Sleep(2000);
	printf("A pizza vai ser pequena, média ou família?\n[1] %s R$15,00 (Tem direito a 1 sabor)\n[2] %s R$28,00 (Tem direito a 2 sabores)\n[3] %s R$38,00 (Pizza com os sabores Mussarela, Calabresa e Carne)\n", tamanhoPizza[0], tamanhoPizza[1], tamanhoPizza[2]);
	printf("Escolha: ");
	scanf("%d", &pizzat);
	
	if (pizzat == 1){
		printf("-----------------------------------------------------------------------------------------------\n");
		printf("Qual o sabor desejado:\n[1] %s\n[2] %s\n[3] %s\n", saboresPizza[0], saboresPizza[1], saboresPizza[2]);
		printf("Escolha: ");
		scanf("%d", &pizzas);

		
		//erro ao escolher menor que 0 e maior que 4
		if ((pizzas <= 0)||(pizzas >= 4)){
			printf("-----------------------------------------------------------------------------------------------\n");
			printf("Não entendi o pedido. Fechando o programa.");
			exit(3);
		}
	}
	if (pizzat == 2){
		printf("-----------------------------------------------------------------------------------------------\n");
		printf("Qual é o primeiro sabor desejado:\n[1] Mussarela\n[2] Calabresa\n[3] Carne\n");
		printf("Escolha: ");
		scanf("%d", &pizzas);
		sabores = pizzas;
			
		//erro ao escolher menor que 0 e maior que 4
		if ((pizzas <= 0)||(pizzas >= 4)){
			printf("-----------------------------------------------------------------------------------------------\n");
			printf("Não entendi o pedido. Fechando o programa.\n");
			exit(3);
		}
		sabor ++;
			
			//Loop de repetição para o sabor ser diferente
			while(sabor<2){
				if (sabor == 1){
					printf("-----------------------------------------------------------------------------------------------\n");
					printf("Qual é o segundo sabor desejado:\n[1] Mussarela\n[2] Calabresa\n[3] Carne\n");
					printf("Escolha: ");
					scanf("%d", &pizzas);
					if (pizzas == sabores){
						printf("-----------------------------------------------------------------------------------------------\n");
						printf("Você já escolheu esse sabor. Tem certeza que quer o mesmo?\n[1] Sim\n[2] Não\n");
						printf("Escolha: ");
						scanf("%d", &pizzas);
						if (pizzas == 1){
							printf("-----------------------------------------------------------------------------------------------\n");
							printf("Sabor escolhido com sucesso.\n");
							printf("-----------------------------------------------------------------------------------------------\n");
							sabor ++;
						}
						else if (pizzas == 2){
							printf("-----------------------------------------------------------------------------------------------\n");
							printf("Retornando...\n");
							Sleep(1000);
						}
						else {
							printf("-----------------------------------------------------------------------------------------------\n");
							printf("Não entendi o pedido. Retornando...\n");
							Sleep(1000);
						}
					}
					else if ((pizzas != sabores) && (pizzas > 4) || (pizzas < 0)){
						printf("-----------------------------------------------------------------------------------------------\n");
						printf("Sabor inexistente. Por favor, escolha outro.\n");
					}
					else if ((pizzas != sabores) && (pizzas < 4) || (pizzas > 0)){
						printf("-----------------------------------------------------------------------------------------------\n");
						printf("Sabores escolhidos com sucesso\n");
						printf("-----------------------------------------------------------------------------------------------\n");
						sabor ++;
					}
				
			}
		}
	}
	//escolha da pizza familia
	if (pizzat == 3){
		printf("-----------------------------------------------------------------------------------------------\n");
		printf("Todos os sabores estão incluidos\n");
		printf("-----------------------------------------------------------------------------------------------\n");
	}
	//erro ao escolher menor que 0 e maior que 4
	if ((pizzat <= 0)||(pizzat >= 4)){
		printf("-----------------------------------------------------------------------------------------------\n");
		printf("Não entendi o pedido. Fechando o programa.");
		exit(3);
	}
	printf("Quantidade de pizza desejada: ");
	scanf("%d", &quantidade);
	if (pizzat == 1){
		total += quantidade*15;
	}
	else if (pizzat == 2){
		total += quantidade*28;
	}
	else if (pizzat == 3){
		total += quantidade*38;
	}
	return total;
}

int bebidas(){
	//Vetor para as opções de bebidas
	char bebidasOpcoes [2][20] = { "Refrigerante", "Cerveja" };
	
	//Sistema para o case 2 para bebidas
	
	int bebida=0, idade;
	
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("Carregando o cardápio de bebidas...\n");
	printf("-----------------------------------------------------------------------------------------------\n");
	Sleep(2000);
	printf("Qual bebida desejada?\n[1] %s\n[2] %s\n", bebidasOpcoes[0], bebidasOpcoes[1]);
	printf("Escolha: ");
	scanf("%d", &bebida);
	
	if ((bebida <= 0)||(bebida >= 3)){
		printf("-----------------------------------------------------------------------------------------------\n");
		printf("Não entendi o pedido. Fechando o programa.");
		exit(3);
	}
	
	//Primeira Opção
	
	if (bebida == 1){
		printf("-----------------------------------------------------------------------------------------------\n");
		printf("Nós temos os seguintes refrigerantes:\n[1] Coca R$7,00\n[2] Guaraná R$6,00\n[3] Fanta R$5,00\n");
		printf("Escolha: ");
		scanf("%d", &bebida);
		
		//erro ao escolher menor que 0 e maior que 4
		if ((bebida <= 0)||(bebida >= 4)){
			printf("-----------------------------------------------------------------------------------------------\n");
			printf("Não entendi o pedido. Fechando o programa.");
			exit(3);
		}

		printf("Quantidade de bebida desejada: ");
		scanf("%d", &quantidade);
		
		//Condição para definir o preço da bebida com base na quantidade
		
		if (bebida == 1){
			total += quantidade*7;
		}
		else if (bebida == 2){
			total += quantidade*6;
		}
		else if (bebida == 3){
			total += quantidade*5;
		}
	}
	
	//Pedido de alcoól com idade
	
	else if (bebida == 2){
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("Só vendemos bebida alcoólica para maiores. Por favor, nos informe sua idade:  ");	
	scanf("%d", &idade);
	if (idade >= 18){
		printf("-----------------------------------------------------------------------------------------------\n");
		printf("Nós temos os seguintes tipos de cerveja:\n[1] Schin R$ 4,00\n[2] Brahma R$ 5,00\n[3] Heineken R$ 8,00\n");
		printf("Escolha: ");
		scanf("%d", &bebida);
		
		//erro ao escolher menor que 0 e maior que 4
		if ((bebida <= 0)||(bebida >= 4)){
			printf("-----------------------------------------------------------------------------------------------\n");
			printf("Não entendi o pedido. Fechando o programa.");
			exit(3);
		}
		
		printf("Quantidade desejada? ");
		scanf("%d", &quantidade);
		if (bebida == 1){
			total += quantidade*4;
		}
		else if (bebida == 2){
			total += quantidade*5;
		}
		else if (bebida == 3){
			total = quantidade*8;
		}
	}
		else if (idade < 18){
			printf("-----------------------------------------------------------------------------------------------\n");
			printf("Não podemos vender bebidas alcoólicas para menores de idade.\n");
			exit(3);
		}
}
		return total;
}

int lanches(){
	//Vetor para os sabores de lanches
	char lanchesSabores[3][20] = { "Misto", "Frango", "Carne" };
	
	int lanche;
	
	//Sistema para o case 3 dos lanches
	
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("Carregando o cardápio de lanches...\n");
	printf("-----------------------------------------------------------------------------------------------\n");
	Sleep(2000);
	printf("Qual sabor do lanche desejado? \n[1] %s R$4,00\n[2] %s R$4,00\n[3] %s R$5,00\n", lanchesSabores[0], lanchesSabores[1], lanchesSabores[2]);
	printf("Escolha: ");
	scanf("%d", &lanche);
		//erro ao escolher menor que 0 e maior que 4
		if ((lanche <= 0)||(lanche >= 4)){
			printf("-----------------------------------------------------------------------------------------------\n");
			printf("Não entendi o pedido. Fechando o programa.");
			exit(3);
		}
	printf("Quantidade de lanche desejado: ");
	scanf("%d", &quantidade);
	
	//Condição para definir o preço do lanche com base na quantidade
	
	if(lanche == 1){
		total += quantidade*4;
	}
	else if(lanche == 2){
		total += quantidade*4;
	}
	else if(lanche == 3){
		total += quantidade*5;
	}
	return total;
}

struct cadastro{
	char nome[20];
	char cpf[11];
};

main (){
	
	int escolha, escolha2, escolhaf;
	struct cadastro cliente;
	
	setlocale(LC_ALL, "portuguese");
	
	//Nome e cardápio
	printf("Bem vindo a Pizzaria São Frascisco. Vamos começar seu cadastro.\n");
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("Nos informe seu primeiro nome: ");
	scanf("%s", cliente.nome);
	printf("Seu CPF: ");
	scanf("%s", cliente.cpf);
	printf("\n-----------------------------------------------------------------------------------------------\n");
	printf("Bem vindo, %s! Gostaria de ver nosso cardápio?\n[1] Sim\n[2] Não\n", cliente.nome);
	printf("Escolha: ");	
	scanf("%d", &escolha);
	printf("-----------------------------------------------------------------------------------------------\n");
	printf("Carregando...\n");
	Sleep(3000);
	escolhaf = 1;
	
	//Loop da escolha final e switch com as escolhas de lanches
	while(escolhaf!=2){ 
		if (escolha == 1){
			printf("-----------------------------------------------------------------------------------------------\n");
			printf("Nosso cardápio tem os seguintes itens:\n[1] Pizzas\n[2] Bebidas\n[3] Lanches\n");
			printf("Qual sua preferência? ");
			scanf("%d", &escolha2);
			switch(escolha2){
				case 1:
					pizza();
					break;
				case 2:
					bebidas();
					break;
				case 3:
					lanches();
					break;
				default:
					printf("-----------------------------------------------------------------------------------------------\n");
					printf("Não entendi seu pedido. Por favor, tente novamente.\n");
					exit(3);
			}
		printf("-----------------------------------------------------------------------------------------------\n");
		printf("Gostaria de pedir mais alguma coisa?\n[1] Sim\n[2] Não\n");
		printf("Escolha: ");
		scanf("%d", &escolhaf);
 		}//fechamento do if

	else if (escolha == 2){
		printf("-----------------------------------------------------------------------------------------------\n");
		printf("Agradeçemos por seu tempo.\n");
		break;
}
	else if ((escolha <= 0)||(escolha >= 3)){
		printf("-----------------------------------------------------------------------------------------------\n");
		printf("Não entendi sua escolha. ");
		break;
}
}//fechamento do while
if (total >= 1){
	printf("Obrigado pelo pedido e volte sempre! O preço total a ser pago é de R$%d,00", total);
}
else{
	printf("Obrigado e volte sempre!");
}
}
