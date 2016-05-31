class MyClass
  attr_reader :alpha, :beta

  def initialize(a, b, g)
    @alpha, @beta, @gamma = a, b, g
  end
end

x = MyClass.new(10, 11, 12)

x.instance_variable_set("@alpha", 234)
p x.alpha

x.instance_variable_set("@gamma", 345)
v = x.instance_variable_get("@gamma")
