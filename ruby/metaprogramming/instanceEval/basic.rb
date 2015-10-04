# Reference:
# http://web.stanford.edu/~ouster/cgi-bin/cs142-winter15/classEval.php
# http://blog.jayfields.com/2007/03/ruby-instanceeval-and-classeval-method.html

Foo = Class.new
Foo.class_eval do
  def bar
    "bar"
  end
end

# Using def in an instance_eval defines an instance method on the singleton
# class of the receiver
# ClassName.instance_eval to define a class method
Foo.instance_eval do
  def baz
    "baz"
  end
end

# Go to irb, and play with it.
#Foo.bar
#Foo.new.bar
#Foo.baz
#Foo.new.baz
