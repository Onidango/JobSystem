#include <iostream>
#include <JobSystem.hpp>

// Exemple d'utilisation du JobSystem
void myJobFunction(Job& job) {
    std::cout << "Je travaille sur le job\n";
    // insérer ici le corps de la fonction du job
}

int main() {
    // construire un Job en fournissant la fonction, sans parent
    Job j(&myJobFunction, nullptr);

	// exécuter le job
    j.run();
    return 0;
}