class MyClass
  def new_method(name, &block)
    self.class.send(:define_method, name, &block)
  end
end

x = MyClass.new
x.new_method(:mymeth) { p "Me again..." }
x.mymeth
