class Address

  attr_accessor :street, :city, :state

  def initialize(street1, city, state)
    @street, @city, @state = street, city, state
  end

end

books = Address.new('411 xpto', 'abc', 'de')

# Struct
Address = Struct.new("Address", :street, :city, :state)
books2 = Address.new('442', 'yo', 'youuu')
