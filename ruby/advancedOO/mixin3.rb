module MyMod
  def meth3
    p "Module instance method meth3"
    p "can become a class method."
  end
end

  class MyClass
    extend MyMod
  end

MyClass.meth3
