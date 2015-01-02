require_relative 'smokestack'
#This example was extracted from:
# http://robots.thoughtbot.com/writing-a-domain-specific-language-in-ruby

class User
  attr_accessor :name, :pet_name
end

class Post
end

Smokestack.define do
  factory(User) do
    name("Gabe Bw")
    pet_name("Toto") 
  end
end

user = Smokestack.build(User)
puts user.name == 'Gabe Bw'
puts user.pet_name == 'Toto'

other_user = Smokestack.build(User, name: 'Bob')
puts user.name == 'Bob'
puts user.pet_name == 'Toto'
