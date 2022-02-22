# Challenge One - Writing a custom iterative POW function
### Written by Bryce Tuppurainen - SENG1120 PASS Leader

In this challenge, I'd like you to create a function called pow that takes two inputs that returns inputA to the power of inputB, name the arguments however you'd like. Use std::cin in main() to take these arguments from the user at runtime and run repeatedly until the value 0 is entered as inputA.

Implement this iteratively, and then test it by using the following values:

### INPUT: 1 1 OUTPUT: 1
### INPUT: 1 2 OUTPUT: 1
### INPUT: 22 0 OUTPUT: 1
### INPUT: 2 2 OUTPUT: 4
### INPUT: 2 3 OUTPUT: 8
### INPUT: 3 2 OUTPUT: 9
### INPUT: 3 4 OUTPUT: 81
### INPUT: 1928 7 OUTPUT: ?

## What happens at 1928 ^ 7 and why?
## Can we include preconditions and postconditions to let you know what inputs and outputs this will provide?
#### If you said no to the question above, try using negative values for your base and exponent and see what happens... And will you ever get a negative output from this function with a positive base or even exponent?