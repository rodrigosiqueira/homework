class MyClass
  def self.new_method(name, &block)
    define_method(name, &block)
  end
end

MyClass.new_method(:mymeth) { puts "This is my method." }
x = MyClass.new
x.mymeth
