class ClassOne

  @a
  @b

  def initialize
    @a = "a"
    @b = "b"
  end

  def show
    puts "I'M ONE"
    puts @a
    puts @b
  end

  def <<(objectTwo)
    @a = objectTwo.c
    @b = objectTwo.d
  end

end
