*This project has been created as part of the 42 curriculum by mbruyere.*

## Description

Philosophers is an introduction to multithreading in C, based on the classic
dining philosophers problem. N philosophers sit around a round table with one
fork between each pair. To eat, a philosopher needs both adjacent forks. Each
philosopher repeatedly eats, sleeps and thinks, and dies if they do not start
eating within `time_to_die` milliseconds of the start of their last meal.

Each philosopher is a thread and each fork is a mutex. The main thread acts as
a monitor: it detects a death within a few milliseconds, or stops the
simulation once every philosopher has eaten enough.

Technical choices:
- **Deadlock prevention**: even philosophers take their right fork first, odd
  philosophers their left fork first, so a circular wait cannot happen.
- **Data races**: every shared value is protected by a mutex (`meal_mutex` per
  philosopher for `last_meal` and `meals_count`, `stop_mutex` for the stop flag,
  `print_mutex` for the output).
- **Timing**: a custom sleep checks the clock every 0.5 ms instead of relying
  on a single `usleep`, so delays do not accumulate.
- **Odd number of philosophers**: a short thinking delay keeps the schedule
  fair so that no philosopher starves.
- **Single philosopher**: takes the only fork and waits until the monitor
  declares their death.
- **No global variables**: all shared data lives in one `t_table` structure
  declared in `main`, and each philosopher keeps a pointer to it.

## Instructions

Compile and run:

```bash
cd philo
make
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

All times are in milliseconds. Examples:

```bash
./philo 1 800 200 200      # the philosopher dies
./philo 5 800 200 200      # no one should die
./philo 5 800 200 200 7    # stops once everyone has eaten 7 times
./philo 4 410 200 200      # no one should die
./philo 4 310 200 100      # one philosopher dies
```

Check for data races and memory leaks:

```bash
valgrind --tool=helgrind ./philo 4 800 200 200 3
valgrind --tool=drd ./philo 4 800 200 200 3
valgrind --leak-check=full ./philo 4 800 200 200 3
```

## Resources

- [Dining philosophers problem (Wikipedia)](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [Threads, mutexes and concurrent programming in C (codequoi)](https://www.codequoi.com/en/threads-mutexes-and-concurrent-programming-in-c/)
- `man pthread_create`, `man pthread_join`, `man pthread_mutex_lock`, `man gettimeofday`

### Use of AI

An AI assistant (Claude) was used as a tutor throughout the project:

- to explain the subject, threads, mutexes, data races and deadlocks, and to
  review the evaluation criteria;
- to write this README.
