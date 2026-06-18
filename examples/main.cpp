#include <iostream>
#include <JobSystem.hpp>

void childJob(Job& job)
{
    std::cout << "    enfant : début\n";
    std::cout << "    enfant : fin\n";
}

void parentJob(Job& job)
{
    std::cout << "parent : début\n";
    std::cout << "parent : fin\n";
}

int main()
{
    Job parent(&parentJob, nullptr); // construire le parent
    Job child(&childJob, &parent);   // construire l'enfant avec le parent

    std::cout << std::boolalpha; // pour afficher true/false au lieu de 1/0
    std::cout << "Avant parent.run() : parent fini = " << parent.finished() << "\n";

    parent.run();

    std::cout << "Après parent.run() : parent fini = " << parent.finished() << "\n";

    child.run();

    std::cout << "Après child.run() : parent fini = " << parent.finished() << "\n";

    return 0;
}