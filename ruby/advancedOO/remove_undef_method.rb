class Parent
  def alpha
    puts "Parent alpha"
  end

  def beta
    puts "parent beta"
  end
end

class Child < Parent
  def alpha
    puts "child alpha"
  end

  def beta
    puts "Child beta"
  end

  remove_method :alpha  # Remove 'this' alpha
  undef_method :beta    # Remove every beta
end

x = Child.new

x.alpha # Parent alpha

puts "We expect an error now."
x.beta  # Error!
