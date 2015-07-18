class MallardDuck < Duck

  def initialize
    setFlyBehaviour(FlyWithWings.new)
    setQuackBehaviour(Quack.new)
  end

  def swin
    puts "I'm swimming now!"
  end

  def display
    puts "I'm the mallard Duck!"
  end

end
