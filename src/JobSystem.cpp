#include <JobSystem.hpp>

// Constructeur du Job
Job::Job(void(*jobFunction)(Job&), Job* parent) :
    _jobFunction{jobFunction},
    _parent{parent},
    _unfinishedJobs{1} // initialisé à 1 => le job n'a pas encore été exécuté
{
    if(_parent != nullptr)
    {
        _parent->_unfinishedJobs++; // incrémenter le compteur du parent
    }
}

// Fonction pour exécuter le job
void Job::run()
{
    _jobFunction(*this);
    finish();
}

// Fonction pour marquer le job comme terminé
void Job::finish()
{
    _unfinishedJobs--;

    if(finished())
    {
        if(_parent != nullptr)
        {
            _parent->finish();
        }
    }
}

// Fonction pour vérifier si le job est terminé
bool Job::finished() const
{
    return _unfinishedJobs == 0; //retrourne vrai si le job est terminé (compteur à 0)
}