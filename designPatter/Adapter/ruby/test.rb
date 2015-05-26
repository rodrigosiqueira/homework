require_relative 'duck.rb'
require_relative 'mallard_duck.rb'
require_relative 'turkey_adapter.rb'
require_relative 'wild_turkey.rb'

def mainTest

  duck = MallardDuck.new()

  turkey = WildTurkey.new()

  xpto = TurkeyAdapter.new(turkey)

  puts "O peru..."
  turkey.gobble()
  turkey.fly()

  puts ""
  puts "O pato..."
  duck.quack()
  duck.fly()

  puts ""
  puts "Finalmente, o adaptador..."
  xpto.quack()
  xpto.fly()

end

