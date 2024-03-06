#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>
#include <cassert>
using namespace std;



bool exitProgram = false;
int proximoNumeroAluno = 1;

struct Data{
	int dia;
	int mes;
	int ano;

	void preencher() {
		cin >> dia >> mes >> ano;
		if ((dia < 1 || dia > 31) || (mes < 1 || mes > 12) || (ano < 1904 || ano > 2024)) {
			system("cls");
			cout << "opcao invalida, TENTE NOVAMENTE!" << endl;
			cout << "Data (dia, mes e ano): ";
			preencher();
		}
	}
};

struct Aluno{
	string nome;
	int numeroAluno;
	Data dataNascimento;
	Data dataMatricula;
	long long int telefone;
	int diasRestantesMatricula;
	string tipo;

	Aluno(){
        // a cada momento que a struct é chamada, o código realiza esta operação;
		numeroAluno = proximoNumeroAluno;
		proximoNumeroAluno++;
	}

    //preenche os dados de qual é o tempo de matrícula do aluno
	void preencherTipoMatricula() {
		cout << "1 - anual" << endl;
		cout << "2 - mensal" << endl;
		int tecla;
		cin >> tecla;
		switch (tecla) {
			case 1:
				tipo = "anual";
				break;
			case 2:
				tipo = "mensal";
				break;
			default:
				system("cls");
				cout << "opcao invalida, TENTE NOVAMENTE!" << endl;
				cin.clear();
				cin.ignore(99999, '\n');
				preencherTipoMatricula();
				break;
		}
	}

    // preenche os dados de cada aluno
	void preencher() {
		cout << "Nome: ";
		cin >> nome;

		cout << "Data de Nascimento (dia, mes e ano): ";
        //chama a função que realiza o preenchimento da data de nascimento do aluno;
		dataNascimento.preencher();
		cout << "Data de matricula: ";
        //chama a função que realiza o preenchimento da data de matrícula do aluno;
		dataMatricula.preencher();

		cout << "Telefone: ";
		cin >> telefone;

        //chama a função que realiza o preenchimento do tipo de matricula o aluno irá realizar
		preencherTipoMatricula();
	}
};

vector<Aluno> listaAlunos;

void menu();
void contarDiasRestantes(const Aluno &aluno);
void adicionarAluno();
void mostrarAluno(int i);
void escolherAluno();
void percorrerAlunos(int numeroAluno);
int idade(const Data &dataNascimento);
void trocarAlunos(Aluno &a, Aluno &b);


int idade(const Data &dataNascimento) {
    //time_t retorna a variável o tempo em segundo desde a época de 1970
	time_t now = time(0);
    //tm converte o tempo atual para uma estrutura local
	tm *ltm	= localtime(&now);

    // faz a subtração da variável ltm, que guradava nesse caso, o ano, e subtrai o ano de nascimento do aluno
	int idade = ltm->tm_year + 1900 - dataNascimento.ano;
    //verifica se o mês e o dia atual são menores do que o mês e o dia em que o aluno nasceu, descobrindo se ele tem ou não, um ano a menos
	if (ltm->tm_mon + 1 < dataNascimento.mes || (ltm->tm_mon + 1 == dataNascimento.mes && ltm->tm_mday < dataNascimento.dia)) {
		idade--;
	}
	return idade;
}

//função que apenas realiza a troca entre alunos para poder realizar a ordenação por idade;
void trocarAlunos(Aluno &a, Aluno &b) {
	Aluno temp = a;
	a = b;
	b = temp;
}

void bubbleSortRecursivo(int n) {
	if (n == 1) return;
	for (int i = 0; i < n - 1; i++){
        //verifica se o aluno com a data de nascimento do vetor na posição i é menor da posição i+1;
		if (idade(listaAlunos[i].dataNascimento) < idade(listaAlunos[i + 1].dataNascimento)){
            //faz a troca dos alunos para poder ordená-los com base em suas idades;
			trocarAlunos(listaAlunos[i], listaAlunos[i + 1]);
		}
	}
	bubbleSortRecursivo(n - 1);
}

void adicionarAluno() {
	int quantidadeAluno;

	cout << "Quantos alunos deseja adicionar: ";
    //enquanto tiver uma entrada diferente de um int, ele ficará repetindo até que haja uma reposta correta;
	while (!(cin >> quantidadeAluno)) {
		system("cls");
		cout << "Valor invalido, insira novamente: ";
		cin.clear();
		cin.ignore();
	}
	//chama a função de preencher os dados dos alunos conforme a quantidade de alunos que você deseja adicionar;
	for (int i = 0; i < quantidadeAluno; i++) {
		Aluno novoAluno;

		cout << endl << "Digite os dados para o aluno " << i + 1 << endl;
		novoAluno.preencher();

		listaAlunos.push_back(novoAluno);
	}

	bubbleSortRecursivo(listaAlunos.size());
}

