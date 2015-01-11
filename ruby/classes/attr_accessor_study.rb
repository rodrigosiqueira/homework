
class AttrAccessorStudy
  attr_accessor :thisIsArray
  attr_accessor :thisIsString
  attr_accessor :thisIsInteger

  def initialize
    @thisIsArray = Array.new
    @thisIsString = "First!!"
  end

  def << (value)
    @thisIsArray.push(value)
  end

end
