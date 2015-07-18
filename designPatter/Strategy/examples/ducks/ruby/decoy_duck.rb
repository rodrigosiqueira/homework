class Decoy < Duck

  def initialize
    setFlyBehaviour(FlyNoWay.new)
    setQuackBehaviour(Squeak.new)
  end

  def swin
    puts "Hey, can I swim?"
  end

  def display
    puts "I'm Decoy duck!"
  end

end
