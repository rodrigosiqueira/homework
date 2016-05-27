class Document
  attr_accessor :title, :text
  attr_reader :timestamp

  def initialize(title, text)
    @title, @text = title, text
    @timestamp = Time.now
  end
end

doc1 = Document.new("Random Stuff", File.read("Document.rb"))
sleep 3
doc2 = doc1.clone

doc1.timestamp == doc2.timestamp
