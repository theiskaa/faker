# faker

A UNIX command line for simulating/faking human interaction with a computer.

- The order of switches between apps is determined randomly.
- The time it takes to switch between apps depends on their listed order of priority. The sequence of app switching adheres to this priority list. Consequently, the actual duration between these app switches, often referred to as the "sleep time," is calculated within a range defined by the current highest and lowest values. _To clarify, the algorithm that establishes the sleep time operates as follows:_
```
max / (index + 1) ... (max / (max / (index + 2)))
```

### Usage
```
Usage: %s <app-1> <app-2> ... <app-N>
```
