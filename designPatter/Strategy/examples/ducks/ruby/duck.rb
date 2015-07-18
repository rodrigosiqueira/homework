# Abstract class that encapsulate Duck behaviour.
class Duck

  @flyBehavior
  @quackBehavior

  def swin
    raise NotImplementedError
  end

  # Introduce what kind of duck is the child.
  def display
    raise NotImplementedError
  end

  # Perform quack behaviour, independent of what kind of duck.
  def performDuck
    @quackBehavior.quack
  end

  # Perform fly behaviour, independent of what kind of duck.
  def performFly
    @flyBehavior.fly
  end

  # Set the fly behaviour.
  def setFlyBehaviour(pFlyBehaviour)
    @flyBehavior = pFlyBehaviour
  end

  def setQuackBehaviour(pQuackBehaviour)
    @quackBehavior = pQuackBehaviour
  end

end
