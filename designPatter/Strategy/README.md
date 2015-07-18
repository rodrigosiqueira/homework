# STRATEGY

----
# Introduction

> In a software project of any kind, exists a constant named "changes". Hence,
it is important to find out any approach for make the project flexible enough 
for new changes. If you already accepted the "change" factor, now you have to
overcome this problem with some program technique. Here, I will introduced you
to STRATEGY pattern.

----
# Basic concepts

> Before dive in the STRATEGY pattern, it is required to have 4 basic concepts
in mind.

* Abstraction: An abstract class, virtually does not have much reason for
  exists. Unless it is extend by another class.
* Interface: It is make a method abstract and provide more flexibility. 
* Is one Vs Has one: If you want to know, if some class should extends another
  class you can apply the "is one" test. Basically, you ask to yourself if is
  something "is one" thing. If the answer make a sense, you have a extend case.
* Composition: In the composition, the parent object is responsible for create
  and destroy the child object.

----
# Project principles

> Find characteristics in your application which change, and separated it from
the rest of the application.

> Code for an interface, not for concrete implementation.

> Prioritize the composition.

----
# Pattern Description

> Follows the problem which Strategy aims to fix, and the solution:

* PROBLEM: How to project varied algorithms or policies, related with each
  other? How to reduce the impact of changes?
* SOLUTION: Define each algorithm/policies/strategies in a separated class
  with one common interface. Try to isolate the things that change of things
  that not change. 

> Follows the GoF description to Strategy Pattern:
Define a family of algorithms, encapsulate each one, and make them 
interchangeable. Strategy, lets the algorithm vary independently from clients
that use it.

> See the figure below with the basic representation of Strategy class diagram:

<<<Picture>>>

