#include <atomic>

class Job
{
public:
    Job() = default;
    Job(void(*jobFunction)(Job&), Job* parent = nullptr);

    void run();
    bool finished() const;

private:
    void(*_jobFunction)(Job&);
    Job* _parent;
    std::atomic<size_t> _unfinishedJobs;

    void finish();
};