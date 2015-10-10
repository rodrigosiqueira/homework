require_relative 'xmlDsl'

xml.person :name => 'Xpto "Silva" Stewart' do

  book :name => 'Godel, Escher, Bach' do
    title do
      'I am inside of this tag'
    end
  end

  book do
    'The life'
  end

  book do
    'The fabric'
  end

  info do
    'my test'
  end

  book do
    'Testing'
  end

  book

end

puts xml.tag
