class MyClass
  def self.new_method(name, &block)
    define_method(name, &block)
  end
end

a, b = 3, 79

MyClass.new_method(:compute) { a * b }
x = MyClass.new
puts x.compute

a, b = 23, 32
p x.compute
