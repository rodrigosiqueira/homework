class RedHeadDuck < Duck

  def initialize
    setFlyBehaviour(FlyWithWings.new)
    setQuackBehaviour(Squeak.new)
  end

  def swin
    puts "Swimming..."
  end

  def display
    puts "Hey dude, I'm RedHeadDuck!"
  end

end