void escolherAluno() {
	int numeroAluno;

	cout << "Selecione o numero do aluno:" << endl;
	//imprime todos os alunos;
	for (auto &aluno : listaAlunos) {
		cout << aluno.numeroAluno << ". " << aluno.nome << endl;
	}
	//enquanto a entrada for diferente do número de algum aluno, ele continuará repetindo para você colocar um valor correto
	while (!(cin >> numeroAluno)) {
		cout << "Valor invalido, insira novamente: ";
		cin.clear();
		cin.ignore();
	}
	percorrerAlunos(numeroAluno);
}

void percorrerAlunos(int numeroAluno) {
	// onde ocorre a busca sequencial do aluno escolhido
    int n = listaAlunos.size();
    int v[n];
    for(int i = 0; i < n; i++){
        v[i] = i + 1;
    }
    int *p = v;

	for (int i = 0; i < n; i++) {
		if (numeroAluno == *(p + i)) {
			mostrarAluno(i);
		}
	}
}

//mostra os dados que haviamos colocado no aluno que escolhermos;
void mostrarAluno(int i) {
	const Aluno &aluno = listaAlunos[i];
	cout << endl << "Aluno encontrado:" << endl;
	cout << "Nome: " << aluno.nome << endl;
	cout << "Data de Nascimento: " << aluno.dataNascimento.dia << "/" << aluno.dataNascimento.mes << "/" << aluno.dataNascimento.ano << endl;
	cout << "Data de matricula: " << aluno.dataMatricula.dia << "/" << aluno.dataMatricula.mes << "/" << aluno.dataMatricula.ano << endl;
	cout << "Telefone: " << aluno.telefone << endl;
	contarDiasRestantes(aluno);
	cout << "-----------------------" << endl;
}

void contarDiasRestantes(const Aluno &aluno){
	//conta quantos dias faltam para acabar a matrícula do aluno;
	time_t tempo = time(nullptr);
	tm *dataHora = localtime(&tempo);
	//calcula o total da soma de dias;
	int diasMesAno = dataHora->tm_mday + (dataHora->tm_mon + 1) * 30 + (dataHora->tm_year + 1900) * 365;
	int diasMatricula = aluno.dataMatricula.dia + aluno.dataMatricula.mes * 30 + aluno.dataMatricula.ano * 365;
	assert(aluno.tipo == "anual" || aluno.tipo == "mensal");
	//calcula os dias restantes de acordo com o tipo da matricula do aluno;
	int diasRestantes = diasMatricula + ((aluno.tipo == "anual") ? 365 : 30) - diasMesAno;

	if (diasRestantes > 0) {
		cout << "Dias restantes da matricula para " << aluno.nome << ": " << diasRestantes << " dias." << endl;
	} else {
		cout << "A matricula de " << aluno.nome << " expirou! Por favor, renove sua matricula." << endl;
	}
	
}

void menu() {
	int *ptr = new int;
	int escolha;

	cout << "1 - Adicionar aluno" << endl;
	cout << "2 - Procurar aluno" << endl;
	cout << "3 - Sair" << endl;

	cin >> escolha;
	*ptr = escolha;
	switch (*ptr) {
		case 1:
			adicionarAluno();
			break;
		case 2:
			escolherAluno();
			break;
		case 3:
			exitProgram = true;
			break;
	}
}

void lerArquivos() {
	ifstream arquivo("alunos.gym");
	string nome;
	while (arquivo >> nome) {
		Aluno aluno;
		aluno.nome = nome;
		arquivo >> aluno.numeroAluno;
		arquivo >> aluno.dataNascimento.dia >> aluno.dataNascimento.mes >> aluno.dataNascimento.ano;
		arquivo >> aluno.dataMatricula.dia >> aluno.dataMatricula.mes >> aluno.dataMatricula.ano;
		arquivo >> aluno.telefone;
		arquivo >> aluno.diasRestantesMatricula;
		arquivo >> aluno.tipo;
		listaAlunos.push_back(aluno);
	}
}

void escreverArquivos() {
	ofstream arquivo("alunos.gym");
	for (Aluno aluno : listaAlunos) {
		arquivo << aluno.nome << "\n";
		arquivo << aluno.numeroAluno << "\n";
		arquivo << aluno.dataNascimento.dia << "\n" << aluno.dataNascimento.mes << "\n" << aluno.dataNascimento.ano << "\n";
		arquivo << aluno.dataMatricula.dia << "\n" << aluno.dataMatricula.mes << "\n" << aluno.dataMatricula.ano << "\n";
		arquivo << aluno.telefone << "\n";
		arquivo << aluno.diasRestantesMatricula << "\n";
		arquivo << aluno.tipo << "\n";
	}
}

int main() {
	
	lerArquivos();

	while (!exitProgram) {
		menu();
	}

	escreverArquivos();
	return 0;
}