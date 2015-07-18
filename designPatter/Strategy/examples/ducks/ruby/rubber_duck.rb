class RubberDuck < Duck

  def initialize
    setFlyBehaviour(FlyNoWay.new)
    setQuackBehaviour(MuteQuack.new)
  end

  def swin
    puts "No dude... You cannot swing :("
  end

  def display
    puts "Rubber Duck!!!"
  end

end
