*This project has been created as part of the 42 curriculum by* <*dna2*>

## Description

**What is it all about?**<br>
-> A stack of integers that need to be sorted in ascending order, with least amount of moves.<br>
(Stack: is a method of sorting data, whether in an array or linked list, using the method **FIFO**(FirstInFirstOut))<br>
-> We are allowed to use another empty stack as a container to hold the moving pieces to ease the sorting<br>
<br>

**What is the challenge?**<br>
-> We are only allowed to use a pre-set of instructions to maneuver the stack:
1. Push(to and from stack a)
2. Swap: the first two elements (for both stacks, each on its own or at the same time)
3. Rotate: top element becomes last, all stack moves up (for both stacks, each or at the same time)
4. Reverse Rotate: last element becomes first and all stack moves down (for both stacks, each or at the same time)<br>
-> The input is from **argv can be a whole string on integers or multiple strings of integers (will need to check for valid input, and yes, it can be negative)<br>
-> We are allowed only one more stack (stack_b) to help with sorting the main stack (stack_a).<br>
<br>

**What is the purpose?**<br>
-> Multiple goals should be achieved depending on ones proficiency level:
1. Understanding how search and sorting happens.<br>
2. A window into algorithms and the vast world of it.<br>
3. Understanding the idea behind of algorithms is achieving the goal with minimum load and time correctly.<br>
4. Personally had a better practice on nodes and pointers.<br>
<br>

**The Output**<br>
-> A list of all the possible moves (in abreviation) each on a seperate line, that were used to sort the enterd values in ascending order.<br>
-> Abreviations used:<br>
- pa: push to a
- pb: push to b
- sa: swap a
- sb: swap b
- ss: swap both at the same time
- ra: rotate a
- rb: rotate b
- rr: rotate both at the same time
- rra: reverse rotate a
- rrb: reverse rotate b
- rrr: reverse rotate both at the same time
-> Example output (totally random!):  sa
                                      ra
                                      ss
                                      rrr
<br>

## Instruction

To run the program, you simply will need to:<br>
    run make-> ./push_swap (any sequence on integers) -> the output<br>
-> if you wish to see the list sorted printed out, youcan add the following to the file push_swap.c, right before the both frees:<br>
&nbsp;**while (stack_a)<br>&nbsp;{<br> &nbsp;&nbsp;&nbsp; ft_printf("%d ", stack_a->value);<br>&nbsp;&nbsp;&nbsp; stack_a = stack_a->next;<br>&nbsp;}<br>&nbsp;ft_printf("\n");**
<br>
<br>

## Resources

->As this project had been a real door to more complex programming, I have used many tools in order to understand, organise and finally debug my code to achieve the desired goal:<br>

**YouTube videos:** <br>
-><br>
**Articles & GitHub repos:** <br>
-><br>
**AI:** <br>
-><br>
