require_relative 'smokestack'
#This example was extracted from:
# http://robots.thoughtbot.com/writing-a-domain-specific-language-in-ruby

# Classes that can be used in the build.
class User
  attr_accessor :name, :pet_name
end

class Post
end

# This is the default
Smokestack.define do
  factory(User) do
    name("Gabe Bw")
    pet_name("Toto") 
  end
end

# Just use the default here
user = Smokestack.build(User)
puts user.name == 'Gabe Bw'
puts user.pet_name == 'Toto'

# Buid using the override
other_user = Smokestack.build(User, name: 'Bob')
puts user.name == 'Bob'
puts user.pet_name == 'Toto'
