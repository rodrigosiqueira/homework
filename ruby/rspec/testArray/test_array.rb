require 'rspec'

RSpec.describe Array do
  before do
    @array = Array.new(["value1", "value2", "value3"])
  end
 
  it "should return a blank instance" do
    Array.new.should == []
  end
 
  it "hash the correct information in a key" do
    @array[0].should == 'value1'
  end

  it "Test all elements in the list" do
    expect(@array).to match_array(["value1", "value2", "value3"])
  end
end
