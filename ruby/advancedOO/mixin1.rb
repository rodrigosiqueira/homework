module MyMod

  def MyMod.append_features(someClass)
    def someClass.modmeth
      puts "Module (class) method"
    end
    super
  end

  def meth1
    puts "yes, I'm meth1"
  end
end

class MyClass
  include MyMod

  def MyClass.classmeth
    puts "class method"
  end

  def meth2
    puts "method 2"
  end
end

x = MyClass.new

MyClass.classmeth
x.meth1
MyClass.modmeth
x.meth2
