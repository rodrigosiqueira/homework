class Person
  attr_accessor :name, :age, :phone

  def initialize(n, a, p)
    @name, @age, @phone = n, a, p
  end
end

p1 = Person.new('John Smith', 29, '555-555')
p2 = Person.allocate

p p1.age
p p2.age
