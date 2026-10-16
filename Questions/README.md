# Theorical questions

[Back to main README](../README.md)

1. What are the steps involved in the compilation process?

- Precompilation : Macro and optimisation
- Compilation : create object file 
- Linkage : gather all object file to create executable

2. What is the difference between a declaration and a definition?

- declaration : the signature and the type of the return value (if there is one) often in the `.hpp` file or at the start of the file.
- definition : the logical part of the function (What does the function do).

3. What is the difference between passing a parameter by value, by reference, and by pointer?

- by value : create a copy of the original variable so the modifications are local to the function.
- by pointer : any modification a done or the variable pointed so the modifications are global.
- by reference : the variable is used normally (don't need to dereference to access the data) but behind it's a pointer (so the modifications are global).

4. What is the difference between the stack and the heap?

- stack : the static memory of the program (know at the compilation).
- heap : the dynamic memory of the program (use for every `new` object create for exemple).

5. What is the difference between struct and class in C++?

Only the scope change, function and variable are private by default in a class and they are public for a struct.

6. What is the difference between the public, protected, and private access specifiers?

- Public : can be used inside and outside the object.
- Private : can only be used inside the object and not inside children's object.
- Protected : like private but can be use inside children's objects.

7. What is a pure virtual function? What effect does it have on a class?

It's a function that doesn't have a definition, they can't be called. It's used so the children's class must have a definition for the function.

8. Briefly explain the diamond problem in multiple inheritance.

It's when a class inherits from two classes that inherits from the same class :
```
   A
 /   \
B     C
 \   /
   D

```

The issue is that the class B and C will create their own instance of A so in memory it will be : [A][B][A][C][D]
So there is confusion on which A to use.  

9. Name the different containers studied in class and describe the strengths and weaknesses of each.

- Array
  - strengths : easy to go through, to add element
  - weaknesses : Can't change the size, expensive to research a element

- Vector : It's a Array but with a dynamic size
  - strengths : can change the size, easy to go through
  - weaknesses : can be expensive to add/remove element, to research a element

- List : Chained or doubled chained list
  - strengths : easy to add/remove element
  - weaknesses : heavier, expensive to research a element

- Map : use a pair of Key and Value to stock element
  - strengths : easy to research a element
  - weaknesses : heavier, expensive to go through

- Set :  like map but use the hash of the Value as the Key 
  - strengths : easy to research a element
  - weaknesses : heavier

- Queue : FIFO, are use in some special case
- Stack : FILO, are use in some special case

10. For each of the following scenarios, identify the most appropriate container and justify your choice.
- You need to store the top ten scores in a game. The number of elements is known and will never change. -> `Array`
- You need to manage a queue of tasks that must be executed in the order they arrive. -> `Queue`
- You frequently need to insert and remove elements in the middle of a sequence. -> `List`
- You need to store a large number of elements and frequently check whether a particular element exists. The order of the elements does not matter. ->`(unordered) Set`
- You need to keep track of actions so that the most recent action can be undone before earlier actions. -> `Stack`
- You need to manage a collection of players whose number can change over time, with frequent read and traversal operations. -> `Vector` 
- You need to associate each student ID with a grade and retrieve a grade quickly using the student ID. ->`(unordered) Map`