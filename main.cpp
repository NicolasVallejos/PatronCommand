#include <iostream>
#include <vector>

// Interfaz Command
class Command {

    public:

        virtual ~Command() = default;
        virtual void execute() = 0;

};

// Comandos concretos
class CommandA : public Command {

    public:

        void execute() override {
            std::cout << "Ejecutando comando A" << std::endl;
        }

};

class CommandB : public Command {

    public:

        void execute() override {
            std::cout << "Ejecutando comando B" << std::endl;
        }
        
};

class CommandC : public Command {
    
    public:
       
        void execute() override {
            std::cout << "Ejecutando comando C" << std::endl;
        }

};

// Invocador (Invoker)
class Menu {

    private:

        std::vector<Command*> commands;

    public:

        void addCommand(Command* command) {
            commands.push_back(command);
        }

        void executeCommand(int index) {
            if (index >= 0 && index < commands.size()) {
                commands[index]->execute();
            } else {
                std::cout << "Opción no válida" << std::endl;
            }
        }
        
};

int main() {

    // Creo instancias de comandos
    CommandA commandA;
    CommandB commandB;
    CommandC commandC;

    // Creo el menú
    Menu menu;

    // Agrego comandos al menú
    menu.addCommand(&commandA);
    menu.addCommand(&commandB);
    menu.addCommand(&commandC);

    
    int opcionSeleccionada = 1; 
    menu.executeCommand(opcionSeleccionada);

    return 0;
}