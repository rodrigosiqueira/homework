require_relative 'xmlDsl'

xml.person :name => 'Xpto "Silva" Stewart' do
  book do
    'Godel, Escher, Bach'
  end

  book do
    'The life'
  end

  book do
    'The fabric'
  end

  book do
    'Testing'
  end

  book

end

puts xml.tag
