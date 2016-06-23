Start a little text file called notes.txt and use it as a kind of "lab notes" for ideas, bugs, problems, etc.
Before you use gdb, write out the bug you're going to fix and what could be causing it.
For each cause, write out the files and functions where you think the cause is coming from, or just write that you don't know.
Now start gdb and pick the first possible cause with good file:function possibles and set breakpoints there.
Use gdb to then run the program and confirm if that is the cause. The best way is to see if you can use the set command to either fix the program easily or cause the error immediately.
If this isn't the cause, then mark in the notes.txt that it wasn't and why. Move on to the next possible cause that's easiest to debug, and keep adding information you gather.