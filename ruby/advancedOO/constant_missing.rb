class Module
  def const_missing(x)
    "From Module"
  end
end

class X
end

p X::BAR  # From module
p BAR     # From module
p Array::BAR # From module
