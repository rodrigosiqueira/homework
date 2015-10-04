class ClassTwo

  attr_reader :c
  attr_reader :d

  def initialize
    @c = "c"
    @d = "d"
  end

  def show
    puts "I'M TWO"
    puts @c
    puts @d
  end

end
