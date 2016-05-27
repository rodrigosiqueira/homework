class Document
  attr_accessor :title, :text
  attr_reader :timestamp

  def initialize(title, text)
    @title, @text = title, text
    @timestamp = Time.now
    puts 'jo'
  end

  def initialize_copy(other)
    puts 'Me'
    @timestamp = Time.now
  end
end

doc1 = Document.new("Random Stuff", File.read("Document.rb"))
sleep 3
doc2 = doc1.clone

doc1.timestamp == doc2.timestamp

doc3 = Document.new("More Stuff", File.read("Document.rb"))
sleep 3
doc4 = doc3.clone

doc3.timestamp == doc4.timestamp
