#include <iostream>

using std::string;


class AbstractEmployee {
	virtual void AskForPromotion() = 0;
};

class Employee: AbstractEmployee {
private: // We can change de default member
	// Members is private by default
	// private, public and protected
	string Name;
	string Company;
	int Age;
public: // Emcapsulation
	
	void setName(string name) {
		Name = name;
	}
	string getName() {
		return Name;
	}

	void setCompany(string company) {
		Company = company;
	}
	string getCompany() {
		return Company;
	}

	void setAge(int age) {
		Age = age;
	}
	int getAge() {
		return Age;
	}
	// Abstraction
	void AskForPromotion() {
		
	}

	void IntroduceYourself() {
		std::cout << "Name - " << Name << std::endl;
		std::cout << "Company - " << Company << std::endl;
		std::cout << "Age - " << Age << std::endl;
	}

	Employee(string name, string company, int age) {
		Name = name;
		Company = company;
		Age = age;
	}
};

class Developer : Employee {
public:
	string FavPromigramminLanguage;
	Developer(string name, string company, int age, string favPromigramminLanguage) : Employee(name, company, age) {
		FavPromigramminLanguage = favPromigramminLanguage;
	}
};

/*
	Polymorphm
	The most common use is when a parent class reference is used to refer to a child class object
*/

void main() {
	Employee employee1 = Employee("Leo", "Autaza", 21);

	employee1.IntroduceYourself(); 

	std::cout << employee1.getAge() << std::endl;

	// F11 to debug more specific
	// F10 shalow debug
	
}


/*
	Nome de arquivo .cpp e .h
	Separação por _

	nome_arquivo.cpp


*/

// Primeria letra maíuscula
class Class {


	// Nome de Atributos das classes
	string m_theta21; // Iniciasse com m_

	// Nome para variáveis
	string scale_max; // Todas letras minúsculas, separado por _

	//Defines e Constantes
	string MAX_HEIGHT; // Todas as letra maíusculas, separada por _

	// Siglas
	string ROI;

	// Methods
	void applyMask() {} // Primeira letra minuscula, aa demais maíuscula

	/*
		Branches

		Feature
		vX/palavras-separadas-por-hifen
		vX = version ex: v9

		Release
		release-v11.7.18-BETAv1

		Bugfix

		Bugs autorizados no BETA
		bugfix-release-vA.B.C-<NOME>

		Para o cliente
		bugfix-vA.B.C+1-<NOME>

		Fix - Corrigir feature no develop
		vX/fix-<regra de branch de feature>
		Ex: v8/fix-phase-shift
			v12/fix-curvature-enums

		Commit
		Mensagens significativas que descrevam o conteúdo enviado 
		naquele commit considerando cada mudança
	
		Tag
		Versão do release sem complemento preferencialmente
		Ex: v10.0.0    /    v10.1.0-debugMode

		Tag no submódulo
		Software e versão completa que usou o branch do submódulo
		Ex: AutazaSurfacev9.0.0
	
	*/


};


class Remuneracao {
public:
	virtual void pagamento() {};
};

class Estagiario : public Remuneracao {
public:
	void pagamento() {
		std::cout << "Test Intern" << std::endl;
	}
};

class CLT : public Remuneracao {
	void pagamento() {
		std::cout << "Test CLT" << std::endl;
	}
};

class FolhaDePagamento {
	public:
		virtual void calcular(Remuneracao remuneracao) {
			remuneracao.pagamento();
		}
};

/*
	Inversão de Dependênia com injeção de dependência

	------------------------------------------------------------------------------------------------

	Inversão de Dependência - Um módulo de alto nível não deve depender de módulos de baixo nível, 
	ambos devem depender da abstração.

	Módulo de alto nível é um módulo que depende de outros módulos.
	
	O módulo que é a dependência é o modulo de baixo nível

	------------------------------------------------------------------------------------------------

	“Programe para uma interface e não para uma implementação.”

	Isso significa que ao invés de programar uma classe que seria uma classe concreta, programar uma
	interface, para que as classes concretas implementem a interface

	classe é implementação
	interface é abstração
*/

/*
	Inversão de Dependênia com injeção de dependência
*/

class ConnectionInterface {
public:
	virtual void connect() {};

	ConnectionInterface() {};
};

class MySQLConnection : ConnectionInterface {
public:
	void connect() {
		std::cout << "MySQL Connection connected ..." << std::endl;
	};
};

class UserController {
public:

	ConnectionInterface DbConnection;

	UserController(ConnectionInterface connectionInterface) {
		DbConnection = connectionInterface;
	}

	void login() {
		DbConnection.connect();
	}
};

