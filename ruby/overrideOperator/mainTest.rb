require_relative 'classOne'
require_relative 'classTwo'

m = ClassOne.new
m.show
k = ClassTwo.new
k.show

m << k
m.show
