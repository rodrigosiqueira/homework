# Approach to install

* You can use apr-util package
* You can compile APR from source, and install it in your home

# Install APR inside home dir

* mkdir ~/apr
* export PATHOME=$HOME/apr
* ./buildconf
* ./configure --prefix=$PATHOME
* make
* make install

# How to compile

> Apr has a command line very useful to generate flags. It is:

```
apr-1-config 
apr-2-config
```
> To compile using apr uses:

* 

