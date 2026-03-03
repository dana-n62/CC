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

->As this project had been a real door to more complex programming, I have used many tools in order to understand, organize and finally debug my code to achieve the desired goal:<br>

**YouTube videos:** <br>
-> https://youtu.be/OaG81sDEpVk?si=j2aj1crmmEkPfCT8<br>
-> https://youtu.be/4dMsuxfqufg?si=hLvz9vCPhXSgaCBr<br><br>
**Other resources:** <br>
-> Before starting, i used Notion to organize my thoughts and build a structure for the work to be done, and explanation in my own words for some concepts, you can find it here: <br>
-> https://www.notion.so/5-Push_Swap-291b038429a8803599e7cc9c8bdcb2bf <br><br>
**AI:** <br>
-> I used the following prompt to help me understand and save time on navigating the project, which lead to a deeper understanding and faster work pace as if you had a friend leaving everything and walk you through the project! Having that said, the output was faulty and i had to debug the project multiple times until i found the error and had it fixed:<br><br>
"act like a guiding teacher, walk me through steps to build the given project, and explanation of key concepts, also questions to test knowledge acquired along.  the outcome should be a fully functioning code ready to be submitted, and a good understanding of nodes, stacks and the chosen algorithm" --> this lead ot to give me code, so i added the following: <br><br>
"no code needed now, i want to build the code by myself, i need you to walk me through it one step at a time, starting with explaining the complete journey, then start the  guide one by one where you should wait for my confirmation to move to the next step, after we're done ask me to upload the code so you can evaluate it like a 42school molunitte" <br><br>
It will be helpful as well to add the wanted file structure but not necessary. <br>
